/*#include "ModbusClient.h"
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
    
    
    status=motor.writeSingleRegister(21, 1);  // Closed loop
    if (Modbus::StatusIsGood(status))
            std::cout << "Parameter 13 maintenant = " << std::endl;
        else
            std::cout << "Erreur verification: " << status << std::endl;
sleep(1);
    status=motor.writeSingleRegister(20, 2);  // Save EEPROM
    if (Modbus::StatusIsGood(status))
        std::cout << "Parameter 13 maintenant = " << std::endl;
    else
        std::cout << "Erreur verification: " << status << std::endl;
sleep(1);


    uint16_t currentLimit;
    motor.readHoldingRegisters(32, 1, &currentLimit);
    if (Modbus::StatusIsGood(status))
        std::cout << "Current limit = " << currentLimit << std::endl;
    else
            std::cout << "Erreur verification: " << status << std::endl;


status = motor.writeSingleRegister(26, 100);  // 100 ms ou 0.1 s selon unité
if (!Modbus::StatusIsGood(status))
    std::cout << "Erreur écriture Acceleration" << std::endl;

// Sauvegarde EEPROM
motor.writeSingleRegister(20, 2);
sleep(1);

uint16_t accel;
motor.readHoldingRegisters(26, 1, &accel);
    if (Modbus::StatusIsGood(status))
        std::cout << "Acceleration = " << accel << std::endl;
    else
        std::cout << "Erreur verification: " << status << std::endl;





    // Ecrire registre 1 (vitesse)
    status = motor.writeSingleRegister(1,300);

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










    // Activer le Bus
   status = motor.writeSingleRegister(0, 1);   

    if (Modbus::StatusIsGood(status))
        std::cout << "Bus ok " << std::endl;
    else
        std::cout << "Erreur ecriture " << status << std::endl;

    // Verif que Disable = 0
   status = motor.writeSingleRegister(2, 0);   

    if (Modbus::StatusIsGood(status))
        std::cout << "Disable desac " << std::endl;
    else
        std::cout << "Erreur ecriture " << status << std::endl;

    //Ecriture direction 1 (avant)
    status =motor.writeSingleRegister(3, 1);

    if (Modbus::StatusIsGood(status))
        std::cout << "Dir ok " << std::endl;
    else
        std::cout << "Erreur ecriture " << status << std::endl;









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
            w=2*PI*value;
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
}*/




#include "ModbusClient.h"
#include <iostream>
#include <unistd.h>

#define PI 3.14159265359

int main()
{
    // ----------------------------
    // 1️⃣ Config port série Modbus
    Modbus::SerialSettings settings;
    settings.portName = "/dev/ttyAMA0";
    settings.baudRate = 19200;
    settings.parity = Modbus::EvenParity;
    settings.dataBits = 8;
    settings.timeoutInterByte = 1000;

    ModbusClientPort* port = Modbus::createClientPort(Modbus::RTU, &settings, true);
    if (!port) {
        std::cout << "Port creation failed" << std::endl;
        return -1;
    }

    ModbusClient motor(1, port); // Slave ID 1
    Modbus::StatusCode status;
    uint16_t value;

    // ----------------------------
    // 2️⃣ Mode Bus (Parameter 13)
    motor.writeSingleRegister(33, 2);
    sleep(1);

    // ----------------------------
    // 3️⃣ Courant et acceleration élevés
    //motor.writeSingleRegister(32, 40); // courant max
    //motor.writeSingleRegister(26, 200);  // acceleration max
    sleep(1);

    // ----------------------------
    // 4️⃣ Mode Closed Loop (reg 21)
    //motor.writeSingleRegister(21, 1);
    sleep(0.5);

    // ----------------------------
    // 5️⃣ Activer bus et désactiver safety
    motor.writeSingleRegister(0, 1); // Enable bus
    sleep(0.2);
    motor.writeSingleRegister(2, 0); // Disable = 0
    sleep(0.5);

    // ----------------------------
    // 6️⃣ Choisir direction (1 = avant)
    motor.writeSingleRegister(3, 1);
    sleep(0.2);

    // ----------------------------
    // 7️⃣ Écrire vitesse pour test
    motor.writeSingleRegister(1, 300); // vitesse max (ajuster selon doc EM-347B)
    sleep(0.5);


    //motor.writeSingleRegister(25, 0); // av=20
    //sleep(0.5);

    //motor.writeSingleRegister(34, 3); // av=0
    //sleep(0.5);



    std::cout << "Moteur démarré, monitoring..." << std::endl;
    int nb;
    // ----------------------------
    // 8️⃣ Monitoring fréquence et courant moteur
    //for (int c = 0; c < 3; c++) {
        while(1){
        // Fréquence moteur
        status = motor.readInputRegisters(4, 1, &value);
        if (Modbus::StatusIsGood(status)) {
            double RPM = value * 60;
            double w = 2 * PI * value;
            std::cout << "Fréquence = " << value << " | RPM = " << RPM << " | w = " << w << std::endl;
        } else {
            std::cout << "Erreur lecture fréquence" << std::endl;
        }

        // Courant moteur
        status = motor.readInputRegisters(5, 1, &value);
        if (Modbus::StatusIsGood(status))
            std::cout << "Courant moteur = " << value << std::endl;
        else
            std::cout << "Erreur lecture courant" << std::endl;

        // Courant moteur
        status = motor.readInputRegisters(3, 1, &value);
        if (Modbus::StatusIsGood(status))
            std::cout << "Voltage = " << value << std::endl;
        else
            std::cout << "Erreur lecture " << std::endl;

        sleep(1);
        
       
        nb=0;
        while (nb!=4){
            status = motor.readHoldingRegisters(nb, 1, &value);
            if (Modbus::StatusIsGood(status))
                std::cout << "Valeur du param " << nb <<" = "<< value << std::endl;
            else
                std::cout << "Erreur lecture courant" << std::endl;
            nb++;
            sleep(0.5);
        }
        nb=21;
        while (nb!=43){
            status = motor.readHoldingRegisters(nb, 1, &value);
            if (Modbus::StatusIsGood(status))
                std::cout << "Valeur du param " << nb <<" = "<< value << std::endl;
            else
                std::cout << "Erreur lecture courant" << std::endl;
            nb++;
            sleep(0.5);
        }
        sleep(1);
        nb=0;
        while (nb!=16){
            status = motor.readInputRegisters(nb, 1, &value);
            if (Modbus::StatusIsGood(status))
                std::cout << "Valeur du param " << nb <<" = "<< value << std::endl;
            else
                std::cout << "Erreur lecture courant" << std::endl;
            nb++;
            sleep(0.5);
        }
        sleep(1);
     }
    

    // ----------------------------
    // 9️⃣ Stop moteur et désactiver bus
    /*motor.writeSingleRegister(2, 1); // Disable = 1
    sleep(0.2);
    motor.writeSingleRegister(0, 0); // Disable bus
    std::cout << "Moteur arrêté" << std::endl;*/

    return 0;
}


