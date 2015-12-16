/*
=================
cTileMap.h
- Header file for class definition - SPECIFICATION
- Header file for the tileMap class which is a child of cSprite class
=================
*/
#ifndef _CTILEMAP_H
#define _CTILEMAP_H
#include "cSprites.h"
#include "jigsawMaker.h"


class cJigsaw: public cSprites
{
protected:
	int Jigsaw[6][6];

private:
	vector<cTextures*> tileTextureList;
	glm::vec2 mapStartXY;
	glm::ivec2 tileClickedRC;

	void loadTextures();		// Load the texture list with the correct textures

public:
	cJigsaw();
	cJigsaw(vector<cTextures*> tileTextList);
	cJigsaw(vector<cTextures*> tileTextList, int tMap[][6]);

	void initialiseMap(int map[6][6]);		// Set the initial values for the map
	void render();		// Default render function
	void renderGridLines();
	void update();
	void setMapStartXY(glm::vec2 startPosXY);
	glm::vec2 getMapStartXY();
	string getMap();
};
#endif