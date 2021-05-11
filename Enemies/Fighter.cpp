#include "Fighter.h"


ENMY_TYPE Fighter:: getType() const {
	return FIGHTER;
}
Fighter::Fighter( int id, int arrTime, int d) : Enemy( id, arrTime,  d) {
	TYP = FIGHTER;
}
Fighter::~Fighter() {

}

