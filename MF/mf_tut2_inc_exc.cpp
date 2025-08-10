#include<iostream>
using namespace std;

int main(){
	int size_universal = 200;
	int size_sports = 120;
	int size_music = 90;
	int size_intersection = 50;
	
	cout << "\nStudents in either one club: " << size_music + size_sports - size_intersection;
	cout << "\nStudents only in Sports Club: " << size_sports - size_intersection;
	cout << "\nStudents only in Music Club: " << size_music - size_intersection;
	cout << "\nStudents in neither club: " << size_universal - (size_music + size_sports - size_intersection);
	
	return 0;
}

