#include <iostream>
using namespace std;

class construct {
public:
    float area;
    construct() {
        area = 0;
    }

    construct(int a, int b) {
        area = a * b;
    }

    void disp() {
        cout << area << endl;
    }
};

int main() {
    cout << "Name: Malaprabha Bekwadkar"<< endl;
    cout << "Roll No:40" << endl;
    cout << "Division:B" << endl;
    cout << "Department: CSE(SY)" << endl;

    construct o1;          
    construct o2(10, 20);  
    o1.disp();  
    o2.disp();  
    return 0;
}
