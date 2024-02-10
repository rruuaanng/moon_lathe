#include "stm32h7xx_hal_gpio.h"
#include "stm32h7xx_hal.h"
#include "soft_i2c.h"
#include "main.h"

void i2c_init()
{
    HAL_GPIO_WritePin(SDA_GPIO_Port,SDA_Pin,GPIO_PIN_SET);
    HAL_GPIO_WritePin(SCL_GPIO_Port,SCL_Pin,GPIO_PIN_SET);
}

int i2c_send_byte(char data)
{
    
    for (int i = 0; i < 8; i++){
        // judg high bit it's 1
        if (data & 0x80) 
            __i2c_sda_high_level();
        else 
            __i2c_sda_low_level();

        data <<= 1;

        __i2c_scl_clk_gen();         
    }

    return 0;
}

int i2c_recv_byte(char *data)
{
    return 0;
}

static void __i2c_sda_low_level()
{
    HAL_GPIO_WritePin(SDA_GPIO_Port,SDA_Pin,GPIO_PIN_RESET);
}

static void __i2c_sda_high_level()
{
    HAL_GPIO_WritePin(SDA_GPIO_Port,SDA_Pin,GPIO_PIN_SET);
    HAL_Delay(30);
}

static void __i2c_scl_clk_gen()
{
    HAL_GPIO_WritePin(SDA_GPIO_Port,SCL_Pin,GPIO_PIN_SET);
    HAL_Delay(30);
    HAL_GPIO_WritePin(SCL_GPIO_Port,SCL_Pin,GPIO_PIN_RESET);
    HAL_Delay(30);
}