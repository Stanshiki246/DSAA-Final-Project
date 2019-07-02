#ifndef RestaurantUIH
#define RestaurantUIH
/*
DSAA Final Project - Restaurant Business System
Group Members: Stanley Tantysco (2201814670), Stephanus Jovan Novarian (2201832856)
Menu and Order list class object
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <map>
#include "FoodDrinkH.h"
#include "MenuH.h"
#include "OrderH.h"
#include "TableH.h"
#include "WaitingListH.h"
using namespace std;
class RestaurantUI{
	public:
		void mainUI();//main UI function
	private:
		Menu m;//call Menu object
		Table t;//call Table List object
		WaitingList wl;//call Waiting List object
		//declare boolean variables
		bool run = true,menuUI=true,orderUI=true,wlUI=true,proc=true,proc2=true;
		//declare string variables
		string key,f,text,customer;
		//declare integer variables
		int choice,choice2,choice3,choice4,in,numofCus,tablenum;
		double payment;//declare double variable
		char attend;//declare char variable
		void OrderUI();//Order UI function
		void MenuUI();//Menu UI function
		void WaitingListUI();//Waiting List UI function
		void AddMenuUI();//Add Menu UI function
		void AddOrderUI();//Add Order UI function
		void DelMenuUI();//Delete Menu UI function
		void DelOrderUI();//Delete Order UI function
		void ViewMenuUI();//View Menu UI function
		void ViewOrderUI();//View Order UI function
		void TakeBillUI();//Take Bill UI function
		void SaveOrderUI();//Save Order UI function
		void LoadOrderUI();//Load Order UI function
		void CheckTableUI();//Check Table Number UI function
		void CallCustomerUI();//Call Customer Name UI function
		void ViewWaitingListUI();//View Waiting List UI function
		bool isTableNumber(int n);//Table Number checking function
};
#endif
