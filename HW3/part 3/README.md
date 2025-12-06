# HW3 – Part 3

## 📌 Question
Implement a **sensor-based IoT monitoring system** using **MQTT, Node-RED, InfluxDB, and a dashboard interface**.  

The system must:
1. Collect real-time sensor data (temperature, humidity, pressure, and wind speed).  
2. Display live readings on a Node-RED dashboard.  
3. Store all data in an InfluxDB database for historical analysis.

---

## 📝 Description
This project implements a **complete IoT data pipeline** integrating **MQTT messaging**, **Node-RED dataflow**, and **InfluxDB storage** to monitor environmental parameters.

### ⚙️ System Components
| Component | Role | Details |
|------------|------|---------|
| **MQTT Broker (Mosquitto)** | Message hub | Handles communication between sensor publishers and Node-RED subscribers. |
| **Node-RED** | Workflow engine | Subscribes to sensor topics, visualizes live data on dashboard gauges / charts, and forwards it to InfluxDB. |
| **InfluxDB v1.8** | Time-series database | Stores historical measurements for each sensor type. |
| **Node-RED Dashboard** | UI layer | Provides real-time visualization of temperature, humidity, pressure, and wind speed. |

---

## 🌡️ Sensors Simulation
This project includes **virtual sensors** that generate synthetic environmental data and publish it to MQTT topics.  
Each sensor creates **randomized values** within realistic ranges and sends updates periodically.

| Sensor | MQTT Topic | Data Range | Unit | Description |
|---------|-------------|------------|------|--------------|
| 🌡️ **Temperature Sensor** | `topic/sensor1/temperature` | 20 – 35 | °C | Simulates ambient temperature changes. |
| 💧 **Humidity Sensor** | `topic/sensor1/humidity` | 40 – 60 | % | Generates random relative humidity readings. |
| ⛅ **Pressure Sensor** | `topic/sensor2/pressure` | 900 – 1100 | hPa | Mimics atmospheric pressure values. |
| 🌬️ **Wind Speed Sensor** | `topic/sensor3/wind_speed` | 0 – 15 | m/s | Represents varying wind speed conditions. |

Each topic is subscribed to by a **Node-RED MQTT In** node.

---

## 🧠 Logic Summary
1. Each sensor publishes data to its dedicated MQTT topic.  
2. **Node-RED** receives these messages through MQTT In nodes.  
3. Data are simultaneously:  
   - Displayed on **dashboard gauges** and **line charts**, and  
   - Stored into **InfluxDB database `sensors`** using InfluxDB Out nodes.  
4. InfluxDB automatically creates measurements:
   - `temperature`
   - `humidity`
   - `pressure`
   - `wind_speed`

---

## 💾 InfluxDB Configuration
| Parameter | Value |
|------------|--------|
| **Host** | `127.0.0.1` |
| **Port** | `8086` |
| **Version** | `1.x` |
| **Database Name** | `sensors` |
| **Measurements** | temperature, humidity, pressure, wind_speed |

Example query:
```sql
USE sensors
SELECT * FROM temperature LIMIT 5
```

---

## 🧩 Tools Used
- Node-RED v3.x  
- Eclipse Mosquitto MQTT Broker  
- InfluxDB v1.8  
- Node-RED Dashboard nodes  

---

## 🎥 Demonstration
https://github.com/user-attachments/assets/4c89bdc1-c90f-41e8-bbf1-d834e448528b
