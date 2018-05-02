#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor4 = AFMS.getMotor(4);

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
Servo myservo7;
Servo myservo8;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(58, A0, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  AFMS.begin();
  pixels.begin();
  pixels.show(); 

}

void loop() {
  //startup
  set_all_colors(0, 0, 0);
  delay(1000);
  set_all_colors(255, 255, 255);
  delay(1000);

  
  fall();
  winter();
  spring();
  summer();
}


void fall() {
  Serial.println("fall");
  set_all_colors(10, 180, 10);
  
  fade_vine_color(0, 10, 180, 10, 255, 0, 0, 100, 20);
  fade_vine_color(3, 10, 180, 10, 255, 128, 0, 100, 20);
  fade_vine_color(2, 10, 180, 10, 150, 102, 0, 100, 20);
  fade_vine_color(5, 10, 180, 10, 150, 51, 0, 100, 20);
  fade_vine_color(1, 10, 180, 10, 204, 205, 0, 100, 20);
  fade_vine_color(4, 10, 180, 10, 255, 0, 0, 100, 20);
  
  delay(3000);
  blow_wind(200);
  wind_gust();
  end_wind();
  set_dc_speed(0);
  kill_vines();

  

}

void winter() {
  set_all_colors(0, 0, 0);
  pixels.show();

  set_vine_color(0, 255, 0, 255);
  set_vine_color(2, 255, 0, 255);
  set_vine_color(4, 255, 0, 255);
  pixels.show();
  delay(375*2);

  set_vine_color(0, 0, 0, 0);
  set_vine_color(2, 0, 0, 0);
  set_vine_color(4, 0, 0, 0);
  set_vine_color(1, 0, 0, 255);
  set_vine_color(3, 0, 0, 255);
  set_vine_color(5, 0, 0, 255);
  pixels.show();
  delay(375*2);

  set_vine_color(0, 255, 0, 255);
  set_vine_color(2, 255, 0, 255);
  set_vine_color(4, 255, 0, 255);
  set_vine_color(1, 0, 0, 0);
  set_vine_color(3, 0, 0, 0);
  set_vine_color(5, 0, 0, 0);
  pixels.show();
  delay(375*2);

  set_vine_color(0, 0, 0, 0);
  set_vine_color(2, 0, 0, 0);
  set_vine_color(4, 0, 0, 0);
  set_vine_color(1, 50, 0, 200);
  set_vine_color(3, 50, 0, 200);
  set_vine_color(5, 50, 0, 200);
  pixels.show();
  delay(375*2);

  set_all_colors(0,0,0);
  delay(375*2);

  set_vine_color(0, 0, 0, 255);
  pixels.show();
  delay(375);
  
  set_vine_color(1, 0, 0, 255);
  pixels.show();
  delay(375);

  set_vine_color(2, 0, 0, 255);
  pixels.show();
  delay(375);

  set_vine_color(3, 0, 0, 255);
  pixels.show();
  delay(375);

  set_vine_color(4, 0, 0, 255);
  pixels.show();
  delay(375);

  set_vine_color(5, 0, 0, 255);
  pixels.show();
  delay(375);

  set_all_colors(0,0,0);
  pixels.show();
  delay(2000);

  snow_fall(3);
  snow_fall(0);
  snow_fall(4);
  snow_fall(1);
  snow_fall(5);
  snow_fall(2);
  delay(4000);
}

void spring() {
  grow_vines();
  blow_wind(200);
  for (int i = 0; i < 30; i++) {
    pixels.setPixelColor(random(59), random(255), random(255), random(255));
    pixels.show();
    delay(300);
  }
  Serial.println("spring");
}

void summer() {
  Serial.println("summer");
  set_dc_speed(0);
  rainbow(40);
  blow_wind(100);
  servo_dance();
  delay(2000);

  set_all_colors(255, 255, 255);
  delay(5000);
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel((i+j) & 255));
    }
    pixels.show();
    delay(wait);
  }

}

void kill_vines() {
  for (int i = 9; i >= 0; i--) {
    for (int vine = 0; vine < 6; vine++) {
      setColor(vine, i, 0, 0, 0);
    }
    pixels.show();
    delay(500);

  }
}

