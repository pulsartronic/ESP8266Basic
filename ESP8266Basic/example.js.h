static const char EXAMPLE_JS[] PROGMEM = R""""(
// /////////////////////////////////////////////////////////////////////////////////////////
// this is a basic example of how to communicate with the device
// to turn its led on and off

// /////////////////////////////////////////////////////////////////////////////////////////
// Program entry point
window.onload = () => {
	let app = window.app = new ESP8266Basic();

	app.exampleLED = new ExampleLED(window.app, 'exampleLED');
	app.addNode(window.app.exampleLED);
	app.tabs.addTab(window.app.exampleLED.tag, 'ExampleLED');

	let config = document.getElementById('config');
	config.append(window.app.tag);
	window.app.init();
};

let ExampleLED = function(parent, name) {
	Node.call(this, parent, name);

	this.tag = document.createElement('div');
	this.tag.className = 'ExampleLED'
	this.tag.node = this;

	this.title = document.createElement("div");
	this.tag.append(this.title);
	this.title.className = "Title";
	this.title.textContent = "LED on / off Example";

	this.button = document.createElement("div");
	this.tag.append(this.button);
	this.button.className = "ToggleButton LightOFF";
	this.button.onclick = this.toggle.bind(this);
	this.button.innerHTML = "-";

	this.explanation = document.createElement("div");
	this.tag.append(this.explanation);
	this.explanation.className = 'TextContent Explanation';
	this.explanation.innerHTML = `
		ESP8266Basic ExampleLED. It shows how to bidirectionally communicate using existing system.<br/>
		Arduino IDE project file is:<br/>
		<span class='ProjectFolder'>ESP8266Basic/ESP8266Basic.ino</span>
	`;

	this.on = 0;
};

for (let i in Node.prototype)
	ExampleLED.prototype[i] = Node.prototype[i];


/*
 * The server periodically makes this call via websockets as a ping mechanism
 */
ExampleLED.prototype.state = function(state) {
	this.on = state.on;
	this.loaded = this.button.enabled = true;

	// change this if it shows off when it should be on
	this.button.classList[state.on ? "remove" : "add"]("LightON");
	this.button.textContent = state.on ? "OFF" : "ON";
};

ExampleLED.prototype.toggle = function() {
	if (this.button.enabled) {
		this.button.enabled = false;

		let command = {"turnit":{"on":!this.on}};
		this.command(command);
	}
};




)"""";
