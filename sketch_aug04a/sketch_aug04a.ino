// Distance Sensor
// For outside sensor
int trigPin1 = 2;
int echoPin1 = 3;
// For inside sensor
int trigPin2 = 4;
int echoPin2 = 5;

// For Servo
#include <Servo.h>

Servo myServo;
int servoPosition = 9;

// Flag to track if the message has been printed
bool messagePrinted = false;

void setup()
{
  // For Distance Sensor
  // For outside sensor
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  // For inside sensor
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  // For Servo
  myServo.attach(servoPosition);
  myServo.write(0);

  // Serial Monitor
  Serial.begin(9600);
}

void loop()
{
  // For outside sensor
  digitalWrite(trigPin1, LOW);
  delay(2);
  digitalWrite(trigPin1, HIGH);
  delay(10);
  digitalWrite(trigPin1, LOW);

  // Calculate distance1
  float time1 = pulseIn(echoPin1, HIGH);
  float distance1 = (0.0343 * time1) / 2;

  // Open the dustbin lid if person is near
  if (distance1 <= 30)
  {
    myServo.write(120);
  }
  else
  {
    myServo.write(0);
  }

  // For inside sensor
  digitalWrite(trigPin2, LOW);
  delay(2);
  digitalWrite(trigPin2, HIGH);
  delay(10);
  digitalWrite(trigPin2, LOW);

  // Calculate distance2
  float time2 = pulseIn(echoPin2, HIGH);
  float distance2 = 3;

  // Check if dustbin is full and print message if not printed before
  if (distance2 <= 3 && !messagePrinted)
  {
    Serial.println("Your dustbin is full! Please empty it.");
    messagePrinted = true; // Set the flag to indicate the message has been printed
  }

  // Reset messagePrinted flag if dustbin is no longer full
  if (distance2 > 3)
  {
    Serial.println("Your dustbin is not full.");
    messagePrinted = false; // Reset the message printed flag
  }
}
