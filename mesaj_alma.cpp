#include <Wire.h>

String gelenMesaj = "";

void setup() {
  Wire.begin(8); // Slave ID
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  if (gelenMesaj != "") {
    Serial.print("Gelen mesaj: ");
    Serial.println(gelenMesaj);
    gelenMesaj = "";
  }
}

void receiveEvent(int bytes) {
  gelenMesaj = "";
  while (Wire.available()) {
    char c = Wire.read();
    gelenMesaj += c;
  }
}
