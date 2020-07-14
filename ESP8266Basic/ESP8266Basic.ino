/*
 * Pulsartronic
 * An Open Source project is a forever Work In Progress, feel free to contribute
 *
 */

#include "ESP8266Basic.h"

ESP8266Basic* esp8266Basic = NULL;

void setup() {
	esp8266Basic = new ESP8266Basic();
	esp8266Basic->setup();
}

void loop() {
	esp8266Basic->loop();
}
