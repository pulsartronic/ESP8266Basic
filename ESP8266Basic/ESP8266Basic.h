#ifndef __ESP8266Basic__
#define __ESP8266Basic__

#include <DebugM.h>

#define ARDUINOJSON_USE_DOUBLE 1
#include <ArduinoJson.h>
#include <NetworkNode.h>
#include <WIFI.h>
#include <System.h>

#include "index.html.h"
#include "example.js.h"
#include "example.css.h"
#include "ExampleLED.h"

class ESP8266Basic : public NetworkNode {
	public:
	WIFI* wifi = NULL;
	System* system = NULL;
	ExampleLED* exampleLED = NULL;

	ESP8266Basic();
	virtual ~ESP8266Basic();
	void loop();
	void setup();
	virtual void html();
	void javascript();
	void css();
};

#endif
