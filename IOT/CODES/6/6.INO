#define gasSensor A0
#define buzzer 7
#define ledGreen 13
#define ledRed 8 
#define HIGH_THRESHOLD 200

void setup() {
  // Initializing all pins
  pinMode(gasSensor, INPUT); 
  pinMode(buzzer, OUTPUT); 
  pinMode(ledGreen, OUTPUT); 
  pinMode(ledRed, OUTPUT);

  // Initialize Serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Read data from the sensor
  int gas_value = analogRead(gasSensor);

  // Print gas sensor value to the Serial Monitor
  Serial.print("Gas Sensor Value: "); 
  Serial.println(gas_value);

  // Check data from sensor; if there is smoke, the 'if' block will execute, otherwise 'else' will execute
  if (gas_value > HIGH_THRESHOLD) {
    tone(buzzer, 1000, 500);  // Sound the buzzer
    digitalWrite(ledRed, HIGH);  // Turn on red LED
    digitalWrite(ledGreen, LOW);  // Turn off green LED
  } else {
    noTone(buzzer);  // Turn off buzzer
    digitalWrite(ledGreen, HIGH);  // Turn on green LED
    digitalWrite(ledRed, LOW);  // Turn off red LED
  }

  // Short delay
  delay(200);
}
