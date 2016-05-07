#include <app.h>
#include <user_config.h>
#include <tyswitch.h>

SwitchGPIO* thermoHead;

AppClass App;

void init()
{
        App.init();
        App.start();
}
