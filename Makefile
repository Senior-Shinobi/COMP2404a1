a1:	main.o Library.o Reservation.o Room.o Date.o Student.o
	g++ -o a1 main.o Library.o Reservation.o Room.o Date.o Student.o

main.o:	main.cc Date.h Library.h
	g++ -c main.cc

Library.o: Library.cc Library.h Reservation.h Room.h Date.h Student.h
	g++ -c Library.cc

Reservation.o: Reservation.cc Reservation.h Room.h Date.h Student.h
	g++ -c Reservation.cc

Room.o:	Room.cc Room.h
	g++ -c Room.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Student.o:	Student.cc Student.h
	g++ -c Student.cc

clean:
	rm -f *.o a1
