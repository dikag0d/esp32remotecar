# esp32remotecar
# 🚗 ESP32 Remote Car with PS3 Controller (Bluetooth HID)

Project ini adalah sistem **mobil remote berbasis ESP32** yang dikendalikan menggunakan **Stik PS3 (DualShock 3)** menggunakan koneksi **Bluetooth HID asli**, bukan simulasi.  
Joystick PS3 langsung mengontrol kecepatan dan arah motor kiri serta motor kanan secara analog.

---

## 📌 Fitur Utama
- 🎮 **Kontrol penuh dengan PS3 Controller**
- ⚙️ **Kecepatan analog** berdasarkan tekanan joystick
- ↕️ Maju / Mundur  
- ↔️ Belok kiri / kanan  
- 🟢 Kompatibel semua driver motor (L298N, BTS7960, MX1508, L9110, dll)
- 🧩 Kode bersih & mudah dikembangkan (mode drift, 4WD, lampu, klakson, dll)

---

## 🧰 Hardware yang Digunakan
- **ESP32 Dev Module**
- **PS3 Controller (DualShock 3)**
- **Driver Motor** (pilih salah satu):
  - L298N
  - BTS7960
  - L9110
  - MX1508
- **2 Motor DC** (roda kiri & kanan)
- Power supply 7–12V

---

## 🔌 Wiring Motor

| Fungsi              | Pin ESP32 |
|--------------------|-----------|
| ENA (PWM kiri)     | 25        |
| IN1                | 26        |
| IN2                | 27        |
| ENB (PWM kanan)    | 14        |
| IN3                | 12        |
| IN4                | 13        |

Semua pin bisa diganti sesuai kebutuhan.

---

## 📥 Install Library PS3 Controller

Gunakan library berikut:

- **PS3Controller**

Tambahkan melalui **Arduino IDE → Library Manager** atau install manual dari GitHub.

---

## 🔗 Pairing PS3 Controller ke ESP32

1. Hubungkan PS3 Controller ke PC via USB.  
2. Buka aplikasi **SixaxisPairTool**.  
3. Masukkan MAC Address Bluetooth ESP32 ke kolom "Current Master".  
4. Klik **Update**.  
5. Lepas kabel → Controller akan connect otomatis ke ESP32.

MAC Address ESP32 ditulis di:

```cpp
PS3.begin("01:02:03:04:05:06");
