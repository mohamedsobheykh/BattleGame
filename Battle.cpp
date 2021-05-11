#include "Battle.h"
#include <time.h>
#include <iostream>
using namespace std;


Battle::Battle()
{	
	EnemyCount = 0;
	KilledCount = 0;
	ActiveCount = 0;
	FrostedCount = 0;
	DemoListCount = 0;
	CurrentTimeStep = 0;
	pGUI = NULL;
}

void Battle::AddtoDemoList(Enemy* Ptr)
{
	DemoList[DemoListCount++] = Ptr;

	// Note that this function doesn't allocate any enemy objects
	// It just enqueue a pointer that is already allocated into the queue
}


Castle * Battle::GetCastle()
{
	return &BCastle;
}


void Battle::RunSimulation()
{
	pGUI = new GUI;
	PROG_MODE	mode = pGUI->getGUIMode();
		
	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		break;
	case MODE_STEP:
		break;
	case MODE_SLNT:
		break;
	case MODE_DEMO:
		Just_A_Demo();

	}

	delete pGUI;
	
}

/*
//This is just a demo function for project introductory phase
//It should be removed in phases 1&2
void Battle::Just_A_Demo()
{

	pGUI->PrintMessage("Just a Demo. Enter Enemies Count(next phases should read I/P filename):");
	EnemyCount = atoi(pGUI->GetString().c_str());	//get user input as a string then convert to integer

	pGUI->PrintMessage("Generating Enemies randomly... In next phases, Enemies should be loaded from a file...CLICK to continue");
	pGUI->waitForClick();

	CurrentTimeStep = 0;
	//
	// THIS IS JUST A DEMO Function
	// IT SHOULD BE REMOVED IN PHASE 1 AND PHASE 2
	//

	srand(time(NULL));
	int Enemy_id = 0;
	int ArrivalTime = 1;
	Enemy* pE = NULL;
	//Create Random enemies and add them all to inactive queue
	for (int i = 0; i < EnemyCount; i++)
	{
		ArrivalTime += (rand() % 3);	//Randomize arrival time
		pE = new Enemy(++Enemy_id, ArrivalTime);
		pE->SetStatus(INAC); //initiall all enemies are inactive
		Q_Inactive.enqueue(pE);		//Add created enemy to inactive Queue
	}

	AddAllListsToDrawingList();
	pGUI->UpdateInterface(CurrentTimeStep);	//upadte interface to show the initial case where all enemies are still inactive

	pGUI->waitForClick();

	while (KilledCount < EnemyCount)	//as long as some enemies are alive (should be updated in next phases)
	{
		CurrentTimeStep++;
		ActivateEnemies();

		Demo_UpdateEnemies();	//Randomly update enemies distance/status (for demo purposes only)

		pGUI->ResetDrawingList();
		AddAllListsToDrawingList();
		pGUI->UpdateInterface(CurrentTimeStep);
		Sleep(250);
	}
}
*/
void Battle::Just_A_Demo()
{	
	loadfile();

	pGUI->waitForClick();

	CurrentTimeStep = 0;
	 

	AddAllListsToDrawingList();
	pGUI->UpdateInterface(CurrentTimeStep);	//upadte interface to show the initial case where all enemies are still inactive

	pGUI->waitForClick();
	
	while( KilledCount < EnemyCount )	//as long as some enemies are alive (should be updated in next phases)
	{
		CurrentTimeStep++;
		ActivateEnemies();

		Demo_UpdateEnemies();	//Randomly update enemies distance/status (for demo purposes only)

		pGUI->ResetDrawingList();
		AddAllListsToDrawingList();
		pGUI->UpdateInterface(CurrentTimeStep);
		pGUI->waitForClick();
	}		
}

//Add enemy lists (inactive, active,.....) to drawing list to be displayed on user interface
void Battle::AddAllListsToDrawingList()
{	
	//Add inactive queue to drawing list
	int InactiveCount;
	Enemy* const * EnemyList = Q_Inactive.toArray(InactiveCount);
	for (int i = 0; i < InactiveCount; i++)
	{
		pGUI->AddToDrawingList(EnemyList[i]);
	}

	//Add other lists to drawing list
	//TO DO
	//In next phases, you should add enemies from different lists to the drawing list
	//For the sake of demo, we will use DemoList
	for(int i=0; i<DemoListCount; i++)
		pGUI->AddToDrawingList(DemoList[i]);
}

