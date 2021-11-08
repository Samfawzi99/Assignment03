// Assignment03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "windows.h"
#include <cstring>
#include <algorithm>
#include <fstream>


using namespace std;
//declaring variables
double ordertotal = 0;
string itemname = "";
string iffragile;
string destination = "";
double total = 0;
double fragile = 0;
double shippingcost = 0;
//declaring stream strings
const string inFileName = "Order.txt";
const string outFileName = "Order.txt";

int main()
{
    //outputting error message incase file doesnt exist
    ifstream fInStream;
    ofstream fOutStream;
    fInStream.open(inFileName);
    if (!fInStream)
    {
        cout << "Error in opening the file: " << endl;
        return 1;
    }
    fOutStream.open(outFileName);
    if (!fOutStream)
    {
        cout << "Error in opening the file: " << endl;
        fInStream.close();
        return 1;
    }
    //outputting message and demonstrating i/o manipulation
    cout << setw(51) << setfill('.') << "." << endl;
    cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
    cout << setw(51) << setfill('.') << "." << endl << endl << endl;
    
    //asking for input
    cout << "Please enter the item name (no spaces)"<<setw(12)<<"."<<":";
    //setting input into variable itemname
    cin >> itemname;
    //asking whether item is fragile?
    cout << "Is the item fragile? (y=yes/n=no)"<<setw(17)<<"."<<":";
    //getting input
    cin >> iffragile;
    //starting if structure to decide what to do if item is fragile, or if something else is entered
    if (iffragile == "y" || iffragile == "Y") {
        fragile = 2.00;
    }

    else if (iffragile == "n" || iffragile == "N") {
        fragile = 0.00;
    }
    //outputting error message incase something else instead of y or n is entered
    else {
        fragile = 0;
        cout << "\nInvalid entry, exiting" << endl;
        system("pause");
        exit(0);
    }

    //asking for the order total with i/o manipulation
    cout << "Please enter your order total"<<setw(21)<<"."<<":";
    cin >> ordertotal;
    //asking for destination with i/o manipulation

    cout << "Please enter destination. (usa/can/aus/mars)" << setw(11) << "." << ":";
    cin >> destination;
    
    //starting if structure to decide shipping based on country and total order
    if (destination == "usa")
    {
        if (ordertotal < 50)
            shippingcost = shippingcost + 6.00;
        else if (ordertotal < 100 and ordertotal > 50)
            shippingcost = shippingcost + 9.00;
        else if (ordertotal > 100 and ordertotal < 150)
            shippingcost = shippingcost + 12.00;

    }

    else if (destination == "can")
    {
        if (ordertotal < 50)
            shippingcost = shippingcost +8.00;
        else if (ordertotal < 100 and ordertotal > 50)
            shippingcost = shippingcost +12.00;
        else if (ordertotal > 100 and ordertotal < 150)
            shippingcost = shippingcost +15.00;

    }
    else if (destination == "aus")
    {
        if (ordertotal < 50)
            shippingcost = shippingcost + 10.00;
        else if (ordertotal < 100 and ordertotal > 50)
            shippingcost = shippingcost +14.00;
        else if (ordertotal > 100 and ordertotal < 150)
            shippingcost = shippingcost + 17.00;

    }
    else if (destination == "mars")
    {
        if (ordertotal < 50)
            shippingcost = shippingcost + 25.00;
        else if (ordertotal < 100 and ordertotal > 50)
            shippingcost = shippingcost + 34.00;
        else if (ordertotal > 100 and ordertotal < 150)
            shippingcost = shippingcost + 47.00;

    }
    //outputting error incase destination isn't usa,can,aus or mars
    else {
        cout << "\nInvalid entry, exiting" << endl;
        system("pause");
        exit(0);
    }
    //making orders that are $150+ free shipping
    if (ordertotal > 150)
    {
        shippingcost = 0.00;
    }
    //capitalizing output of destination and itemname
    transform(destination.begin(), destination.end(), destination.begin(), ::toupper);
    transform(itemname.begin(), itemname.end(), itemname.begin(), ::toupper);
    //outputting bottom part of message with i/o manipulation
    cout << "\nYour item is" << setw(29) << "." << itemname << endl;
    cout << "Your shipping cost is" << setw(20) <<"." << "$" << fixed << setprecision(2) << shippingcost + fragile << endl;
    cout << "You are shipping to" << setw(22) << "." << destination << endl;
    total = ordertotal + shippingcost + fragile;
    cout << "Your total shipping costs are" << setw(12) << "." << "$" << fixed <<setprecision(2) << total << endl << endl;
    cout << setfill('-') << setw(51) << "Thank you!" << endl << endl;

    //filestream closing and outputting to text file
    fOutStream << "Your item is: "<< itemname << endl << "Your shipping cost is: " << shippingcost << endl << "You are shipping to: " << destination << endl << "Your total shipping costs are: " << total;
    
    fOutStream.close();

system("Pause");
return 0;
}

