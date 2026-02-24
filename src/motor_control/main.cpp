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
    status = motor.writeSingleRegister(1,10);

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
        }
        else
            std::cout << "Erreur lecture " << status << std::endl;

        sleep(5);
        // Mettre Disable = 1
       status = motor.writeSingleRegister(2, 1);   

        if (Modbus::StatusIsGood(status))
            std::cout << "Fin " << std::endl;
        else
            std::cout << "Erreur ecriture " << status << std::endl;
    }

    return 0;
}
