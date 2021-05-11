#pragma once
#include "Enemy.h"
class Healer : public Enemy
{

public:
	ENMY_TYPE getType() const;
	Healer(int id, int arrTime, int d = MaxDistance);
	~Healer();
};

