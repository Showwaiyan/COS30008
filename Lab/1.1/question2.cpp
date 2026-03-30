#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    int age;

public:
    Person(string fName, string lName, int a) {
        firstName = fName;
        lastName = lName;
        age = a;
    }

    void display() {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Age: " << age << endl;
    }
};

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date(int m, int d, int y) {
        month = m;
        day = d;
        year = y;
    }

    void display() {
        cout << month << "/" << day << "/" << year << endl;
    }
};

class DentalAppointment {
private:
    Person patient;
    Date appointment;
    int duration;

public:
    DentalAppointment(Person p, Date d, int dur) : patient(p), appointment(d), duration(dur) {}

    void display() {
        cout << "Patient: ";
        patient.display();
        cout << "Appointment Date: ";
        appointment.display();
        cout << "Duration: " << duration << " minutes" << endl;
    }
};

int main() {
    Person p("Jane", "Smith", 30);
    Date d(4, 15, 2026);
    DentalAppointment appt(p, d, 60);
    appt.display();
    
    return 0;
}
