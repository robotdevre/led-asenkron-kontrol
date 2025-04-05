 struct LedKontrol { 
  int pin;
  unsigned long aralik;
  unsigned long oncekiZaman;
  bool durum;
};

LedKontrol led1 = {8, 500, 0, false};
LedKontrol led2 = {9, 700, 0, false};

void setup() {
  Serial.begin(9600);
  delay(100); // Bazı durumlarda gerekli
  Serial.println("LED ON");
  pinMode(led1.pin, OUTPUT);
  pinMode(led2.pin, OUTPUT);
}

void loop() {
  unsigned long simdikiZaman = millis();
  ledGuncelle(led1, simdikiZaman);
  ledGuncelle(led2, simdikiZaman);
}

void ledGuncelle(LedKontrol &led, unsigned long simdikiZaman) {
  if (simdikiZaman - led.oncekiZaman >= led.aralik) {
    led.oncekiZaman = simdikiZaman;
    led.durum = !led.durum;
    digitalWrite(led.pin, led.durum);
  }
}
