#include "bsp_button.h"
#include "main.h"

void BSP_Button_Init(void)
{
    /* GPIO is initialized by MX_GPIO_Init(). */
}

bsp_button_state_t BSP_Button_GetState(void)
{
    GPIO_PinState state;

    state = HAL_GPIO_ReadPin(
        USER_BUTTON_GPIO_Port,
        USER_BUTTON_Pin);

    if (state == GPIO_PIN_SET)
    {
        return BSP_BUTTON_PRESSED;
    }

    return BSP_BUTTON_RELEASED;
}
