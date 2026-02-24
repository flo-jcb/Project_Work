#include "ModbusClient.h"
#include <iostream>
#include <unistd.h>

#define PI  3.14159265359

int main()
{
    Modbus::SerialSettings settings;

    settings.portName = "/dev/ttyAMA0";
    settings.baudRate = 19200;
    settings.parity = Modbus::EvenParity;
    settings.dataBits = 8;
    settings.timeoutInterByte=1000;

    ModbusClientPort* port =
        Modbus::createClientPort(Modbus::RTU, &settings, true);

    if (!port)
    {
        std::cout << "Port creation failed" << std::endl;
        return -1;
    }

    ModbusClient motor(1, port); // Slave ID 1

    uint16_t value;

    uint16_t RPM; //Revolutions/min

    double w; //Angular velocity

    Modbus::StatusCode status;








uint16_t mode;
status = motor.readHoldingRegisters(21, 1, &mode); // 40022 -> index 21
std::cout << "Mode = " << mode << std::endl;

// 1️⃣ Lire Parameter 13
    status = motor.readHoldingRegisters(33, 1, &value);
    if (Modbus::StatusIsGood(status))
        std::cout << "Parameter 13 actuel = " << value << std::endl;
    else
    {
        std::cout << "Erreur lecture param 13: " << status << std::endl;
        return -1;
    }
    if( value!= 2){
        // 2️⃣ Mettre Parameter 13 = 2 (mode Bus)
        status = motor.writeSingleRegister(33, 2);
        if (Modbus::StatusIsGood(status))
            std::cout << "Parameter 13 mis a 2 (Bus mode)" << std::endl;
        else
        {
            std::cout << "Erreur ecriture param 13: " << status << std::endl;
            return -1;
        }

        sleep(1);

        // 3️⃣ Sauvegarder dans EEPROM (Parameter Update = 2)
        status = motor.writeSingleRegister(20, 2);
        if (Modbus::StatusIsGood(status))
            std::cout << "Parametres sauvegardes en EEPROM" << std::endl;
        else
        {
            std::cout << "Erreur sauvegarde: " << status << std::endl;
            return -1;
        }

        sleep(1);

        // 4️⃣ Vérifier que la valeur est bien appliquée
        status = motor.readHoldingRegisters(33, 1, &value);
        if (Modbus::StatusIsGood(status))
            std::cout << "Parameter 13 maintenant = " << value << std::endl;
        else
            std::cout << "Erreur verification: " << status << std::endl;
    }
    










 // 4️⃣ Vérifier que la valeur est bien appliquée
        status = motor.readHoldingRegisters(23, 1, &value);
        if (Modbus::StatusIsGood(status))
            std::cout << "Parameter 3 maintenant = " << value << std::endl;
        else
            std::cout << "Erreur verification: " << status << std::endl;
    
    

















    // Activer le Bus
   status = motor.writeSingleRegister(0, 1);   

    if (Modbus::StatusIsGood(status))
        std::cout << "Début " << std::endl;
    else
        std::cout << "Erreur ecriture " << status << std::endl;

    // Verif que Disable = 0
   status = motor.writeSingleRegister(2, 0);   

    if (Modbus::StatusIsGood(status))
        std::cout << "Début " << std::endl;
    else
        std::cout << "Erreur ecriture " << status << std::endl;

    //Ecriture direction 1 (avant)
    status =motor.writeSingleRegister(3, 1);

    if (Modbus::StatusIsGood(status))
        std::cout << "Début " << std::endl;
    else
        std::cout << "Erreur ecriture " << status << std::endl;






// Ecrire registre 1 (vitesse)
    status = motor.writeSingleRegister(23,4);

    if (Modbus::StatusIsGood(status))
        std::cout << "Ecriture OK 1500rpm" << std::endl;
    else
        std::cout << "Erreur ecriture : " << status << std::endl;









    sleep(10);

    // Ecrire registre 1 (vitesse)
    status = motor.writeSingleRegister(1,600);

    if (Modbus::StatusIsGood(status))
        std::cout << "Ecriture OK" << std::endl;
    else
        std::cout << "Erreur ecriture : " << status << std::endl;
        
    //Lire vitesse rentrée
    status = motor.readHoldingRegisters(1, 1, &value);
    if (Modbus::StatusIsGood(status))
        std::cout << "Vitesse actuel = " << value << std::endl;
    else
        std::cout << "Erreur lecture " << status << std::endl;

    int c=0; 
    while(1){
        // Lire registre 7 (vitesse)
        status = motor.readInputRegisters(7, 1, &value);

        if (Modbus::StatusIsGood(status))
            std::cout << "Vitesse actuel = " << value << std::endl;
        else
            std::cout << "Erreur lecture " << status << std::endl;

        // Lire registre 1 (Motor frequency)
        status = motor.readInputRegisters(4, 1, &value);

        if (Modbus::StatusIsGood(status)){
            std::cout << "Fréquence actuel = " << value << std::endl;
            RPM=value*60;
            w=(2*PI*RPM)/60;
            std::cout << "RPM: " << RPM << " w: " << w<< std::endl;
        }
        else
            std::cout << "Erreur lecture " << status << std::endl;

        sleep(3);
        // Mettre Disable = 1
       if(c==5){
        status = motor.writeSingleRegister(2, 1);   

        if (Modbus::StatusIsGood(status))
            std::cout << "Fin " << std::endl;
        else
            std::cout << "Erreur ecriture " << status << std::endl;
        }
        c++;
    }

    return 0;
}
