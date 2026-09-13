#ifndef BSP_BUTTON_H
#define BSP_BUTTON_H

#include <stdint.h>

typedef enum
{
    BSP_BUTTON_RELEASED = 0,
    BSP_BUTTON_PRESSED
} bsp_button_state_t;

void BSP_Button_Init(void);
bsp_button_state_t BSP_Button_GetState(void);

#endif /* BSP_BUTTON_H */
