#ifndef OrderListH
#define OrderListH
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "OrderH.h"
#include "MenuH.h"
using namespace std;
class OrderList{
	private:
		vector<Order> myorder;
		Order od;
		fstream file;
	public:
		void addOrder(Menu m);
		bool delOrder(string key);
		void viewOrder();
		void clearOrder();
		double grandTotal();
		void save(string t);
		void load(string t);
		bool isEmptyOrder();
};
#endif
