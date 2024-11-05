// The department maintains student information. the file contains roll no, name, division, and address. Allow users to add, delete, insert and search information of student. use direct access files  to maintain the data.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

const int RECORD_SIZE = 100;

class Student {
private:
    int rollNo;
    char name[30];
    char division;
    char address[50];

public:
    void getData();
    void displayData();
    int getRollNo() { return rollNo; }
};

void Student::getData() {
    cout << "Enter Roll No: ";
    cin >> rollNo;
    cin.ignore(); // Clear input buffer
    cout << "Enter Name: ";
    cin.getline(name, 30);
    cout << "Enter Division: ";
    cin >> division;
    cin.ignore(); // Clear input buffer
    cout << "Enter Address: ";
    cin.getline(address, 50);
}

void Student::displayData() {
    cout << setw(10) << rollNo << setw(30) << name << setw(5) << division << setw(50) << address << endl;
}

void addRecord() {
    fstream file;
    file.open("students.dat", ios::out | ios::app | ios::binary);

    Student student;
    student.getData();

    file.write(reinterpret_cast<char*>(&student), sizeof(Student));
    file.close();
}

void displayAllRecords() {
    ifstream file;
    file.open("students.dat", ios::in | ios::binary);

    if (!file) {
        cout << "Error in opening file!";
        return;
    }

    cout << setw(10) << "Roll No" << setw(30) << "Name" << setw(5) << "Div" << setw(50) << "Address" << endl;
    cout << "-------------------------------------------------------------" << endl;

    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        student.displayData();
    }

    file.close();
}

void searchRecord(int rollNo) {
    ifstream file;
    file.open("students.dat", ios::in | ios::binary);

    if (!file) {
        cout << "Error in opening file!";
        return;
    }

    bool found = false;
    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.getRollNo() == rollNo) {
            found = true;
            student.displayData();
            break;
        }
    }

    if (!found) {
        cout << "Record not found!" << endl;
    }

    file.close();
}

void deleteRecord(int rollNo) {
    ifstream inFile;
    inFile.open("students.dat", ios::in | ios::binary);

    if (!inFile) {
        cout << "Error in opening file!";
        return;
    }

    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);

    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.getRollNo() != rollNo) {
            outFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found) {
        cout << "Record deleted successfully!" << endl;
    } else {
        cout << "Record not found!" << endl;
    }
}

int main() {
    int choice, rollNo;
    while (true) {
        cout << "1. Add Record" << endl;
        cout << "2. Display All Records" << endl;
        cout << "3. Search Record" << endl;
        cout << "4. Delete Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                cout << "Enter Roll No to search: ";
                cin >> rollNo;
                searchRecord(rollNo);
                break;
            case 4:
                cout << "Enter Roll No to delete: ";
                cin >> rollNo;
                deleteRecord(rollNo);
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
