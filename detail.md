## Fleet Management System

## Overview
A console-based Fleet Management System built in C++ using 
Object Oriented Programming concepts. This system helps 
manage a fleet of vehicles along with their assigned 
employees, supporting full CRUD operations with file-based 
data persistence.

---

## Features
- Add new vehicles to the fleet
- Display complete fleet with all details
- Edit existing vehicle information
- Delete vehicles from the fleet
- Assign employees to vehicles
- Search vehicles by license plate
- Data saved automatically to file (fleet.dat)
- Data loads automatically on startup

---

## Vehicle Information Managed
| Field | Description |
|---|---|
| License Plate | Unique vehicle identifier |
| Name | Vehicle name |
| Model | Vehicle model |
| Color | Vehicle color |
| Year | Manufacturing year |
| Assigned Employee | Employee name |
| Employee CNIC | Employee CNIC number |
| Employee Contact | Employee contact number |

---

## Menu Options

========================================
Fleet Management System

Add Vehicle
Display Fleet
Edit Vehicle
Delete Vehicle
Assign Employee
Search Vehicle
Exit
========================================

---

## OOP Concepts Used
- **Struct:** Vehicle structure with all attributes
- **Vector:** Dynamic fleet storage using STL vector
- **File Handling:** Save and load fleet data using fstream
- **Lambda Functions:** Used in search and find operations
- **Algorithm Library:** find_if for vehicle searching

---

## Functions
| Function | Description |
|---|---|
| addVehicle() | Adds new vehicle to fleet |
| displayFleet() | Shows all vehicles in table format |
| editVehicle() | Edit any field of existing vehicle |
| deleteVehicle() | Remove vehicle by license plate |
| assignEmployee() | Assign employee to a vehicle |
| searchVehicle() | Search vehicle by license plate |
| saveFleet() | Save fleet data to fleet.dat file |
| loadFleet() | Load fleet data from fleet.dat file |

---

## Data Persistence
- All fleet data is saved in **fleet.dat** file
- Data is automatically loaded when program starts
- Data is automatically saved after every change
- No data is lost when program is closed

---

## Technologies Used
- **Language:** C++
- **Concepts:** OOP, Structs, File Handling
- **Libraries:** iostream, fstream, vector, 
  string, iomanip, algorithm
- **IDE:** Dev C++ / Visual Studio Code

---

## How to Run
1. Open project in Dev C++ or Visual Studio Code
2. Compile the file:

g++ fleet.cpp -o fleet

3. Run the program:

./fleet

4. Use the menu to manage your fleet!

---

## Input Validation
- License plate cannot be empty
- Model cannot be empty
- Invalid inputs are caught and user is notified

---

## Contact
Taskeen Shoukat 
GitHub: github.com/taskeenshoukat51-cmd 
Email: taskeenshoukat23@gmail.com  
