# HW3 – Part 1

## 📌 Question
Implement a **CoAP-based communication system** consisting of one **server** and one **client** to demonstrate the basic functionality of the CoAP protocol in IoT environments.

**Server functions:**
- Expose a resource `/alarm` over CoAP.  
- Respond to `POST` requests to update the alarm state (`ON` or `OFF`).  
- Respond to `GET` requests to return the current alarm state.  

**Client functions:**
- Randomly generate an alarm state (`ON` or `OFF`).  
- Send a `POST` request to update the alarm state on the server.  
- Send a `GET` request to retrieve and display the current state.  

**Rules:**
- Use the `aiocoap` Python library.  
- The client must print both request and response results.  
- The system must run locally on `localhost` or `127.0.0.1` with port `5683`.  
- Communication follows the CoAP message exchange model (request–response over UDP).  

---

## 📝 Description
This project demonstrates how to establish communication between two IoT components using the **CoAP (Constrained Application Protocol)**.  

- The **server** defines a CoAP resource named `/alarm`, which supports both `POST` and `GET` methods.  
  - The `POST` method updates the internal state of the alarm (turning it `ON` or `OFF`).  
  - The `GET` method returns the current state.  
- The **client** acts as an IoT node that:
  - Randomly chooses an alarm state.  
  - Sends it to the server via `POST`.  
  - Fetches the updated state from the server using `GET`.  
- The messages are exchanged over **UDP** (default CoAP transport).  
- This simulates an IoT alarm system where a sensor node (client) reports its status to a control hub (server).

---

## 🎥 Demonstration
https://github.com/rezaeim748/IoT-course/blob/main/HW3/videos/HW3_Part1.mp4
