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
        YEEP144_DebugUART_printf("IR0(float): %f\r\n", distance_IR0);
        
		HAL_Delay(1000);
    }
}