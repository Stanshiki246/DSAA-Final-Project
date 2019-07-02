/*
DSAA Final Project - Restaurant Business System
Group Members: Stanley Tantysco (2201814670), Stephanus Jovan Novarian (2201832856)
Menu and Order list class object
*/
#include "TableH.h"
void Table::addTable(string t,string n)//add table number function
{
	//check whether empty table is available or not
	if(isAvailable()){
		slot.insert(make_pair(t,n));//add table number and customer name into table list
	}
	else{
		cout << "Tables are full" << endl;//print "Tables are full"
	}	
}
void Table::removeTable(string t)//remove table number function
{
	bool deleted = false;//declare flag variable
	map<string,string>::iterator miter=slot.begin();//call map iterator
	for(miter;miter!=slot.end();++miter)//iterate through table list map
	{
		//check whether table number is equal to table list key
		if(miter->first==t){
			slot.erase(miter);//delete table list key and value
			deleted = true;//set flag into true
			break;//stop iterating
		}
	}
	//check whether flag is true or not
	if(deleted){
		cout << "Deleted Successfully" <<endl;//print "Deleted Successfully"
	}
	else{
		cout << "There is nothing to be deleted"<<endl;//print "There is nothing to be deleted"
	}	
}
bool Table::isAvailable()//available table number function
{
	//check whether amount of tables is less than 10 or not
	if(slot.size()<10){
		return true;//give true statement
	}
	else{
		return false;//give false statement
	}
}
string Table::getname(string t)//customer name getter function
{
	bool found = false;//declare flag variable
	map<string,string>::iterator miter=slot.begin();//call map iterator
	for(miter;miter!=slot.end();++miter)//iterate through table list map
	{
		//check whether table number is equal to table list key or not
		if(miter->first == t){
			found = true;//set flag into true
			break;//stop iterating
		}
	}
	//check whether flag is true or not
	if(found){
		return miter->second;//give flagged table list value
	}
	else{
		return "";//give empty string
	}
}
bool Table::isEmptyTable()//empty table list checking function
{
	return slot.empty();//give statement whether table list is empty or not
}
bool Table::isOccupied(string t)//occupied table number checking function
{
	bool found = false;//declare flag variable
	map<string,string>::iterator miter=slot.begin();//call map iterator
	for(miter;miter!=slot.end();++miter)//iterate through table list map
	{
		//check whether table number is equal to table list key or not
		if(miter->first == t){
			found = true;//set flag into true
			break;//stop iterating
		}
	}
	return found;//give flag statement
}
