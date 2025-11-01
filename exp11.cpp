#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int no;
    string name;

public:
    virtual void salary() {
        cout << "Enter employee number: ";
        cin >> no;
        cout << "Enter employee name: ";
        cin >> name;
    }

    virtual void display() {
        cout << "Employee Number: " << no << endl;
        cout << "Employee Name  : " << name << endl;
    }
};

class SalariedEmployee : public Employee
{
private:
    double monthlySalary;

public:
    void salary() override {
        Employee::salary();
        cout << "Enter employee monthly salary: ";
        cin >> monthlySalary;
    }

    void display() override {
        cout << "\n--- Salaried Employee ---" << endl;
        Employee::display();
        cout << "Monthly Salary : " << monthlySalary << endl;
    }
};

class HourlyEmployee : public Employee
{
private:
    double hours;
    double rate;

public:
    void salary() override {
        Employee::salary();
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter hourly rate: ";
        cin >> rate;
    }

    void display() override {
        cout << "\n--- Hourly Employee ---" << endl;
        Employee::display();
        cout << "Hours Worked   : " << hours << endl;
        cout << "Hourly Rate    : " << rate << endl;
        cout << "Total Salary   : " << (rate * hours) << endl;
    }
};

class CommissionedEmployee : public Employee
{
private:
    double baseSalary;
    int overtime;

public:
    void salary() override {
        Employee::salary();
        cout << "Enter base salary: ";
        cin >> baseSalary;
        cout << "Enter overtime hours: ";
        cin >> overtime;
    }

    void display() override {
        cout << "\n--- Commissioned Employee ---" << endl;
        Employee::display();
        cout << "Base Salary    : " << baseSalary << endl;
        cout << "Overtime Hours : " << overtime << endl;
        cout << "Total Salary   : " << (baseSalary + (overtime * 15)) << endl;
    }
};

int main()
{
    cout << "Name         : Malaprabha Bekwadkar" << endl;
    cout << "Roll No.     : 40" << endl;
    cout << "Division     : B" << endl;
    cout << "Department   :CSE(SY)" << endl;


    Employee* employees[3];
    SalariedEmployee newSalariedEmployee;
    HourlyEmployee newHourlyEmployee;
    CommissionedEmployee newCommissionedEmployee;

    employees[0] = &newSalariedEmployee;
    employees[1] = &newHourlyEmployee;
    employees[2] = &newCommissionedEmployee;

    cout << "\n========= ENTER EMPLOYEE DETAILS =========\n" << endl;
    for (int i = 0; i < 3; i++) {
        employees[i]->salary();
        cout << endl;
    }

    cout << "\n========= EMPLOYEE DETAILS =========\n" << endl;
    for (int i = 0; i < 3; i++) {
        employees[i]->display();
    }

    cout << "Program executed successfully by: Pranjali (Roll No. 222)" << endl;

    return 0;
}
