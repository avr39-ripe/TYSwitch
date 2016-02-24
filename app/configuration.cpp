#include <tyswitch.h>

SwitchConfig ActiveConfig;

SwitchConfig loadConfig()
{
	StaticJsonBuffer<ConfigJsonBufferSize> jsonBuffer;
	SwitchConfig cfg;
	if (fileExist(SWITCH_CONFIG_FILE))
	{
		int size = fileGetSize(SWITCH_CONFIG_FILE);
		char* jsonString = new char[size + 1];
		fileGetContent(SWITCH_CONFIG_FILE, jsonString, size + 1);
		JsonObject& root = jsonBuffer.parseObject(jsonString);

		JsonObject& network = root["network"];
		cfg.StaSSID = String((const char*)network["StaSSID"]);
		cfg.StaPassword = String((const char*)network["StaPassword"]);
		cfg.StaEnable = network["StaEnable"];

		delete[] jsonString;
	}
	else
	{
		//Factory defaults if no config file present
		cfg.StaSSID = WIFI_SSID;
		cfg.StaPassword = WIFI_PWD;
	}
	return cfg;
}

void saveConfig(SwitchConfig& cfg)
{
	StaticJsonBuffer<ConfigJsonBufferSize> jsonBuffer;
	JsonObject& root = jsonBuffer.createObject();

	JsonObject& network = jsonBuffer.createObject();
	root["network"] = network;
	network["StaSSID"] = cfg.StaSSID.c_str();
	network["StaPassword"] = cfg.StaPassword.c_str();
	network["StaEnable"] = cfg.StaEnable;

	char buf[ConfigFileBufferSize];
	root.prettyPrintTo(buf, sizeof(buf));
	fileSetContent(SWITCH_CONFIG_FILE, buf);
}


