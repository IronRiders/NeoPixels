#include <Adafruit_NeoPixel.h>

 
#define PIN    5 //port number on side labeled "DIGITAL" on arduino
#define N_LEDS 50 //number of led light sections

#define MAX 255
#define MID 127

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_BRG + NEO_KHZ400); //creates the led strip with the number of leds, the port number and the type of led strip
 
void setup() {
  Serial.begin(9600);
  strip.begin(); //allows the strip to start showing colors
}
 
void loop() {
  solid(0, 0, 255);
  delay(100);
}

static void solid(uint32_t r, uint32_t g, uint32_t b) { //entirely 1 color
  for(uint16_t i=0; i<N_LEDS; i++) {
    strip.setPixelColor(i, r, g, b); //draw new pixel. Position i, rgb color values
  }
  strip.show();
}

static void fade(uint32_t r, uint32_t g, uint32_t b) {
    uint32_t r1 = r;
    uint32_t g1 = g;
    uint32_t b1 = b;
    while(r1 != 0 && g1 != 0 && b1 != 0) {
      strip.Color(r1, b1, g1);
      if(r1 > 0) r1--;
      if(g1 > 0) g1--;
      if(b1 > 0) b1--;
      strip.show();
  }
}

static void randomFlashing() { //randomly flashes lights
  for(uint16_t i=0; i<N_LEDS; i++) {
    strip.setPixelColor(random(0, N_LEDS), random(0, 255), random(0, 255), random(0, 255)); //draw new pixel. Position i, rgb color values
    strip.show();
    delay(100);
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
