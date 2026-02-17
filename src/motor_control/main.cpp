#include "ModbusClient.h"
#include <iostream>

int main()
{
    Modbus::SerialSettings settings;

    settings.portName = "/dev/serial0";   // Pico vu comme port USB
    settings.baudRate = 19200;
    settings.parity = Modbus::EvenParity;
    settings.dataBits = 8;
    settings.timeoutInterByte = 1000;

    ModbusClientPort* port =
        Modbus::createClientPort(Modbus::RTU, &settings, true);

    ModbusClient motor(1, port);   // Slave ID = 1 (EM347)

    uint16_t value;

    // Activer le bus
    //motor.writeSingleRegister(0, 1);   // 40001

    // Régler la vitesse
   // motor.writeSingleRegister(1, 500); // 40002

    // Lire vitesse réelle (exemple registre 10)

    Modbus::StatusCode status = motor.readHoldingRegisters(10, 1, &value);

    if (Modbus::StatusIsGood(status))
    {
        std::cout << "Feedback : " << value << std::endl;
    }
    else
    {
        std::cout << "Error code: " << status << std::endl;
    }


    return 0;
}
