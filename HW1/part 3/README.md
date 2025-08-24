# HW1 – Part 3

## 📌 Question
Design and implement a countdown timer system with the following features:
1. A keypad is used for entering the countdown value.  
2. A start button begins the countdown.  
3. The remaining time is shown on a 7-segment display.  
4. When the countdown reaches zero, a buzzer alarm activates.  
5. The countdown can be restarted with new input from the keypad.  
6. An LDR sensor turns off the 7-segment display in bright environments to save power.  

---

## 📝 Description
In this part, an **Arduino-based countdown timer** is implemented.  
- The user enters a number (seconds) via a keypad.  
- When the start button is pressed, the value is displayed on a **7-segment display** and begins decreasing every second.  
- Once the countdown reaches zero, a **buzzer** is triggered to indicate the end.  
- The system resets if the user enters a new value.  
- Additionally, an **LDR sensor** is used to measure ambient light. If the surrounding light level is high, the Arduino automatically turns off the 7-segment display to reduce power consumption.  

This exercise introduces:
- Using a keypad for numeric input.  
- Displaying values on a 7-segment module.  
- Implementing timer logic in Arduino.  
- Integrating sensors for adaptive behavior (LDR for display control).  

---

## 🎥 Demonstration
You can watch the demo here:

[▶️ Watch Part 3 Demo](../videos/HW1_Part3.mp4)
