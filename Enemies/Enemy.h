#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

class GUI;
// Enemy is the base class of each type of enemy
// Enemy should be an abstract class in next phases
class Enemy
{
	//ID 
	//TYP 
	//AT 
	//H 
	//POW 
	//RLD 
	//SPD
protected:
	const int ID;         //Each enemy has a unique ID (sequence number)
	const int ArrvTime;	//arrival time (time it starts to join battle)
    ENMY_TYPE TYP; //fighter, healer or freezer

	ENMY_STATUS status;	    //status of the enemy (inactive, inactive, frosted, killed)
	int Distance;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)
	double Health;	//Enemy health
	double POW;
	int RLD;
	int SPD;

	
	//
	// TODO: Add More Data Members As Needed
	//

public:
	void setRLD(int rld);
	void setPOW(double pow);
	void setSPD(int spd);
	void setHealth(double he);

	int getRLD() const;
	double getPOW() const;
	int getSPD() const;
	double getHealth() const;


	virtual ENMY_TYPE getType() const;

	Enemy(int id, int arrTime, int d = MaxDistance);
	virtual ~Enemy();

	int Enemy::GetID() const;
	ENMY_STATUS GetStatus() const;
	void SetStatus(ENMY_STATUS);
	
	void DecrementDist();

	void SetDistance(int );
	int GetDistance() const;

	int GetArrvTime() const;


	// Virtual Functions: ----------------

	//virtual void Move() = 0;	//All enemies can move
	//virtual void Act() = 0;	//Acting means fighting or healing

	//
	// TODO: Add More Member Functions As Needed
	//

};

