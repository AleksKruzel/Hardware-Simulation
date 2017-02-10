#ifndef HARDWARESTORE_H
#define HARDWARESTORE_H
#include "Inventory.h"
#include "Shopper.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Shopper;

class HardwareStore{
	public:
		HardwareStore(int numRegisters=1);
		void addShopperToLine(const Shopper& shopper);
		double processShopper();
		double checkoutAllShoppers();
		double totalRevenue();
		Inventory inventory;
        double revenue;
	private:
	    //I CREATED A VECTOR OF QUEUES, SO THAT EACH QUEUE CAN BE ACCESSED BY ITS INDEX INSTEAD OF A NAME
        vector< queue<Shopper> > q;
};

#endif
