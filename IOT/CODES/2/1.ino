#include <Servo.h>

Servo myServo;   // Create a servo object

const int trigPin = 7;  // Trigger pin of the ultrasonic sensor
const int echoPin = 6;  // Echo pin of the ultrasonic sensor
int distance;           // Variable to store the distance value

void setup() {
  Serial.begin(9600);    // Start serial communication
  myServo.attach(9);     // Attach servo to pin 9
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Get distance from the ultrasonic sensor
  distance = getDistance();
  
  // Map the distance to a servo position (0 to 180 degrees)
  int servoPosition = map(distance, 0, 100, 0, 180);  // Map distance (0-100 cm) to servo angle
  servoPosition = constrain(servoPosition, 0, 180);   // Make sure the angle stays between 0 and 180
  
  myServo.write(servoPosition);  // Move the servo to the calculated position
  delay(500);  // Wait for half a second

  // Print the distance and servo position to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, Servo position: ");
  Serial.println(servoPosition);
}

// Function to get the distance from the ultrasonic sensor
int getDistance() {
  long duration, distance;
  
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin, and get the time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;  // Speed of sound: 0.034 cm/microsecond
  
  return distance;
}