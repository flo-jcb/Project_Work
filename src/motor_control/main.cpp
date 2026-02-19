#include "ModbusClient.h"
#include <iostream>

int main()
{
    Modbus::SerialSettings settings;

    settings.portName = "/dev/ttyAMA0";
    settings.baudRate = 19200;
    settings.parity = Modbus::EvenParity;
    settings.dataBits = 8;

    ModbusClientPort* port =
        Modbus::createClientPort(Modbus::RTU, &settings, true);

    if (!port)
    {
        std::cout << "Port creation failed" << std::endl;
        return -1;
    }

    ModbusClient motor(1, port); // Slave ID 1

    uint16_t value;

    Modbus::StatusCode status;

    while(1){
        // Lire registre 1 (courrant en dV)
        status = motor.readInputRegisters(3, 1, &value);

        if (Modbus::StatusIsGood(status))
            std::cout << "Courrant actuel = " << value << std::endl;
        else
            std::cout << "Erreur lecture " << status << std::endl;

        // Ecrire registre 1 (vitesse)
        status = motor.writeSingleRegister(1,100);

        if (Modbus::StatusIsGood(status))
            std::cout << "Ecriture OK, vitesse 100" << std::endl;
        else
            std::cout << "Erreur ecriture : " << status << std::endl;
        
        //Lire vitesse rentrée
        status = motor.readHoldingRegisters(1, 1, &value);
        if (Modbus::StatusIsGood(status))
            std::cout << "Vitesse actuel = " << value << std::endl;
        else
            std::cout << "Erreur lecture " << status << std::endl;

        // Lire registre 7 (vitesse)
        status = motor.readInputRegisters(7, 1, &value);

        if (Modbus::StatusIsGood(status))
            std::cout << "Vitesse actuel = " << value << std::endl;
        else
            std::cout << "Erreur lecture " << status << std::endl;

        // Lire registre 1 (Motor frequency)
        status = motor.readInputRegisters(4, 1, &value);

        if (Modbus::StatusIsGood(status))
            std::cout << "Fréquence actuel = " << value << std::endl;
        else
            std::cout << "Erreur lecture " << status << std::endl;
    }

    return 0;
}
