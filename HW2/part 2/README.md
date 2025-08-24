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
This part implements a two-node Zigbee system that mimics a phone alarm:

- **Node A (Controller):**  
  - Reads an integer `t` (seconds) from the keypad.  
  - Starts a countdown timer locally.  
  - When `t` elapses, sends a Zigbee message `RING` to Node B.  
  - Handles buttons:  
    - **SNOOZE:** sends `SNOOZE`/`SILENCE` to Node B, waits **5 s**, then sends `RING` again.  
    - **STOP:** sends `STOP` to Node B and terminates the alarm.  
  - Prints the protocol and states to Serial: `SET t=...`, `COUNTDOWN`, `RING → sent`, `SNOOZE`, `STOP`, etc.

- **Node B (Alarm):**  
  - Waits for Zigbee commands.  
  - On `RING` → **buzzer ON** (continuous or patterned tone).  
  - On `SILENCE`/`SNOOZE`/`STOP` → **buzzer OFF**.  
  - Logs received commands to Serial for verification.

This exercise covers:
- Multi-node coordination over **Zigbee**.  
- Keypad input and **button-driven state machine** (Idle → Waiting → Ringing → Snooze/Stopped).  
- Clear serial logging for reproducibility.

---

## 🎥 Demonstration
You can watch the demo here:

[▶️ Watch HW2 Part 2 Demo](../videos/HW2_Part2.mp4)
