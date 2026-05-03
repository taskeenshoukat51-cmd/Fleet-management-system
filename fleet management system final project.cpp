#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Vehicle {
    string licensePlate;
    string name;
    string model;
    string color;
    int year;
    string assignedEmployee;
    string employeeCNIC;
    string employeeContact;
};

vector<Vehicle> fleet;

bool isValidLicensePlate(const string& licensePlate) {
    return !licensePlate.empty();
}

bool isValidModel(const string& model) {
    return !model.empty();
}

void addVehicle() {
    Vehicle v;
    cout << "\nEnter license plate: ";
    cin >> v.licensePlate;
    if (!isValidLicensePlate(v.licensePlate)) {
        cout << "Invalid license plate format.\n";
        return;
    }
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, v.name);
    cout << "Enter model: ";
    cin >> v.model;
    if (!isValidModel(v.model)) {
        cout << "Invalid model format.\n";
        return;
    }
    cout << "Enter color: ";
    cin >> v.color;
    cout << "Enter year: ";
    cin >> v.year;
    v.assignedEmployee = "";
    v.employeeCNIC = "";
    v.employeeContact = "";
    fleet.push_back(v);
    cout << "\nVehicle added successfully!\n";
}

void displayFleet() {
    if (fleet.empty()) {
        cout << "\nNo vehicles in the fleet.\n";
        return;
    }
    cout << left << setw(15) << "License Plate" << setw(15) << "Name" << setw(15) << "Model" << setw(10) << "Color" << setw(10) << "Year" << setw(20) << "Assigned Employee" << setw(20) << "Employee CNIC" << setw(20) << "Employee Contact" << '\n';
    for (const auto& v : fleet) {
        cout << left << setw(15) << v.licensePlate << setw(15) << v.name << setw(15) << v.model << setw(10) << v.color << setw(10) << v.year << setw(20) << v.assignedEmployee << setw(20) << v.employeeCNIC << setw(20) << v.employeeContact << '\n';
    }
    cout << "\nTotal number of vehicles: " << fleet.size() << '\n';
}

void saveFleet() {
    ofstream outFile("fleet.dat");
    if (!outFile) {
        cout << "Error opening file for saving.\n";
        return;
    }
    for (const auto& v : fleet) {
        outFile << v.licensePlate << ' ' << v.name << ' ' << v.model << ' ' << v.color << ' ' << v.year << ' ' << v.assignedEmployee << ' ' << v.employeeCNIC << ' ' << v.employeeContact << '\n';
    }
}

void loadFleet() {
    ifstream inFile("fleet.dat");
    if (!inFile) {
        cout << "No previous fleet data found. Starting fresh.\n";
        return;
    }
    fleet.clear();
    Vehicle v;
    while (inFile >> v.licensePlate >> v.name >> v.model >> v.color >> v.year >> v.assignedEmployee >> v.employeeCNIC >> v.employeeContact) {
        fleet.push_back(v);
    }
}

void editVehicle() {
    string licensePlate;
    cout << "\nEnter license plate of vehicle to edit: ";
    cin >> licensePlate;
    auto it = find_if(fleet.begin(), fleet.end(), [&licensePlate](const Vehicle& v) {
        return v.licensePlate == licensePlate;
    });
    if (it == fleet.end()) {
        cout << "\nVehicle not found.\n";
        return;
    }

    Vehicle& v = *it;
    int choice;

    while (true) {
        cout << "\nChoose the field to edit:\n";
        cout << "1. Name\n";
        cout << "2. Model\n";
        cout << "3. Color\n";
        cout << "4. Year\n";
        cout << "5. Assigned Employee\n";
        cout << "6. Employee CNIC\n";
        cout << "7. Employee Contact\n";
        cout << "8. Done\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();  // To ignore the newline character left in the input buffer
        if (choice == 8) break;

        switch (choice) {
            case 1:
                cout << "Enter new name: ";
                getline(cin, v.name);
                break;
            case 2:
                cout << "Enter new model: ";
                cin >> v.model;
                if (!isValidModel(v.model)) {
                    cout << "Invalid model format.\n";
                    return;
                }
                break;
            case 3:
                cout << "Enter new color: ";
                cin >> v.color;
                break;
            case 4:
                cout << "Enter new year: ";
                cin >> v.year;
                break;
            case 5:
                cout << "Enter new assigned employee: ";
                cin.ignore();
                getline(cin, v.assignedEmployee);
                break;
            case 6:
                cout << "Enter new employee CNIC: ";
                cin >> v.employeeCNIC;
                break;
            case 7:
                cout << "Enter new employee contact: ";
                cin >> v.employeeContact;
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                continue;
        }
        cout << "\nField updated successfully!\n";
    }

    saveFleet();  // Save changes
}

void deleteVehicle() {
    string licensePlate;
    cout << "\nEnter license plate of vehicle to delete: ";
    cin >> licensePlate;
    auto it = find_if(fleet.begin(), fleet.end(), [&licensePlate](const Vehicle& v) {
        return v.licensePlate == licensePlate;
    });
    if (it != fleet.end()) {
        fleet.erase(it);
        cout << "\nVehicle deleted successfully!\n";
        saveFleet();  // Save changes
    } else {
        cout << "\nVehicle not found.\n";
    }
}

void assignEmployee() {
    string licensePlate, employee, cnic, contact;
    cout << "\nEnter license plate of vehicle for test drive: ";
    cin >> licensePlate;
    cout << "Enter employee name: ";
    cin.ignore();
    getline(cin, employee);
    cout << "Enter employee CNIC: ";
    cin >> cnic;
    cout << "Enter employee contact: ";
    cin >> contact;
    for (auto& v : fleet) {
        if (v.licensePlate == licensePlate) {
            v.assignedEmployee = employee;
            v.employeeCNIC = cnic;
            v.employeeContact = contact;
            cout << "\nEmployee assigned successfully!\n";
            saveFleet();  // Save changes
            return;
        }
    }
    cout << "\nVehicle not found.\n";
}

void searchVehicle() {
    string licensePlate;
    cout << "\nEnter license plate of vehicle to search: ";
    cin >> licensePlate;
    for (const auto& v : fleet) {
        if (v.licensePlate == licensePlate) {
            cout << "\nVehicle Found:\n";
            cout << "License Plate: " << v.licensePlate << "\nName: " << v.name << "\nModel: " << v.model << "\nColor: " << v.color << "\nYear: " << v.year << "\nAssigned Employee: " << v.assignedEmployee << "\nEmployee CNIC: " << v.employeeCNIC << "\nEmployee Contact: " << v.employeeContact << '\n';
            return;
        }
    }
    cout << "\nVehicle not found.\n";
}

void showMenu() {
    cout << R"(
    ========================================
                Fleet Management System
    ========================================
    1. Add Vehicle
    2. Display Fleet
    3. Edit Vehicle
    4. Delete Vehicle
    5. Assign Employee
    6. Search Vehicle
    7. Exit
    ========================================
    Enter your choice: )";
}

int main() {
    int choice;
    loadFleet();
    while (true) {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: addVehicle(); saveFleet(); break;
            case 2: displayFleet(); break;
            case 3: editVehicle(); break;
            case 4: deleteVehicle(); break;
            case 5: assignEmployee(); break;
            case 6: searchVehicle(); break;
            case 7:
            	                cout << "Program ended.....";
                cout << "\nThanks for visiting our software.\n";
                return 0;
            default: cout << "\nInvalid choice. Try again.\n";
        }
    }
}