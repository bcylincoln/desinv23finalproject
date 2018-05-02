#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(58, A0, NEO_GRB + NEO_KHZ800);


void setup() {
  pixels.begin();

}

void loop() {
  int red = 10;
  int green = 180;
  int blue = 10;

  for (int i = 0; i < 10; i++) {
    for (int vine = 0; vine < 6; vine++) {
      setColor(vine, i, red, green, blue);
    }
    pixels.show();   
    if (i == 2 || i == 6) {
      delay(2500);
    } else {
      delay(500);
    }

  }
 
}

void setColor(int vine, int number, int colorRed, int colorGreen, int colorBlue) {
  pixels.setPixelColor(getPixelOnVine(vine, number), pixels.Color(colorRed, colorGreen, colorBlue));
}

int getPixelOnVine(int vine, int i) {
  switch(vine) {
    case 0:
      return i;
      break;

    case 1:
      if (i == 9) {
        return 10;
      } else {
        return 18 - i;
      }
      break;

    case 2:
      return 19 + i; 
      break;

    case 3:
      if (i == 0) {
        return 37;
      } else {
        return 38 - i;
      }
      break;
       
    case 4:
      return 38 + i;
       break;
       
    case 5:
      return 57 - i;
       break;
     
  }
}

