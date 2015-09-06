#include "quadcopter.h"
#include <iostream>
#include <unistd.h>
#include <algorithm>

Copter *c;

int main(int argc, char* argv[])
{
	int desiredPitch = 0;
	int desiredRoll = 0;
	int basePower = 100; //IDK what the height should be, this just assumes 100 is the hovering power.\
				It could shoot off into the distance, it could not even get off the ground.
	double pwrNum = 2; //This number decides how much the copter should correct. It changes\
				based on how far the copter overshoots and stuff.
	c = new Copter();
	
	//for(int i = 0; i < 100; i++)
	while(true)
	{
		c->move();
		int pDiff = c->getPitch() - desiredPitch;
		int rDiff = c->getRoll()  - desiredRoll;
		c->setFR(std::min(std::max((int)(basePower + pDiff*pwrNum + rDiff*pwrNum), 0), 255));
		c->setFL(std::min(std::max((int)(basePower + pDiff*pwrNum - rDiff*pwrNum), 0), 255));
		c->setBR(std::min(std::max((int)(basePower - pDiff*pwrNum + rDiff*pwrNum), 0), 255));
		c->setBL(std::min(std::max((int)(basePower - pDiff*pwrNum - rDiff*pwrNum), 0), 255));
		usleep(50000);
	}
}
