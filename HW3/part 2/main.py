from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI()

# Data structures to store hospital and blood bank information
hospital_beds = 0
empty_beds = 0
patients = []

blood_bank = {}

class BloodRequest(BaseModel):
    patient_name: str
    blood_group: str
    blood_needed_per_day: int
    days_hospitalized: int

class BedRequest(BaseModel):
    total_beds: int

class BloodBankRequest(BaseModel):
    blood_group: str
    blood_amount: int

class AdmitPatientRequest(BaseModel):
    patient_name: str

class DeletePatientRequest(BaseModel):
    patient_name: str


# Reception API Ports

@app.post("/beds", response_model=bool)
def set_total_beds(bed_request: BedRequest):
    global hospital_beds, empty_beds
    hospital_beds = bed_request.total_beds
    empty_beds = hospital_beds
    return True

@app.post("/admit_patient", response_model=bool)
def admit_patient(request: AdmitPatientRequest):
    global empty_beds, patients

    if empty_beds > 0:
        patients.append(request.patient_name)
        empty_beds -= 1
        return True
    else:
        return False

@app.get("/empty_beds")
def get_empty_beds():
    global empty_beds
    return empty_beds

@app.delete("/discharge_patient", response_model=bool)
def discharge_patient(request: AdmitPatientRequest):
    global empty_beds, patients

    if request.patient_name in patients:
        patients.remove(request.patient_name)
        empty_beds += 1
        return True
    else:
        return False

# Blood Bank API Ports

@app.post("/set_bank", response_model=bool)
def set_blood_bank(blood_bank_request: BloodBankRequest):
    blood_group = blood_bank_request.blood_group
    blood_amount = blood_bank_request.blood_amount
    blood_bank[blood_group] = blood_amount
    return True

@app.put("/add_to_bank", response_model=bool)
def add_to_blood_bank(blood_bank_request: BloodBankRequest):
    global blood_bank

    blood_group = blood_bank_request.blood_group
    blood_amount = blood_bank_request.blood_amount

    if blood_group in blood_bank:
        blood_bank[blood_group] += blood_amount
        # Check if we are out of critical mode after adding to the bank
        check_critical_mode()
        return True
    else:
        raise HTTPException(status_code=400, detail=f"Blood group {blood_group} not found in the bank.")

@app.post("/add_patient", response_model=bool)
def add_patient(blood_request: BloodRequest):
    global blood_bank, patients

    patient_blood_group = blood_request.blood_group
    blood_needed_per_day = blood_request.blood_needed_per_day
    days_hospitalized = blood_request.days_hospitalized

    if patient_blood_group not in blood_bank:
        raise HTTPException(status_code=400, detail=f"Blood group {patient_blood_group} not found in the bank.")

    # Calculate the total blood needed for the entire hospital stay
    total_blood_needed = blood_needed_per_day * days_hospitalized

    # Check if the bank can supply the blood for the patient
    if can_supply_blood(patient_blood_group, total_blood_needed):
        patients.append(blood_request.patient_name)
        deduct_blood_from_bank(patient_blood_group, total_blood_needed)
        return True
    else:
        # Check if we are in a critical mode and can still supply for at least 1 day
        if(can_supply_blood(patient_blood_group, blood_needed_per_day)):
            patients.append(blood_request.patient_name)
            deduct_blood_from_bank(patient_blood_group, total_blood_needed)
            return True
        return False

def can_supply_blood(patient_blood_group, total_blood_needed):
    global blood_bank

    # Special case for blood group O, which can receive from A and B
    if patient_blood_group == 'O':
        return blood_bank.get('A', 0) + blood_bank.get('B', 0) >= total_blood_needed

    # Special case for blood group AB, which can receive from all
    if patient_blood_group == 'AB':
        return sum(blood_bank.values()) >= total_blood_needed

    # For other blood groups, check the available amount
    return blood_bank.get(patient_blood_group, 0) >= total_blood_needed

def deduct_blood_from_bank(patient_blood_group, total_blood_needed):
    global blood_bank

    # Deduct the blood from the bank based on the patient's blood group
    if patient_blood_group == 'O':
        # Deduct from both A and B
        blood_bank['A'] -= total_blood_needed // 2
        blood_bank['B'] -= total_blood_needed // 2
    elif patient_blood_group == 'AB':
        # Deduct from all blood groups
        for blood_group in blood_bank:
            blood_bank[blood_group] -= total_blood_needed // len(blood_bank)
    else:
        # Deduct from the specific blood group
        blood_bank[patient_blood_group] -= total_blood_needed

@app.get("/is_critical_mode_on", response_model=bool)
def is_critical_mode_on():
    return check_critical_mode()

def check_critical_mode():
    global blood_bank
    total_blood = sum(blood_bank.values())
    if total_blood < 1:
        return True
    return False

if __name__ == "__main__":
    import uvicorn

    uvicorn.run(app, host="127.0.0.1", port=8000)
