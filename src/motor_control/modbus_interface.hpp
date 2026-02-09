#pragma once
#include "ModbusClient.h"
#include "ModbusTcpPort.h"
#include "ModbusClientPort.h"

class MotorController {
public:
    MotorController(const char* device, int baud, int slave_id);
    ~MotorController();

    bool connect();
    void setSpeed(int speed);
    void setPosition(int position);
    int  readPosition();

private:
    mode_t* ctx;
};
