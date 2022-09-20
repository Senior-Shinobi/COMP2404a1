
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {

	public:

		//constructors
		Student();
		Student(string, string);
		Student(Student&);

		//getter functions
		string getName();
		string getNumber();

		//setter functions
		void setName(string);
		void setNumber(string);

		//other
		bool lessThan(Student&);
		void print();

	private:
		string name, number;


};
#endif
