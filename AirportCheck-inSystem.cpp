

#include <iostream>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Passenger {
public:
    string name;
    string ticketNumber;
    int priority; 
    //priority queue is the main data structure for this project
    Passenger(string n, string t, int p) : name(n), ticketNumber(t), priority(p) {}
};

struct ComparePassenger {
    bool operator()(const Passenger& p1, const Passenger& p2) {
        return p1.priority > p2.priority; // Higher priority value means lower priority in queue
    }
};

class CheckInSystem {
private:
    unordered_map<string, priority_queue<Passenger, vector<Passenger>, ComparePassenger>> flightQueues;
    unordered_map<string, string> airlineGates = {
        {"AI", "Gate 1"},   // Air India
        {"EM", "Gate 5"},   // Emirates
        {"KF", "Gate 2"},   // Kingfisher
        {"SJ", "Gate 3"},   // Spice Jet
        {"ET", "Gate 4"}    // Etihad
    };

public:
    // Function to check in the passenger
    void checkInPassenger(const string& airlineCode, const string& name, int seatNum, char gender, bool specialNeeds, int ticketClass) {
        string ticketNumber = airlineCode;
        ticketNumber += to_string(seatNum).insert(0, 3 - to_string(seatNum).length(), '0'); 
        ticketNumber += gender;


        if (ticketClass == 1) {
            ticketNumber += "F"; // First Class
        } else if (ticketClass == 2) {
            ticketNumber += "B"; // Business Class
        } else {
            ticketNumber += "E"; // Economy Class
        }

        // Add special needs indicator to the ticket number
        ticketNumber += (specialNeeds ? 'Y' : 'N');

        // Determine passenger priority
        int priority = 3; // Default priority for economy class
        if (specialNeeds) {
            priority = 1; // Special needs passengers get the highest priority
        } else if (ticketClass == 1) {
            priority = 2; // First class passengers have higher priority
        } else if (ticketClass == 2) {
            priority = 2; // Business class passengers have higher priority than economy class
        } else if (ticketClass == 3) {
            priority = 3; // Economy class passengers have the lowest priority
        }

        Passenger passenger(name, ticketNumber, priority);

        // Adding passenger to the appropriate flight queue
        flightQueues[airlineCode].push(passenger);
        //printing the checked in information

        cout << "Checked in passenger: " << name << ", Ticket Number: " << ticketNumber;
        cout << ", Gate: " << airlineGates[airlineCode] << endl;  
    }

    void addHardcodedPassengers() {
        checkInPassenger("AI", "John Doe", 12, 'M', false, 3);
        checkInPassenger("AI", "Alice Smith", 15, 'F', true, 1);
        checkInPassenger("EM", "Charlie Brown", 5, 'M', false, 2);
        checkInPassenger("EM", "Eve Johnson", 2, 'F', true, 3);
        checkInPassenger("KF", "Frank Harris", 1, 'M', false, 3);
        checkInPassenger("KF", "Grace Lee", 3, 'F', false, 1);
        checkInPassenger("SJ", "Bob White", 22, 'M', true, 3);
        checkInPassenger("SJ", "Hannah Adams", 10, 'F', false, 2);
        checkInPassenger("ET", "Jack Black", 8, 'M', true, 1);
        checkInPassenger("ET", "Ivy Green", 20, 'F', false, 3);
    }


void addManualPassenger() {
    string airlineCode, name;
    int seatNum, ticketClass;
    char gender;
    bool specialNeeds;

    while (true) {
        cout << "\n============================" << endl;
        cout << "       Check-In Menu        " << endl;
        cout << "============================" << endl;

        cout << "Enter Airline Code or '-1' to stop:" << endl;
        cout << "  AI : Air India" << endl;
        cout << "  EM : Emirates" << endl;
        cout << "  KF : Kingfisher" << endl;
        cout << "  SJ : Spicejet" << endl;
        cout << "  ET : Etihad" << endl;
        cout << "Your Choice: ";
        cin >> airlineCode;

        if (airlineCode == "-1") {
            cout << "\nExiting passenger check-in..." << endl;
            break; 
        }

        cout << "\nEnter Passenger Name: ";
        cin.ignore(); 
        getline(cin, name);

        cout << "Enter Seat Number (1-999): ";
        cin >> seatNum;

        while (seatNum < 1 || seatNum > 999) {
            cout << "Invalid seat number! Please enter a valid seat number (1-999): ";
            cin >> seatNum;
        }

        cout << "Enter Gender (M/F): ";
        cin >> gender;

        while (gender != 'M' && gender != 'F') {
            cout << "Invalid gender! Please enter 'M' for Male or 'F' for Female: ";
            cin >> gender;
        }

        cout << "Does the passenger have special needs? (1 for Yes, 0 for No): ";
        cin >> specialNeeds;

        while (specialNeeds != 0 && specialNeeds != 1) {
            cout << "Invalid input! Please enter 1 for Yes or 0 for No: ";
            cin >> specialNeeds;
        }

        cout << "Enter Ticket Class:" << endl;
        cout << "  1 : First Class" << endl;
        cout << "  2 : Business Class" << endl;
        cout << "  3 : Economy Class" << endl;
        cout << "Your Choice: ";
        cin >> ticketClass;

        while (ticketClass < 1 || ticketClass > 3) {
            cout << "Invalid ticket class! Please select 1, 2, or 3: ";
            cin >> ticketClass;
        }

        checkInPassenger(airlineCode, name, seatNum, gender, specialNeeds, ticketClass);

        cout << "\n--- Passenger Successfully Checked-In! ---\n";
    }
}


