const int trigPin = D4; 
const int echoPin = D5;
const int ledPin = D6; // Define the pin connected to the LED

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT); // Set D6 as an output
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Check if distance is less than or equal to 15cm
  if (distance <= 15) {
    digitalWrite(ledPin, HIGH); // Turn on the LED connected to D6
    delay(10000); // Keep the LED on for 10 second (adjust as needed)
    digitalWrite(ledPin, LOW); // Turn off the LED
  }

  delay(2000);
}