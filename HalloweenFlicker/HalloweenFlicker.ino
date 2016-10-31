#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define LIGHTS 150

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LIGHTS, PIN, NEO_GRB + NEO_KHZ800); 
bool lightsOn = false;

void setup() {
	strip.begin();
	strip.show();
}

void loop() {
  //setStripColor(strip.Color(255, 69, 0));
	toggleStrip();
  strip.show();
}

void toggleStrip() {
    if (lightsOn) {
        setStripColor(strip.Color(0, 0, 0));
        lightsOn = false;
        delay(random(100));
    } else {
        setStripColor(strip.Color(255, 69, 0));
        lightsOn = true;
        delay(random(1000));
    }
}

void setStripColor(uint32_t c) {
	for(uint16_t i=0; i<strip.numPixels(); i++) {
		strip.setPixelColor(i, c);
	}
}
