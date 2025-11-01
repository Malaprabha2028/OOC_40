#include <iostream>
using namespace std;

class Person {
public:
    Person() {
        cout << "Person's constructor called" << endl;
    }
};

class Faculty : virtual public Person {
public:
    Faculty() {
        cout << "Faculty's constructor called" << endl;
    }
};

class Student : virtual public Person {
public:
    Student() {
        cout << "Student's constructor called" << endl;
    }
};

class TA : public Faculty, public Student {
public:
    TA() {
        cout << "TA's constructor called" << endl;
    }
};

int main() {
        cout << "Name: Malaprabha Bekwadkar" << endl;
        cout << "Roll No: 40" << endl;
        cout << "Division: B" << endl;
        cout << "Department: CSE (SY)" << endl;
        TA ta; 
    
    return 0;
}

