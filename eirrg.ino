#include <Servo.h>

#define trig1 2
#define echo1 3
#define trig2 4
#define echo2 5
#define trig3 6
#define echo3 7
#define pir 8
#define servo1 9
#define servo2 10

int duration1;
int duration2;
int duration3;
int distance1;
int distance2;
int distance3;

/*Keterangan : 
  pin-pin diatas tidak mutlak, akan
  diubah jika ada perubahan */

Servo servo_side;
Servo servo_rotate;

void setup() {
  Serial.begin(9600);
  pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(trig3, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(echo3, INPUT);
  pinMode(pir, INPUT);
  servo_side.attach(servo1);
  servo_rotate.attach(servo2);
}

void loop() {
  
}

void baca_ultrasonic() {
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig1, LOW);
  
}
