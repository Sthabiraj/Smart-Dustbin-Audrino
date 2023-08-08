void setup() {
  Serial.begin(9600); // Set the baud rate to match the baud rate in the Python script
}

void loop() {
  // Read data from your sensor or device
  char sensorData[20] = "Hello"; // Replace this with your actual sensor reading.

  // Send the data through the Serial interface
  Serial.println(sensorData);

  delay(1000); // Adjust the delay based on how often you want to send data (1 second in this example)
}
