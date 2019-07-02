/*
DSAA Final Project - Restaurant Business System
Group Members: Stanley Tantysco (2201814670), Stephanus Jovan Novarian (2201832856)
Food and Drink class object
*/
#include "FoodDrinkH.h"
FoodDrink::FoodDrink()//Constructor
{
	name="";
	category="";
	price=0.0;
}
void FoodDrink::setfood(string n,string c,double p)//food setter function
{
	name = n;
	category = c;
	price = p;
}
string FoodDrink::getname() const //name getter function
{
	return name;
}
double FoodDrink::getprice() const //price getter function
{
	return price;
}
string FoodDrink::getcategory() const //category getter function
{
	return category;
}
