# 💧 Water Flow Measurement Using Arduino

A practical and low-cost water flow monitoring system using the **YF-S201 Hall Effect sensor** and **Arduino Uno**. This project calculates real-time **flow rate** and **total volume** of water, displaying the data on a **16x2 LCD**. Ideal for applications in smart homes, agriculture, industry, and environmental monitoring.

---

## 🌟 Features

- **Real-Time Monitoring**: Measures flow rate in L/min and total volume in Litres  
- **LCD Display**: 16x2 screen shows current rate and total volume  
- **Low-Cost Components**: Utilizes affordable and readily available parts  
- **Interrupt-Based Sensing**: Accurate pulse counting using hardware interrupts  
- **Overflow Protection**: Ignores pulses when sensor is inactive  
- **User Feedback**: Serial Monitor outputs for debugging and tracking

---

## 🔧 Hardware Components

| Component             | Quantity | Price (INR) |
|----------------------|----------|-------------|
| Arduino Uno          | 1        | ₹450        |
| YF-S201 Flow Sensor  | 1        | ₹180        |
| 16x2 LCD Display     | 1        | ₹80        |
| Potentiometer        | 1        | ₹20         |
| Jumper Wires         | 1 set    | ₹40         |
| Breadboard           | 1        | ₹80        |

---

## ⚙️ Working Principle

The YF-S201 sensor generates pulses based on the flow of water. Each pulse corresponds to a specific volume.  
The Arduino reads these pulses and calculates:
- **Flow rate (L/min)** = Pulses per second / 7.5  
- **Total Volume (L)** = Accumulated flow over time

---

## 💻 Arduino Code Overview

```cpp
attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING); // Setup Interrupt
l_minute = (flow_frequency / 7.5);   // Flow rate in L/min
vol += (l_minute / 60);              // Accumulate volume in Litres
```

LCD output:
```
Rate: 1.23 L/m
Vol: 4.56 L
```

---

## 🧪 Test and Use Cases

- ✔️ Measuring household water usage
- ✔️ Irrigation monitoring
- ✔️ Leak detection systems
- ✔️ DIY smart water meters

---

## 📝 Notes

- Reset is manual (via Arduino reset button)
- Accuracy depends on sensor calibration and steady flow
- Can be extended for **data logging**, **wireless alerts**, or **IoT integration**

---

## 📦 Future Enhancements

- Add SD card logging  
- Integrate with Wi-Fi/Bluetooth for remote monitoring  
- Real-time web dashboard or app interface  

---

## 🤝 Contributing

Open to contributions! Fork the repo, create a branch, and submit a pull request.

---

## 📄 License

This project is licensed under the **MIT License** – free to use and modify.
