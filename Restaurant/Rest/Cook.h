#pragma once

#include "..\Defs.h"

#pragma once
class Cook
{
	int ID;
	ORD_TYPE type;	//for each order type there is a corresponding type (VIP, Normal, Vegan)
	int Speed;		//dishes it can prepare in one clock tick (in one timestep)
	int Dishes_break;     // number of dishes that he must finish before break
	int Inbreak;     // break period in timesteps

public:
	Cook();

	Cook(int id, ORD_TYPE tp, int spd, int dsh_brk, int inbrk);
	
	virtual ~Cook();
	int GetID() const;
	ORD_TYPE GetType() const;
	void setID(int);
	void setType(ORD_TYPE) ;
	
	void setSpeed(int s);
	void setDishes_break(int db);
	void setInbreak(int ib);
	int GetSpeed();
	int GetDishes_break();
	int GetInbreak();

};
