#include <iostream>
using namespace std;
#include "Library.h"
#include "Date.h"
#include "a1-global.cc"

int main()
{
  //testing date overlap
  /*
  Date d1(2020,1,24,11,3);
  Date d2(2020,1,23,11,3);
  testDate(d1,d2,false);
  Date d3(2020,1,23,11,3);
  Date d4(2020,1,23,14,3);
  testDate(d3,d4,false);
  Date d5(2020,1,23,11,1);
  Date d6(2020,1,23,12,3);
  testDate(d5,d6,false);
  Date d7(2020,1,23,11,3);
  Date d8(2020,1,23,12,3);
  testDate(d7,d8,true);
  Date d9(2020,1,23,12,3);
  Date d10(2020,1,23,12,3);
  testDate(d9,d10,true);
*/
  //creates library object
  Library l;
  populate(l);
  testReservations(l);


  return 0;
}
