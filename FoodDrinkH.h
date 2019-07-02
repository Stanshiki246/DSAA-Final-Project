#ifndef FoodDrinkH
#define FoodDrinkH
/*
DSAA Final Project - Restaurant Business System
Group Members: Stanley Tantysco (2201814670), Stephanus Jovan Novarian (2201832856)
Food and Drink class object
*/
#include <string>
using namespace std;

class FoodDrink{
	private:
		//declare private attributes
		string name;
		string category;
		double price;
	public:
		FoodDrink();//Constructor
		void setfood(string n,string c,double p);//food setter function
		string getname() const;//name getter function
		string getcategory() const;//category getter function
		double getprice() const;//price getter function
};
#endif
