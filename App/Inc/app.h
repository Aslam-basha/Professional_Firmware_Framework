#ifndef APP_H
#define APP_H

typedef enum
{
    INITIAL = 0,
    BUTTON_PRESSED,
	BUTTON_RELEASED,
	BUTTON_PRESSED_AGAIN
} app_button_state_t;

void App_Init(void);
void App_Run(void);

#endif /* APP_H */
