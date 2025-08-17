#include<iostream>
#include<string>
using namespace std;

class Institute{
	public:
		string ins_name = "MMCOE";
		int estd_year = 2006;
		string courses[3] = {"Computer", "AIDS", "Electrical"};

		void ins_display();
};

void Institute :: ins_display(){
	cout << "Belonging to Institution: " << ins_name << endl;
	cout << "Established in the year: " << estd_year << endl;

	cout << "Courses offered by " << ins_name << ": ";
	
	for (int i = 0; i < 3; i++){
		cout << courses[i] << " ";
	}
	cout << endl;
}

class Students : public Institute{
	public:
		string name, stream, grad_year;
		
		void getdata();
		void display(); 
};

class Teachers : public Institute{
	public:
		int salary;
		string name, department, doj;
		
		void getdata();
		void display();
};

void Students :: getdata(){
	cout << "Name: "; 
	getline(cin, name);
	cout << "Stream: "; 
	getline(cin, stream);
	cout << "Graduation Year: "; 
	getline(cin, grad_year);  
}

void Students :: display(){
	cout << "Student's name: " << name << endl;
	ins_display();
	
	cout << "Course opted by " << name << ": " << stream << endl;
	cout << "Graduation by the year: " << grad_year << endl;
}

void Teachers :: getdata(){
	cout << "Name: "; 
	getline(cin, name);
	cout << "Salary: "; 
	cin >> salary;
	cin.ignore();
	cout << "Stream: "; 
	getline(cin, department);
	cout << "Date of joining: "; 
	getline(cin, doj);
}

void Teachers :: display(){
	cout << "Teacher's name: " << name << endl;
	ins_display();
	
	cout << "Course taught by " << name << ": " << department << endl;
	cout << "Date of joining: " << doj << endl;
	cout << "Salary: " << salary << endl;
}

int main(){
	Students s[3];
	Teachers t[3];
	
	cout << "Enter data for the Student 1" << endl;
	s[0].getdata(); cout << endl;
	cout << "Enter data for the Student 2" << endl;
	s[1].getdata(); cout << endl;
	cout << "Enter data for the Student 3" << endl;
	s[2].getdata(); cout << endl;
	
	cout << "Enter data for the teacher 1" << endl;
	t[0].getdata(); cout << endl;
	cout << "Enter data for the teacher 2" << endl;
	t[1].getdata(); cout << endl;
	cout << "Enter data for the teacher 3" << endl;
	t[2].getdata(); cout << endl;
	
	cout << "-----" << endl;
	
	s[0].display(); cout << endl;
	s[1].display(); cout << endl;
	s[2].display(); cout << endl;
	
	t[0].display(); cout << endl;
	t[1].display(); cout << endl;
	t[2].display(); cout << endl;
	
	return 0;
}
