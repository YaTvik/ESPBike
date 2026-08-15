- Open **Tools → Board → Boards Manager**
- Find and install **esp32** (by Espressif Systems)

### 3. Install Libraries
In Library Manager (**Sketch → Include Library → Manage Libraries**) install:

| Library | Author |
|------------|-------|
| **TFT_eSPI** | Bodmer |
| **SparkFun u-blox GNSS** | SparkFun |
| **XPT2046_Touchscreen** | Paul Stoffregen |
| **DHT sensor library** | Adafruit |

### 4. Upload the Firmware
- Download `ESPBike.ino` from the `firmware/` folder
- Open it in Arduino IDE
- Connect ESP32 to your computer
- Select **Tools → Board → ESP32 Dev Module**
- Select the correct **port**
- Click **Upload**

### 5. Verify Operation
After upload, ESP32 will reboot and start initialization. If all sensors are connected correctly, you'll see the main bike computer screen.

---

## ❓ Frequently Asked Questions

### ❓ Why does speed show 0 even though I'm riding?
**Answer:** Check the satellite count in the top-right corner. If it's 0 — GPS hasn't locked signal. Move to an open area and wait a minute.

### ❓ How does auto-stop work?
**Answer:** If you stop, the trip timer continues for 3 more seconds, then pauses. This prevents resetting time on short stops.

### ❓ Why doesn't slope work?
**Answer:** Check if MPU6050 initialized at startup. If not — reboot the device. Make sure the sensor is connected correctly.

### ❓ How to enable PACER?
**Answer:** Press the green PACER button. Enter time (in minutes) and distance (in kilometers). Press OK. The mode starts.

### ❓ Can I use it without GPS?
**Answer:** No. GPS is the only source of speed. Without it, the bike computer won't work.

### ❓ How to check total mileage?
**Answer:** On the main screen, there's a "TOTAL" line. This is the total distance since assembly. It never resets.

### ❓ What if the screen doesn't turn on?
**Answer:** Check correct connection to the microcontroller.

---

## 🎯 Who Is This Project For

| You | Is ESPBike right for you? |
|---|---------------------------|
| Want a bike computer without overpaying | ✅ Yes |
| Ride on weekends | ✅ Yes |
| Commute to work daily | ✅ Yes |
| Want to monitor load | ✅ Yes |
| Want to control pace on long distances | ✅ Yes |
| Learning ESP32 programming | ✅ Yes |
| Love DIY projects | ✅ Yes |

---

## 🤝 How to Support the Project

This is my first project, so any help is valuable:

- **Share it** with other cyclists and makers
- **Report bugs** — if something doesn't work
- **Suggest ideas** — what could be improved
- **Show your builds** — I'm curious to see
- **Star ⭐ the project** — it helps it grow

---

## 📄 License

### Code (Firmware) — MIT License
The code is distributed under the MIT License. You are free to use, modify, and distribute the code.

### Hardware (Enclosure, Schematics) — Proprietary
The enclosure, 3D models, and wiring diagram are my intellectual property. You may use them for personal, non-commercial use only. Commercial use (including selling devices based on my schematics or enclosure) is prohibited without my written permission.

### Brand
The name "ESPBike" is my trademark. No one may sell devices under this name without my permission.

---

## 📬 Contact

For commercial use, licensing, or collaboration inquiries:

- 📧 Email: mcvictorok@gmail.com
- 💬 GitHub Issues: [Create an issue](https://github.com/YaTvik/ESPBike/issues)

---

## 🌟 Star the Project!

If you find this project useful — give it a ⭐ on GitHub. It helps others discover it.

[![GitHub stars](https://img.shields.io/github/stars/YaTvik/ESPBike.svg?style=social)](https://github.com/YaTvik/ESPBike)

---

**Made with ❤️ for cyclists and those who learn.**

*This is my first project, and I'm glad you checked it out. Ride safe, protect your knees, and don't be afraid to build your own devices!* 🚴‍♂️

---

## 📝 Note on AI Usage

I used ChatGPT during the development of this firmware. I believe it's normal to learn with modern tools.
