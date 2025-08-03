#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// --- A class to represent a single vehicle ---
class Vehicle {
public:
    string type;
    int fee;

    Vehicle(string type, int fee) : type(type), fee(fee) {}
};

// --- The main class to manage the parking lot ---
class ParkingLot {
private:
    int totalAmount = 0;
    int autoCount = 0;
    int carCount = 0;
    int busCount = 0;
    int capacity = 50; // Set a maximum capacity for the lot
    const string DATA_FILE = "parking_data.txt";

public:
    // Constructor to load data when the object is created
    ParkingLot() {
        loadData();
    }

    void parkVehicle(const string& type, int fee) {
        if (autoCount + carCount + busCount >= capacity) {
            cout << "\nError: Parking lot is full. Cannot park more vehicles.\n";
            return;
        }

        if (type == "AutoRickshaw") {
            autoCount++;
        } else if (type == "Car") {
            carCount++;
        } else if (type == "Bus") {
            busCount++;
        }
        totalAmount += fee;
        cout << "\n" << type << " parked successfully. Fee: $" << fee << "\n";
        saveData(); // Save data after every change
    }

    void showRecords() const {
        cout << "\n--- Parking Lot Records ---\n";
        cout << "Total Amount Collected: $" << totalAmount << endl;
        cout << "Vehicles Parked:\n";
        cout << " - AutoRickshaw: " << autoCount << endl;
        cout << " - Car:          " << carCount << endl;
        cout << " - Bus:          " << busCount << endl;
        cout << "---------------------------\n";
    }

    void deleteRecords() {
        totalAmount = 0;
        autoCount = 0;
        carCount = 0;
        busCount = 0;
        cout << "\nAll parking records have been deleted.\n";
        saveData(); // Save the empty state
    }

    void saveData() const {
        ofstream outFile(DATA_FILE);
        if (!outFile) {
            cerr << "Error: Could not save data to file.\n";
            return;
        }
        outFile << totalAmount << "\n";
        outFile << autoCount << "\n";
        outFile << carCount << "\n";
        outFile << busCount << "\n";
        outFile.close();
    }

    void loadData() {
        ifstream inFile(DATA_FILE);
        if (!inFile) {
            cout << "No previous data found. Starting fresh.\n";
            return;
        }
        inFile >> totalAmount;
        inFile >> autoCount;
        inFile >> carCount;
        inFile >> busCount;
        cout << "Parking records loaded successfully.\n";
        inFile.close();
    }
};

// --- The main function where the program runs ---
int main() {
    ParkingLot myParkingLot;
    int user_input;

    while (true) {
        cout << "\n--- VEHICLE PARKING SYSTEM ---\n";
        cout << "1. Park AutoRickshaw ($100)\n";
        cout << "2. Park Car ($200)\n";
        cout << "3. Park Bus ($300)\n";
        cout << "4. Show Records\n";
        cout << "5. Delete All Records\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        // --- Input validation to handle non-numeric input ---
        if (!(cin >> user_input)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (user_input) {
            case 1:
                myParkingLot.parkVehicle("AutoRickshaw", 100);
                break;
            case 2:
                myParkingLot.parkVehicle("Car", 200);
                break;
            case 3:
                myParkingLot.parkVehicle("Bus", 300);
                break;
            case 4:
                myParkingLot.showRecords();
                break;
            case 5:
                myParkingLot.deleteRecords();
                break;
            case 6:
                cout << "Thank you! Goodbye.\n";
                return 0; // Proper way to exit the program
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}