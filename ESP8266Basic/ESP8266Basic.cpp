#include "ESP8266Basic.h"

/**
 * Contructor. Here's where the program entry point
 */
ESP8266Basic::ESP8266Basic() : NetworkNode(NULL, "root") {
	// TODO:: make checks against this
	bool filesystemInitilized = LittleFS.begin();

	this->system = new System(this, "system");
	this->nodes->set(this->system->name, this->system);

	this->wifi = new WIFI(this, "wifi");
	this->nodes->set(this->wifi->name, this->wifi);

	// ////////////////////////////////////////////////////////////////////////////////
	// EXAMPLE
	this->exampleLED = new ExampleLED(this, "exampleLED");
	this->nodes->set(this->exampleLED->name, this->exampleLED);
	// ////////////////////////////////////////////////////////////////////////////////


	// ////////////////////////////////////////////////////////////////////////////////
	// DEFAULT CONFIGURATION //////////////////////////////////////////////////////////
	// Change these values as needed, they can be modified later from the web interface

	// Default credentials for WiFi Access Point
	this->wifi->ap->settings.ssid = "ESP8266 " + String(ESP.getChipId());
	this->wifi->ap->settings.pass = "12345678";

	// Default password for the configuration interface
	// SHA256("adminadmin") change "adminadmin" by "user+pass"
	this->key = new byte[32] {
		0xd8, 0x24, 0x94, 0xf0, 0x5d, 0x69, 0x17, 0xba, 
		0x02, 0xf7, 0xaa, 0xa2, 0x96, 0x89, 0xcc, 0xb4,
		0x44, 0xbb, 0x73, 0xf2, 0x03, 0x80, 0x87, 0x6c,
		0xb0, 0x5d, 0x1f, 0x37, 0x53, 0x7b, 0x78, 0x92
	};

	// ping period in milliseconds, see NetworkNode.cpp
	this->iping = 15ul * 1000ul;

	// DEFAULT CONFIGURATION //////////////////////////////////////////////////////////
	// ////////////////////////////////////////////////////////////////////////////////
}

ESP8266Basic::~ESP8266Basic() {
	delete this->system;
	delete this->wifi;
	delete this->exampleLED;
}

void ESP8266Basic::setup() {
	NetworkNode::setup();
	this->system->setup();
	this->wifi->setup();

	// ////////////////////////////////////////////////////////////////////////////////
	// EXAMPLE
	this->exampleLED->setup();
	this->httpServer->on(F("/example.css"), std::bind(&ESP8266Basic::css, this));
	this->httpServer->on(F("/example.js"), std::bind(&ESP8266Basic::javascript, this));
	// ////////////////////////////////////////////////////////////////////////////////

	Serial.println("ESP8266 Basic ... OK");
}

void ESP8266Basic::loop() {
	NetworkNode::loop();
	this->system->loop();
	this->wifi->loop();
	this->exampleLED->loop();
}

void ESP8266Basic::html() {
	this->httpServer->send_P(200, "text/html", HTML);
}

void ESP8266Basic::javascript() {
	this->httpServer->send_P(200, "application/javascript", EXAMPLE_JS);
}

void ESP8266Basic::css() {
	this->httpServer->send_P(200, "text/css", EXAMPLE_CSS);
}

