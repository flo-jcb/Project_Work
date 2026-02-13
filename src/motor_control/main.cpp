/*#include <ModbusClientPort.h>
#include <ModbusClient.h>
#include <ModbusServerPort.h>
#include <iostream>

int main()
{   Modbus::TcpSettings settings;
    settings.host = "EM-347B";
    settings.port = Modbus::STANDARD_TCP_PORT;
    settings.timeout = 3000;
    ModbusClientPort *port = Modbus::createClientPort(Modbus::TCP, &settings, true);
    ModbusClient c1(1, port);
    ModbusClient c2(2, port);
    ModbusClient c3(3, port);
    ModbusClient c4(4, port);
    Modbus::StatusCode s1, s2, s3, s4;
    uint16_t regs1[10], regs2[10], regs3[10],regs4[10];
    while(1)
    {
        s1 = c1.readHoldingRegisters(0, 10, regs1);
        s2 = c2.readHoldingRegisters(0, 10, regs2);
        s3 = c3.readHoldingRegisters(0, 10, regs3);
        s4 = c4.readHoldingRegisters(0, 10, regs4);
        Modbus::msleep(1);
    }
    return 0;
}*/

#include "ModbusClient.h"
#include <iostream>

int main()
{
    Modbus::SerialSettings settings;

    settings.portName = "/dev/ttyACM0";   // Pico vu comme port USB
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

    Modbus::StatusCode status = motor.readHoldingRegisters(10, 0, &value);
    if (Modbus::StatusIsGood(status))
    {
           

            std::cout << "Feedback : " << value << std::endl;

    }
    else
        std::cout << "Error " << '\n';

    return 0;
}
