#ifndef TableH
#define TableH
/*
DSAA Final Project - Restaurant Business System
Group Members: Stanley Tantysco (2201814670), Stephanus Jovan Novarian (2201832856)
Menu and Order list class object
*/
#include <string>
#include <map>
#include <iostream>
using namespace std;
class Table{
	private:
		map<string,string> slot;//call map object using string key and string value
	public:
		bool isAvailable();//available table number checking function
		void addTable(string t,string n);//add table number function
		void removeTable(string t);//remove table number function
		string getname(string t);//customer name getter function 
		bool isEmptyTable();//empty table list checking function
		bool isOccupied(string t);// occupied table number checking function
};
#endif
