#include "modbus_interface.hpp"
#include <iostream>

int main() {
    MotorController motor("/dev/ttyUSB0", 19200, 1);

    /*if (!motor.connect()) return -1;

    motor.setSpeed(500);
    motor.setPosition(1000);

    int pos = motor.readPosition();
    std::cout << "Position actuelle: " << pos << std::endl;*/

    return 0;
}
