/*
=================
cTile.h
- Header file for class definition - SPECIFICATION
- Header file for the tileMap class which is a child of cSprite class
=================
*/
#ifndef _CTILE_H
#define _CTILE_H
#include "cSprites.h"
#include "jigsawMaker.h"


class cPieces: public cSprites
{

private:

	glm::ivec2 tileClickedRC;

public:
	cPieces();

	void setTextureWidth();


	void render();		// Default render function
	void render(int textureToRender);		// Default render function
	void update();
};
#endif