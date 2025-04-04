# led-asenkron-kontrol ✅

Bu proje, Arduino Uno kartı kullanılarak iki LED’in farklı aralıklarda asenkron şekilde yanıp sönmesini sağlar. Yapılandırılmış `struct` yapısı ile temel zamanlama mantığı öğretilir. Orta seviye bir Arduino projesidir.

---

## 🔧 Kullanılan Malzemeler

- Arduino Uno  
- 2 x 220 Ohm direnç  
- 2 x LED (Kırmızı ve Yeşil)  
- Breadboard  
- Jumper kablolar  

---

## 🎯 Proje Amacı

- `struct` yapısını kullanarak veri gruplama yöntemini öğrenmek  
- `millis()` fonksiyonu ile zamanlama yapmak  
- `digitalWrite()` ile çıkış kontrolü yapmak  
- Temel donanım bağlantılarını kavramak  

---

## 📷 Devre Şeması

📁 `diagram.json` dosyasında Wokwi uyumlu devre şeması bulunmaktadır.  
İstersen doğrudan [Wokwi üzerinde simüle etmek için buraya tıklayabilirsin.](https://wokwi.com/projects/426591851373025281)

---

## 💡 Kod

```cpp
struct LedKontrol {
  int pin;
  unsigned long aralik;
  unsigned long oncekiZaman;
  bool durum;
};

LedKontrol led1 = {8, 500, 0, false};
LedKontrol led2 = {9, 700, 0, false};

void setup() {
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
