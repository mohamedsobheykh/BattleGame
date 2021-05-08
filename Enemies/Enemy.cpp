#include "Enemy.h"


Enemy::Enemy(int id, int arrTime, int d):ID(id),ArrvTime(arrTime)
{
	SetDistance(d);
}

Enemy::~Enemy()
{
}

int Enemy::GetID() const
{
	return ID;
}


void Enemy::SetStatus(ENMY_STATUS s)
{
	status = s;
}


ENMY_STATUS Enemy::GetStatus() const
{
	return status;
}


void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
		Distance--;
}

void Enemy::SetDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Enemy::GetDistance() const
{
	return Distance;
}



int Enemy::GetArrvTime() const
{
	return ArrvTime;
}

void Enemy::setRLD(int rld) {
	RLD = rld;
}
void Enemy::setPOW(double pow) {
	POW = pow;
}
void Enemy::setSPD(int spd) {
	SPD = spd;
}
void Enemy::setHealth(double he) {
	Health = he;
}

ENMY_TYPE Enemy::getType() const {
	return TYP;
}
int Enemy::getRLD() const{
	return RLD;
}
double Enemy::getPOW() const {
	return POW;
}
int Enemy::getSPD() const {
	return SPD;
}
double Enemy::getHealth() const {
	return Health;
}