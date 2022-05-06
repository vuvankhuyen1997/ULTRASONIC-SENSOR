#include<Servo.h>
Servo myservo;
const int trigPin=3;
const int echoPin=5; 
long tmeduration;
int distance;
const int redPin = 6;
const int greenPin = 10;
const int bluePin = 11;

 
void setup() {
myservo.attach(9);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600);
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);

 
}
 
void loop() {
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
 
tmeduration=pulseIn(echoPin,HIGH);
distance=(0.034*tmeduration)/2;
 
if(distance <= 10){
  delay(7000);
  primaryColors(0,1,0);
  myservo.write(90);
  }else {
    myservo.write(0);
    primaryColors(1,0,0);
    }
delay(1);
}

void primaryColors(int redValue, int greenValue, int blueValue){
  digitalWrite(redPin, redValue);
  digitalWrite(greenPin, greenValue);
  digitalWrite(bluePin, blueValue);
  }
