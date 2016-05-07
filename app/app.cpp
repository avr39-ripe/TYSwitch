/*
 * app.cpp
 *
 *  Created on: 30 марта 2016
 *      Author: shurik
 */
#include <app.h>
#include <tyswitch.h>

void AppClass::init()
{
	thermoHead = new SwitchGPIO(16);

	ApplicationClass::init();

	webServer.addPath("/set_state",HttpPathDelegate(&SwitchGPIO::httpSetState,thermoHead));
}

void AppClass::start()
{
	ApplicationClass::start();
	thermoHead->start();
}

void AppClass::_loop()
{
	ApplicationClass::_loop();
}

