#include <FastLED.h>

#define NUM_LEDS 20
#define STRIP_ONE_PIN 5

CRGB leds[NUM_LEDS];

void setup() { 
  FastLED.addLeds<NEOPIXEL, STRIP_ONE_PIN>(leds, NUM_LEDS);
}
void loop() { 
  leds[1] = CRGB::Red; 
  FastLED.show(); 
  delay(30); 
}
