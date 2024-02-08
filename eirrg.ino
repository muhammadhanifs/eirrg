#include <Servo.h>

#define trig1 1
#define echo1 2
#define trig2 3
#define echo2 4
#define trig3 5
#define echo3 6
#define pir 7
#define servo1 8
#define servo2 9
#define in1 10   //kiri
#define in2 11   //kiri
#define in3 12   //kanan
#define in4 13   //kanan

const int en12 = A0;
const int en34 = A1;

int duration1;
int duration2;
int duration3;
int distance1;
int distance2;
int distance3;
int pos = 0;

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
  servo_rotate.write(pos);
}

void loop() {
  baca_kiri();
  baca_tengah();
  baca_kanan();
  if (distance1 < 10 && distance2 < 10 && distance3 < 10) {
    stop();
    off();
    if (digitalRead(pir) == HIGH) {
      gripper();
    }
    else putarbalik();
  }
  else if (distance1 > 10 && distance2 < 10 && distance3 < 10) {
    kiri();
  }
  else if (distance1 < 10 && distance2 > 10 && distance3 < 10) {
    maju();
  }
  else if (distance1 < 10 && distance2 < 10 && distance3 > 10) {
    kanan();
  }
  else if (distance1 > 10 && distance2 < 10 && distance3 > 10) {
    kiri();
  }
}

void baca_kiri() {
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig1, LOW);
  duration1 = pulseIn(echo1, HIGH);
  distance1 = (duration1 * 0.034)/2;
}

void baca_tengah() {
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig2, LOW);
  duration2 = pulseIn(echo2, HIGH);
  distance2 = (duration2 * 0.034)/2;
}

void baca_kanan() {
  digitalWrite(trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(trig3, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig3, LOW);
  duration3 = pulseIn(echo3, HIGH);
  distance3 = (duration3 * 0.034)/2;
}

void maju() {
  //aksi maju
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(en12, 255);
  analogWrite(en34, 255);
}

void kanan() {
  //aksi ke kanan
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(en12, 255);
  analogWrite(en34, 255);
}

void kiri() {
  //aksi ke kiri
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(en12, 255);
  analogWrite(en34, 255);
}

void stop() {
  //aksi berhenti
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(en12, 0);
  analogWrite(en34, 0);
}

void off() {
  digitalWrite(trig1, LOW);
  digitalWrite(trig2, LOW);
  digitalWrite(trig3, LOW);
}

void gripper() {
  for (pos = 0; pos <= 45; pos++) {
    servo_rotate.write(pos);
  }
  putarbalik();
}

void putarbalik() {
  off();
  kiri();
}
