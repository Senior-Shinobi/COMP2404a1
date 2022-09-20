
#include "Date.h"

//no arg constructor
Date::Date(){
	setDate(1,1,1901,0,0);
}
//arg constructor
Date::Date(int y, int m, int d, int h, int dur){
	setDate(y,m,d,h,dur);
}
//copy constructor
Date::Date(Date& d){
	setDate(d.year,d.month,d.day,d.hour,d.duration);
}


//setter for day
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}
//setter for month
void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}
//setter for year
void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}
//setter for hour
void Date::setHour(int h){
	if (h >= 23){
		h = 23;
	}
	if (h <= 0){
		h = 0;
	}
	hour = h;
}
//setter for duration
void Date::setDuration(int d){
	if (d >= MAX_DUR){
		d = MAX_DUR;
	}
	if (d <= 0){
		d = 0;
	}
	duration = d;
}
//setter for date
void Date::setDate(int y, int m, int d, int h, int dur){
	setMonth(m);
	setDay(d);
	setYear(y);
	setHour(h);
	setDuration(dur);
}
//copy setter for date
void Date::setDate(Date& d){
	setDate(d.day, d.month, d.year, d.hour, d.duration);
}


//getters
int Date::getDay(){ return day; }
int Date::getMonth(){ return month; }
int Date::getYear(){ return year; }
int Date::getHour(){ return hour; }
int Date::getDuration(){ return duration; }
const string& Date::getMonthName(){return months[month-1];}


//other
//compares dates
bool Date::lessThan(Date& d){
	if (year == d.year){
		if (month == d.month){
			if (day == d.day){
					return hour < d.hour;
			}else{
					return day < d.day;
			}
		}else{
			return month  < d.month;
		}
	}else{
		return year < d.year;
	}
}
//checker for if dates and times overlap
bool Date::overlaps(Date& d){
	if (year == d.year && month == d.month && day == d.day){
		if (hour == d.hour){
			return true;
		} else if (((hour + duration) > d.hour)&& hour < d.hour){
			return true;
		} else if (((d.hour + d.duration) > hour)&& hour > d.hour){
			return true;
		}
	}
	return false;
}

void Date::print(){
	cout << getMonthName()<<" "<<getDay()<<", "<<getYear()
	<< ". "<< getHour()<<":00 duration: "<< getDuration()<<endl;
}

int Date::getMaxDay(){
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}
