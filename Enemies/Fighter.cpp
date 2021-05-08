#include "Fighter.h"


ENMY_TYPE Fighter:: getTYP() const {
	return FIGHTER;
}
Fighter::Fighter( int id, int arrTime, int d) : Enemy( id, arrTime,  d) {
	TYP = FIGHTER;
}
Fighter::~Fighter() {

}

