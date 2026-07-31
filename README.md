# 📌 Microphone!

> A simple Microphone that you can build to record your Audio Data!

---

## 📖 Table of Contents

* 🚀 [Features](#-features)
* 🛒 [Bill of Materials](#-bill-of-materials)
* 🛠️ [Steps to Reproduce](#️-steps-to-reproduce)
* 💻 [Usage](#-usage)

---

## 🚀 Features

An INMP441 Microphone Module that is able to capture Audio Data (vibrations in the air, or sound)
A Micro SD Card as well as an SD Card reader that stores that audio data
LEDs to let you know if your recording or not (green = yes, red = no), and a button to press stop or start to record.

---

## 🛒 Bill of Materials

| Item | Quantity | Description / Component with Link | Approx. Unit Cost |
| :--- | :---: | :--- | :---: |
| 1 | 1 | [ESP32](https://www.alibaba.com/product-detail/Esp32-Development-Board-Wifi-Ultra-low_1601030060154.html?spm=a2700.prosearch.normal_offer.d_title.733a67afcJ84oK&priceId=3cf063b523884a038f0c1823b3017da3) | $3.00 |
| 2 | 1 | [BreadBoard](https://www.alibaba.com/product-detail/Stock-New-MB-102-830-Point_62474400468.html?spm=a2700.prosearch.normal_offer.d_title.603467afhc1Apg&selectedCarrierCode=SEMI_MANAGED_STANDARD%40%40STANDARD&priceId=e492a8e6a65448d5a1d6abf75ea7d892) | $0.65 |
| 3 | 1 | [INMP441](https://www.alibaba.com/product-detail/INMP441-Omni-directional-MEMS-Microphone-Module_1601724989762.html?spm=a2700.prosearch.normal_offer.d_title.2ed267afZyfFCn&priceId=7a26cbf665ef4a119280b80428e141b3) | $1.00 |
| 4 | 1 | [Push Button](https://www.alibaba.com/product-detail/6-6-4-3-5-6_1601833865319.html?spm=a2700.prosearch.normal_offer.d_title.6eaa67af4eUNfS&priceId=667d9cdd7bb7455e9871e26a3fd161b2) | $0.05 |
| 5 | 2 | [LEDS of different color](https://www.alibaba.com/product-detail/China-Manufacturer-Red-Green-Blue-Yellow_1600947326535.html) | $0.10 |
| 6 | 2 | [220 Ohm Resistors](https://www.alibaba.com/product-detail/Fuse-Resistor-2W-1-100R-150_1600789699976.html?spm=a2700.prosearch.normal_offer.d_title.3e1367afspSEj6&selectedCarrierCode=SEMI_MANAGED_STANDARD%40%40STANDARD&priceId=8e6c4a268a5c41369eeee7eb861f39ca) | $0.04 |
| 7 | 1 | [SD Card Reader](https://www.alibaba.com/product-detail/Micro-SD-Card-Module-TF-Card_1601463910540.html?spm=a2700.prosearch.normal_offer.d_title.14c367afjk1aiV&priceId=25debad767474e719ee8c87758902714) | $0.30 |
| 8 | 1 | [Micro SD Card](https://www.alibaba.com/product-detail/Shine-True-Custom-Mini-SD-Memory_1601595206889.html?spm=a2700.prosearch.normal_offer.d_title.376567afGpLVhv&selectedCarrierCode=SEMI_MANAGED_STANDARD%40%40STANDARD&priceId=12dcffaac9154ae1a2794e56279c8a5e) | $1.70 |
| 9 | as needed (about 14-17) | [Wires](https://www.alibaba.com/product-detail/TZT-Hot-Sell-140pcs-U-Shape_1601466408418.html?spm=a2700.prosearch.normal_offer.d_title.27e067afdBlNmu&priceId=dec8cd697f8a4587b4fe52e36af310c9) | $0.65 |
| **Total** | | | **~$7.40 (not including shipping or anything)** |

---

## 🛠️ Steps to Reproduce

### 1. Assembly
**Soldering:** [You might have to solder INMP441 pins and ESP32 pins onto itself, so thats the first step.]
**Wiring:** [You can check out the pinOut here:] <img width="1640" height="1082" alt="Screenshot 2026-07-31 105242" src="https://github.com/user-attachments/assets/af708962-f8ca-4338-abae-3b9d49559cf4" /> 
