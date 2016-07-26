#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define LIGHTS 150

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LIGHTS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
	strip.begin();
	strip.show();
}

void loop() {
	colorWheel(250);
}

void setStripColor(uint32_t c, uint8_t wait) {
	for(uint16_t i=0; i<strip.numPixels(); i++) {
		strip.setPixelColor(i, c);
	}
}

void colorWheel(uint8_t wait) {
	for (int j=0; j < 256; j++) {
		setStripColor(wheel(j), wait);
		strip.show();
		delay(wait);
	}
}

uint32_t wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
