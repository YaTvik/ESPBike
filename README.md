# 🚴⚡ ESPBike - [Русский](https://github.com/YaTvik/ESPBike/blob/main/README_RU.md)
🚴 This is a bike computer based on the ESP32 microcontroller that displays speed and distance, assists the rider, and even suggests when to slow down!

# ESPBike — Bicycle Computer.

**Version: 1.0 | Open Source (MIT) | Based on ESP32**

[![Platform: ESP32](https://img.shields.io/badge/Platform-ESP32-blue.svg)](https://www.espressif.com/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
[![Build Status](https://img.shields.io/badge/Status-Working-brightgreen.svg)]()

---
![Project Logo](Images/Logo.jpg)

## 📋 About the Project

**ESPBike** is my first public project based on the ESP32 microcontroller. I built a bike computer that displays speed, distance, helps monitor knee strain, suggests optimal pace, and even detects road slope.

The project is fully functional and tested in practice. All code and wiring diagrams are open source.

---

## 🚴 What the Bike Computer Can Do

### 📊 Key Metrics
- **Current Speed** — large digits, visible even while riding
- **Maximum Speed** — for the entire trip
- **Average Speed** — accurate calculation without GPS errors
- **Auto-Stop** — if you stop at a traffic light, the trip timer pauses

### 📏 Distance
- **Trip Distance** — how far you've ridden today
- **Daily Distance** — resets every day
- **Total Distance** — total mileage since assembly

### ⏱️ Time
- **Moving Time** — excluding stops
- **Total Time** — since device power-on
- **Clock** — displayed on the main screen (from GPS)

### 🦵 Load and Health
- **Knee load** — my own development. It analyzes speed, distance traveled, and road gradient.
  | ⚠️ WARNING! |
  |--------|
  **The estimated load is an experimental indicator of the intensity of the trip, calculated based on speed, distance, and gradient. It is not a medical measurement.**


- **Color Scale from Green to Red** — if it turns red, it's time to rest
- **Overload Alert** — at 100% load: 3-second beep, then 3-minute pause, then continuous beep until load decreases
- **Calories** — approximate energy expenditure during the ride

### ⛰️ Road Slope
- **Slope Percentage Display** — shows steepness of ascent or descent
- **Left Arrows** — visual indicator: up (climb), down (descent), square (flat)
- **Auto-Calibration** — at startup, accounts for device position
- **Rapid Slope Change Warning** — audible alert if slope changes suddenly

### 🎯 PACER Mode (Pacing)
- **Set Time and Distance** — the bike computer calculates the required speed
- **Pace Guidance** — displays target speed
- **Warning** — if speed deviates by more than 5 km/h, an alert sounds
- **ETA Calculation** — shows estimated time of arrival
- **Congratulations** — success melody plays when you reach your goal

### 📳 Vibration Warning
- **Vibration Analysis** — MPU6050 sensor monitors shaking
- **Warning** — if vibrations exceed normal at speeds > 10 km/h, an alert sounds

### 🌡️ Weather
- **Temperature** and **Humidity** — from DHT11 sensor

### 🌓 Auto-Theme
- **Light theme during day**, **dark theme at night** (based on GPS time)
- **Theme Lock** — if GPS is lost, the theme stays the same

---

## 🔧 Power-On Self-Test

When you turn on the device, it **doesn't just show the screen**. It first runs an automatic check of all modules.

**What is checked:**

| Module | What is checked | What if error |
|--------|-----------------|---------------|
| **TFT** | Screen, backlight | Won't turn on — you'll see a blank screen |
| **EEPROM** | Memory for saving settings | Will stop remembering total mileage |
| **TOUCH** | Touch screen | Buttons won't work |
| **MPU6050** | Motion sensor | Slope and load won't be calculated |
| **GPS** | Satellite module | Speed and distance won't work |
| **BUZZER** | Buzzer | No sound alerts |
| **DHT11** | Temperature sensor | Weather won't display |

**Important:** If any module fails to initialize, the device will show an error and wait for 30 seconds. You can **hold the screen** (touch and hold) — this will skip the check and boot with the non-working module. Handy if you're testing the build without all sensors.

---

## 🔋 Battery Life

| Mode | Runtime |
|-------|--------------|
| From USB charging | Unlimited |
| From 18650 (2000 mAh) | ~15+ hours |

---

## 🛠️ What You Need for Assembly

### Main Components

| Part | Purpose | Approximate price | Links / Cart |
|--------|-------------|----------------|------------------|
| **ESP32-WROOM** | Main processor | ~400 ₽ | https://ozon.ru/t/sX2Xuq5 |
| **2.8" TFT screen** | Displays data | ~800 ₽ | https://ozon.ru/t/6lilXGP |
| **QUESCAN M10Q GPS module** | Measures speed | ~1000 ₽ | https://ozon.ru/t/a8y8j0E |
| **MPU6050** | Motion sensor (tilt) | ~200 ₽ | https://ozon.ru/t/9ocoVb5 |
| **DHT11** | Temperature/humidity | ~150 ₽ | https://ozon.ru/t/RhGhY2H |
| **Buzzer** | Audible signals | ~50 ₽ | https://ozon.ru/t/bTDTdHa |
| **Battery** | Autonomous power supply | ~200 ₽ | https://ozon.ru/t/LC3CNfX |
| **Battery compartment** | Battery holder | ~80 ₽ | https://ozon.ru/t/9ocoVb5 |
| **M2x10mm self‑tapping screws** | Fasteners, can also be bought at any hardware store | ~50 ₽ | — |
| **Housing** | Printing it yourself will cost about 100 rubles | ~50 ₽ | https://github.com/YaTvik/ESPBike/tree/main/3D_Models |
| **Battery display** | Optional, but then you won’t see the charge percentage | ~50 ₽ | https://ali.click/2iidj1l |
| **Switches** | For turning the device on/off | ~40 ₽ WHOLESALE | https://ali.click/1iodj1y |
| **tp4056** | Charge board | ~100 ₽ WHOLESALE | https://ali.click/694ij1h |
| **Total** | | **~3000 ₽** | Cart: https://www.ozon.ru/cart?share=RhGhbio without self‑tapping screws, battery display, and switches.

### Additional
- Enclosure: [can be 3D printed](https://github.com/YaTvik/ESPBike/tree/main/3D_Models)

---

# 🔌 Module Wiring for ESP32

---

## TFT Display (2.8" ILI9341)

| TFT | ESP32 Pin |
|-----|-----------|
| VCC | 3.3V |
| GND | GND |
| CS | GPIO5 |
| DC | GPIO2 |
| RST | GPIO4 |
| MOSI | GPIO23 |
| SCLK | GPIO18 |
| LED | 3.3V |

---

## Touch Screen (XPT2046)

| Touch | ESP32 Pin |
|-------|-----------|
| VCC | 3.3V |
| GND | GND |
| T_CS | GPIO33 |
| T_MOSI | GPIO32 |
| T_MISO | GPIO34 |
| T_CLK | GPIO25 |
| T_IRQ | GPIO35 |

---

## GPS (QUESCAN M10Q)

| GPS | ESP32 Pin |
|-----|-----------|
| VCC | 3.3V |
| GND | GND |
| TX | GPIO16 |
| RX | GPIO17 |

---

## MPU6050

| MPU6050 | ESP32 Pin |
|---------|-----------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

---

## DHT11

| DHT11 | ESP32 Pin |
|-------|-----------|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO13 |



---

## Buzzer

| Buzzer | ESP32 Pin |
|--------|-----------|
| SIG | GPIO26 |
| GND | GND |

---

## TP4056

| TP4056 | Connect to |
|--------|------------|
| IN+ | USB 5V |
| IN- | USB GND |
| BAT+ | 18650 + |
| BAT- | 18650 - |
| OUT+ | Switch (COM) |
| OUT- | GND |

---

## 3-Pin Switch

| Switch | Connect to |
|--------|------------|
| 1 (COM) | TP4056 OUT+ |
| 2 (NO) | ESP32 VIN |
| 3 (NC) | Not connected |

---

## Battery Indicator

| Indicator | Connect to |
|-----------|------------|
| B+ | TP4056 BAT+ |
| B- | TP4056 BAT- |

---

## ⚙️ How to Install the Firmware

### 1. Install Arduino IDE
Download and install [Arduino IDE](https://www.arduino.cc/en/software)

### 2. Configure Arduino IDE for ESP32
- Open **File → Preferences**
- In **Additional Boards Manager URLs** add: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

- Open **Tools → Board → Boards Manager**
- Find and install **esp32** (by Espressif Systems)

### 3. Install Libraries

**Easiest way — download the ready archive:**

1. Download the archive with all libraries:  
   👉 [ESPBike_Libs.zip](libs/ESPBike_library.zip)

2. Extract the contents to:  
   `Documents/Arduino/libraries/`

3. Restart Arduino IDE

**Or install manually via Library Manager:**

| Library | Author |
|------------|-------|
| **TFT_eSPI** | Bodmer |
| **SparkFun u-blox GNSS** | SparkFun |
| **XPT2046_Touchscreen** | Paul Stoffregen |
| **DHT sensor library** | Adafruit |

---

### 🔧 TFT_eSPI Configuration

**Important!** After installing the TFT_eSPI library, you need to replace one file.
**If you downloaded the ready archive** — the file is already replaced, you can skip this step.

**If you installed libraries manually:**

1. Find the folder: `Documents/Arduino/libraries/TFT_eSPI/`
2. Delete the file `User_Setup.h`
3. Copy the file `User_Setup.h` from here:  
   👉 [Settings TFT_eSPI/User_Setup.h](Settings%20TFT_eSPI/User_Setup.h)

📖 **Detailed instructions:** [Open](Settings TFT_eSPI/Instructions)

---
### 4. Upload the firmware
- Download the `ESPBike.ino` file from the `firmware/` folder
- Open it in the Arduino IDE
- IF YOU HAVE A MORE ACCURATE DHT22 module installed instead of DHT11, you need to replace #define DHTTYPE DHT11 with #define DHTTYPE DHT22 at the beginning of the code.
- Connect the ESP32 to the computer
- Select **Tools → Board → ESP32 Dev Module**
- Select the correct **port**
- Click **Download**
- Press and hold the “boot” button on the board to switch the board to firmware mode. If the board does not switch to firmware mode, try forcing it into firmware mode by connecting the GPIO0 pin on the board to the GND pin using a regular jumper (a piece of wire).

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


## 🏁 Финальный результат

![Результат](Images/21929.jpg)

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
