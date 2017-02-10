#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "HardwareStore.h"
#include "Inventory.h"
#include "Shopper.h"
using namespace std;

//THE VECTOR HAS INITIALLY 1 but we pass in and set a specific size here
HardwareStore::HardwareStore(int numRegisters){
    // why am i not redefinding the q here
    Inventory inventory;//creates an inventory for this store
    q.resize(numRegisters);//create number of queues/registers
}

void HardwareStore::addShopperToLine(const Shopper& shopper){
    //THIS VARIABLE THAT STORES THE SHORTEST LINE INTEGER
    int shortest = 0;
    //THIS VARIABLE WILL STORE THE INDEX OF THE SHORTEST LINE
    int shortestQ;
    //WE LOOP THROUGH THE AMOUNT OF QUEUES WE HAVE.
    for(int i=0;i<q.size();i++){
        //FOR EACH LINE WE COMPARE IT TO THE SHORTEST LINE FOUND SO FAR
        if(q[i].size()<=shortest)
            shortest = q[i].size();
            shortestQ = i;//RECORD THE INDEX SO YOU HAVE ACCESS TO THE LINE THAT IS THE SHORTEST
    }
    //AFTER FINDING THE SHORTEST LINE WE PUSH THE PASSED IN SHOPPER TO THE SHORTEST QUEUE IN THE VECTOR
    q[shortestQ].push(shopper);//
}


double HardwareStore::processShopper(){
    double Revenue = 0;
    int longest = 1;
    int longestQ;
    for(int i=0;i<q.size();i++){
        if(q[i].size()>=longest){
            longest = q[i].size();
            longestQ = i;
        }
    }
    // ADDED HOW MUCH THE SHOPPER OWES THE STORE TO revenue
    Revenue = q[longestQ].front().S.grandTotal();
    q[longestQ].pop();//SHOPPER THAT WAS JUST PROCESSED IS TAKEN OUT OFF THE QUEUE BECAUSE THEY ARE DONE SHOPPING
    return Revenue;
}


//this seemed most convenient to turn into a function that returns a double
//having a global variable didnt work for me because the revenue kept on reseting after it was returned
double HardwareStore::checkoutAllShoppers(){//parallel?
    //CREATE A VARIABLE TO HOLD THE AMOUNT OF SHOPPERS ON THE LINES
    int numOfCustomers=0;
    //LOOP THROUGH THE VECTOR OF QUEUES AND ADD UP ALL THE SHOPPERS
    for(int i=0;i<q.size();i++){
        numOfCustomers += q[i].size();
    }
    //NOW WE PROCESS ALL THE SHOPPERS UNTIL ALL THE LINES ARE EMTPY
    while(numOfCustomers!=0){
            cout << "Checking out shopper..in progress.." << endl;
        revenue += processShopper(); //update the revenue
        numOfCustomers--; //one shopper has been processed so we subtract from the line
    }
    return revenue; //pass the revenue total for all the shoppers so far to main
}

//THE revenue VARIABLE HAS BEEN TRACKED THROUGHOUT THE WHOLE PROGRAM AND NOW WE AN RETURN IT
double HardwareStore::totalRevenue(){
    //this returns the appropriate revenue value so long as the last code in the events.txt is a P
   return revenue;
}

