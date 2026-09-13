#ifndef BSP_LED_H
#define BSP_LED_H

#include <stdint.h>

typedef enum
{
    BSP_LED_OFF = 0,
    BSP_LED_ON
} bsp_led_state_t;

void BSP_LED_Init(void);
void BSP_LED_Set(bsp_led_state_t state);
void BSP_LED_Toggle(void);
bsp_led_state_t BSP_LED_GetState(void);

#endif /* BSP_LED_H */
