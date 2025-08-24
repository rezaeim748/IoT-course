# HW1 – Part 2

## 📌 Question
Control the brightness of a lamp (LED) based on ambient light using an LDR sensor:
- Connect an LDR sensor to Arduino to measure light intensity.
- Use an LED to simulate a city streetlight.
- Adjust the LED brightness with PWM: as light increases, LED brightness decreases.
- When the lamp is completely off, activate a buzzer as an indicator.

---

## 📝 Description
In this part, an **LDR (Light Dependent Resistor)** is used to sense the ambient light level.  
The Arduino reads the LDR value through an analog pin and maps it to control the LED brightness using **PWM (Pulse Width Modulation)**.

- If the environment is **dark**, the LED brightness increases.  
- If the environment is **bright**, the LED brightness decreases.  
- When the LED brightness reaches zero (completely off), the **buzzer** activates as a signal.

This exercise introduces:
- Reading sensor values from an analog input.  
- Mapping sensor values to PWM output for brightness control.  
- Using a buzzer for alerting specific conditions.

---

## 🎥 Demonstration
https://github.com/user-attachments/assets/25b3589d-1d7e-4f17-8b01-2377e0cc0c9f

