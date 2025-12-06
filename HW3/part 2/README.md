# HW3 – Part 2

## 📌 Question
Implement a **REST API–based hospital management system** using the **HTTP protocol**.  

The system consists of two main components:
1. **Hospital Bed Management**
2. **Blood Bank Management**

It must provide separate endpoints to manage hospital beds, admit/discharge patients, track empty beds, manage blood storage, and detect critical blood levels.

---

## 📝 Description
This project implements a **FastAPI-based HTTP server** to simulate the operation of a smart hospital system.  
The application provides RESTful endpoints for both **reception** (bed management) and **blood bank** operations.

### 🏥 Hospital Reception APIs
| Endpoint | Method | Description |
|-----------|---------|-------------|
| `/beds` | `POST` | Set the total number of hospital beds. Takes `{ "total_beds": int }` and returns `true` if successful. |
| `/admit_patient` | `POST` | Admit a new patient if a bed is available. Takes `{ "patient_name": str }`. |
| `/empty_beds` | `GET` | Returns the number of currently available (empty) beds. |
| `/discharge_patient` | `DELETE` | Discharge a patient and free their bed. Takes `{ "patient_name": str }`. |

### 🩸 Blood Bank APIs
| Endpoint | Method | Description |
|-----------|---------|-------------|
| `/set_bank` | `POST` | Initialize a blood group’s stock with a given amount. |
| `/add_to_bank` | `PUT` | Add or remove blood from a group (positive or negative value). |
| `/add_patient` | `POST` | Admit a patient with blood requirements. Checks if the bank can supply enough blood for the hospitalization period. |
| `/is_critical_mode_on` | `GET` | Returns `true` if the total available blood is below the safety threshold (1 L). |

### 🧠 Logic Summary
- Blood compatibility rules are implemented:  
  - **O** can receive from **A** and **B**.  
  - **AB** can receive from all groups.  
- The system automatically enters **critical mode** when total blood in the bank is less than 1 L.  
- Adding new blood via `/add_to_bank` automatically checks if the hospital exits critical mode.

---

## 🧪 Example Test Sequence
1. **Initialize beds**
   ```json
   { "total_beds": 10 }
   ```
2. **Admit a patient**
   ```json
   { "patient_name": "Ali" }
   ```
3. **Set blood bank for group A**
   ```json
   { "blood_group": "A", "blood_amount": 10 }
   ```
4. **Add patient with blood needs**
   ```json
   {
     "patient_name": "Sara",
     "blood_group": "A",
     "blood_needed_per_day": 2,
     "days_hospitalized": 3
   }
   ```
5. **Check critical mode**
   → returns `false` unless stock < 1 L.

---