    void printPrioritySequences() {
        for (const auto& flight : flightQueues) {
            cout << "\n" << flight.first << " Passengers (Priority Order):" << endl;


            priority_queue<Passenger, vector<Passenger>, ComparePassenger> tempQueue = flight.second;

            while (!tempQueue.empty()) {
                const Passenger& passenger = tempQueue.top();
                cout << passenger.name << " - " << passenger.ticketNumber << endl;
                tempQueue.pop();
            }

            cout << endl; 
        }
    }
};


int main() {
    CheckInSystem checkInSystem;

    // Adding the  hardcoded passengers
    cout << "\n===================================" << endl;
    cout << "   Adding 10 Hardcoded Passengers   " << endl;
    cout << "===================================" << endl;
    checkInSystem.addHardcodedPassengers();

    int choice;

    while (true) {
        cout << "\n===============================" << endl;
        cout << "       Check-In System Menu     " << endl;
        cout << "===============================" << endl;
        cout << "1. Check-in a Passenger" << endl;
        cout << "2. Check-in Multiple Passengers Manually" << endl;
        cout << "3. Print Priority Queues for All Flights" << endl;
        cout << "4. Exit" << endl;
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        cout << "\n===================================" << endl;

        switch (choice) {
            case 1: {
                string airlineCode, name;
                int seatNum, ticketClass;
                char gender;
                bool specialNeeds;

                cout << "Enter Airline Code or '-1' to stop:" << endl;
                cout << "  AI : Air India" << endl;
                cout << "  EM : Emirates" << endl;
                cout << "  KF : Kingfisher" << endl;
                cout << "  SJ : Spicejet" << endl;
                cout << "  ET : Etihad" << endl;
                cout << "Your Airline: ";
                cin >> airlineCode;
                
                cout << "Enter Passenger Name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter Seat Number (1-999): ";
                cin >> seatNum;

                while (seatNum < 1 || seatNum > 999) {
                    cout << "Invalid seat number! Please enter a valid seat number (1-999): ";
                    cin >> seatNum;
                }

                cout << "Enter Gender (M/F): ";
                cin >> gender;

                while (gender != 'M' && gender != 'F') {
                    cout << "Invalid gender! Please enter 'M' for Male or 'F' for Female: ";
                    cin >> gender;
                }

                cout << "Does the passenger have special needs? (1 for Yes, 0 for No): ";
                cin >> specialNeeds;

                while (specialNeeds != 0 && specialNeeds != 1) {
                    cout << "Invalid input! Please enter 1 for Yes or 0 for No: ";
                    cin >> specialNeeds;
                }

                cout << "Enter Ticket Class:" << endl;
                cout << "  1 : First Class" << endl;
                cout << "  2 : Business Class" << endl;
                cout << "  3 : Economy Class" << endl;
                cout << "Your Choice: ";
                cin >> ticketClass;

                while (ticketClass < 1 || ticketClass > 3) {
                    cout << "Invalid ticket class! Please select 1, 2, or 3: ";
                    cin >> ticketClass;
                }

                checkInSystem.checkInPassenger(airlineCode, name, seatNum, gender, specialNeeds, ticketClass);
                break;
            }
            case 2:
                checkInSystem.addManualPassenger();
                break;
            case 3:
                checkInSystem.printPrioritySequences();
                break;
            case 4:
                cout << "\nExiting the system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << "===================================" << endl;
    }

    return 0;
}
