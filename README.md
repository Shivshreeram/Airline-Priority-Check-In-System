# DSA Lab Project 1

## Airline Check-In System

This project implements a **check-in system** for passengers across multiple airlines. Passengers are prioritized based on factors such as ticket class and special needs. The system efficiently manages airline-specific queues and gate assignments using **hash tables** and processes passengers based on priority using **priority queues**.
  
## Features

- **Passenger Check-In:** Allows check-in for passengers with the following details:
  - Name
  - Seat Number
  - Gender
  - Special Needs (if any)
  - Ticket Class (First Class, Business Class, Economy Class)
  
- **Prioritization:** Passengers are prioritized based on:
  - Special needs passengers (highest priority)
  - First Class passengers (higher priority than Business and Economy)
  - Business Class passengers (higher priority than Economy)
  - Economy Class passengers (default priority)

- **Airline-Specific Queues:** Each airline has its own queue of passengers, ensuring that passengers are processed in the correct order for their respective airlines.

- **Gate Assignments:** Each airline is assigned a specific gate, and the system displays the gate information upon check-in.

- **Hardcoded Passengers:** 10 hardcoded passengers are added to demonstrate the check-in process.

- **Manual Check-In:** Passengers can be added manually via a user input interface.

- **Priority Sequence Display:** View the priority order of passengers for each airline.

## Technologies Used

- **C++**
  - **`unordered_map` (Hash Table)** for efficient airline-specific data storage
  - **`priority_queue`** (Heap) for managing passenger priority
  - **Standard C++ libraries**: `iostream`, `string`, `vector`, `queue`

## How to Run

### Prerequisites

- A C++ compiler (e.g., **g++**, **clang++**) installed on your machine.

### Compilation and Execution

1. Clone this repository:
   ```
   git clone https://github.com/yourusername/airline-checkin-system.git
   ```

2. Navigate to the project directory:
```
cd airline-checkin-system
```

3. Compile the program:
```
g++ -o checkin_system main.cpp
```

4. Run the program:
```
./checkin_system
```

## Example Output

### Example Output

```bash
Adding 10 hardcoded passengers to the system...

--- Check-In System Menu ---
1. Check-in a Passenger
2. Check-in Multiple Passengers Manually
3. Print Priority Queues for All Flights
4. Exit
Enter your choice: 1
Enter Airline Code (AI : Air India, EM : Emirates, KF : Kingfisher, SJ : Spicejet, ET : Etihad): AI
Enter Passenger Name: John Doe
Enter Seat Number: 12
Enter Gender (M/F): M
Does the passenger have special needs? (1 for Yes, 0 for No): 0
Enter Ticket Class (1 for First Class, 2 for Business Class, 3 for Economy Class): 3
Checked in passenger: John Doe, Ticket Number: AI012M, Gate: Gate 1

--- Check-In System Menu ---
1. Check-in a Passenger
2. Check-in Multiple Passengers Manually
3. Print Priority Queues for All Flights
4. Exit
Enter your choice: 3

AI Passengers (Priority Order):
Alice Smith - AI015F
John Doe - AI012M

EM Passengers (Priority Order):
Eve Johnson - EM002F
Charlie Brown - EM005B

KF Passengers (Priority Order):
Grace Lee - KF003F
Frank Harris - KF001E

SJ Passengers (Priority Order):
Bob White - SJ022M
Hannah Adams - SJ010B

ET Passengers (Priority Order):
Jack Black - ET008M
Ivy Green - ET020E
```
## How It Works
- The system stores passengers in a `priority_queue`, which ensures that the passenger with the highest priority (lowest priority value) is processed first.
- Each airline's queue is managed in an unordered_map, which provides constant-time access to airline-specific data.
- Passengers are processed according to their priority level, with special needs passengers receiving the highest priority, followed by first-class, business-class, and economy-class passengers.
  

## About team

- BM23BTECH11006 | BM23BTECH11021
- Created by [Sriharsha Rao C](www.github.com/MeltngLiquid) and [ShivShreeram P](www.github.com/Shivshreeram)
