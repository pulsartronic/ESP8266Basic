static const char EXAMPLE_CSS[] PROGMEM = R""""(
div.ExampleLED {
	position: relative;
	display: flex;
	flex-wrap: wrap;
	justify-content: center;
	align-items: center;
	width: 100%;
	min-height: 60vh;
}

div.ExampleLED div.Explanation {
	width: calc(100% - 2em);
	margin: 1em;
	line-height: 1.5em;
	padding: 1em 1em 2em;
	border-bottom: 1px solid #AAA;
}

div.ExampleLED div.Explanation span.ProjectFolder {
	font-weight: bold;
}

div.ExampleLED div.Title {
	width: 100%;
	display: flex;
	justify-content: center;
	font-size: 2em;
}

div.ToggleButton {
	background: linear-gradient(var(--light-color) 5%, var(--dark-color) 60%);
	width: calc(1.61*4em);
	height: 4em;
	border-radius: 1em;
	display: flex;
	align-items: center;
	justify-content: center;
	border: 1px solid #888;
	box-shadow: 0 0 1em #CCC;
	cursor: pointer;
	color: white;
	font-weight: bold;
}

div.ToggleButton::after {
	content: "";
	position: absolute;
	top: -0.5em;
	bottom: -0.5em;
	left: -0.5em;
	right: -0.5em;
	border: 1px solid #AAA;
	border-radius: 1em;
}

div.LightON {
	background: linear-gradient(rgb(54, 245, 245), rgb(47, 175, 175));
	box-shadow: 0 0 1em #FFF;
	border: 1px solid white;
}

div.LightON::after {
	border: 1px solid #CCC;
}
)"""";
