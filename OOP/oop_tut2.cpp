/*
Employee Information System
Develop a program in C++ to create a database of an employee&#39;s information
system containing the following fields: Name, employee ID, Department, Date of
Joining, Contact address, Telephone number etc. Construct the database with
suitable member functions to accept and print employee details. Make use of
constructor types, destructor, static members, inline function and dynamic
memory allocation using operators-new and delete
*/


#include <iostream>
#include <string>
using namespace std;

class Employee{
   string name, department, doj, address, telephone;
   int emp_id;

   public:
   static int count;
   inline Employee();
   inline Employee(string name, string depart, string doj, string add, string tele, int id);
   Employee(const Employee &obj);

   void display();
   void getdata();

   ~Employee(){
       cout << "Object no. " << count << " destroyed!" << endl;
       count--;
   }
};

int Employee::count = 0;

Employee::Employee(){   // default constructor
    count++;

    name = "Default";
    department = "Default";
    doj = "Not Defined";
    address = "Not Defined";
    telephone = "Default";
    emp_id = 0000;
}

// parameterized constructor
Employee::Employee(string name, string depart, string doj, string add, string tele, int id){
    count++;

    this->name = name;
    department = depart;
    this->doj = doj;
    address = add;
    telephone = tele;
    emp_id = id;
}

// copy constructor
Employee::Employee(const Employee &obj){
    count++;

    name = obj.name;
    department = obj.department;
    doj = obj.doj;
    address = obj.address;
    telephone = obj.telephone;
    emp_id = obj.emp_id;
}

void Employee::display(){
    cout << "Name: " << name << endl;
    cout << "Department: " << department << endl;
    cout << "Date of joining: " << doj << endl;
    cout << "Address: " << address << endl;
    cout << "Telephone: " << telephone << endl;
    cout<< "Employee ID: " << emp_id << endl;
}

void Employee::getdata(){
    // cin.ignore();

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter Department: ";
    getline(cin, department);

    cout << "Enter Date of Joining: ";
    getline(cin, doj);

    cout << "Enter Address: ";
    getline(cin, address);

    cout << "Enter Telephone: ";
    cin >> telephone;

    cout << "Enter ID: ";
    cin >> emp_id;
}

int main(){
    Employee emp[3] = {
        Employee(),   // default constructor
        Employee("Neel", "Computer Engg", "26 /07/ 2021", "Pune, Maharashtra", "9922910011", 0022),   // parameterized constructor
        Employee(emp[1])    // copy constructor
    };

    cout << "Employee 1, before feeding data:" << endl;
    emp[0].display();

    cout << "\nEnter data for Employee 1:" << endl;
    // cout << endl;
    emp[0].getdata();

    cout << endl;

    cout << "\nFinal data:" << endl;

    emp[0].display();
    cout << "\n";

    emp[1].display();
    cout << "\n";

    emp[2].display();
    cout << "\n";

    return 0;

}
