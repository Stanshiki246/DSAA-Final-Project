#ifndef MenuH
#define MenuH
/*
DSAA Final Project - Restaurant Business System
Group Members: Stanley Tantysco (2201814670), Stephanus Jovan Novarian (2201832856)
Menu and Order list class object
*/
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include "FoodDrinkH.h"
#include "OrderH.h"
using namespace std;
class Menu{
	private:
		vector<Order> myorder;//call vector object using Order class
		Order od;//call Order object
		vector<FoodDrink> menu;//call vector object using FoodDrink class
		FoodDrink fd;//call FoodDrink object
		fstream file;//call fstream object
	public:
		void addMenu();//add menu function
		bool delMenu(string key);//delete menu function
		void viewMenu();//view menu list function
		void viewMenu(int in);// overloading view menu list function
		double findPrice(string key);//find price function
		bool isPrice(double p);//price checking function
		void save();//save function
		void load();//load function
		void addOrder();//add order function
		bool delOrder(string key);//delete order function
		void viewOrder();//view order function
		void clearOrder();//clear order function
		double grandTotal();//grand total price getter function
		bool isQuantity(int q);// quantity checking function
		void save(string t);//overloading save function
		void load(string t);//overloading load function
		bool isEmptyOrder();// empty order checking function
};
#endif
