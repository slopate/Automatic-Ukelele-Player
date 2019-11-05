#include <ESP32Servo.h>
#include <analogWrite.h>

Servo myServo;

// variable declarations
int servoPos = 10;
int flag = 1;

long duration1;
long duration2;
long cm = 21.5;
long inches = 8.46;
long prevTime = 0;
int dcSpeed = 0;

// pin declarations
int trig1Pin = 16;
int echo1Pin = 4;
int trig2Pin = 2;
int echo2Pin = 15;

int dcSpeedPin = 25;
int dcDir1Pin = 26;
int dcDir2Pin = 27;

int servoPin = 18;


void setup() {
  //  set up serial, dc, and ultrasound pins
  Serial.begin(115200);
  myServo.attach(servoPin);

  pinMode(dcDir1Pin, OUTPUT);
  pinMode(dcDir2Pin, OUTPUT);

  pinMode(trig1Pin, OUTPUT);
  pinMode(echo1Pin, INPUT);
  pinMode(trig2Pin, OUTPUT);
  pinMode(echo2Pin, INPUT);

}

// method for reading from sonar sensor
int SonarSensor(int trigPin,int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH);
}

void loop() {

  //  read sonar sensors
  duration1 = SonarSensor(trig1Pin, echo1Pin);
  duration2 = SonarSensor(trig2Pin, echo2Pin);

  //  print values
  Serial.print(duration1);
  Serial.print(',');
  Serial.println(duration2);

  // Convert the time into a distance
  if (duration1 < 10000) {
    cm = (duration1/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
    inches = (duration1/2) / 74;   // Divide by 74 or multiply by 0.0135
  }

  //  process data and move servo
  int delta = map(cm, 2, 30, 300, 3000);
  long curTime = millis();
  if (curTime - prevTime >= delta) {
    prevTime = curTime;

    myServo.write(servoPos);
    servoPos = servoPos + (30 * flag);
    flag = flag * -1;
  }

  //  handle DC motor direction and speed
  if (duration2 < 6300) {

    if (duration2 < 1000 ) {

      // set speed     
      dcSpeed = map(duration2, 0, 1000, 255, 0);
      analogWrite(dcSpeedPin, dcSpeed);
      
      // set direction
      digitalWrite(dcDir1Pin, LOW);
      digitalWrite(dcDir2Pin, HIGH);
    } else {

      // set speed     
      dcSpeed = map(duration2, 1000, 3000, 0, 255);
      analogWrite(dcSpeedPin, dcSpeed);

      // set direction
      digitalWrite(dcDir1Pin, HIGH);
      digitalWrite(dcDir2Pin, LOW);  
    }
    
  }

}
