/*
DSAA Final Project - Restaurant Business System
Group Members: Stanley Tantysco (2201814670), Stephanus Jovan Novarian (2201832856)
Food order class object
*/
#include "OrderH.h"
Order::Order()//Constructor
{
	name = "";
	price = 0.0;
	quantity = 0;
}
void Order::setOrder(string n,double p,int q)//order setter function
{
	name = n;
	price = p;
	quantity = q;
}
string Order::getname() const //name getter function
{
	return name;
}
double Order::getprice() const //price getter function
{
	return price;
}
int Order::getquantity() const //quantity getter function
{
	return quantity;
}
double Order::getTotal() const //total price getter function
{
	return price*quantity;
}
