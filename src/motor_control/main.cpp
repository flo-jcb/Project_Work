#include <ModbusClientPort.h>
#include <ModbusClient.h>
#include <ModbusServerPort.h>
#include <iostream>

void main()
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

}

