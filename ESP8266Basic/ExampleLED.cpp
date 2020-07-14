#include "ExampleLED.h"

ExampleLED::ExampleLED(Node* parent, const char* name) : Node(parent, name) {
	// this is the way we register a method to be called via javascript
	Method* turnit = new Method(std::bind(&ExampleLED::turnit, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	this->methods->set("turnit", turnit);
}

void ExampleLED::setup() {
	pinMode(LED_BUILTIN, OUTPUT);
}

void ExampleLED::loop() {
	
}

void ExampleLED::state(JsonObject& params, JsonObject& response, JsonObject& broadcast) {
	// there is a reason to do it, it has to do with the way ArduinoJson allocates memory
	JsonObject object = this->rootIT(response);

	// create an object to be sent through the network
	JsonObject state = object.createNestedObject("state");
	state["on"] = this->on;
}

// this method is "directly" called from javascript
void ExampleLED::turnit(JsonObject& params, JsonObject& response, JsonObject& broadcast) {
	this->on = params["on"];
	digitalWrite(LED_BUILTIN, this->on);
	this->state(params, broadcast, response);
}