//check the inactive list and activate all enemies that has arrived
void Battle::ActivateEnemies()
{
	Enemy *pE;
	while( Q_Inactive.peekFront(pE) )	//as long as there are more inactive enemies
	{
		if(pE->GetArrvTime() > CurrentTimeStep )	//no more arrivals at current time
			return;
				
		Q_Inactive.dequeue(pE);	//remove enemy from the queue
		pE->SetStatus(ACTV);	//make status active
		AddtoDemoList(pE);		//move it to demo list (for demo purposes)
	}
}


//Randomly update enemies distance/status (for demo purposes)
void Battle::Demo_UpdateEnemies()	
{
	Enemy* pE;

	int ACTV_To_FRST = 0;
	int ACTV_To_KILL = 0;
	int FRST_To_ACTV = 0;
	int FRST_To_KILL = 0;

	for(int i=0; i<DemoListCount; i++)
	{
		pE = DemoList[i];
		switch(pE->GetStatus())
		{
		case ACTV:
			pE->DecrementDist();	//move the enemy towards the castle
			
			
			
			if (ACTV_To_FRST++ < 2)		//with Freeze propablity, change some active enemies to be frosted
			{
				pE->SetStatus(FRST);
				ActiveCount--;
				FrostedCount++;
			}
			else	if (ACTV_To_KILL++ < 1)	//with kill propablity, kill some active enemies
					{
						pE->SetStatus(KILD);
						ActiveCount--;
						KilledCount++;
					}
			
			break;
		case FRST:

			
			if (FRST_To_ACTV++ < 2)			//with activation propablity, change restore some frosted enemies to be active again
			{
				pE->SetStatus(ACTV);
				ActiveCount++;
				FrostedCount--;
			}
			else	if (FRST_To_KILL++ < 1)			//with kill propablity, kill some frosted enemies
					{
						pE->SetStatus(KILD);
						FrostedCount--;
						KilledCount++;
					}

			break;
		}
	}
}

void Battle::loadfile() {
	infile.open("input.txt");
	if (infile.is_open()) {
		cout << "\\^o^/";
	}
	//Queue<Enemy> Q;

	int indicator = 1; //line indicator...
	char* t;
	char* context = nullptr;
	const int size = 100;
	char line[size];
	int ccc = 0;
	while (infile.getline(line, size)) {
		if (indicator == 1) {
			t = strtok_s(line, " ", &context);
			BCastle.SetHealth(atoi(t));
			t = strtok_s(context, " ", &context);
			BCastle.SetN(atoi(t));
			t = strtok_s(context, " ", &context);
			BCastle.SetCP(atoi(t));
			indicator++;
		}
		else if (indicator == 2) {
			t = strtok_s(line, " ", &context);
			M = atoi(t);
			EnemyCount = M;
			indicator++;
		}
		else if (indicator == 3) {
			t = strtok_s(line, " ", &context);
			int a = atoi(t);
			t = strtok_s(context, " ", &context);
			int b = atoi(t);
			t = strtok_s(context, " ", &context);
			int c = atoi(t);
			t = strtok_s(context, " ", &context);
			int d = atoi(t);
			t = strtok_s(context, " ", &context);
			int e = atoi(t);
			t = strtok_s(context, " ", &context);
			int f = atoi(t);
			t = strtok_s(context, " ", &context);
			int g = atoi(t);
			if (b == 0) {
				Fighter* recca = new Fighter(a, c, MaxDistance);
				recca->setRLD(f);
				recca->setPOW(e);
				recca->setSPD(g);
				recca->setHealth(d);
				Enemy* re = recca;
				re->SetStatus(INAC);
				Q_Inactive.enqueue(re);
			}
			else if (b == 1) {
				Healer* tama = new Healer(a, c, MaxDistance);
				tama->setRLD(f);
				tama->setPOW(e);
				tama->setSPD(g);
				tama->setHealth(d);
				Enemy* ta = tama;
				ta->SetStatus(INAC);
				Q_Inactive.enqueue(ta);
			}
			else if (b == 2) {
				Freezer* enyosha = new Freezer(a, c, MaxDistance);
				enyosha->setRLD(f);
				enyosha->setPOW(e);
				enyosha->setSPD(g);
				enyosha->setHealth(d);
				Enemy* en = enyosha;
				en->SetStatus(INAC);
				Q_Inactive.enqueue(en);
			}
		}
	}

	(infile).close();

}