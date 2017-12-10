#include <SoftwareSerial.h> // Bluetooth HC-05 recommended library

#include <Servo.h>  //Servo library
Servo myservo1, myservo2; //Assigning names to the servos

int bluetoothTx = 10; //Connect tx to pin 10
int bluetoothRx = 11; //Connect rx to pin 11

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);


#define pin1 2 //motor 1/L +
#define pin2 7 //motor 1/L -
#define pw1 9 //motor 1/L pwm
#define pin3 4 //motor 2/R +
#define pin4 8 //motor 2/R -
#define pw2 6 //motor 2/R pwm

void setup() {

  myservo1.attach(3);
  myservo2.attach(5);

  Serial.begin(9600);

  bluetooth.begin(9600);

pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
pinMode(pin4, OUTPUT);
pinMode(pw1, OUTPUT);
pinMode(pw2, OUTPUT);
Serial.begin(9600);
digitalWrite(pin1, LOW);
digitalWrite(pin2, LOW);
digitalWrite(pin3, LOW);
digitalWrite(pin4, LOW);
analogWrite(pw1, 10);
analogWrite(pw2, 10);
}

void loop() {
 if(bluetooth.available()>= 2 )
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 * 256) + servopos;
 
  if (realservo >= 1000 && realservo <= 1180) {
    int servo1 = realservo;
    servo1 = map(servo1, 1000, 1180, 0, 180);
    myservo1.write(servo1);
    int servo2 = 180 - realservo;
    servo2 = map(servo2, 1000, 1180, 0, 180);
    myservo2.write(servo2);
  }

   else if ( realservo >= 2000 && realservo <= 2255) {
      analogWrite (pw1, realservo - 2000);
      analogWrite (pw2, realservo - 2000);
    
   }
  
  
  }
  
  
  }


