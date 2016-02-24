#ifndef INCLUDE_CONFIGURATION_H_
#define INCLUDE_CONFIGURATION_H_

#include <user_config.h>
#include <SmingCore/SmingCore.h>

const char SWITCH_CONFIG_FILE[] = ".switch.conf"; // leading point for security reasons :)

struct SwitchConfig
{
	SwitchConfig()
	{
		StaEnable = 1; //Enable WIFI Client
	}

	String StaSSID;
	String StaPassword;
	uint8_t StaEnable;

// ThermControl settings


};

SwitchConfig loadConfig();
void saveConfig(SwitchConfig& cfg);

extern SwitchConfig ActiveConfig;

#endif /* INCLUDE_CONFIGURATION_H_ */
