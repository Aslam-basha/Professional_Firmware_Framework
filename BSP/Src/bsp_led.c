#include "bsp_led.h"
#include "main.h"

static bsp_led_state_t s_led_state = BSP_LED_OFF;
static uint32_t s_toggle_count = 0U;

void BSP_LED_Init(void)
{
    s_led_state = BSP_LED_OFF;

    HAL_GPIO_WritePin(
        LED_GREEN_GPIO_Port,
        LED_GREEN_Pin,
        GPIO_PIN_RESET);
}

void BSP_LED_Set(bsp_led_state_t state)
{
    s_led_state = state;

    HAL_GPIO_WritePin(
        LED_GREEN_GPIO_Port,
        LED_GREEN_Pin,
        (state == BSP_LED_ON) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void BSP_LED_Toggle(void)
{
    HAL_GPIO_TogglePin(
        LED_GREEN_GPIO_Port,
        LED_GREEN_Pin);

    s_led_state = !s_led_state;
    s_toggle_count++;
}

bsp_led_state_t BSP_LED_GetState(void)
{
    return s_led_state;
}

uint32_t BSP_LED_GetToggleCount(void)
{
    return s_toggle_count;
}
