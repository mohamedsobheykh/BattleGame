#include "Healer.h"


ENMY_TYPE Healer::getTYP() const {
	return HEALER;
}
Healer::Healer(int id, int arrTime, int d) : Enemy(id, arrTime, d ) {
	TYP = HEALER;
}
Healer::~Healer() {

}