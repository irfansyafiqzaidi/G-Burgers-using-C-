#include<iostream>
#include<windows.h>
using namespace std;

// all functions

void ownerStock();     // owner enter item stocks
void menuNstock();     // display menu and item stocks availability
void brgrOptn();       // customer input their choice of burger type
void meatSelector();   // customer input their meat of choice 
void custBill();       // display burger name based on customer choice and total price after tax
string burgerNaming(); // determines the burger name based on customer's burger choice
void priceCalc();      // calculates price of burger, calculates tax based on burger price and summation of total sales
void grossNstock();    // display total sales made and remainding stocks left

// all data types used and its variable

const int maxItem=4;
int count=0 , stocks[maxItem] , burgerType;
double price , taxAmount , totalPrice , totalSales;
const double tax = 0.06;
char meatOptn;
string burgerName , stockName[maxItem] = {"Buns = " , "Chicken Meat = " , "Beef Meat = " , "Egg = "};



int main()
{
	char repeatOrder='Y';
	
	ownerStock();
	
	while(repeatOrder=='Y' || repeatOrder=='y')
	{
		if(stocks[0]>0) // checks if buns is still in stock
		{	
			if(stocks[1]>0 || stocks[2]>0) // checks if meats is still in stock
			{
				menuNstock();
				brgrOptn();
				burgerName=burgerNaming();
				priceCalc();
				custBill();
			
				cout<<endl<<"Make a new order? (Y to proceed): "; // prompt customer to make new order
				cin>>repeatOrder; 
			}
			else
			{
				repeatOrder='N';
				cout<<endl<<"\t  Sorry! Our meats ran out of stock"<<endl;
				cout<<"\t\tThank You Come Again!"<<endl;
			}
		}
		else
		{
			repeatOrder='N';
			cout<<endl<<"\t  Sorry! Our buns ran out of stock"<<endl;
			cout<<"\t\tThank You Come Again!"<<endl;
		} 
	}
	grossNstock();
}

void ownerStock()
{
	char stockInput='Y';
	
	cout<<"***************************************************"<<endl;
	cout<<"\t\tGood Morning Owner!"<<endl;
	
	while(stockInput=='Y' || stockInput=='y')
	{
		cout<<endl<<"Please enter todays stock:"<<endl<<endl;
		
		count=0;
		for(count ; count<maxItem ; count++)  // owner input buns,chicken,beef and egg stock
		{
			cout<<stockName[count];
			cin>>stocks[count];
		}
		
		cout<<endl;
		
		// checks if stock input is valid
		
		if(stocks[0] <0)
			cout<<"INVALID Buns Stock!"<<endl;
		
		if(stocks[1] <0)
			cout<<"INVALID Chicken Meat Stock!"<<endl;
		
		if(stocks[2] <0)
			cout<<"INVALID Beef Meat Stock!"<<endl;
			
		if(stocks[3] <0)
			cout<<"INVALID Egg Stocks!"<<endl;
		
		if(stocks[0]>0 && (stocks[1]>0 || stocks[2]>0)) // checks if owner is eligible to make any progress
		{
			cout<<endl<<"Want to re-enter stocks? (Y to proceed) : "; // prompt owner to re-enter stocks
			cin>>stockInput;
		}
		
	}
	
	cout<<endl<<"\t\t   Happy Selling!"<<endl;
	cout<<"***************************************************"<<endl<<endl;
	
	system("pause");
	system("cls");
}

void menuNstock()
{
	cout<<endl<<"==================================================="<<endl;
	cout<<"\t\t\tMENU"<<endl<<endl;
	
		
	cout<<"Chicken Burger   (RM3.50)                Stocks:";
	if(stocks[1]>0)
		cout<<stocks[1]<<endl;
	else
		cout<<"OUT OF STOCK"<<endl;
	
	cout<<"Beef Burger      (RM4.50)                Stocks:";
	if(stocks[2]>0)
		cout<<stocks[2]<<endl;
	else
		cout<<"OUT OF STOCK"<<endl;
	
	cout<<"~ Egg add-ons    (RM1.00)                Stocks:";
		if(stocks[3]>0)
		cout<<stocks[3]<<endl;
	else
		cout<<"OUT OF STOCK"<<endl;
	
	cout<<"==================================================="<<endl<<endl;
	
	cout<<"\t\t   ----ORDER----"<<endl<<endl;

	cout<<"1) Special (Egg add-ons)"<<endl;
	cout<<"2) Standard "<<endl<<endl;
}

void brgrOptn()
{
	price=0;
	cout<<"Enter Burger Type (1/2) : "; // prompt customer enter burger type 
	cin>>burgerType;
	cout<<endl;
	
	switch(burgerType)
	{
		case 1: {	stocks[3]--;
					price++;
				}

		case 2: {
					meatSelector(); 
				}
				
		break;
		
		default:{	
					cout<<"INVALID BURGER TYPE"<<endl<<endl;
					brgrOptn();
				}
	}
}

void meatSelector()
{
	cout<<"Enter Burger Meat (C/B) : "; // prompt customer enter burger meat
	cin>>meatOptn;
	
	if(meatOptn=='C' || meatOptn=='c')
	{
		stocks[0]--;
		stocks[1]--;
		price=price+3.5;
	}
	else if(meatOptn=='B' || meatOptn=='b')
	{
		stocks[0]--;
		stocks[2]--;
		price=price+4.5;
	}
	else
	{
		price=0;
		cout<<endl<<"INVALID BURGER MEAT"<<endl<<endl;
		meatSelector();		
	}
	
	system("pause");
	system("cls");
}

string burgerNaming()
{
	if(burgerType==1)
	{
		if(meatOptn=='C' || meatOptn=='c')
		{
			return "Special Chicken Burger";
		}
		else if(meatOptn=='B' || meatOptn=='b')
		{
			return "Special Beef Burger";
		}
	}
	else if(burgerType==2)
	{
		if(meatOptn=='C' || meatOptn=='c')
		{
			return "Chicken Burger";
		}
		else if(meatOptn=='B' || meatOptn=='b')
		{
			return "Beef Burger";
		}
	}

}

void priceCalc()
{
	taxAmount=price*tax;
	totalPrice=price+taxAmount;
	totalSales=totalSales+totalPrice;
}

void custBill()
{
	cout<<endl<<"###################################################"<<endl;
	cout<<"\t\t\tBills"<<endl<<endl;
	
	cout<<burgerName<<endl<<endl;
	cout<<"Price       :RM "<<price<<endl;
	cout<<"Tax(6%)     :RM "<<taxAmount<<endl;
	cout<<"Total Price :RM "<<totalPrice<<endl<<endl;
	
	cout<<"###################################################"<<endl<<endl;
	
	system("pause");
	system("cls");
}

void grossNstock()
{
	cout<<endl<<"---------------------------------------------------"<<endl;
	cout<<"\t\t-|Todays Statistic|-"<<endl<<endl<<endl;
	
	cout<<"Total Sales: RM"<<totalSales<<endl<<endl;
	
	cout<<"Stocks Left:"<<endl;
	count=0;
	for(count ; count<maxItem ; count++)  // displays stocks left
	{
		cout<< stockName[count] << stocks[count] << endl;
	}
	
	cout<<"---------------------------------------------------"<<endl;
}