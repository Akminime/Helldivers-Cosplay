const int buttonPin = 2;
const int buttonLedPin = 4;

const int ledUpPin = 5;
const int ledDownPin = 6;
const int ledLeftPin = 7;
const int ledRightPin = 8;

const int xPin = A2;
const int yPin = A1;

const int threshold = 200;

int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);

  pinMode(buttonLedPin, OUTPUT);

  pinMode(ledUpPin, OUTPUT);
  pinMode(ledDownPin, OUTPUT);
  pinMode(ledLeftPin, OUTPUT);
  pinMode(ledRightPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  int xValue = analogRead(xPin);
  int yValue = analogRead(yPin);

  if (buttonState == HIGH) {
    digitalWrite(buttonLedPin, HIGH);
  } else {
    digitalWrite(buttonLedPin, LOW);
  }

  digitalWrite(ledUpPin, LOW);
  digitalWrite(ledDownPin, LOW);
  digitalWrite(ledLeftPin, LOW);
  digitalWrite(ledRightPin, LOW);

  if (xValue > 512 + threshold) {
    digitalWrite(ledRightPin, HIGH);
  } 
  else if (xValue < 512 - threshold) {
    digitalWrite(ledLeftPin, HIGH); //
  } 
  else if (yValue > 512 + threshold) {
    digitalWrite(ledUpPin, HIGH);
  } 
  else if (yValue < 512 - threshold) {
    digitalWrite(ledDownPin, HIGH);
  }
}
