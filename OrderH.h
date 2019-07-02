#ifndef OrderH
#define OrderH
/*
DSAA Final Project - Restaurant Business System
Group Members: Stanley Tantysco (2201814670), Stephanus Jovan Novarian (2201832856)
Food order class object
*/
#include <string>
using namespace std;
class Order{
	private:
		//declare private attributes
		string name;
		double price;
		int quantity;
	public:
		Order();//Constructor
		void setOrder(string n, double p, int q);//order setter function
		string getname() const;//name getter function
		double getprice() const;//price getter function
		int getquantity() const;//quantity getter function
		double getTotal() const;//total price getter function
};
#endif
