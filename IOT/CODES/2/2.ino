//2) Fading LED with the help of Arduino.
#include <Arduino.h>

const int ledPin = 9;           // Use a PWM-capable pin (e.g., 9, 10, 11)
const int powerPin = 13;        // Pin to control the 3.5V supply

void setup() {
    pinMode(ledPin, OUTPUT);    // Set the LED pin as an output
    pinMode(powerPin, OUTPUT);  // Set the power pin as an output
    digitalWrite(powerPin, HIGH);  // Enable the 3.5V supply
}

void loop() {
    // Gradually increase brightness (fade in)
    for (int brightness = 0; brightness <= 255; brightness++) {
        analogWrite(ledPin, brightness);   // Set the brightness
        delay(10);                         // Adjust delay to control fading speed
    }

    // Gradually decrease brightness (fade out)
    for (int brightness = 255; brightness >= 0; brightness--) {
        analogWrite(ledPin, brightness);   // Set the brightness
        delay(10);                         // Adjust delay to control fading speed
    }

    // Optional: Add a delay between fades to create a blink effect
    delay(500);  // Wait for 500 milliseconds (adjust as needed)
}
