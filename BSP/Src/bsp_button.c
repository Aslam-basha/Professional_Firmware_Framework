#include "bsp_button.h"
#include "main.h"
#include "system_service.h"

#define BSP_BUTTON_DEBOUNCE_TIME_MS    (20U)

typedef struct
{
    bsp_button_state_t raw_state;
    bsp_button_state_t stable_state;

    bsp_button_state_t previous_stable_state;

    bsp_button_event_t event;

    uint32_t last_raw_change_time;

} bsp_button_t;

static bsp_button_t s_button;

void BSP_Button_Init(void)
{
    bsp_button_state_t initial_state;

    initial_state =
        (HAL_GPIO_ReadPin(
            USER_BUTTON_GPIO_Port,
            USER_BUTTON_Pin) == GPIO_PIN_SET)
        ? BSP_BUTTON_PRESSED
        : BSP_BUTTON_RELEASED;

    s_button.raw_state = initial_state;
    s_button.stable_state = initial_state;
    s_button.previous_stable_state = initial_state;

    s_button.event = BSP_BUTTON_EVENT_NONE;

    s_button.last_raw_change_time = SystemService_GetTick();
}

void BSP_Button_Process(void)
{
    bsp_button_state_t current_raw_state;
    uint32_t current_time;

    current_time = HAL_GetTick();

    current_raw_state = (HAL_GPIO_ReadPin(USER_BUTTON_GPIO_Port, USER_BUTTON_Pin) == GPIO_PIN_SET)
        ? BSP_BUTTON_PRESSED
        : BSP_BUTTON_RELEASED;

    /*
     * Detect raw state change.
     */
    if (current_raw_state != s_button.raw_state)
    {
        s_button.raw_state = current_raw_state;
        s_button.last_raw_change_time = current_time;
    }

    /*
     * Check whether raw state has remained stable
     * for the debounce period.
     */
    if ((current_time - s_button.last_raw_change_time)
        >= BSP_BUTTON_DEBOUNCE_TIME_MS)
    {
        if (s_button.stable_state != s_button.raw_state)
        {
            s_button.previous_stable_state = s_button.stable_state;

            s_button.stable_state = s_button.raw_state;

            if (s_button.stable_state == BSP_BUTTON_PRESSED)
            {
                s_button.event = BSP_BUTTON_EVENT_PRESSED;
            }
            else
            {
                s_button.event = BSP_BUTTON_EVENT_RELEASED;
            }
        }
    }
}

bsp_button_state_t BSP_Button_GetState(void)
{
    return s_button.stable_state;
}

bsp_button_event_t BSP_Button_GetEvent(void)
{
    bsp_button_event_t event;

    event = s_button.event;

    s_button.event = BSP_BUTTON_EVENT_NONE;

    return event;
}
