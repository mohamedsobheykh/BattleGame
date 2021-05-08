#include "Freezer.h"


ENMY_TYPE Freezer::getTYP() const {
	return FREEZER;
}

Freezer::Freezer(int id, int arrTime, int d = MaxDistance) : Enemy(id, arrTime, d = MaxDistance) {
	TYP = FREEZER;
}
Freezer::~Freezer() {

}