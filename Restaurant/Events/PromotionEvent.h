#ifndef __PROMOTION_EVENT_H_
#define __PROMOTION_EVENT_H_

#include "Event.h"


//class for the promotion event
class PromotionEvent : public Event
{
	int ExtraMoney;
public:
	PromotionEvent(int eTime, int oID, int exMoney);

	virtual void Execute(Restaurant* pRest);
};
#endif
