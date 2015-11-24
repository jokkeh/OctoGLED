#include<OctoWS2811.h>

// Must be FastLED 3.1+
#include<FastLED.h>

#define NUM_LEDS_PER_STRIP 256
#define NUM_STRIPS 8
#define CMD_NEW_DATA 1

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];

void setup() {
	FastLED.addLeds<WS2811_PORTD, NUM_STRIPS>(leds, NUM_LEDS_PER_STRIP);
	FastLED.setBrightness(100);

	Serial.begin(9600);
}

void loop() {
	while (!Serial.available() || Serial.read() != CMD_NEW_DATA);
	Serial.readBytes((char*)leds, NUM_LEDS_PER_STRIP * NUM_STRIPS * 3);
	FastLED.show();
}