#include "Healer.h"


ENMY_TYPE Healer::getTYP() const {
	return HEALER;
}
Healer::Healer(int id, int arrTime, int d = MaxDistance) : Enemy(id, arrTime, d = MaxDistance) {
	TYP = HEALER;
}
Healer::~Healer() {

}