# Smart-car-accident-avoidance Robot

## 🚀 Project Overview
This project demonstrates an **autonomous accident avoidance robot** using **Arduino**. The robot utilizes **ultrasonic sensors** to detect obstacles and automatically navigate to prevent collisions. It alerts with a buzzer and LED indicators when an obstacle is detected.

## 📌 Features
- **Real-time obstacle detection** using ultrasonic sensors.
- **Automatic movement control** (forward and backward motion).
- **Buzzer and LED warnings** for obstacle detection.
- **Smooth motor transitions** to prevent sudden stops.
- **Efficient distance calculation** with optimized sensor readings.

## 🛠️ Components Used
- **Arduino Board**
- **Ultrasonic Sensors (HC-SR04)** (Front and Back)
- **Motor Driver (L298N or similar)**
- **DC Motors & Wheels**
- **Buzzer & LEDs**
- **Power Supply (Battery Pack)**

## 📄 Code Explanation
The code utilizes the **NewPing library** for handling ultrasonic sensors efficiently. The robot follows this logic:
1. **Measure distances** from front and back sensors.
2. **If an obstacle is detected at the front**, stop and move backward.
3. **If an obstacle is detected at the back**, stop and move forward.
4. **If no obstacles**, move forward normally.
5. **Buzzer & LED warnings** activate when obstacles are detected.

## 🖥️ Installation & Usage
### 🔹 1. Clone the Repository
```bash
git clone https://github.com/your-username/Car-Accident-Avoidance-Robot.git
cd Car-Accident-Avoidance-Robot
```

### 🔹 2. Install Dependencies
Make sure you have **Arduino IDE** installed.
- Install the **NewPing Library** in Arduino IDE.

### 🔹 3. Upload the Code to Arduino
- Connect the **Arduino board** to your computer.
- Open the `car_accident_avoidance.ino` file in **Arduino IDE**.
- Select the correct **board and COM port**.
- Click **Upload**.

### 🔹 4. Power Up the Robot
- Connect the **battery pack** to the Arduino.
- The robot will start moving automatically.

## 📸 Demonstration
![Robot Image](https://your-image-url.com)

## 🏆 Future Enhancements
- Implement **speed control** based on obstacle distance.
- Add **AI-based decision-making** for better navigation.
- Integrate **GPS for outdoor movement**.

## 🤝 Contribution
Want to improve this project? Feel free to:
- **Fork the repo**
- **Make changes**
- **Submit a Pull Request**

## 📜 License
This project is **open-source** under the **MIT License**.

## 📧 Contact
For any inquiries, reach out at: **emmynono2013@gmail.com**

---
🔹 **Developed by:** Ngendahimana Emmanuel 🚀

