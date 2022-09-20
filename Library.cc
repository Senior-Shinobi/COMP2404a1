
#include "Library.h"


//constructor
Library::Library(){
	 studArr = new Student*[32];
	 resArr = new Reservation*[32];
	 resSize = 0;
	 studSize = 0;
	 roomSize = 0;
}
//destructor
Library::~Library(){

	for (int i=0; i<resSize; ++i){
    delete resArr[i];
  }
  delete[] resArr;
	for (int i=0; i<studSize; ++i){
    delete studArr[i];
  }
  delete[] studArr;
	for (int i=0; i<roomSize; ++i){
    delete roomArr[i];
  }
}

//adds students to array in sorted order
bool Library::addStudent(const string& name, const string& number){
  if (studSize<32){
		int temp = 0;
		Student* s = new Student(name,number);
    for (int i = 0;i<studSize;i++){

      if (s->lessThan(*studArr[i])){

        temp =i;
        break;
      }

    }
    for (int i = studSize;i>=temp;i--){
      studArr[i+1] = studArr[i];
    }
    studArr[temp] = s;
    studSize++;
		return true;
  }
	return false;
}

//adds rooms to array in sorted order
bool Library::addRoom(string a, int b, int c, bool d){
  if (roomSize<32){
		int temp = 0;
		Room* r = new Room(a,b,c,d);
    for (int i = 0;i<roomSize;i++){

      if (r->lessThan(*roomArr[i])){

        temp =i;
        break;
      }

    }
    for (int i = roomSize;i>=temp;i--){
      roomArr[i+1] = roomArr[i];
    }
    roomArr[temp] = r;
    roomSize++;
		return true;
  }
	return false;
}
//getter for student
bool Library::getStudent(const string& name,Student** student){
	for (int i = 0;i<studSize;i++){
		if (name == (*studArr[i]).getName()){
			*student = studArr[i];
			return true;
		}
	}
	return false;
}
//getter for room
bool Library::getRoom(const string& roomName,Room** room){
	for (int i = 0;i<roomSize;i++){
		if (roomName == (*roomArr[i]).getName()){
			*room = roomArr[i];
			return true;
		}
	}
	return false;
}
//checks if a given room exists and is occupied
bool Library::isFree(const string& room, Date& d){
	bool check = false;
	for (int i = 0;i<roomSize;i++){

		if (room.compare((*roomArr[i]).getName()) == 0){
			check = true;
		}
	}
	if (check){

		for (int i = 0;i<resSize;i++){

			if (room.compare((*resArr[i]).getRoom()->getName()) == 0){

				return !(*resArr[i]).overlaps(room,d);
			}
		}
		return true;
	}
	return false;
}
//adds a reservation to the array
bool Library::makeReservation(const string& student, const string& room, Date& d){
	if (resSize<32){
		Student* s;
		Room* r;
		if (getStudent(student,&s)){
			cout<<"hello\n";
			s->print();
			cout<<"hello2\n";
			if (getRoom(room,&r)){
				r->print();
				if (isFree(room,d)){
					Reservation* res = new Reservation(s,r,d);
					int temp = 0;
					for (int i = 0;i<resSize;i++){

			      if (res->lessThan(*resArr[i])){

			        temp =i;
			        break;
			      }

			    }
			    for (int i = resSize;i>=temp;i--){
			      resArr[i+1] = resArr[i];
			    }
			    resArr[temp] = res;
			    resSize++;
					return true;
				}
			}
		}
	}
	return false;
}

//prints all reservations
void Library::printReservations(){
	for (int i = 0;i<resSize;i++){
		resArr[i]->print();
	}
}

//prints everything
void Library::print(){
	printReservations();
	for (int i=0; i<studSize; ++i){
    studArr[i]->print();
  }
  delete[] studArr;
	for (int i=0; i<roomSize; ++i){
    roomArr[i]->print();
  }
}
