#include<OctoWS2811.h>

// Must be FastLED 3.1+
#include<FastLED.h>

// Change these according to your setup
#define NUM_LEDS_PER_STRIP 256
#define NUM_STRIPS 8

// This can be adjusted in the control software, but one could also set
// a limit here. Don't burn your power supplies!
#define MAX_BRIGHTNESS 255

// Don't change this
#define CMD_NEW_DATA 1

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];

void setup()
{
    FastLED.addLeds<WS2811_PORTD, NUM_STRIPS>(leds, NUM_LEDS_PER_STRIP).setCorrection( TypicalPixelString );
    FastLED.setBrightness( MAX_BRIGHTNESS );

    // Seems baud rate doesn't really matter
    Serial.begin( 9600 );
}

void loop()
{
    while ( !Serial.available() || Serial.read() != CMD_NEW_DATA );
    Serial.readBytes( (char*)leds, NUM_LEDS_PER_STRIP * NUM_STRIPS * 3 );
    FastLED.show();
}