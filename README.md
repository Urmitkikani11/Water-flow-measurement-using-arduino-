# 💧 Water Flow Measurement Using Arduino

A cost-effective and accurate water flow monitoring system using the **YF-S201 Hall Effect sensor** and **Arduino Uno**. This project calculates the real-time **flow rate** and **total volume** of water, displaying the data on a **16x2 LCD screen**. Ideal for smart homes, precision irrigation, industrial automation, and environmental monitoring applications.

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

---

## 🌟 Key Features

-  **Real-Time Monitoring** – Displays both flow rate (L/min) and total volume (Litres)
-  **LCD Display** – User-friendly 16x2 I2C interface for live data
-  **Affordable Components** – Built with low-cost and easily available parts
-  **Interrupt-Based Measurement** – Reliable and precise pulse counting using hardware interrupts
-  **Noise Filtering** – Ignores sensor spikes when flow is inactive
-  **Debugging Support** – Serial monitor output for real-time feedback

---

## 🔩 Hardware Requirements

| Component             | Quantity | Approx. Price (INR) |
|----------------------|----------|----------------------|
| Arduino Uno          | 1        | ₹450                 |
| YF-S201 Flow Sensor  | 1        | ₹180                 |
| 16x2 LCD Display     | 1        | ₹80                  |
| Potentiometer        | 1        | ₹20                  |
| Jumper Wires         | 1 Set    | ₹40                  |
| Breadboard           | 1        | ₹80                  |

---

## ⚙️ How It Works

The YF-S201 flow sensor produces pulses as water flows through it. These pulses are directly proportional to the flow rate.

- **Flow Rate (L/min)** = `Pulse frequency ÷ 7.5`
- **Total Volume (Litres)** = Accumulated flow rate over time

The Arduino captures pulse frequency using an **interrupt pin** and updates the flow and volume in real time on the LCD display.

---

## 💻 Sample Code Snippet

```cpp
attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING); // Setup interrupt on pulse
l_minute = (flow_frequency / 7.5);   // Calculate flow rate in L/min
vol += (l_minute / 60);              // Add flow to total volume every second
```

### 📟 LCD Output

```
Rate: 1.23 L/min
Vol : 4.56 L
```

---

## 🧪 Example Applications

-  **Smart Homes** – Monitor water usage in real time
-  **Agriculture** – Optimize irrigation efficiency
-  **Leak Detection** – Detect unexpected flow for early warning
-  **DIY Smart Water Meters** – Build custom meters for usage tracking

---

## 📘 Project Files

- 📄 [Project Report (PDF)](./Report/Water_Flow_Measurement%20By%20Urmit%20and%20Harshvardhan.pdf)
- 💾 [Arduino Source Code](./Code/Arduino%20Code.ino)

---

## 📝 Notes

- Resetting the system requires a manual press of the Arduino reset button.
- Accuracy depends on:
  - Steady water flow
  - Proper calibration (check sensor datasheet)
- Extendable with:
  -  SD card for data logging
  -  Wireless modules (Wi-Fi/Bluetooth)
  -  Cloud integration and dashboard display

---

## 🔮 Future Improvements

-  **Data Logging** – Save usage logs to an SD card
-  **Remote Monitoring** – Wi-Fi or Bluetooth module support
-  **Mobile Interface** – Control and view data via app or web dashboard

---

## 🤝 Contribution

Contributions are welcome!  
If you'd like to improve this project, feel free to fork the repository, create a new branch, and submit a pull request.

---

## 📩 Contact

For questions, suggestions, or collaboration:  [Urmitkikani1184@gmail.com](mailto:Urmitkikani1184@gmail.com)

---

## 📄 License

This project is licensed under the [MIT License](./LICENSE) – free to use, modify, and distribute for personal or academic purposes.
