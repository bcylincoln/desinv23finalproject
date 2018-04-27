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
//  pixels.setPixelColor(0, pixels.Color(red, green, blue));
//  pixels.show();
  grow(1, 0, red, green, blue);
  grow(2, 0, red, green, blue);
  grow(3, 0, red, green, blue);
  grow(4, 0, red, green, blue);
  grow(5, 0, red, green, blue);
  grow(6, 0, red, green, blue);

  delay(1000);
  
  grow(1, 1, red, green, blue);
  grow(2, 1, red, green, blue);
  grow(3, 1, red, green, blue);
  grow(4, 1, red, green, blue);
  grow(5, 1, red, green, blue);
  grow(6, 1, red, green, blue);

  delay(2000);
  
  grow(1, 2, red, green, blue);
  grow(2, 2, red, green, blue);
  grow(3, 2, red, green, blue);
  grow(4, 2, red, green, blue);
  grow(5, 2, red, green, blue);
  grow(6, 2, red, green, blue);
  
  delay(8000);

  grow(1, 3, red, green, blue);
  grow(2, 3, red, green, blue);
  grow(3, 3, red, green, blue);
  grow(4, 3, red, green, blue);
  grow(5, 3, red, green, blue);
  grow(6, 3, red, green, blue);

  delay(2000);

  grow(1, 4, red, green, blue);
  grow(2, 4, red, green, blue);
  grow(3, 4, red, green, blue);
  grow(4, 4, red, green, blue);
  grow(5, 4, red, green, blue);
  grow(6, 4, red, green, blue);

  delay(1500);

  grow(1, 5, red, green, blue);
  grow(2, 5, red, green, blue);
  grow(3, 5, red, green, blue);
  grow(4, 5, red, green, blue);
  grow(5, 5, red, green, blue);
  grow(6, 5, red, green, blue);

  delay(1800);

  grow(1, 6, red, green, blue);
  grow(2, 6, red, green, blue);
  grow(3, 6, red, green, blue);
  grow(4, 6, red, green, blue);
  grow(5, 6, red, green, blue);
  grow(6, 6, red, green, blue);

  delay(8000);

  grow(1, 7, red, green, blue);
  grow(2, 7, red, green, blue);
  grow(3, 7, red, green, blue);
  grow(4, 7, red, green, blue);
  grow(5, 7, red, green, blue);
  grow(6, 7, red, green, blue);

  delay(2900);

  grow(1, 8, red, green, blue);
  grow(2, 8, red, green, blue);
  grow(3, 8, red, green, blue);
  grow(4, 8, red, green, blue);
  grow(5, 8, red, green, blue);
  grow(6, 8, red, green, blue);

  delay(1200);

  grow(1, 9, red, green, blue);
  grow(3, 9, red, green, blue);
  grow(4, 9, red, green, blue);
  grow(5, 9, red, green, blue);
  grow(6, 9, red, green, blue);
 
}

void grow(int vine, int number, int colorRed, int colorGreen, int colorBlue) {
  pixels.setPixelColor(getPixelOnVine(vine, number), pixels.Color(colorRed, colorGreen, colorBlue));
  pixels.show();
}

float getPixelOnVine(int vine, int number){
  if (vine == 1) {
    return number;
  } else if (vine == 2) {
     if (number >= 9) {
      return 18-8;
     }
     for (int i = 0; i < 9; i++) {
       if (number == i) {
         return 18-i;
       }
     }
  } else if (vine == 3) {
     if (number >= 10) {
      return 19+9;
     }
     for (int i = 0; i < 10; i++) {
       if (number == i) {
         return 19+i;
       }
     }
  } else if (vine == 4) {
     if (number >= 10) {
      return 38-9;
     }
     for (int i = 0; i < 10; i++) {
       if (number == i) {
         return 38-i;
       }
     }
  } else if (vine == 5) {
    if (number >= 10) {
      return 39+9;
    }
     for (int i = 0; i < 10; i++) {
       if (number == i) {
         return 39+i;
       }
     }
  } else if (vine == 6) {
    if (number >= 10) {
      return 58-9;
    }
     for (int i = 0; i < 10; i++) {
       if (number == i) {
         return 58-i;
       }
     }
  }
}

