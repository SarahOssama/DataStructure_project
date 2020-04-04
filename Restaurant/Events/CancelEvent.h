#pragma once
#include "Event.h"

//Test


class CancelEvent: public Event
{

	ORD_TYPE* OrdType; //to receive the order that will be deleted 


public:
	CancelEvent(int eTime, int oID);
	~CancelEvent();

	virtual void Execute(Restaurant* pRest);
};



