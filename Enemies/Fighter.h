#pragma once
#include "Enemy.h"
class Fighter : public Enemy 
{
public:
	ENMY_TYPE getType() const;
	Fighter( int id, int arrTime, int d = MaxDistance);
	~Fighter();
};

