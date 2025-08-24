# HW2 – Part 2

## 📌 Question
Simulate a **mobile phone alarm** using a **buzzer** over a Zigbee network with **two nodes**:

- **Controller node (Node A):**  
  - Receives the alarm **time (in seconds)** from a **keypad** at program start (how many seconds later the alarm should ring).  
  - Has two physical buttons: **Snooze** and **Stop**.  
- **Alarm node (Node B):**  
  - Activates the **buzzer** when instructed by the controller.  

**Behavior**
- After Node A gets the input time, it counts down and, when the time is reached, **commands Node B** to turn the **buzzer ON**.  
- Pressing **Snooze** on Node A: stop the buzzer immediately and **delay the alarm for 5 seconds**, then ring again (buzzer ON).  
- Pressing **Stop** on Node A: **turn the buzzer OFF** and **end** the alarm cycle.  
- All actions (entered time, countdown start, Zigbee commands, Snooze/Stop events, buzzer ON/OFF) must be shown on the **Serial Monitor**.  

**Note:** The **keypad**, **Snooze**, and **Stop** buttons are **only on the controller node**. The alarm node only controls the buzzer based on Zigbee commands.

---

## 📝 Description
- Node A reads a number `t` (seconds) from the keypad and starts a timer.  
- When the timer finishes, Node A tells Node B to **ring**.  
- **Snooze**: stop the ring now and ring again after **5 s**.  
- **Stop**: stop the ring and finish.  
- Both nodes print what they do to the Serial Monitor (sent/received commands and buzzer/btn states).

---

## 🎥 Demonstration
https://github.com/user-attachments/assets/4ef7838b-9a6e-4907-839b-b04836f1c9a4
