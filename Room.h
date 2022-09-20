
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room {

	public:

		//constructors
		Room(string, int, int, bool);
		Room(Room&);

		//getter functions
		string getName();
		int getCapacity();
		int getComputers();
		bool hasWhiteboard();

		//setter functions
		void setName(string);
		void setCapacity(int);
		void setComputers(int);
		void setWhiteboard(bool);

		//other
		bool meetsCriteria(int, int = -1, bool = true);
		bool lessThan(Room&);
		void print();

	private:
		string name;
		int capacity, computers;
		bool whiteboard;


};
#endif
