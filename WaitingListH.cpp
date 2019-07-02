/*
DSAA Final Project - Restaurant Business System
Group Members: Stanley Tantysco (2201814670), Stephanus Jovan Novarian (2201832856)
Menu and Order list class object
*/
#include "WaitingListH.h"
void WaitingList::enqueue(string n, int c)//enqueue customer function
{
	//add pair of customer name and number of customers into waiting list
	waitlist.push_back(make_pair(n,c));
	//print customer name after being added
	cout << waitlist.back().first << " is added into waiting list" << endl;
}
void WaitingList::dequeue()//dequeue customer function
{
	waitlist.pop_front();//delete front of waiting list
}
string WaitingList::getname()//customer name getter function
{
	return waitlist.back().first;//give back of waiting list's customer name
}
int WaitingList::getnumofCustomers()//number of customers getter function
{
	return waitlist.back().second;// give bacl of waiting list's number of customers
}
void WaitingList::viewlist()//view waiting list function
{
	string name;//declare string variable
	//print customer name and number of customers tags
	cout << "Name"<<setw(40)<<"Number of Person"<<endl;
	list< pair<string, int> >::iterator liter=waitlist.begin();//call list iterator
	for(liter;liter!=waitlist.end();++liter)//iterate through waiting list
	{
		name = liter->first;//get name value
		cout << liter->first << setw(40-name.length());//print customer name and spacing
		cout << liter->second << endl;//print number of customers
	}
}
string WaitingList::callCustomer()//call customer function
{
	return waitlist.front().first;//give front of waiting list's customer name
}
bool WaitingList::isEmptyList()//empty waiting list checking function
{
	return waitlist.empty();//give statement whether waiting list is empty or not
}
