#include "system_service.h"
#include "stm32f4xx_hal.h"

void SystemService_Init(void)
{
}

uint32_t SystemService_GetTick(void)
{
    return HAL_GetTick();
}

void SystemService_Delay(uint32_t delay_ms)
{
    HAL_Delay(delay_ms);
}
