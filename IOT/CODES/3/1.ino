const int pirPin = 2;      // Pin connected to the PIR sensor's OUT
const int ledPin = 13;     // Pin connected to the LED

int pirState = LOW;        // Start with no motion detected
int val = 0;               // Variable to store the PIR sensor value

void setup() {
    pinMode(pirPin, INPUT);   // Set the PIR sensor pin as input
    pinMode(ledPin, OUTPUT);  // Set the LED pin as output
    Serial.begin(9600);       // Initialize serial communication (for debugging)
}

void loop() {
    val = digitalRead(pirPin);  // Read the value from the PIR sensor

    if (val == HIGH) {          // Check if motion is detected
        digitalWrite(ledPin, HIGH);  // Turn on the LED

        if (pirState == LOW) {  // Only print message when motion starts
            Serial.println("Motion detected!");  // Print to Serial Monitor
            pirState = HIGH;    // Update the PIR state
        }
    } else {
        digitalWrite(ledPin, LOW);   // Turn off the LED

        if (pirState == HIGH) {  // Only print message when motion ends
            Serial.println("Motion ended!");    // Print to Serial Monitor
            pirState = LOW;    // Update the PIR state
        }
    }
}
