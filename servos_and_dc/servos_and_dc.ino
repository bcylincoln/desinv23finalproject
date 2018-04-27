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
  for (pos = 45; pos <= 135; pos += 1) { // goes from 45 degrees to 135 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);
    myservo5.write(pos);
    myservo6.write(pos);
    myservo7.write(pos);
    myservo8.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 135; pos >= 45; pos -= 1) { // goes from 135 degrees to 45 degrees
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos);
    myservo3.write(pos); 
    myservo4.write(pos); 
    myservo5.write(pos); 
    myservo6.write(pos); 
    myservo7.write(pos); 
    myservo8.write(pos);  
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
}
