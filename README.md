# Smart Hospital Management System (C Language)

A modular, console-based Hospital Management and Emergency Triage System written in C. The application handles real-time patient intake, priority queue sorting based on medical urgency, bed capacity tracking across hospital wards, itemized bill generation, and local file persistence.

---

##  Features

- **Patient Intake & Specialty Allocation:** Automated registration with daily departmental intake limits.
- **Emergency Priority Triage:** Dynamic patient queue prioritization (Critical, Urgent, Normal) using bubble sort algorithm across parallel arrays.
- **Ward Bed Allocation Matrix:** Real-time 2D grid display and management of bed occupancy per ward.
- **Automated Financial Calculations:** Itemized billing including triage surcharges, ward stay accommodation costs, and age-based concession discounts (<5 or >65 years).
- **Hospital Analytics & Reports:** Statistical breakdowns of patient urgency distributions, ward occupancy rates, gross revenue, and highest-paying accounts.
- **Data Persistence:** Automated load/save routines for patient records and bed allocation states using flat text files.

---

## 📁 Repository Structure

```text
├── src/
│   ├── main.c           # Program entry point and system menu loop
│   ├── patients.c       # Patient intake and registration routines
│   ├── priority.c       # Emergency triage sorting algorithms
│   ├── bed.c            # Ward bed matrix and allocation operations
│   ├── calculations.c   # Billing, surcharges, and discount logic
│   ├── analytics.c      # Statistical reports and summaries
│   ├── display.c        # Console display and formatted receipts
│   └── filehandling.c   # File reading and writing operations
├── include/
│   ├── config.h         # System parameters, limits, and pricing constants
│   ├── patients.h
│   ├── priority.h
│   ├── bed.h
│   ├── calculations.h
│   ├── analytics.h
│   ├── display.h
│   └── filehandling.h
├── data/
│   ├── patient_records.txt # Persistent storage for patient details
│   └── beds_status.txt     # Persistent storage for bed occupancy matrix
└── README.md



# Compile all source files
gcc -Wall *.c -o hospital_app

# Run the compiled executable
hospital_app.exe