#ifndef T2D_H
#define T2D_H

#include <Arduino.h>

class T2D {

public:

    enum class Register {
        Temp,
        Config,
        T_hyst,
        T_os
    };

    T2D(byte i2cAddr = 0b01001000);

    void INIT(byte configVal = 0b00000000);

    int write(T2D::Register reg, unsigned int regValue);
    int write(T2D::Register reg, byte regValue);

    unsigned int read(T2D::Register reg, bool readOneByte = false);

    double getTemp();

private:
    byte getRegAddress(T2D::Register regName);

private:
    const byte _I2C_ADDR;
};

#endif  // T2D_H