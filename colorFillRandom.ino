#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

const int colors[3] = { LED_GREEN, LED_YELLOW, LED_RED };

int count = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  matrix.begin(0x70);  // pass in the address
  
  matrix.setBrightness(15);
  
  matrix.setRotation(3);
}

void loop() {
  matrix.clear();
    
  for(int x = 0; x < 8; x++) {
    for(int y = 0; y < 8; y++) {
      if(random(0,2) == 0) {
        matrix.drawPixel(y, x, colors[random(0,3)]);
      }
    }
  }

  matrix.writeDisplay();  

  delay(50);
}
