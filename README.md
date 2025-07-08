# Smart Lighting System using STM32F401 Black Pill

An embedded system project that enables automated lighting based on real-time sensor data, designed to improve energy efficiency, user comfort, and sustainability using STM32F401 microcontroller.

---


## 🎯 Project Goal

To design and implement an **automated smart lighting system** that adjusts its behavior based on environmental inputs like motion, light intensity, and object proximity, ensuring optimal lighting with minimal energy waste.

---

## 🔧 Key Features

- 📡 Motion detection with PIR sensor  
- 🌤 Ambient light detection with LDR (Analog + Digital)  
- 📏 Proximity-based brightness control with Ultrasonic sensor  
- 🔋 Energy-efficient adaptive lighting  
- 🔘 Manual override for user control  
- 🔄 Real-time feedback via LED indicators  

---

## 🧠 Microcontroller Overview

**STM32F401 Black Pill**

- ARM Cortex-M4 CPU (84 MHz)  
- 40 GPIO pins  
- 3 ADC channels  
- Controls sensor input and LED output logic

---

## 🧰 Sensors & Components

| Sensor/Component   | Functionality |
|--------------------|---------------|
| **PIR Sensor**     | Detects motion, turns light on/off based on presence |
| **LDR (Analog/Digital)** | Measures ambient light to decide if artificial lighting is needed |
| **Ultrasonic Sensor** | Detects user/object proximity and adjusts brightness |
| **Bluetooth Sensor** | *(To be implemented)* Future wireless control |
| **LED Indicators** | Provide visual feedback based on sensor input |

---

## 🔌 Sensor-to-Pin Mapping (STM32F401)

| Pin  | Function                                 |
|------|------------------------------------------|
| PA1  | Digital LDR Input (Light On/Off)         |
| PA2  | PIR LED Output (Motion detected)         |
| PA3  | PIR Sensor Input                         |
| PA4  | Ultrasonic Trigger Output                |
| PA5  | Ultrasonic Echo Input                    |
| PA6  | LDR LED Output (Light level indicator)   |
| PA7  | Ultrasonic LED Output (Proximity alert)  |

---

## 🧪 Use Case Scenario

**Scenario:** Entering a dim room  
1. PIR detects motion → system becomes active  
2. LDR checks ambient light → if low, lights turn on  
3. Ultrasonic measures proximity → adjusts brightness  
4. LEDs provide visual feedback for each detection  

---

## 🌟 Benefits

- **⚡ Energy Efficiency:** Lights only operate when necessary  
- **🧘‍♂️ User Comfort:** Brightness adapts to real-world conditions  
- **🌱 Sustainability:** Reduces overall energy usage  
- **🤖 Automation:** Fully sensor-driven operation with minimal user input  
- **🛠 Manual Override:** For custom control if needed  

---

## ✅ Conclusion

The **Smart Lighting System** provides an innovative and intelligent solution to optimize lighting using embedded technologies. By leveraging the STM32F401 Black Pill and a variety of sensors, it ensures a responsive, efficient, and eco-friendly lighting experience.

---
