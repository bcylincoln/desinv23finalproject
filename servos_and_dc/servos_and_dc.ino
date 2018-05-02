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

const int buttonPin = A2;     // the number of the pushbutton pin
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  AFMS.begin();
  
  myservo1.attach(3);  
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(9);
  myservo5.attach(10);
  myservo6.attach(11);
  myservo7.attach(12);
  myservo8.attach(13);

  myMotor1->setSpeed(50);
  myMotor1->run(FORWARD);

 
  myMotor2->setSpeed(50);
  myMotor2->run(FORWARD);


  myMotor3->setSpeed(50);
  myMotor3->run(FORWARD);


  myMotor4->setSpeed(50);
  myMotor4->run(FORWARD);
}

void loop() {
  int pos = 0;
  
  for(int i=0;i<58;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.
  }  
}

void fall() {
  Serial.println("fall");
}

void winter() {
  Serial.println("winter");
}

void spring() {
  Serial.println("spring");
}

void summer() {
  Serial.println("summer");
}





