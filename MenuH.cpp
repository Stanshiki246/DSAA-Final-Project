/*
DSAA Final Project - Restaurant Business System
Group Members: Stanley Tantysco (2201814670), Stephanus Jovan Novarian (2201832856)
Menu and Order list class object
*/
#include "MenuH.h"
void Menu::addMenu()//add menu function
{
	//declare input variables
	string name,category;
	int in;
	double price;
	
	cout << "[1: Main Dishes\n2: Appetizers\n3: Desserts\n4: Drinks]\nChoose: ";
	cin >> in;//input category number
	cin.ignore();//ignore input
	if(in == 1)
	{
		category = "Main Dishes";//category becomes Main Dishes
	}
	else if(in == 2){
		category = "Appetizers";//category becomes Appetizers
	}
	else if(in == 3){
		category = "Desserts";//category becomes Desserts
	}
	else if(in == 4){
		category = "Drinks";//category becomes Drinks
	}
	else{
		category = "";//category becomes empty string
	}
	//check whether category is empty string or not
	if(category != "")
	{
		cout << "Enter the name of food/drink: ";
		getline(cin,name);//input name
		cout << "Enter the price: ";
		cin >> price;//input price
		if(isPrice(price))
		{
			//set input name, category, and price into FoodDrink attributes
			fd.setfood(name,category,price);
			menu.push_back(fd);//add setted FoodDrink into menu vector
			cout << "Added Successfully"<<endl;//print "Added Successfully"
		}
		else{
			cout << "Invalid Input" <<endl;//print "Invalid Input"
		}
	}
	else{
		cout << "Invalid Input"<<endl;//print "Invalid Input"
	}
	
		
}
bool Menu::delMenu(string key)//delete menu function
{
	vector<FoodDrink>::iterator veciter=menu.begin();//get iterator object
	for(veciter;veciter!=menu.end();++veciter)//iterate through menu vector
	{
		if(veciter->getname() == key)//whether key is equal to name of iterator or not
		{
			menu.erase(veciter);//delete object based on iterator
			break;//stop memory leaking
			return true;//give true statement
		}
	}
}
void Menu::viewMenu()//view menu function
{
	string name, category;//declare string variables
	//print name, category, and price tags
	cout << "Name"<<setw(36)<<"Category"<<setw(10)<<"Price"<<endl;
	//call vector iterator
	vector<FoodDrink>::iterator veciter=menu.begin();
	for(veciter;veciter!=menu.end();++veciter)//iterate through menu vector
	{
		name = veciter->getname();//get name value
		category=veciter->getcategory();//get category value
		if((category=="Main Dishes"||"Appetizers"))
		{
			cout << veciter->getname();//print name value
			cout << setw(40-name.length());//print spacing
			cout << veciter->getcategory();//print category value
			cout << setw(10);//print spacing
			cout << veciter->getprice()<<endl;//print price value
		}
		else if((category=="Drinks"||"Desserts"))
		{
			cout << veciter->getname();//print name value
			cout << setw(40-name.length());//print spacing
			cout << veciter->getcategory();//print category value
			cout << setw(15);//print spacing
			cout << veciter->getprice()<<endl;//print price value
		}	
	}
}
void Menu::viewMenu(int in)//view menu function
{
	string name, category;//declare string variables
	int catelen;//declare width setter variables
	if(in == 1){
		category = "Main Dishes";//category becomes Main Dishes
		catelen=10;//set width into 10
	}
	else if(in == 2){
		category = "Appetizers";//category becomes Appetizers
		catelen=10;//set width into 10
	}
	else if(in == 3){
		category = "Desserts";//category becomes Desserts
		catelen=10;//set width into 10
	}
	else if(in == 4){
		category = "Drinks";//category becomes Drinks
		catelen=10;//set width into 10
	}
	else{
		category = "";//category becomes empty string
	}
	//check whether category is empty string or not
	if(category != ""){
		//print name, category, and price tags
		cout << "Name"<<setw(36)<<"Category"<<setw(10)<<"Price"<<endl;
		//call vector iterator
		vector<FoodDrink>::iterator veciter=menu.begin();
		for(veciter;veciter!=menu.end();++veciter)//iterate through menu vector
		{
			name = veciter->getname();//get name value
			if(veciter->getcategory() == category){
				cout << veciter->getname();//print name value
				cout << setw(40-name.length());//print spacing
				cout << veciter->getcategory();//print category value
				cout << setw(catelen);//print spacing
				cout << veciter->getprice()<<endl;//print price value
			}
		}
	}
	else{
		cout << "Invalid Input"<<endl;//print invalid input
	}
		
}
bool Menu::isPrice(double p)//price checking function
{
	//check whether price is greater than 0
	if(p > 0)
	{
		return true;
	}
	else{
		return false;
	}
}
void Menu::load()//load file function
{
	file.open("menu.txt",ios::in);//open menu.txt file
	string line, name, category,parse=";",temp;//declare string variables
	double price;//declare double variable
	while(getline(file,line))//read file through line
	{
		name = line.substr(0,line.find(parse));//get name value after splited by ';'
		line.erase(0,line.find(parse)+parse.length());//delete ';'
		category = line.substr(0,line.find(parse));//get category value after splited by ';'
		line.erase(0,line.find(parse)+parse.length());//delete ';'
		temp = line.substr(0,line.find(parse));//get temp value after splitted by ';'
		price = atof(temp.c_str());//change temp value into double type to get price value
		
		fd.setfood(name,category,price);//set values into fd object
		menu.push_back(fd);//push fd object into menu list
	}
	file.close();//close the file
}
void Menu::save()//save file function
{
	file.open("menu.txt",ios::out);//open menu.txt file
	vector<FoodDrink>::iterator veciter=menu.begin();//call vector iterator
	for(veciter;veciter!=menu.end();++veciter)//iterate through menu vector
	{
		//write values of FoodDrink object from menu list into file
		file << veciter->getname() << ";";
		file << veciter->getcategory() << ";";
		file << veciter->getprice()<<endl;
	}
	file.close();//close the file
}
double Menu::findPrice(string key)//find price function
{
	bool found = false;//declare flag variable
	vector<FoodDrink>::iterator veciter=menu.begin();//call vector iterator
	for(veciter;veciter!=menu.end();++veciter)//iterate through menu vector
	{
		//check whether key name is equal to name value of object or not
		if(veciter->getname()==key){
			found = true;//set flag into true
			break;//break iteration
		}
	}
	//check whether flag is true or not
	if(found){
		return veciter->getprice();//give price value of flagged object
	}
	else{
		return 0;//give 0
	}
}
void Menu::addOrder()//add order function
{
	//declare input variables
	string name;
	int quantity;
	double price;
	
	cout << "Enter the name of food/drink: ";
	getline(cin,name);//input name
	//check whether price value from findPrice function is 0 or not
	if(findPrice(name)!=0){
		cout << "Enter the quantity: ";
		cin >> quantity;//input quantity
		//check whether quantity value is 0 or not
		if(isQuantity(quantity)){
			price = findPrice(name);//get price value
			//set name, price, and quantity values into order object
			od.setOrder(name,price,quantity);
			myorder.push_back(od);//add order object into order list
			cout << "Order has been added" <<endl;//print "Order has been added"
		}
		else{
			cout << "Invalid Input" <<endl;//print "Invalid Input"
		}
	}
	else{
		cout << "There is no item in the menu"<<endl;//print "No item"
	}
	
}
bool Menu::delOrder(string key)//delete order function
{
	vector<Order>::iterator veciter2=myorder.begin();//call vector iterator
	for(veciter2;veciter2!=myorder.end();++veciter2)//iterate through order list vector
	{
		//check whether key name is equal to name value of object or not
		if(veciter2->getname() == key){
			myorder.erase(veciter2);//delete order object
			break;//stop iterating
			return true;//give true statement
		}
	}
}
void Menu::viewOrder()//view order function
{
	string name;//declare string variable
	//print name, quantity, and price tags
	cout << "Name"<<setw(40)<<"Quantity"<<setw(10)<<"Price"<<setw(15)<<"Total Price"<<endl;
	vector<Order>::iterator veciter2=myorder.begin();//call vector iterator
	for(veciter2;veciter2!=myorder.end();++veciter2)//iterate through order list vector
	{
		name =veciter2->getname();//print name value
		cout << veciter2->getname() <<setw(40-name.length());//print spacing
		cout << veciter2->getquantity()<<setw(15);//print quantity value
		cout << veciter2->getprice()<<setw(15);//print spacing
		cout << veciter2->getTotal()<<endl;//print price value
	}
}
void Menu::clearOrder()//clear order function
{
	myorder.clear();//clear order list
	
}
double Menu::grandTotal()//grand total price function
{
	double total=0;//declare total price variable
	vector<Order>::iterator veciter2=myorder.begin();//call vector iterator
	for(veciter2;veciter2!=myorder.end();++veciter2){
		total = total + veciter2->getTotal();//get total price value
	}
	return total;//give total price value
}
bool Menu::isQuantity(int q)//quantity checking function
{
	//check whether input q is greater than 0 or not
	if(q > 0){
		return true;//give true statement
	}
	else{
		return false;//give false statement
	}
}
void Menu::save(string t)//overloading save function
{
	file.open(t.c_str(),ios::out);//open input named file
	vector<Order>::iterator veciter2=myorder.begin();//call vector iterator
	for(veciter2;veciter2!=myorder.end();++veciter2)//iterate through order list vector
	{
		//write values of Order object from order list into file 
		file << veciter2->getname() <<";";
		file << veciter2->getquantity()<<";";
		file << veciter2->getprice()<<endl;
	}
	file.close();//close the file
}
void Menu::load(string t)//overloading load function
{
	file.open(t.c_str(),ios::in);//open input named file
	string line, name,parse=";",temp1,temp2;//declare string variables
	double price,total;//declare double variables
	int quantity;//declare integer variables
	while(getline(file,line))//read file through line
	{
		name = line.substr(0,line.find(parse));//get name value after splited by ';'
		line.erase(0,line.find(parse)+parse.length());//delete ';'
		temp1 = line.substr(0,line.find(parse));//get temp1 value after splitted by ';'
		line.erase(0,line.find(parse)+parse.length());//delete ';'
		quantity  = atoi(temp1.c_str());//change temp1 value into double type to get price value
		temp2 = line.substr(0,line.find(parse));//get temp2 value after splitted by ';'
		price = atof(temp2.c_str());//change temp2 value into double type to get price value
		
		od.setOrder(name,price,quantity);//set values into od object
		myorder.push_back(od);//push od object into order list
	}
	file.close();//close the file
}
bool Menu::isEmptyOrder()//empty order checking function
{
	return myorder.empty();//give statement whether order list is empty or not
}
