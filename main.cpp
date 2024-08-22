#include <iostream>
#include <string>
using namespace std;

// Function that adds an hour to the time
void addHour(int& hour12, int& hour24, string& amPm) {
    hour12++;
    if (hour12 == 13) {
        hour12 = 1;
        amPm = "PM";
    }
    else if ((hour12 == 12) && (amPm == "PM")) {
        amPm = "AM";
    }
    hour24++;
    if (hour24 == 24) {
        hour24 = 0;
    }
}

// Funstion that adds a minute to the time
void addMinute(int& hour12, int& hour24, string& amPm, int& minute) {
    minute++;
    if (minute == 60) {
        minute = 0;
        addHour(hour12, hour24, amPm);
    }
}

// Function that adds a second to the time
void addSecond(int& hour12, int& hour24, string& amPm, int& minute, int& second) {
    second++;
    if (second == 60) {
        second = 0;
        addMinute(hour12, hour24, amPm, minute);
    }
}

// Function that displays the time and menu and gets menu selection
void displayTimeAndMenu(int& hour12, int& hour24, string& amPm, int& minute, int& second, string hour12String, string hour24String, string minuteString, string secondString, int& menuSelection) {

    // Sets time strings to get ready for display
    hour12String = to_string(hour12);
    hour24String = to_string(hour24);
    minuteString = to_string(minute);
    secondString = to_string(second);

    if (hour12String.length() == 1) {
        hour12String = "0" + hour12String;
    }
    if (hour24String.length() == 1) {
        hour24String = "0" + hour24String;
    }
    if (minuteString.length() == 1) {
        minuteString = "0" + minuteString;
    }
    if (secondString.length() == 1) {
        secondString = "0" + secondString;
    }

    // Time Display
    cout << "*************************\t*************************" << endl;
    cout << "*     12-Hour Clock     *\t*     24-Hour Clock     *" << endl;
    cout << "*      " << hour12String << ":" << minuteString << ":" << secondString << " " << amPm << "      *\t*\t\t" << hour24String << ":" << minuteString << ":" << secondString << "\t\t*" << endl;
    cout << "*************************\t*************************" << endl;

    // Menu display
    cout << "*************************" << endl;
    cout << "* 1 - Add One Hour      *" << endl;
    cout << "* 2 - Add One Minute    *" << endl;
    cout << "* 3 - Add One Second    *" << endl;
    cout << "* 4 - Exit Program      *" << endl;
    cout << "*************************" << endl;

    // Recieves user input for menu selection
    cin >> menuSelection;
}

// Computes 12 hour time from 24 hour time
void compute12HourTime(int& hour12, int& hour24, string& amPm) {
    if (hour24 > 12) {
        hour12 = hour24 - 12;
        amPm = "PM";
    }
    else if (hour24 == 12) {
        hour12 = 12;
        amPm = "PM";
    }
    else {
        hour12 = hour24;
        amPm = "AM";
    }
}

// Increments time based on user input and runs displayTimeAndMenu function for continued incrementation or program exit
void incrementTime(int& hour12, int& hour24, string& amPm, int& minute, int& second, int& menuSelection, string& hour12String, string& hour24String, string& minuteString, string& secondString) {
    while (menuSelection != 4) {
        switch (menuSelection)
        {
        case 1:
            addHour(hour12, hour24, amPm);
            break;
        case 2:
            addMinute(hour12, hour24, amPm, minute);
            break;
        case 3:
            addSecond(hour12, hour24, amPm, minute, second);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        displayTimeAndMenu(hour12, hour24, amPm, minute, second, hour12String, hour24String,         minuteString, secondString, menuSelection);
    }
}

int main()
{
    int hour12, hour24, minute, second; // All ints for time
    string amPm;
    int menuSelection;
    string hour12String, hour24String, minuteString, secondString; // All strings for time display

    // Recieves user input for time in 24-hour notation and computes 12 hour time
    cout << "Please input the current time in 24-hour notation (HH MM SS): ";
    cin >> hour24 >> minute >> second;
    compute12HourTime(hour12, hour24, amPm);

    // Clock and menu display with incrementation
    displayTimeAndMenu(hour12, hour24, amPm, minute, second, hour12String, hour24String, minuteString, secondString, menuSelection);
    incrementTime(hour12, hour24, amPm, minute, second, menuSelection, hour12String, hour24String, minuteString, secondString);

    cout << "Program exited. Thank you for chosing Chada Tech!" << endl;

    return 0;
}
