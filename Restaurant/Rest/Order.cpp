#include "Order.h"
#include "..\Rest\Restaurant.h"


Order::Order(int id, ORD_TYPE r_Type)
{
	ID = (id>0&&id<1000)?id:0;	//1<ID<999
	type = r_Type;
	status = WAIT;
}

Order::Order(int id, ORD_TYPE r_Type, int size, double tMoney)
{
	ID = (id > 0 && id < 1000) ? id : 0;	//1<ID<999
	type = r_Type;
	status = WAIT;
	Size = size;
	totalMoney = tMoney;
}


Order::~Order()
{
}

int Order::GetID()
{
	return ID;
}


ORD_TYPE Order::GetType() const
{
	return type;
}


void Order::SetDistance(int d)
{
	Distance = d>0?d:0;
}

int Order::GetDistance() const
{
	return Distance;
}


void Order::setStatus(ORD_STATUS s)
{
	status = s;
}

ORD_STATUS Order::getStatus() const
{
	return status;
}

void Order::setType(ORD_TYPE t)
{
	type = t;
}

void Order::SetServTime(int time)
{
	ServTime = time;
}

void Order::setSize(int s)
{
	Size = s;
}

int Order::getSize() const
{
	return Size;
}

void Order::settotalmoney(double m)
{
	totalMoney = m;
}

double Order::gettotalmoney() const
{
	return totalMoney;
}
