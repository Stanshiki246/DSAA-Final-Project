/*
DSAA Final Project - Restaurant Business System
Group Members: Stanley Tantysco (2201814670), Stephanus Jovan Novarian (2201832856)
Menu and Order list class object
*/
#include "RestaurantUIH.h"
void RestaurantUI::mainUI()//main UI function
{
	m.load();//call load menu function
	while(run){
		cout << "1.Menu\n2.Order\n3.Waiting List\n4.Exit\n>";
		cin >> choice;//input choice
		cin.ignore();//ignore input
		if(choice == 1){
			MenuUI();//call Menu UI function
		}
		else if(choice == 2){
			OrderUI();//call Order UI function
		}
		else if(choice == 3){
			WaitingListUI();//call Waiting List UI function
		}
		else if(choice == 4){
			m.save();//call save menu function
			run = false;//quit main program
			break;//stop looping
		}
		else{
			cout << "Invalid Input"<<endl;//print 'invalid input'
		}
	}
}
void RestaurantUI::OrderUI()//Order UI function
{
	//check whether table number list is empty or not
	if(t.isEmptyTable()){
		//print 'show table number first'
		cout << "You have to show the table number first"<<endl;
		orderUI=false;//cannot enter order UI
	}
	else{
		orderUI=true;//enter order UI
	}
	while(orderUI){
		cout << "1.Add Order\n2.Delete Order\n3.View Menu\n4.View Order\n5.Take Bill\n";
		cout << "6.Save Order\n7.Load Order\n8.Back\n>";
		cin >> choice3;//input choice
		cin.ignore();//ignore input
		if(choice3 == 1){
			AddOrderUI();//call add order UI function
		}
		else if(choice3 == 2){
			DelOrderUI();//call delete order UI function
		}
		else if(choice3 == 3){
			ViewMenuUI();//call view menu UI function
		}
		else if(choice3 == 4){
			ViewOrderUI();//call view order list UI function
		}
		else if(choice3 == 5){
			TakeBillUI();//call take bill UI function		
		}
		else if(choice3 == 6){
			SaveOrderUI();//call save order list UI function
		}
		else if(choice3== 7){
			LoadOrderUI();//call load order list UI function
		}
		else if(choice3==8){
			orderUI = false;//quit order UI
		}
		else{
			cout << "Invalid Input"<<endl;//print 'invalid input'
		}	
	}
}
void RestaurantUI::MenuUI()//Menu UI function
{
	menuUI = true;//enter menu UI
	while(menuUI){
		cout << "1.Add Menu\n2.Delete Menu\n3.View Menu\n4.Back\n>";
		cin >> choice2;//input choice
		cin.ignore();//ignore input
		if(choice2 == 1){
			AddMenuUI();//call add menu UI function	
		}
		else if(choice2 ==2){
			DelMenuUI();//call delete menu UI function
		}
		else if(choice2 == 3){
			ViewMenuUI();//call view menu UI function
		}
		else if(choice2 == 4){
			m.save();//call save menu function
			menuUI = false;//quit menu UI
		}
		else{
			cout << "Invalid Input" <<endl;//print 'invalid input'
		}
	}
}
void RestaurantUI::WaitingListUI()//Waiting List UI function
{
	wlUI=true;//enter waiting list UI
	while(wlUI){
		cout << "1.Check Table\n2.Call Customer\n3.View Waiting List\n4.Back\n>";
		cin >> choice4;//input choice
		cin.ignore();//ignore input
		if(choice4==1){
			CheckTableUI();//call check table number UI function
		}
		else if(choice4==2){
			CallCustomerUI();//call Call Customer Name UI function
		}	
		else if(choice4==3){
			ViewWaitingListUI();//call view waiting list UI function
		}
		else if(choice4==4){
			wlUI=false;//quit waiting list UI
		}
		else{
			cout << "Invalid Input"<<endl;//print 'invalid input'
		}
	}
}
void RestaurantUI::AddMenuUI()//Add Menu UI function
{
	m.addMenu();//call add menu function
}
void RestaurantUI::AddOrderUI()//Add Order UI function
{
	m.addOrder();//call add order function
}
void RestaurantUI::DelMenuUI()//Delete Menu UI function
{
	cout << "Enter the name: ";
	getline(cin,key);//input name
	//check whether input name is in list to be deleted or not
	if(m.delMenu(key)){
		cout << "Deleted Successfully"<<endl;//print 'Deleted Successfully'
	}
	else{
		cout << "There is no item in menu" <<endl;//print 'No item'
	}
}
void RestaurantUI::DelOrderUI()//Delete Order UI function
{
	cout << "Enter the name: ";
	getline(cin,key);//input name
	//check whether input name is in list to be deleted or not
	if(m.delOrder(key)){
		cout << "Order has been cancelled"<<endl;//print 'Deleted Successfully'
	}
	else{
		cout << "There is no item in order list" <<endl;//print 'No item'
	}
}
void RestaurantUI::ViewMenuUI()//View Menu UI function
{
	cout << "1.Main Dishes\n2.Appetizers\n3.Deserts\n4.Drinks\n5.All\n>";
	cin >> in;//input choice
	if(in == 1){
		m.viewMenu(1);//call view Main Dishes Menu function
	}
	else if(in == 2){
		m.viewMenu(2);//call view Appetizers Menu function
	}
	else if(in == 3){
		m.viewMenu(3);//call view Desserts Menu function
	}
	else if(in == 4){
		m.viewMenu(4);//call view Drinks Menu function
	}
	else if(in == 5){
		m.viewMenu();//call view All Menu function
	}
	else{
		cout << "Invalid Input"<<endl;//print 'Invalid Input'
	}
}
void RestaurantUI::ViewOrderUI()//View Order UI function
{
	m.viewOrder();//call view order function
}
void RestaurantUI::TakeBillUI()//Take Bill UI function
{
	cout << "Input Table Number[1-10]: ";
	cin >> tablenum;//input table number
	//check whether table number is correct or not
	if(isTableNumber(tablenum)){
		//check whether order list is empty or not
		if(!m.isEmptyOrder()){
			cout << "Table Number: " << text <<endl;//print table number
			cout << "Customer Name: "<< t.getname(text) <<endl;//print customer name
			m.viewOrder();//call view order function
			cout <<"Grand Total: "<< m.grandTotal()<<endl;//print grand total price
			cout <<"Payment: ";//print input payment
			cin >> payment;//input payment
			cout << "Change: " << payment - m.grandTotal() <<endl;//print change price
			cout << "Order has been paid"<<endl;//print 'Order has been paid'
			cout << "Thank you for coming, " << t.getname(text) <<endl;//print 'thank you'
			m.clearOrder();//call clear order list function
			m.save(f);//call save order list function
			t.removeTable(text);//call remove table number function
			orderUI=false;//quit order UI
		}
		else{
			cout << "There is no any orders now" <<endl;//print 'no orders'
		}
	}
	else{
		cout << "Invalid Input" <<endl;//print 'invalid input'
	}		
}
void RestaurantUI::SaveOrderUI()//Save Order UI function
{
	//check whether order list is empty or not
	if(m.isEmptyOrder()){
		cout << "You have to order food or drinks first" <<endl;//print 'have to order first'
	}
	else{
		cout << "Input Table Number[1-10]: ";
		cin >> tablenum;//input table number
		//check whether table number is correct or not
		if(isTableNumber(tablenum)){
			text = to_string(tablenum);//change table number into string type
			f = text + ".txt";//get file name
			m.save(f);//call save order list function
			m.clearOrder();//call clear order list function
			//print 'saved successfully'
			cout << "Table number " << text << " 's orders has been saved"<<endl;
			orderUI = false;//quit order UI
		}
		else{
			cout << "Invalid Input" <<endl;//print 'Invalid Input'
		}
	}
}
void RestaurantUI::LoadOrderUI()//Load Order UI function
{
	//check whether order list is empty or not
	if(m.isEmptyOrder())
	{
		cout << "Input Table Number[1-10]: ";
		cin >> tablenum;//input table number
		cin.ignore();//ignore input
		if(isTableNumber(tablenum)){
			text = to_string(tablenum);//change table number into string type
			f = text + ".txt";//get file name
			m.load(f);//call load order list function
			//print 'loaded successfully'
			cout << "Table number " << text << " 's orders has been loaded"<<endl;
		}
		else{
			cout << "Invalid Input" <<endl;//print 'invalid input'
		}
	}
	else{
		cout << "There is orders in another table"<<endl;//print 'there is another table's order'
	}
}
void RestaurantUI::CheckTableUI()//Check Table Number UI function
{
	//check whether empty table is available or not
	if(!t.isAvailable()){
		cout << "Input customer's name: ";
		getline(cin,customer);//input customer name
		cout << "Input number of customer: ";
		cin >> numofCus;//input number of customers
		wl.enqueue(customer,numofCus);//call enqueue function
	}
	else{
		cout << "Input customer's name: ";
		getline(cin,customer);//input customer name
		proc=true;//set flag into true
		while(proc){
			cout << "Input table number [1-10]: ";
			cin >> tablenum;//input table number
			//check whether table number is correct or not
			if(isTableNumber(tablenum)){
				text = to_string(tablenum);//change table number into string type
				//check whether input table number is occupied or not
				if(t.isOccupied(text)){
					cout << "Already Occupied"<<endl;//print 'Occupied'
				}
				else{
					t.addTable(text,customer);//call add table number function
					cout << "Welcome! Your table number is " << text <<endl;//print 'welcome'
					proc=false;//set flag into false
					wlUI=false;//quit waiting list UI
				}
			}
			else{
				cout << "Invalid Input"<<endl;//print 'Invalid Input'
			}
				
		}	
	}
}
void RestaurantUI::CallCustomerUI()//Call Customer Name UI function
{
	//check whether waiting list is empty or not
	if(wl.isEmptyList()){
		cout << "Waiting List is Empty" <<endl;//print 'waiting list is empty'
	}
	else{
		cout << wl.callCustomer() << " is called" << endl;//print customer name is called
		proc = true;//set flag 1 into true
		while(proc){
			cout << "Is the customer coming here?(y/n)"<<endl;
			cin >> attend;//input yes or no
			//check whether answer is yes or no
			if(attend=='y'||attend=='Y'){
				proc2=true;//set flag 2 into true
				while(proc2){
					cout << "Input table number [1-10]: ";
					cin >> tablenum;//input table number
					//check whether table number is correct or not
					if(isTableNumber(tablenum)){
						customer=wl.callCustomer();//get customer name
						text=to_string(tablenum);//change table number into string type
						//check whether input table number is occupied or not
						if(t.isOccupied(text)){
							cout << "Already Occupied"<<endl;//print 'Occupied'
						}
						else{
							t.addTable(text,customer);//call add table number function
							//print 'Welcome'
							cout << "Welcome! Your table number is " << text <<endl;
							proc2=false;//set flag 2 into false
							proc=false;//set flag 1 into false
						}	
					}
					else{
						cout << "Invalid Input"<<endl;//print 'invalid input'
					}
				}			
			}
			else if(attend=='N'||attend=='n')
			{
				cout << "Sorry! You have to start again"<< endl;//print 'Sorry'
				proc=false;//set flag 1 into false
			}
			else{
				cout << "Invalid Input"<<endl;//print 'invalid input'
			}
		}	
		wl.dequeue();//call dequeue function
	}	
}
void RestaurantUI::ViewWaitingListUI()//View Waiting List UI function
{
	wl.viewlist();//call view waiting list function
}
bool RestaurantUI::isTableNumber(int n)//Table Number checking function
{
	//check whether number is in rang 1-10 or not
	if(n >= 1 && n <=10){
		return true;//give true statement
	}
	else{
		return false;//give false statement
	}
}
