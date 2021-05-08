#pragma once
#include "Enemies/Enemy.h"
class Freezer : public Enemy
{
	
public:
	ENMY_TYPE getTYP() const;
	Freezer(int id, int arrTime, int d = MaxDistance);
	~Freezer();
};

