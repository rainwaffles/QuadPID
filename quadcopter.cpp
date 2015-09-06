#include "quadcopter.h"
#include <stdlib.h>
#include <iostream>

double pitch = 100;
double roll  = -100;

uint8_t FR = 0;
uint8_t FL = 0;
uint8_t BR = 0;
uint8_t BL = 0;

double height = 0;
double vel = 0;

int8_t getPitch()
{
	return pitch;
}

int8_t getRoll()
{
	return roll;
}

void setFR(uint8_t setNum)
{
	FR = setNum;
}

void setFL(uint8_t setNum)
{
	FL = setNum;
}

void setBR(uint8_t setNum)
{
	BR = setNum;
}

void setBL(uint8_t setNum)
{
	BL = setNum;
}

uint8_t getHeight()
{
	return height;
}

void move()
{
	pitch += BR*aNum + BL*aNum;
	pitch -= FR*aNum + FL*aNum;
	//pitch += rand()%21 - 10;
 
	roll  += FL*aNum + BL*aNum;
	roll  -= FR*aNum + BR*aNum;
	//roll  += rand()%21 - 10;
	
	vel = (FR*aNum + FL*aNum + BR*aNum + BL*aNum) - 30;
	height += vel;
	height = (height < 0) ? 0 : height;
	
	std::cout << "FL: " << (int)FL << "	FR: " << (int)FR << std::endl;
	std::cout << "BL: " << (int)BL << "	BR: " << (int)BR << std::endl;
	std::cout << "Pitch: " << pitch << "	Roll: " << roll << std::endl;
	std::cout << "Height: " << height << std::endl;
}
