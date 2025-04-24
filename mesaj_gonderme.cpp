#include <Wire.h>

const int buttonPin = 2;
bool lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Wire.begin(); // Master
  Serial.begin(9600);
}

void loop() {
  bool currentButtonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    // Buton basıldıysa mesaj gönder
    Wire.beginTransmission(8); // Slave ID
    Wire.write("Nasılsın?");
    Wire.endTransmission();
    Serial.println("Mesaj gönderildi: Nasılsın?");
    delay(300); // debounce
  }

  lastButtonState = currentButtonState;
}
