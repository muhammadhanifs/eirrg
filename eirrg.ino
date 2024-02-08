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
  baca_kiri();
  baca_tengah();
  baca_kanan();
  if (distance1 < 10 && distance2 < 10 && distance3 < 10) {
    stop();
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
}

void kanan() {
  //aksi ke kanan
}

void kiri() {
  //aksi ke kiri
}

void stop() {
  //aksi berhenti
}

void gripper() {
  //aksi gripper
}

void putarbalik() {
  //aksi robot putar balik
}
