const int trigPin = 9;      // Pin connected to the Trigger pin of the ultrasonic sensor
const int echoPin = 10;     // Pin connected to the Echo pin of the ultrasonic sensor

long duration;              // Variable to store the time it takes for the pulse to return
int distance;               // Variable to store the calculated distance

void setup() {
    pinMode(trigPin, OUTPUT);  // Set the Trigger pin as an output
    pinMode(echoPin, INPUT);   // Set the Echo pin as an input
    Serial.begin(9600);        // Initialize serial communication at 9600 baud
}

void loop() {
    // Send a 10µs pulse to trigger the ultrasonic sensor
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(1000);    // Delay to stabilize sensor
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(1000);    // 10µs pulse
    digitalWrite(trigPin, LOW);

    // Read the pulse duration
    duration = pulseIn(echoPin, HIGH);

    // Calculate the distance in centimeters
    distance = duration * 0.034 / 2;

    // Print the distance to the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);

    // Wait 1 second before taking another measurement
    delay(1000);
}
