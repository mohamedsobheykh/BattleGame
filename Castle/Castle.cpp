#include "Castle.h"




void Castle::SetHealth(double h)
{
	if(h > 0)
		Health = h;
	else
		Health = 0; // killed
}

double Castle::GetHealth() const
{
	return Health;
}

void Castle::SetN(int n) {
	N = n;
}
int Castle::GetN() const {
	return N;
}

void Castle::SetCP(double cp) {
	CP = cp;
}
double Castle::GetCP() const{
	return CP;
}

void Castle::attack(int nn, int, int) {
	if (!frosted) {

	}
}
void Castle::healby3() {
	Health = Health + (0.03 * Health);
}
void Castle::Setfrosted() {
	frosted = true;
}
void Castle::setmelted() {
	frosted = false;
}
