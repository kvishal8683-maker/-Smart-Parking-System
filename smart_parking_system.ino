#include <LiquidCrystal.h>

// LCD pins: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, A0, A1, A2, A3);

// Sensor pins
int trigPin = 2;
int echoPin = 3;

// LED pins
int greenLED = 6;
int redLED = 7;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Smart Parking");
  delay(2000);
  lcd.clear();
}

void loop() {

  long duration;
  int distance;

  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);

  // Convert to distance (cm)
  distance = duration * 0.034 / 2;

  lcd.setCursor(0, 0);

  if (distance > 10) {
    // Slot empty
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);

    lcd.print("Slot Empty     ");
    lcd.setCursor(0, 1);
    lcd.print("Available      ");
  }
  else {
    // Slot occupied
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);

    lcd.print("Slot Occupied  ");
    lcd.setCursor(0, 1);
    lcd.print("Not Available  ");
  }

  delay(500);
}