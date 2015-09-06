#include "quadcopter.h"
#include <stdlib.h>
#include <iostream>

Copter::Copter()
{
	pitch = 100;
	roll = -100;
	FR = 0;
	FL = 0;
	BR = 0;
	BL = 0;
}

int8_t Copter::getPitch()
{
	return pitch;
}

int8_t Copter::getRoll()
{
	return roll;
}

void Copter::setFR(uint8_t setNum)
{
	FR = setNum;
}

void Copter::setFL(uint8_t setNum)
{
	FL = setNum;
}

void Copter::setBR(uint8_t setNum)
{
	BR = setNum;
}

void Copter::setBL(uint8_t setNum)
{
	BL = setNum;
}

void Copter::move()
{
	pitch += BR*aNum + BL*aNum;
	pitch -= FR*aNum + FL*aNum;
	//pitch += rand()%21 - 10;
 
	roll  += FL*aNum + BL*aNum;
	roll  -= FR*aNum + BR*aNum;
	//roll  += rand()%21 - 10;

	std::cout << "FL: " << (int)FL << "	FR: " << (int)FR << std::endl;
	std::cout << "BL: " << (int)BL << "	BR: " << (int)BR << std::endl;
	std::cout << "Pitch: " << pitch << "	Roll: " << roll << std::endl;
}
