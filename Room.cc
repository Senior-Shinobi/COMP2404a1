
#include "Room.h"


//arg constructor
Room::Room(string nam, int cap, int comp, bool wb){
	name = nam;
	capacity = cap;
	computers = comp;
	whiteboard = wb;
}
//copy constructor
Room::Room(Room& r){
	name = r.name;
	capacity = r.capacity;
	computers = r.computers;
	whiteboard = r.whiteboard;
}
//getter for name
string Room::getName(){
	return name;
}
//getter for number
int Room::getCapacity(){
	return capacity;
}
//getter for computers
int Room::getComputers(){
	return computers;
}
//getter for whiteboard
bool Room::hasWhiteboard(){
	return whiteboard;
}
//setter for name
void Room::setName(string n){
	name = n;
}
//setter for capacity
void Room::setCapacity(int c){
	capacity = c;
}
//setter for computers
void Room::setComputers(int c){
	computers = c;
}
//setter for capacity
void Room::setWhiteboard(bool w){
	whiteboard = w;
}
//function that returns true if all criteria is met
bool Room::meetsCriteria(int cap, int comp, bool w){
	if (cap <= capacity){
		if (comp < 0 || comp <= computers){
			if (w == whiteboard || whiteboard == true){
				return true;
			}
		}
	}
	return false;
}
//comparison function for room names
bool Room::lessThan(Room& r){
	if (name.compare(r.name) <= 0){
		return true;
	}
	return false;
}

//prints all room info
void Room::print(){
	cout<<getName()<<", Max capacity: "<<getCapacity()
	<<", computers in room: "<<getComputers()<<", has a whiteboard: "
	<<hasWhiteboard()<<endl;
}
