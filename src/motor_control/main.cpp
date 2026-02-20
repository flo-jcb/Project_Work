#include "ModbusClient.h"
#include <iostream>
#include <unistd.h>

#define PI  3.14159265359

int main()
{
    std::cout << "hello" << std::endl;
    std::cout << std::flush;

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
            std::cout << std::flush;

        return -1;
    }

    ModbusClient motor(1, port); // Slave ID 1

    std::cout << "hello" << std::endl;
        std::cout << std::flush;

        
    

    uint16_t value;

    uint16_t RPM; //Revolutions/min

    double w; //Angular velocity

    Modbus::StatusCode status;

    while(1){
        // Lire registre 1 (courrant en dV)
        status = motor.readInputRegisters(3, 1, &value);

        if (Modbus::StatusIsGood(status)){
            std::cout << "Courrant actuel = " << value << std::endl;
                std::cout << std::flush;}

        else{
            std::cout << "Erreur lecture " << status << std::endl;
            std::cout << std::flush;
        }

        // Ecrire registre 1 (vitesse)
        status = motor.writeSingleRegister(1,10);

        if (Modbus::StatusIsGood(status)){
            std::cout << "Ecriture OK, vitesse 10" << std::endl;    
            std::cout << std::flush;
        }
            
        else{            std::cout << "Erreur ecriture : " << status << std::endl;

                std::cout << std::flush;

        }
        
        //Lire vitesse rentrée
        status = motor.readHoldingRegisters(1, 1, &value);
        if (Modbus::StatusIsGood(status))
            std::cout << "Vitesse actuel = " << value << std::endl;
        else
            std::cout << "Erreur lecture " << status << std::endl;





 status = motor.readHoldingRegisters(2, 1, &value);
        if (Modbus::StatusIsGood(status))
            std::cout << "disable  " << value << std::endl;
        else
            std::cout << "Erreur lecture " << status << std::endl;
int c=0;
 status = motor.writeSingleRegister(0,1);
while(c<41){
    status = motor.readHoldingRegisters(c, 1, &value);
    std::cout << "value  " << c <<" : " << value << std::endl;
    c++;
    }






 status = motor.writeSingleRegister(2,1);

        if (Modbus::StatusIsGood(status)){
            std::cout << "Ecriture OK" << std::endl;    
            std::cout << std::flush;
        }
            
        else{            std::cout << "Erreur ecriture : " << status << std::endl;

                std::cout << std::flush;

        }





        // Lire registre 7 (vitesse)
        status = motor.readInputRegisters(7, 1, &value);

        if (Modbus::StatusIsGood(status))
            std::cout << "Vitesse reelle = " << value << std::endl;
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
    }

    return 0;
}
