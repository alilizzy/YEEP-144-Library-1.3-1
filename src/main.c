#include "YEEP144.h"
#include "stm32h563xx.h"
#include "stm32h5xx_hal.h"
#include "YEEP144_DebugUART.h"

// 32 byte global array with all elements initialised at 0
uint8_t RxData[32] = {0};
// 16-bit integer variable used to place the resize of the recieved data
uint16_t RxLen = 0;

int main(void){
    // Performs important functions such as initialising the HAL and correctly configuring the system clock
    YEEP144_Init();
    // Configure and start USART3

    // While loop that always runs
	while(1) {
        // Read up to 32 bytes from the Debug UART (UART3) with a one second timeout
        uint8_t err = HAL_UARTEx_ReceiveToIdle(&huart3, RxData, 32, &RxLen,1000);
        // Prints the number of recieved characters as an integer and the recieved buffer as a string
        YEEP144_DebugUART_printf("RxLen: %d\tRxData: %s\r\n", RxLen, RxData);
		HAL_Delay(1000);
    }
}