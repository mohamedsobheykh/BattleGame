#include "Freezer.h"


ENMY_TYPE Freezer::getType() const {
	return FREEZER;
}

Freezer::Freezer(int id, int arrTime, int d ) : Enemy(id, arrTime, d ) {
	TYP = FREEZER;
}
Freezer::~Freezer() {

}