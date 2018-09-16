/**
 * T2D - temperature to digital
 * @author  -   Jacob White (jrw111@mun.ca)
 * @date    -   July 18, 2018
 * @extras  -   https://www.icbanq.com/data/ICBShop/board/Digital-aTS75.pdf
 * 
 * T2D
 * @param i2cAddr   -   (optional) sets the devices I2C address
 * 
 * INIT
 * @brief   -   sets device configuration register
 * @param configVal -   (optional) the value to be set in the configuration register
 * @returns -   void
 * 
 * write
 * @brief   -   writes the given value to the specified register
 * @param reg   -   an enum that specifies which register to write to
 * @param regValue  -   the 2-byte value to be written 
 * @reutrns int -   (optional) error code of writing operation
 * 
 * write
 * @brief   -   writes the given value to the specified register
 * @param reg   -   an enum that specifies which register to write to
 * @param regValue  -   the 1-byte value to be written 
 * @reutrns int -   (optional) error code of writing operation
 * 
 * read
 * @brief   -   reads 1 or 2 bytes from the specified register
 * @param reg   -   the register to read from
 * @param readOneByte   -   specifies wether to read 1 or 2 bytes 
 * @returns unsigned int    -   contents of the register specifed
 * 
 * getTemp
 * @returns double  -   the temperature of the sensor in degrees celcius
 * 
 * getRegAddress
 * @brief   -   provides the byte address of internal regiesters by calling its name
 * @param regName   -   name of the register
 * @returns byte    -   the address of the specified register
 */