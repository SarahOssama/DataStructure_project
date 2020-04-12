#include "CancelEvent.h"
#include "..\Rest\Restaurant.h"

//Constructor
CancelEvent::CancelEvent(int eTime, int oID) :Event(eTime, oID)
{
}

//Excute

void CancelEvent::Execute(Restaurant* pRest)
{

	pRest->DeleteOrder(getOrderID());

	//Add test
}

//Destructor
CancelEvent::~CancelEvent()
{
}