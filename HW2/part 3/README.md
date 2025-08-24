# HW2 – Part 3

## 📌 Question
Set up a smart blind system to control the amount of light entering a room.  
- A **light sensor (L)** outside the window measures ambient light (0–100).  
- The **user’s desired light level (X)** is received through a **slider** in the **Blynk application** (0–100).  
- The system compares L and X and calculates the slat angle (A).  
- The slat angle A is mapped to the servo motor range **0–90°**.  
- If **L < X**, the blinds must be fully open.  
- The blinds can also be fully raised or lowered using another slider in the Blynk app.  
- All values (L, X, A) and states (open/closed) must be shown in the Serial Monitor.  

---

## 📝 Description
- The Arduino reads the **ambient light level (L)** from the sensor.  
- The **user preference (X)** is received from a Blynk slider.  
- The difference between L and X is mapped to a servo angle (0–90°) to adjust blind slats.  
- If ambient light is lower than required, the system forces blinds fully open.  
- A second servo motor, controlled by another Blynk slider, raises or lowers the blinds completely.  
- The Serial Monitor displays the sensor reading (L), user input (X), calculated angle (A), and blind position.  

---

## 🎥 Demonstration
https://github.com/user-attachments/assets/34d8ef47-f0b8-4cdd-9c09-04102ca97ce5
