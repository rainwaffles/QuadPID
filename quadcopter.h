#ifndef __QUADCOPTER_H__
#define __QUADCOPTER_H__

#include <stdint.h>

class Copter
{
public:
	Copter();
	// get the orientation: 0 -> flat, (-)127 -> max tilt
	int8_t getPitch(); // leaning forwards / backwards: positive -> forwards
	int8_t getRoll(); // leaning right / left: positive -> right
	
	// set the motor strength: 0 -> off, 255 -> max thrust
	void setFR(uint8_t); // front right
	void setFL(uint8_t); // front left
	void setBR(uint8_t); // back right
	void setBL(uint8_t); // back left
	void move(); //For simple simulation purposes
private:
	double pitch;
	double roll;
	uint8_t FR;
	uint8_t FL;
	uint8_t BR;
	uint8_t BL;
	
	static const float aNum = 0.1; //Arbitrary number; placeholder for simulation purposes
};
#endif
