#include <Stepper.h>
#include <ESP32Servo.h>

const int stepsPerRev = 32;
Servo myServo;
// Inputs are pin 1, pin 3, pin 2, pin 4
Stepper myStepper(stepsPerRev, 32, 25, 33, 26);

int servoPos = 10;
int flag = 1;
int buttonPin = 35;
int buttonVal = 0;
int prevValue = 0;
long duration;
long cm = 21.5;
long inches = 8.46;
long prevTime = 0;

int trigPin = 4;
int echoPin = 16;

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
 // myServo.attach(18);
  myStepper.setSpeed(840);

  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 

//    if(digitalRead(buttonPin) == LOW){
//    delay(10);
//    if(digitalRead(buttonPin) == LOW){
//      buttonVal = 1;
//    }
//    else{
//      buttonVal = 0;
//    }
//  }
//  else{
//    buttonVal = 0;
//  }

//    if (buttonVal != prevValue) {
//    myServo.write(servoPos);
//    servoPos = servoPos + (30 * flag);
//    flag = flag * -1;
//  }

//  prevValue = buttonVal;
//
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  if (duration < 10000) {
    cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
    inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  }
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  int posi = map(cm, 3, 35, -50, 50);
  myStepper.step(posi);


//  int delta = map(cm, 2, 30, 300, 3000);
//
//  long curTime = millis();
//
//  if (curTime - prevTime >= delta) {
//    prevTime = curTime;
//
//    myServo.write(servoPos);
//    servoPos = servoPos + (30 * flag);
//    flag = flag * -1;
//  }
 

  delay(5);
  
 // delay(delta);
  

 // Serial.println(String(trigVal) + String(echoVal));

  //int buttonVal = digitalRead(buttonPin);
  //Serial.println(buttonVal);


 

}
