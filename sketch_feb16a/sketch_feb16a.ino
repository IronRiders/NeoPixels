#include <Adafruit_NeoPixel.h>

 
#define PIN    2 //port number on side labeled "DIGITAL" on arduino
#define N_LEDS 150 //number of led light sections

#define MAX 255
#define MID 127

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800); //creates the led strip with the number of leds, the port number and the type of led strip
 
void setup() {
  strip.begin(); //allows the strip to start showing colors
}
 
void loop() {
  randomFlashing();
}

static void solid(uint32_t r, uint32_t g, uint32_t b) { //entirely 1 color
  for(uint16_t i=0; i<N_LEDS; i++) {
    strip.setPixelColor(i, r, b, g); //set all pixels
  }
  strip.show();
}

static void randomFlashing() { //randomly flashes lights
  for(uint16_t i=0; i<50; i++) {
    strip.setPixelColor(random(0, N_LEDS), random(0, 255), random(0, 255), random(0, 255)); //draw new pixel. Position i, rgb color values
    strip.show();
    delay(100); //delays for 10ms
   
  }
}

static void follow(uint32_t r, uint32_t g, uint32_t b) { //turns on all lights in order
  for(uint16_t i=0; i<N_LEDS; i++) {
      strip.setPixelColor(i, r, b, g);
      strip.show();
      delay(45);
  }
}

static void chase(uint32_t r, uint32_t g, uint32_t b) { //like a snake stuck inside the neopixels
  for(uint16_t i=0; i<N_LEDS+4; i++) { //+4 for pixel erasing
      strip.setPixelColor(i, r, b, g);
      strip.setPixelColor(i-4, 0); //erase pixel a few steps back
      strip.show();
      delay(45);
  }
}
