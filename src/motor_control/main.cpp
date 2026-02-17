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

    ModbusClient motor(1, port);

    uint16_t value;

    Modbus::StatusCode status =
        motor.readHoldingRegisters(11, 1, &value);

    if (Modbus::StatusIsGood(status))
        std::cout << "OK: " << value << std::endl;
    else
        std::cout << "Error: " << status << std::endl;



    return 0;
}
