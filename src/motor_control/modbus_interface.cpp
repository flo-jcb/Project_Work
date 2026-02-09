#include "modbus_interface.hpp"
#include <iostream>

MotorController::MotorController(const char* device, int baud, int slave_id) {
    //ctx = modbus_new_rtu(device, baud, 'N', 8, 1);
    //modbus_set_slave(ctx, slave_id);
}

MotorController::~MotorController() {
    //modbus_close(ctx);
    //modbus_free(ctx);
}

bool MotorController::connect() {
   /*if (modbus_connect(ctx) == -1) {
        std::cerr << "Erreur connexion Modbus\n";
        return false;
    }*/
    return true;
}

void MotorController::setSpeed(int speed) {
    //modbus_write_register(ctx, 40002, speed);
}

void MotorController::setPosition(int position) {
    //modbus_write_register(ctx, 40001, position);
}

int MotorController::readPosition() {
    uint16_t pos;
    //modbus_read_registers(ctx, 30001, 1, &pos);
    return pos;
}
