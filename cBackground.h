/*
================
cBkGround.h
- Header file for class definition - SPECIFICATION
- Header file for the Background class which is a child of cSprite class
=================
*/
#ifndef _CBKGROUND_H
#define _CBKGROUND_H
#include "cSprites.h"

class cBackground : public cSprites
{
public:
	void render();		// Default render function
	void update();		// Update method
};
#endif