void grow_vines() {
  for (int i = 0; i < 10; i++) {
    for (int vine = 0; vine < 6; vine++) {
      setColor(vine, i, 10, 180, 10);
    }
    pixels.show();   
    if (i == 2 || i == 6) {
      delay(2500);
    } else {
      delay(500);
    }

  }
}

void snow_fall(int vine) {
  for (int i = 0; i < 10; i++) {
    setColor(vine, i, 255, 255, 255);
    if (i > 0) {
      setColor(vine, i-1, 0, 0, 0);
    }
    pixels.show();
    delay(300);
  }
}

void wind_gust() {
  attach_servos();
  int pos = 0;
  for (pos = 45; pos <= 135; pos += 1) { // goes from 45 degrees to 135 degrees
    // in steps of 1 degree
    servo_pos(pos);
    
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 135; pos >= 45; pos -= 1) { // goes from 135 degrees to 45 degrees
    servo_pos(pos);
    delay(15);
  }
  detach_servos();
}

void servo_dance() {
  Serial.println("servo dance");
  attach_servos();
  int pos = 0;
  for (int wait = 50; wait > 0; wait -= 10) {
    for (pos = 45; pos <= 135; pos += 1) { // goes from 45 degrees to 135 degrees
      // in steps of 1 degree
      servo_pos(pos);
      
      delay(wait);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 135; pos >= 45; pos -= 1) { // goes from 135 degrees to 45 degrees
      servo_pos(pos);
      delay(wait);
    }
  }
  detach_servos();
}

void detach_servos() {
  myservo1.detach();  
  myservo2.detach();
  myservo3.detach();
  myservo4.detach();
  myservo5.detach();
  myservo6.detach();
  myservo7.detach();
  myservo8.detach();
}

void attach_servos() {
  myservo1.attach(3);  
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(9);
  myservo5.attach(10);
  myservo6.attach(11);
  myservo7.attach(12);
  myservo8.attach(13);
}

void servo_pos(int pos) {
  attach_servos();
  myservo1.write(pos);
  myservo2.write(pos);
  myservo3.write(pos);
  myservo4.write(pos);
  myservo5.write(pos);
  myservo6.write(pos);
  myservo7.write(pos);
  myservo8.write(pos);
}

void blow_wind(int high) {
  for (int sp=0; sp < high; sp+=5) {
    set_dc_speed(sp);
    delay(200);
  }
}

void end_wind() {
  for (int sp=200; sp >= 0; sp-=5) {
    set_dc_speed(sp);
    delay(200);
  }
}

void set_dc_speed(int sp) {
  myMotor1->setSpeed(sp);
  myMotor1->run(FORWARD);

 
  myMotor2->setSpeed(sp);
  myMotor2->run(FORWARD);


  myMotor3->setSpeed(sp);
  myMotor3->run(FORWARD);


  myMotor4->setSpeed(sp);
  myMotor4->run(FORWARD);
}



uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
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

//note: call pixel.show() after
void set_vine_color(int vine, int r, int g, int b) {
  for (int i=0; i<10; i++) {
    setColor(vine, i, r, g, b);
  }
}

void fade_vine_color(int vine, uint8_t cur_r, 
  uint8_t cur_g, uint8_t cur_b, uint8_t new_r, uint8_t new_g, uint8_t new_b, int steps, int wait) {
   uint8_t r, g, b;
   Serial.print("Fading vine: "); Serial.println(vine);
   for (int j=0; j<steps; j++) {
      for (int i=0; i < 10; i++) {
        r = map(j, 0, steps, cur_r, new_r); 
        g = map(j, 0, steps, cur_g, new_g); 
        b = map(j, 0, steps, cur_b, new_b);
        setColor(vine, i, r, g, b); 
      }
      pixels.show();
      delay(wait);
   }
}

void set_all_colors(uint8_t r,uint8_t g, uint8_t b) {
  for (int i=0; i < pixels.numPixels(); i++) {
    pixels.setPixelColor(i, r, g, b);
  }
  pixels.show();
}


