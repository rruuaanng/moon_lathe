#ifndef _MOON_I2C_H
#define _MOON_I2C_H

void i2c_init();

int i2c_send_byte(char data);

int i2c_recv_byte(char *data);

static void __i2c_sda_low_level();

static void __i2c_sda_high_level();

static void __i2c_scl_clk_gen();


#endif // _MOON_I2C_H