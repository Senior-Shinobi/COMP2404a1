
#include "Student.h"

//no arg constructor
Student::Student(){
	name = "Default";
	number = "0";
}
//arg constructor
Student::Student(string nam, string num){
	name = nam;
	number = num;
}
//copy constructor
Student::Student(Student& s){
	name = s.name;
	number = s.number;
}
//getter for name
string Student::getName(){
	return name;
}
//getter for number
string Student::getNumber(){
	return number;
}
//setter for name
void Student::setName(string n){
	name = n;
}
//setter for number
void Student::setNumber(string n){
	number = n;
}
//comparison function for students
bool Student::lessThan(Student& s){
	if (number.compare(s.number) <= 0){
		return true;
	}
	return false;
}

//prints student info
void Student::print(){
	cout<< getName()<<", #"<<getNumber()<<endl;
}
