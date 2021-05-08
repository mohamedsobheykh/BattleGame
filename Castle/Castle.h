#pragma once
#include "..\Defs.h"
class Castle
{
	double Health;
	//double CH;  //CH is the starting health of the castle
	int N; //N is the maximum number of enemies a castle can attack at any time stepand
	double CP; //CP is the castle power.
	bool frosted;
	int counttt; //to count the fires and ice
	//
	// TODO: Add More Data Members As Needed
	//
public:

	void SetHealth(double h);
	double GetHealth() const;

	void SetN(int h);
	int GetN() const;

	void SetCP(double cp);
	double GetCP() const;

	void attack(int nn, int , int);
	void healby3();

	void Setfrosted();
	void setmelted();

	//
	// TODO: Add More Member Functions As Needed
	//

};

