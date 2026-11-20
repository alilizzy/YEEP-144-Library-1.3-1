#include "YEEP144.h"
#include "stm32h563xx.h"
#include "stm32h5xx_hal.h"
#include "YEEP144_DebugUART.h"
#include "YEEP144_I2C.h"
#include "YEEP144_GP2Y0E02B.h"

int main(void){
    // Performs important functions such as initialising the HAL and correctly configuring the system clock
    YEEP144_Init();
    // Configure and start USART3
    YEEP144_DebugUART_Init();
    // Configures the STM32 I2C2 peripheral for standard 100KHz operation
    YEEP144_I2C_Init();

    // While loop that always runs
	while(1) {
        // Selects the I2C channel 0 (left IR sensor)
        YEEP144_I2C_MuxSelect(0);
        // Float value for the distance measured by the left IR sensor
        float distance_IR0 = YEEP144_GP2Y0E02B_Read();
        // Prints the distance measured by the left IR sensor to the debug UART
        YEEP144_DebugUART_printf("Left IR (float): %f\r\n", distance_IR0);

        // Selects the I2C channel 1 (front left IR sensor)
        YEEP144_I2C_MuxSelect(1);
        // Float value for the distance measured by the front left IR sensor
        float distance_IR1 = YEEP144_GP2Y0E02B_Read();
        // Prints the distance measured by the front left IR sensor to the debug UART
        YEEP144_DebugUART_printf("Front Left IR (float): %f\r\n", distance_IR1);

        // Selects the I2C channel 2 (front right IR sensor)
        YEEP144_I2C_MuxSelect(2);
        // Float value for the distance measured by the front right IR sensor
        float distance_IR2 = YEEP144_GP2Y0E02B_Read();
        // Prints the distance measured by the front right IR sensor to the debug UART
        YEEP144_DebugUART_printf("Front Right IR (float): %f\r\n", distance_IR2);

        // Selects the I2C channel 3 (right IR sensor)
        YEEP144_I2C_MuxSelect(3);
        // Float value for the distance measured by the right IR sensor
        float distance_IR3 = YEEP144_GP2Y0E02B_Read();
        // Prints the distance measured by the right IR sensor to the debug UART
        YEEP144_DebugUART_printf("Right IR (float): %f\r\n", distance_IR3);

		HAL_Delay(1000);
    }
}