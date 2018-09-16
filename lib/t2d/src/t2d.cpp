#include <Wire.h>
#include "t2d.h"

T2D::T2D(byte i2cAddr) : 
    _I2C_ADDR(i2cAddr)
{
}

void T2D::INIT(byte configVal) {
    write(T2D::Register::Config, configVal);
}

int T2D::write(T2D::Register reg, unsigned int regValue) {
    Wire.beginTransmission(this->_I2C_ADDR);
    Wire.write(getRegAddress(reg));
    Wire.write(highByte(regValue));
    Wire.write(lowByte(regValue));
    return Wire.endTransmission();
}

int T2D::write(T2D::Register reg, byte regValue) {
    Wire.beginTransmission(this->_I2C_ADDR);
    Wire.write(getRegAddress(reg));
    Wire.write(regValue);
    return Wire.endTransmission();
}

unsigned int T2D::read(T2D::Register reg, bool readOneByte) {
    Wire.beginTransmission(this->_I2C_ADDR);
    Wire.write(getRegAddress(reg));
    Wire.endTransmission();

    if(readOneByte) {
        byte result = 0;
        Wire.requestFrom(this->_I2C_ADDR, 1);
        if(Wire.available() >= 1) {
            result = Wire.read();
        }
        return (unsigned int)result;
    }
    else {
        unsigned int result = 0;
        Wire.requestFrom(this->_I2C_ADDR, 2);
        if(Wire.available() >= 2) {
            result = Wire.read();
            result = result << 8;
            result |= Wire.read();
        }
        return result;
    }
}

double T2D::getTemp() {
    return ((double)read(T2D::Register::Temp) / 256);
}

byte T2D::getRegAddress(T2D::Register regName) {
    switch(regName) {
        case T2D::Register::Temp :
            return 0b00000000;
            break;
        case T2D::Register::Config :
            return 0b00000001;
            break;
        case T2D::Register::T_hyst :
            return 0b00000010;
            break;
        case T2D::Register::T_os :
            return 0b00000011;
            break;
        default :
            return 0;
            break;
    }
}