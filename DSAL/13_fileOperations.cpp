// The department maintains student information. the file contains roll no, name, division, and address. Allow users to add, delete, insert and search information of student. use sequential file to maintain the data
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    int rollNo;
    string name;
    string division;
    string address;

public:
    Student() {}

    Student(int rollNo, const string& name, const string& division, const string& address)
        : rollNo(rollNo), name(name), division(division), address(address) {}

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << "Roll No: " << student.rollNo << ", Name: " << student.name
           << ", Division: " << student.division << ", Address: " << student.address;
        return os;
    }

    friend istream& operator>>(istream& is, Student& student) {
        cout << "Enter Roll No: ";
        is >> student.rollNo;
        cout << "Enter Name: ";
        is >> student.name;
        cout << "Enter Division: ";
        is >> student.division;
        cout << "Enter Address: ";
        is >> student.address;
        return is;
    }

    int getRollNo() const {
        return rollNo;
    }
};

class StudentDatabase {
private:
    string filename;

public:
    StudentDatabase(const string& filename) : filename(filename) {}

    void addStudent(const Student& student) {
        ofstream file(filename, ios::app);
        file << student.getRollNo() << " " << student.name << " " << student.division << " " << student.address << endl;
        file.close();
    }

    void displayAllStudents() {
        ifstream file(filename);
        if (!file) {
            cout << "File not found or empty!" << endl;
            return;
        }

        int rollNo;
        string name, division, address;
        while (file >> rollNo >> name >> division >> address) {
            cout << "Roll No: " << rollNo << ", Name: " << name
                 << ", Division: " << division << ", Address: " << address << endl;
        }
        file.close();
    }

    bool deleteStudent(int rollNo) {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "File not found or empty!" << endl;
            return false;
        }

        ofstream outFile("temp.txt");
        bool found = false;
        int r;
        string n, d, a;
        while (inFile >> r >> n >> d >> a) {
            if (r != rollNo)
                outFile << r << " " << n << " " << d << " " << a << endl;
            else
                found = true;
        }
        inFile.close();
        outFile.close();

        remove(filename.c_str());
        rename("temp.txt", filename.c_str());

        if (!found)
            cout << "Student with Roll No " << rollNo << " not found!" << endl;
        else
            cout << "Student with Roll No " << rollNo << " deleted successfully!" << endl;

        return found;
    }

    void searchStudent(int rollNo) {
        ifstream file(filename);
        if (!file) {
            cout << "File not found or empty!" << endl;
            return;
        }

        int r;
        string n, d, a;
        bool found = false;
        while (file >> r >> n >> d >> a) {
            if (r == rollNo) {
                cout << "Student found:" << endl;
                cout << "Roll No: " << r << ", Name: " << n
                     << ", Division: " << d << ", Address: " << a << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Student with Roll No " << rollNo << " not found!" << endl;
        file.close();
    }
};

int main() {
    StudentDatabase db("students.txt");

    int choice;
    do {
        cout << "\n\nMenu\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Student student;
                cin >> student;
                db.addStudent(student);
                cout << "Student added successfully!" << endl;
                break;
            }
            case 2: {
                int rollNo;
                cout << "Enter Roll No of student to delete: ";
                cin >> rollNo;
                db.deleteStudent(rollNo);
                break;
            }
            case 3: {
                int rollNo;
                cout << "Enter Roll No of student to search: ";
                cin >> rollNo;
                db.searchStudent(rollNo);
                break;
            }
            case 4:
                db.displayAllStudents();
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (choice != 5);

    return 0;
}
