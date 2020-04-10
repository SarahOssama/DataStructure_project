#ifndef __ORDER_H_
#define __ORDER_H_

#include "..\Defs.h"



class Restaurant; //Forward declation

class Order
{ 

protected:
	int ID;         //Each order has a unique ID (from 1 --> 999 )
	ORD_TYPE type;		//order type: Normal, vegan, VIP
	ORD_STATUS status;	//waiting, in-service, done
	int Distance;	//The distance (in meters) between the order location and the resturant 
	int Size; //added by Farah
	double totalMoney;	//Total order money

	int ArrTime, ServTime, FinishTime;	//arrival, service start, and finish times
	
	
	//
	// TODO: Add More Data Members As Needed
	//

	
public:
	Order(int ID, ORD_TYPE r_Type);

	Order(int ID, ORD_TYPE r_Type, int size, double tMoney); //added by Farah

	virtual ~Order();

	int GetID();

	ORD_TYPE GetType() const;

	void SetDistance(int d);
	int GetDistance() const;

	void setStatus(ORD_STATUS s);
	ORD_STATUS getStatus() const;
	
	
	//
	// TODO: Add More Member Functions As Needed
	//
	void setType(ORD_TYPE t); // in case we wanted to promote an order from normal to VIP
	void SetServTime(int time);

	/*void setSize(int s);
	int getSize() const;

	void settotalmoney(double m);
	double gettotalmoney() const;*/


	int GetServTime();
};

#endif