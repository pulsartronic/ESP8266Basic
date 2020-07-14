#ifndef __ExampleLED__
#define __ExampleLED__

#include <Arduino.h>
#include <Node.h>

class ExampleLED : public Node {
	public:

	bool on = false;

	ExampleLED(Node* parent, const char* name);
	void loop();
	void setup();

	virtual void state(JsonObject& params, JsonObject& response, JsonObject& broadcast);
	void turnit(JsonObject& params, JsonObject& response, JsonObject& broadcast);
};


#endif
