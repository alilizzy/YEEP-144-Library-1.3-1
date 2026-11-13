#include "YEEP144.h"
#include "stm32h563xx.h"
#include "stm32h5xx_hal.h"
#include "YEEP144_DebugUART.h"


int main(void){
    // Performs important functions such as initialising the HAL and correctly configuring the system clock
    YEEP144_Init();
    // Configure and start USART3
    YEEP144_DebugUART_Init();

    // While loop that always runs
	while(1) {

		HAL_Delay(1000);
    }
}