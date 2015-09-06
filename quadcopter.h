#ifndef __QUADCOPTER_H__
#define __QUADCOPTER_H__

#include <stdint.h>

// get the orientation: 0 -> flat, (-)127 -> max tilt
int8_t getPitch(); // leaning forwards / backwards: positive -> forwards
int8_t getRoll(); // leaning right / left: positive -> right
uint8_t getHeight(); // 0 - 255 cm

// set the motor strength: 0 -> off, 255 -> max thrust
void setFR(uint8_t); // front right
void setFL(uint8_t); // front left
void setBR(uint8_t); // back right
void setBL(uint8_t); // back left

void move(); //For simple simulation purposes

extern double pitch;
extern double roll;

extern uint8_t FR;
extern uint8_t FL;
extern uint8_t BR;
extern uint8_t BL;

extern double height;
extern double vel;

static const float aNum = 0.1; //Arbitrary number; placeholder for simulation purposes

#endif
