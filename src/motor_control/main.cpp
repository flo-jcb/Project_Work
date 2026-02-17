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
    else std::cout << "Port created" << std::endl;
    
    ModbusClient motor(1, port); // Slave ID 1

    uint16_t value;

    // Lire registre 4
    Modbus::StatusCode status =
        motor.readHoldingRegisters(4, 1, &value);

    if (Modbus::StatusIsGood(status))
        std::cout << "Reg 11 = " << value << std::endl;
    else
        std::cout << "Erreur lecture : " << status << std::endl;

    // Ecrire registre 1 (exemple)
    /*status = motor.writeSingleRegister(1, 100);

    if (Modbus::StatusIsGood(status))
        std::cout << "Ecriture OK" << std::endl;
    else
        std::cout << "Erreur ecriture : " << status << std::endl;*/

    return 0;
}
