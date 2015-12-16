/*
=================
cTilePicker.h
- Header file for class definition - SPECIFICATION
- Header file for the tileMap class which is a child of cSprite class
=================
*/
#ifndef _CTILEPICKER_H
#define _CTILEPICKER_H
#include "cSprites.h"
#include "jigsawMaker.h"

class cPiecePicker : public cSprites
{
protected:
	int tilePickingList[6][6];
	int tileMap[6][6]; 

private:
	vector<cTextures*> tileTextureList;
	glm::vec2 tileListStartXY;
	glm::ivec2 tileClickedRC;

	void initialiseTileList();		// Set the initial values for the map
	void loadTextures();		// Load the texture list with the correct textures

public:
	cPiecePicker();
	cPiecePicker(vector<cTextures*> tileTextList);
	cPiecePicker(vector<cTextures*> tileTextList, int tMap[][6]);

	void render();		// Default render function
	void update();
	void setTileListStartXY(glm::vec2 startPosXY);
	glm::vec2 getTileListStartXY();
};
#endif