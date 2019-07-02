#include "OrderListH.h"
void OrderList::addOrder(Menu m){
	
	string name;
	int quantity;
	double price;
	
	cout << "Enter the name of food/drink: ";
	getline(cin,name);
	
	if(m.findPrice(name)!=0){
		cout << "Enter the quantity: ";
		cin >> quantity;
		price = findPrice(name);
		od.setOrder(name,price,quantity);
		myorder.push_back(od);
		cout << "Order has been added" <<endl;
	}
	else{
		cout << "There is no item in the menu"<<endl;
	}
	
}
bool OrderList::delOrder(string key){
	vector<Order>::iterator veciter2=myorder.begin();
	for(veciter2;veciter2!=myorder.end();++veciter2){
		if(veciter2->getname() == key){
			myorder.erase(veciter2);
			break;
			return true;
		}
	}
}
void OrderList::viewOrder(){
	cout << "Name\tQuantity\tPrice\tTotal Price"<<endl;
	vector<Order>::iterator veciter2=myorder.begin();
	for(veciter2;veciter2!=myorder.end();++veciter2){
		cout << veciter2->getname() <<"\t";
		cout << veciter2->getquantity()<<"\t";
		cout << veciter2->getprice()<<"\t";
		cout << veciter2->getTotal()<<endl;
	}
}
void OrderList::clearOrder(){
	myorder.clear();
	
}
double OrderList::grandTotal(){
	double total=0;
	vector<Order>::iterator veciter2=myorder.begin();
	for(veciter2;veciter2!=myorder.end();++veciter2){
		total = total + veciter2->getTotal();
	}
	return total;
}
void OrderList::save(string t){
	file.open(t.c_str(),ios::out);
	vector<Order>::iterator veciter2=myorder.begin();
	for(veciter2;veciter2!=myorder.end();++veciter2){
		file << veciter2->getname() <<";";
		file << veciter2->getquantity()<<";";
		file << veciter2->getprice()<<endl;
	}
	file.close();
}
void OrderList::load(string t){
	file.open(t.c_str(),ios::in);
	string line, name,parse=";",temp1,temp2;
	double price,total;
	int quantity;
	while(getline(file,line)){
		name = line.substr(0,line.find(parse));
		line.erase(0,line.find(parse)+parse.length());
		temp1 = line.substr(0,line.find(parse));
		line.erase(0,line.find(parse)+parse.length());
		quantity  = atoi(temp1.c_str());
		temp2 = line.substr(0,line.find(parse));
		price = atof(temp2.c_str());
		
		od.setOrder(name,price,quantity);
		myorder.push_back(od);
	}
	file.close();
}
bool OrderList::isEmptyOrder(){
	return myorder.empty();
}
