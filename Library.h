
#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>

#include "Reservation.h"
#include "Student.h"
#include "Room.h"
#include "Date.h"

using namespace std;

class Library {

	public:

		//constructors
		Library();
		~Library();

		//getters
		bool getStudent(const string& name,Student** student);
		bool getRoom(const string& roomName,Room** room);

		//other
		bool addStudent(const string& name, const string& number);
		bool addRoom(string, int=0, int=0, bool=false);
		bool isFree(const string& room, Date&);
		bool makeReservation(const string& student,const string& room,Date&);

		//print methods
		void printReservations();
		void print();


	private:
		//max size of arrays set to 32
		Student** studArr;
		int studSize;
		Room* roomArr[32];
		int roomSize;
		Reservation** resArr;
		int resSize;


};
#endif
