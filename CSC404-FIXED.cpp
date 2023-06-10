//Student Name : Nurul Zawani Binti Zulkeplee (2020828608)
//This project is to take an order from customer and display the price.

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <windows.h>
using namespace std;

struct customerOrder  //to take an order from customer
{
	char order;
	string name;
	double totalprice, famPrice; 
	double totalN, totalM, totalS, totalC ;
};

double total(customerOrder cust[],int x);   //to show the price for the order pick by customer

ifstream ifs;
ofstream ofs;

int main()
{
	int i;
	char decision;
	string menu,price;
	double totalN, totalM, totalS, totalC ;
	double totalprice, famPrice;
	
	ofstream myRec("wanisale.txt");
	
	customerOrder cust[5];
	cout<<"=============================================================================";
	cout<<"\n\tWELCOME TO WANI RESTAURANT - A FRIENDLY FAMILY RESTAURANT\n";
	cout<<"============================================================================="<<endl;
	cout<<"\nBelow are the list of the menu we serving here : \n"<<endl;
	ifs.open("waniCust'-FIXED.txt");    //list of food name and food price
	while(ifs >> menu >> price)
	{
		cout<< menu << "	" << price << endl;
	}
	
	cout<< endl << "\n---------------ORDER  SECTION---------------"<<endl;
	cout<<"*Please note that one family can order at most 5 per receipt*"<<endl;
	
	for (int i=0 ; i<5 ; i++)
	{
		cout<<"\nCustomer Name : ";
	    cin>>cust[i].name;
	    cout<<"\n[Nasi Goreng - N || Mee Bandung - M || Spagetti - S || Chicken Chop - C] "<<endl;
	    cout<<"Customer Order : ";
	    cin>>cust[i].order;
	    cust[i].totalprice = total(cust,i);
	    famPrice += total(cust,i);
	    
		cout << "\nNext customer? [Y-Yes || N-No] : ";
		cin>>decision;
		
		if (decision=='N'||decision=='n')
			break;    
	}
	
	
	cout<<"\n#####################################################################\n"<<endl;
	
	// output
	cout<<"\n\n---------------WANI RESTAURANT RECEIPT---------------\n"<<endl;
	for (int i=0 ; i<5 ; i++)
	{
		cout<<"Customer Name : "<<cust[i].name<<endl;
		
		if (cust[i].order == 'N') 
	        cout<<"Customer Order  : Nasi Goreng "<<endl;
	    else if (cust[i].order == 'M') 
	        cout<<"Customer Order  : Mee Bandung "<<endl;
	    else if (cust[i].order == 'S') 
	        cout<<"Customer Order  : Spagetti "<<endl;  
		else if (cust[i].order == 'C') 
	        cout<<"Customer Order  : Chicken Chop "<<endl;
		
		cout<<"Total Price : RM "<<fixed<<setprecision(2)<<cust[i].totalprice<<endl<<endl;
	}
	cout<<"\nTotal Price per Recipt : RM "<<fixed<<setprecision(2)<<famPrice<<endl<<endl;
	cout<<"Thank You for Choosing Our Restaurant. Please Come Again <3\n"<<endl;
	
	
	myRec<<"==================================================================="<<endl;
	myRec<<"\n---------------WANI RESTAURANT RECEIPT---------------\n"<<endl;
	for (int i=0 ; i<5 ; i++)
	{
		myRec<<"Customer Name : "<<cust[i].name<<endl;
		
		if (cust[i].order == 'N') 
	        myRec<<"Customer Order  : Nasi Goreng "<<endl;
	    else if (cust[i].order == 'M') 
	        myRec<<"Customer Order  : Mee Bandung "<<endl;
	    else if (cust[i].order == 'S') 
	        myRec<<"Customer Order  : Spagetti "<<endl;  
		else if (cust[i].order == 'C') 
	        myRec<<"Customer Order  : Chicken Chop "<<endl;
		
		myRec<<"Total Price : RM "<<fixed<<setprecision(2)<<cust[i].totalprice<<endl<<endl;
	}
	myRec<<"\nTotal Price per Recipt : RM "<<fixed<<setprecision(2)<<famPrice<<endl<<endl;
	myRec<<"==================================================================="<<endl; 
}

double total(customerOrder cust[],int x)
{
	double totalprice, famPrice;
	double totalN, totalM, totalS, totalC ;
	
	if (cust[x].order == 'N')  
	{
	    //nasi goreng
	    totalprice = 4.00;
	    totalN = totalprice;
	}
		    
	else if (cust[x].order == 'M') 
	{
		//mee bandung
		totalprice = 5.00; 
		totalM = totalprice; 
	}
		    
	else if (cust[x].order == 'S')
	{
		//spagetti
		totalprice = 4.50;
		totalS = totalprice;
	}
			
	else if (cust[x].order == 'C') 
	{
		//chicken chop
		totalprice = 5.50;
		totalC = totalprice;
	}
	
	famPrice = totalN + totalM + totalS + totalC ;
	
	return totalprice;
	return famPrice;
}

