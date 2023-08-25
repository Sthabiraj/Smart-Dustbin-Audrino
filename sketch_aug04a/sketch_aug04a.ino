// Student name: Biraj Shrestha
// Project title: Smart Dustbin
// Date: August 25, 2023

// Distance Sensor
// Pins for the outside distance sensor
int trigPin1 = 2;
int echoPin1 = 3;
// Pins for the inside distance sensor
int trigPin2 = 4;
int echoPin2 = 5;

// Servo
#include <Servo.h>
Servo myServo;

int servoPosition = 9; // Pin for controlling the servo motor

// Flag to indicate if the dustbin is full
bool isDustbinFull = false;

// Location name
char locationName[100] = "Herald College Kathmandu";

void setup()
{
  // Initialize pins for the distance sensors
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  // Attach servo and set initial position
  myServo.attach(servoPosition);
  myServo.write(0);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop()
{
  // Measure distance using the outside sensor
  digitalWrite(trigPin1, LOW);
  delay(2);
  digitalWrite(trigPin1, HIGH);
  delay(10);
  digitalWrite(trigPin1, LOW);

  // Calculate distance from the outside sensor
  float time1 = pulseIn(echoPin1, HIGH);
  float distance1 = (0.0343 * time1) / 2;

  // Open the dustbin lid if a person is nearby
  if (distance1 <= 40)
  {
    myServo.write(120); // Open the lid
    delay(3000);        // Keep the lid open for 3 seconds
  }
  else
  {
    myServo.write(0); // Close the lid
    checkDustbin();   // Check the dustbin status
  }
}

// Function to check if the dustbin is full
void checkDustbin()
{
  digitalWrite(trigPin2, LOW);
  delay(2);
  digitalWrite(trigPin2, HIGH);
  delay(10);
  digitalWrite(trigPin2, LOW);

  // Calculate distance from the inside sensor
  float time2 = pulseIn(echoPin2, HIGH);
  float distance2 = (0.0343 * time2) / 2;

  // Check if the dustbin is full and set the flag to true
  if (distance2 <= 8 && !isDustbinFull)
  {
    Serial.print("Your dustbin at ");
    Serial.print(locationName);
    Serial.println(" is full! Please empty it.");
    delay(3000);          // Display message for 3 seconds
    isDustbinFull = true; // Set the flag to indicate the dustbin is full
  }

  // Reset the flag if the dustbin is not full
  if (distance2 > 8)
  {
    isDustbinFull = false; // Reset the flag
  }
}
