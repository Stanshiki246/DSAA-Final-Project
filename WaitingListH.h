#ifndef WaitingListH
#define WaitingListH
/*
DSAA Final Project - Restaurant Business System
Group Members: Stanley Tantysco (2201814670), Stephanus Jovan Novarian (2201832856)
Menu and Order list class object
*/
#include <string>
#include <list>
#include <iomanip>
#include <iostream>
using namespace std;

class WaitingList{
	private:
		list<pair <string,int> > waitlist;//call list object using pair of string and int
	public:
		void enqueue(string n, int c);//enqueue customer function
		void dequeue();//dequeue customer function
		string getname();//customer name getter function
		int getnumofCustomers();//number of customers getter function
		void viewlist();//view waiting list function
		string callCustomer();//call customer function
		bool isEmptyList();//empty waiting list checking function
}; 
#endif
