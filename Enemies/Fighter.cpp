#include "Fighter.h"


ENMY_TYPE Fighter:: getTYP() const {
	return FIGHTER;
}
Fighter::Fighter( int id, int arrTime, int d = MaxDistance) : Enemy( id, arrTime,  d = MaxDistance) {
	TYP = FIGHTER;
}
Fighter::~Fighter() {

}

