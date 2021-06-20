#include <iostream>
#include <cstring>

using namespace std;

const int MAX_ARRAY = 100;
const int MAX_STRING = 20;

struct Address {
    char street[MAX_STRING];
    char streetNum[MAX_STRING];
    char postCode[MAX_STRING];
    char city[MAX_STRING];
    char country[MAX_STRING];
};

struct Courses {
    char code[6][9];
    char gradePoints[6][2];
    int credits;
};

struct Academic {
    char major[5];
    char degree[4];
    double CPA;
    double ECTS;
    Courses s_course;
};

struct StudentInfo {
    char ID[MAX_STRING];
    char firstName[MAX_STRING];
    char lastName[MAX_STRING];
    char phoneNum[MAX_STRING];
    Address s_address;
    Academic s_academic;
};

void showMenu();
StudentInfo AddStudent(StudentInfo[], int);
bool FindStudent(StudentInfo[],char[], int);
void DisplayStudent(StudentInfo[], int);
void RegisterStudent(StudentInfo[], char[], int);
void WithdrawCourse(StudentInfo[], char[], int);
void CalculateGPA(StudentInfo[], char[], int);
void DisplayMajor(int, char[]);
void HighestCPA();
void Report();
void showMajor();

int main() {
    StudentInfo StudentList[MAX_ARRAY];
    char ID[MAX_STRING];
    int choice;
    int i = 0; //iterator for the StudentList array

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: StudentList[i] = AddStudent(StudentList, i);
            strcpy_s(ID, StudentList[i].ID);
            RegisterStudent(StudentList, ID, i);
            i++;
            break;
        case 2: cout << i << endl;
            break;
        case 3: cout << "Enter Student ID: ";
            cin >> ID;
            if (FindStudent(StudentList, ID, i) == true) {
                cout << "True" << endl;
            }
            else
                cout << "False" << endl;
            break;
        case 4: DisplayStudent(StudentList, i);
            break;
        case 5: cout << "Enter Student ID: ";
            cin >> ID;
            RegisterStudent(StudentList, ID, i);
            break;
        case 0: cout << "Goodbye!";
            break;
        }
    } while (choice != 0);


    return 0;
}
void showMenu()
{
    cout << "1) Add a new student record \n";
    cout << "2) Display number of registered students \n";
    cout << "3) Find a student \n";
    cout << "4) Display student details \n";
    cout << "5) Register a student to courses \n";
    cout << endl;
    cout << "0) Exit \n";
}

StudentInfo AddStudent(StudentInfo StudentList[MAX_ARRAY], int end)
{
    StudentInfo student;
    int unique = 0;

    do {
        cout << "Please Enter Student ID: " << endl;
        cin >> student.ID;


        for (int i = 0; i < end; i++) {
            if (strcmp(StudentList[i].ID, student.ID) == 0) {
                cout << "The student already exists!!!" << endl;
                unique = 1;
            }
            else
                unique = 0;
        }
    } while (unique != 0);

    cout << "Please Enter Student's First Name: " << endl;
    cin >> student.firstName;
    cout << "Please Enter Student's Last Name: " << endl;
    cin >> student.lastName;
    cout << "Please Enter Student's phone number: " << endl;
    cin >> student.phoneNum;

    cout << "Please Enter Student's Address: " << endl;
    cout << "Street name: ";
    cin >> student.s_address.street;
    cout << "Street number: ";
    cin >> student.s_address.streetNum;
    cout << "Postal Code: ";
    cin >> student.s_address.postCode;
    cout << "City: ";
    cin >> student.s_address.city;
    cout << "Country: ";
    cin >> student.s_address.country;
    cout << endl;

    //** ACADEMIC **//

    int choice;
    bool valid = 0;

    while (valid == 0) {
        cout << "Enter your Major:" << endl;
        showMajor();
        cin >> choice;
        switch (choice) {
        case 1: strcpy_s(student.s_academic.major, "COMP");
            valid = 1;
            break;
        case 2: strcpy_s(student.s_academic.major, "DATA");
            valid = 1;
            break;
        case 3: strcpy_s(student.s_academic.major, "CENG");
            valid = 1;
            break;
        case 4: strcpy_s(student.s_academic.major, "MIS");
            valid = 1;
            break;
        default: cout << "Invalid choice!";
        }
    }


    valid = 0;
    while (valid == 0) {
        switch (choice) {
           cout << "Select your Degree:" << endl;
           cout << "1) BSc" << endl << "2) MSc" << endl;
           cin >> choice;
        case 1: strcpy_s(student.s_academic.degree, "BSc");
            valid = 1;
            break;
        case 2: strcpy_s(student.s_academic.degree, "MSc");
            valid = 1;
            break;
        default: cout << "Invalid choice!";
        }
    }

    return student;
}
bool FindStudent(StudentInfo StudentList[MAX_ARRAY], char ID[MAX_STRING], int end)
{
    for (int i = 0; i < end; i++) {
        if (strcmp(StudentList[i].ID, ID) == 0) {
            return true;
        }
    }
    return false;
}
void DisplayStudent(StudentInfo StudentList[MAX_ARRAY], int end)
{
    char name[MAX_STRING];
    int matches[20];
    int count = 0;
    cout << "Please enter the first name: ";
    cin >> name;

    for (int i = 0; i < end; i++) {
            if (strcmp(StudentList[i].firstName, name) == 0) {
                matches[count] = i;
                count++;
            }
    }
    if (count > 1)
        cout << "There is more than one student named \"" << name << "\" \n";
    else if (count == 1)
        cout << "Student found!" << endl;
    else {
        cout << "No match found!" << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "First Name: " << StudentList[matches[i]].firstName << endl;
        cout << "Last Name: " << StudentList[matches[i]].lastName << endl;
        cout << "Phone Number: " << StudentList[matches[i]].phoneNum << endl;
        cout << "Address:" << endl;
        cout << "Street name: " << StudentList[matches[i]].s_address.street << endl;
        cout << "Street number: " << StudentList[matches[i]].s_address.streetNum << endl;
        cout << "Post Code: " << StudentList[matches[i]].s_address.postCode << endl;
        cout << "City: " << StudentList[matches[i]].s_address.city << endl;
        cout << "Country: " << StudentList[matches[i]].s_address.country << endl;
    }
}
void RegisterStudent(StudentInfo StudentList[MAX_ARRAY], char ID[MAX_STRING], int end)
{
    int index = -1;
    for (int j = 0; j <= end; j++) {
        if (strcmp(StudentList[j].ID, ID) == 0) {
            index = j;
        }
    }
    if (index == -1) {
        cout << "Student not found!";
        return;
    }
    for (int i = 0; i < 5; i++) {
        cout << "Enter course name to register: ";
        cin.ignore(); //don't touch
        cin.getline(StudentList[index].s_academic.s_course.code[i],10);
    }
    //ADD 6TH COURSE OPTION F
}

void showMajor()
{
    cout << "1) COMP \n";
    cout << "2) DATA \n";
    cout << "3) CENG \n";
    cout << "4) MIS \n";
}
