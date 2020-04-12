#include "Cook.h"


Cook::Cook()
{
}


Cook::~Cook()
{
}


int Cook::GetID() const
{
	return ID;
}


ORD_TYPE Cook::GetType() const
{
	return type;
}


void Cook::setID(int id)
{
	ID = id;
}

void Cook::setType(ORD_TYPE t)
{
	type = t;
}
void Cook::setDishes_break(int db)
{
	if (db > 0)
	{
		Dishes_break = db;
	}
}
int Cook::GetDishes_break()
{
	return Dishes_break;
}
void Cook::setSpeed(int s)
{
	if (s > 0)
	{
		Speed = s;
	}
}
int Cook::GetSpeed()
{
	return Speed;
}
void Cook::setInbreak(int ib)
{
	if (ib > 0)
	{
		Inbreak = ib;
	}
}
int Cook::GetInbreak()
{
	return Inbreak;
}
Cook::Cook(int id, ORD_TYPE tp, int spd, int dsh_brk, int inbrk)
{
	setID(id);
	setType(tp);
	setSpeed(spd);
	setDishes_break(dsh_brk);
	setInbreak(inbrk);

}