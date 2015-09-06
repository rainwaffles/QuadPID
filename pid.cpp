#include "quadcopter.h"
#include <iostream>
#include <unistd.h>
#include <algorithm>

int main(int argc, char* argv[])
{
	int desiredPitch = 0;
	int desiredRoll = 0;
	int desiredHeight = 100;
	int desiredPower = 100; //This needs to change based on how high it goes / power
	float pwrNum = 2; //This number decides how much the copter should correct. It changes\
				based on how far the copter overshoots and stuff.
	
	int pH = 0;
	int pP = 0;
	int cH = 0;
	int cP = 0;
	
	//for(int i = 0; i < 100; i++)
	while(true)
	{
		move();
		pH = cH;
		pP = cP;
		
		cH = getHeight();
		
		if     ((cH - pH) <= 0 && cH < desiredHeight)
		{
			desiredPower += (desiredHeight - cH) * 0.5;
		}
		else if((cH - pH) >= 0 && cH > desiredHeight)
		{
			desiredPower -= (cH - desiredHeight) * 0.5;
		}
		/*
		else if((cH - pH) >  0 && cH < desiredHeight)
		{
			
		}
		*/
		
		int pDiff = getPitch() - desiredPitch;
		int rDiff = getRoll()  - desiredRoll;
		setFR(std::min(std::max((int)(desiredPower + pDiff*pwrNum + rDiff*pwrNum), 0), 255));
		setFL(std::min(std::max((int)(desiredPower + pDiff*pwrNum - rDiff*pwrNum), 0), 255));
		setBR(std::min(std::max((int)(desiredPower - pDiff*pwrNum + rDiff*pwrNum), 0), 255));
		setBL(std::min(std::max((int)(desiredPower - pDiff*pwrNum - rDiff*pwrNum), 0), 255));
		usleep(50000);
	}
}
