#include "PromotionEvent.h"
#include "..\Rest\Restaurant.h"


PromotionEvent::PromotionEvent(int eTime, int oID, int exMoney) :Event(eTime, oID)
{
	ExtraMoney = exMoney;
}


void PromotionEvent::Execute(Restaurant* pRest)
{

	pRest->PromoteOrder(getOrderID());
	


}