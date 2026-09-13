#ifndef SYSTEM_SERVICE_H
#define SYSTEM_SERVICE_H

#include <stdint.h>

void SystemService_Init(void);

uint32_t SystemService_GetTick(void);

void SystemService_Delay(uint32_t delay_ms);

#endif /* SYSTEM_SERVICE_H */
