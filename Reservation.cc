
#include "Reservation.h"


//constructor
Reservation::Reservation(Student* s, Room* r, Date& d){
	student = s;
	room = r;
	date = &d;
}
//destructor
Reservation::~Reservation(){
	
}

//getter for student
Student* Reservation::getStudent(){
	return student;
}
//getter for room
Room* Reservation::getRoom(){
	return room;
}
//getter for computers
Date* Reservation::getDate(){
	return date;
}
//checks if Reservation dates overlap
bool Reservation::lessThan(Reservation& res){
	return date->lessThan(*res.getDate());
}
//checks if room times overlap
bool Reservation::overlaps(string r, Date& d){
	if (r == room->getName() && d.overlaps(*date)){
		return true;
	}
	return false;
}

//prints Reservation info
void Reservation::print(){
	cout<<"Reservation details:"<<endl;
	student->print();
	room->print();
	date->print();
	cout<<endl<<endl;
}
