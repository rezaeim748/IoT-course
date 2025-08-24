# HW2 – Part 1

## 📌 Question
Set up a system with two Zigbee nodes connected to their microcontrollers. In this system:
- The **first node** sends a **"Hello"** message to the second node.  
- The **second node** randomly responds with either **"Hi"** or **"Hello"**.  
- After receiving the response, the first node checks the message:  
  - If the response is **"Hi"**, a **green LED** turns on for **3 seconds**.  
  - If the response is **"Hello"**, a **buzzer** is activated and a **red LED** lights up.  
- The system’s operation and the exchanged messages should be displayed in the **Serial Monitor**.  

---

## 📝 Description
This part demonstrates a **simple communication protocol** using Zigbee between two microcontrollers:

- **Node A (Sender):**  
  - Transmits `"Hello"` to Node B.  
  - Waits for the response.  
  - If it receives `"Hi"`, turns on the **green LED** for 3 seconds.  
  - If it receives `"Hello"`, turns on the **red LED** and activates the **buzzer**.  
  - Prints all actions (sent messages, received messages, and LED/buzzer status) on the Serial Monitor.  

- **Node B (Responder):**  
  - Listens for the `"Hello"` message.  
  - Randomly chooses a reply: `"Hi"` or `"Hello"`.  
  - Sends it back to Node A.  
  - Also logs the message exchange on the Serial Monitor.  

This exercise introduces:  
- Zigbee wireless communication between Arduino microcontrollers.  
- Simple protocol handling and conditional logic.  
- Using LEDs and buzzers as feedback signals.  
- Logging message exchanges for debugging and verification.  

---

## 🎥 Demonstration
You can watch the demo here:

[▶️ Watch HW2 Part 1 Demo](../videos/HW2_Part1.mp4)
