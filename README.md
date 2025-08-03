# Vehicle Parking Management System

## Project Overview
This is a C++ console application that simulates a vehicle parking management system. It is designed to track vehicles, calculate total fees, and manage parking lot capacity. The project demonstrates an application of Object-Oriented Programming (OOP) to create a structured and scalable system. All parking records are saved to a file, ensuring data is not lost when the program closes.

## Features
- **Object-Oriented Design**: The system is built around a `ParkingLot` class that manages all parking records and state, and a `Vehicle` class that defines vehicle types.
- **Record Management**:
    - Park AutoRickshaws, Cars, and Buses with predefined fees.
    - Track the total amount collected and the number of each type of vehicle parked.
- **Data Persistence**: All parking records (total amount and vehicle counts) are automatically saved to `parking_data.txt` and loaded on startup.
- **Parking Capacity**: The system has a set capacity and will not allow new vehicles to park if the lot is full.
- **User-Friendly Interface**: A clear, menu-driven interface with input validation and a clean exit.

## How to Compile and Run
### Prerequisites
- A C++ compiler (e.g., g++, MinGW, Visual C++).

### Steps
1. Save the code as a `.cpp` file (e.g., `parking_system.cpp`).
2. Compile the code using a C++ compiler. For example, in the terminal:
   ```bash
   g++ parking_system.cpp -o parking_system
