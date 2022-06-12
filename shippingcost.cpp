#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>>
using namespace std;

//My Item Shipping Calculator Program - Tausif Hussan 

char userInput;
string itemName;
double shipCost;
string destination;
double orderTotal;
double totalCost;

const char dot = '.';
const char dash = '-';

//Price Table Variables - Order Total limits for order size.

const double mOrderMIN = 50.01;
const double mOrderMAX = 100.01;
const double lOrderMAX = 150.00;

//Shipping Table Variables - Price of shipping based off size & destination.
//S = small, M = medium, L = large. The price of the shipping cost is determined by the size of the order and where it is shipping to. It is then specified where it is shipping to, (USA,CAN,AUS). If the order is too big then it will be free, and if it is considered fragile then $2 will be added on top.

const double sOrderUSA = 6.00;
const double sOrderCAN = 8.00;
const double sOrderAUS = 10.00;

const double mOrderUSA = 9.00;
const double mOrderCAN = 12.00;
const double mOrderAUS = 14.00;

const double lOrderUSA = 12.00;
const double lOrderCAN = 15.00;
const double lOrderAUS = 17.00;

const double bigOrder = 0.00;
const double fragileItem = 2.00;


int main() {
  
  //Line 0 - This automates the creation of the astericks using setw which selects the amount of characters and setfill which selects what character to fill it with.

  cout << setw(50) << setfill(dot) << dot << endl;
  cout << "ITCS-2530 - Programming Assignment for Week #3" << endl;
  cout << setw(50) << setfill(dot) << dot << endl;
	cout << endl;
	cout << endl;

// Line 1 - This allows the user to input the name of the item they are trying to ship.
  
	cout << left <<setw(49) << setfill(dot) << "Please enter the item name (no spaces)" << ":";
	cin >> itemName;
	
//Line 2 - This allows the user to answer whether the item is fragile or not, in order to see if the $2 surcharge is applicable. If the user puts in either upper/lowercase Y or N it will answer the data by calculating plus 2 if they said yes and nothing if they said no. If anything else is put then, "Invalid entry, exiting" will appear, and the program will end.
  
		cout << left <<setw(49) << setfill(dot) << "Is the item fragile? (Y=yes/N=no)" << ":";
	cin >> userInput;
			switch (userInput)
				{
					case 'Y':
					shipCost = shipCost + fragileItem;
					break;
					case 'y':
					shipCost = shipCost + fragileItem;
					break;
					case 'N':
					break;
					case 'n':
					break;
					default:
						cout << endl;
						cout << "Invalid entry, exiting";
						return 0;
					
				}
				

// Line 3 - This allows the user to input the order total. This allows the program to see how big the order is by using the proce table variable that has limits of how much the order total could be before being identified as the bigger order. (S,M,L).
  
	cout << left <<setw(49) << setfill(dot) << "Please enter your order total" << ":";
	cin >> orderTotal;

//Line 4 - This allows the user to input the destination of the item. User can either type USA, CAN, or AUS. If they type anything else it will say invalid and the program will end. This is done through the if else function, where once the destination is typed, the destination variable will be equaled to the place they type. 
		cout << left <<setw(49) << setfill(dot) << "Please enter destination. (usa/can/aus)" << ":";
	cin >> destination;
		if (destination == "aus" || destination == "can" || destination == "usa") {
			cout << endl;
			}
		else {
			cout << endl;
			cout << "Invalid entry, exiting";
			return 0;
			}

//Line 5 - This line uses the transform function to bring back the variable itemName and capitalize it through toupper.
		transform(itemName.begin(), itemName.end(), itemName.begin(), ::toupper);
	cout << left <<setw(40) << setfill(dot) << "Your item is" << itemName << endl;

//Line 6 - Using the if else statement function and the information off the variable table provided, line 6 calculates the shipping cost based off the destination and the order size. If the order is too big then the ship cost becomes free no matter the location.
	
	if (orderTotal < mOrderMIN && destination == "usa") {
		shipCost = shipCost + sOrderUSA;
		}
	else if (orderTotal < mOrderMIN && destination == "can") {
		shipCost = shipCost + sOrderCAN;
	}
	else if (orderTotal < mOrderMIN && destination == "aus") {
		shipCost = shipCost + sOrderAUS;
	}
	else if (orderTotal > mOrderMIN && orderTotal <= mOrderMAX && destination == "usa") {
		shipCost = shipCost + mOrderUSA;
	}
	else if (orderTotal > mOrderMIN && orderTotal <= mOrderMAX && destination == "can") {
		shipCost = shipCost + mOrderCAN;
	}
	else if (orderTotal > mOrderMIN && orderTotal <= mOrderMAX && destination == "aus") {
		shipCost = shipCost + mOrderAUS;
	}
	else if (orderTotal > mOrderMAX && orderTotal <= lOrderMAX && destination == "usa") {
		shipCost = shipCost + lOrderUSA;
	}
	else if (orderTotal > mOrderMAX && orderTotal <= lOrderMAX && destination == "can") {
		shipCost = shipCost + lOrderCAN;
	}
	else if (orderTotal > mOrderMAX && orderTotal <= lOrderMAX && destination == "aus") {
		shipCost = shipCost + lOrderAUS;
	}
	else {
		shipCost = bigOrder;
	}

  //This line of the program tells the shipping cost after doing the calculations. The setprecision function makes it have the right amount of decimal places in order to display money. 
  
	cout << left <<setw(40) << setfill(dot) << "Your shipping cost is" << "$";
	cout << fixed << setprecision(2) << shipCost << endl;

//Line 7 - This line uses the transform function to say the destination that the user inputted and through toupper it will capitalize it. This line states where the user wants to ship to. 
  
		transform(destination.begin(), destination.end(), destination.begin(), ::toupper);
	
		cout << left <<setw(40) << setfill(dot) << "Your are shipping to" << destination << endl;

//Line 8 - This line calculates the total shipping cost of the order. Using the formula of adding the shipping cost and order total.
  
	totalCost = shipCost + orderTotal;
	
		cout << left <<setw(40) << setfill(dot) << "Your total shipping costs are" << "$" << totalCost << endl;
	cout << endl;

//Line 9 - This line formats the ending. Sets width of 40 digits and setsfill replaces it with dashes.
  
	cout << setfill(dash) << setw(40) << dash;
  cout << "Thank You!" << endl;
}