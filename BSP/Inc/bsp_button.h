#ifndef BSP_BUTTON_H
#define BSP_BUTTON_H

#include <stdint.h>

typedef enum
{
    BSP_BUTTON_RELEASED = 0,
    BSP_BUTTON_PRESSED
} bsp_button_state_t;

typedef enum
{
    BSP_BUTTON_EVENT_NONE = 0,
    BSP_BUTTON_EVENT_PRESSED,
    BSP_BUTTON_EVENT_RELEASED
} bsp_button_event_t;

void BSP_Button_Init(void);

void BSP_Button_Process(void);

bsp_button_state_t BSP_Button_GetState(void);

bsp_button_event_t BSP_Button_GetEvent(void);

#endif /* BSP_BUTTON_H */
