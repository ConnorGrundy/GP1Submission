/*
=================
- cTileMap.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cJigsaw.h"

/*
=================================================================
 Defualt Constructor
=================================================================
*/
cJigsaw::cJigsaw()
{
	spritePos2D.x = 0.0f;
	spritePos2D.y = 0.0f;
	setSpriteTexCoordData();
	spriteTranslation = glm::vec2(0.0f, 0.0f);
	spriteScaling = glm::vec2(1.0f, 1.0f);
	spriteRotation = 0.0f;
	spriteCentre = glm::vec2(0.0f, 0.0f);
}

/*
=================================================================
Defualt Constructor
=================================================================
*/
cJigsaw::cJigsaw(vector<cTextures*> tileTextList)
{
	spritePos2D.x = 0.0f;
	spritePos2D.y = 0.0f;
	setSpriteTexCoordData();
	spriteTranslation = glm::vec2(0.0f, 0.0f);
	spriteScaling = glm::vec2(1.0f, 1.0f);
	spriteRotation = 0.0f;
	spriteCentre = glm::vec2(0.0f, 0.0f);
	tileTextureList = tileTextList;
}
/*
=================================================================
Defualt Constructor
=================================================================
*/
cJigsaw::cJigsaw(vector<cTextures*> tileTextList, int tMap[][6])
{
	spritePos2D.x = 0.0f;
	spritePos2D.y = 0.0f;
	setSpriteTexCoordData();
	spriteTranslation = glm::vec2(0.0f, 0.0f);
	spriteScaling = glm::vec2(1.0f, 1.0f);
	spriteRotation = 0.0f;
	spriteCentre = glm::vec2(0.0f, 0.0f);
	tileTextureList = tileTextList;
	initialiseMap(tMap);
}
void cJigsaw::render()
{
	mapStartXY = spritePos2D;
	glm::vec2 tilePosXY = mapStartXY;
	for (int row = 0; row < 6; row++)
	{
		for (int column = 0; column < 6; column++)
		{
			switch (Jigsaw[row][column])
			{
			case 0:
				GLTextureID = tileTextureList[0]->getTexture();   //getting all the pieces
				break;
			case 1:
				GLTextureID = tileTextureList[1]->getTexture();
				break;
			case 2:
				GLTextureID = tileTextureList[2]->getTexture();
				break;
			case 3:
				GLTextureID = tileTextureList[3]->getTexture();
				break;
			case 4:
				GLTextureID = tileTextureList[4]->getTexture();
				break;
			case 5:
				GLTextureID = tileTextureList[5]->getTexture();
				break;
			case 6:
				GLTextureID = tileTextureList[6]->getTexture();
				break;
			case 7:
				GLTextureID = tileTextureList[7]->getTexture();
				break;
			case 8:
				GLTextureID = tileTextureList[8]->getTexture();
				break;
			case 9:
				GLTextureID = tileTextureList[9]->getTexture();
				break;
			case 10:
				GLTextureID = tileTextureList[10]->getTexture();
				break;
			case 11:
				GLTextureID = tileTextureList[11]->getTexture();
				break;
			case 12:
				GLTextureID = tileTextureList[12]->getTexture();
				break;
			case 13:
				GLTextureID = tileTextureList[13]->getTexture();
				break;
			case 14:
				GLTextureID = tileTextureList[14]->getTexture();
				break;
			case 15:
				GLTextureID = tileTextureList[15]->getTexture();
				break;
			case 16:
				GLTextureID = tileTextureList[16]->getTexture();
				break;
			case 17:
				GLTextureID = tileTextureList[17]->getTexture();
				break;
			case 18:
				GLTextureID = tileTextureList[18]->getTexture();
				break;
			case 19:
				GLTextureID = tileTextureList[19]->getTexture();
				break;
			case 20:
				GLTextureID = tileTextureList[20]->getTexture();
				break;
			case 21:
				GLTextureID = tileTextureList[21]->getTexture();
				break;
			case 22:
				GLTextureID = tileTextureList[22]->getTexture();
				break;
			case 23:
				GLTextureID = tileTextureList[23]->getTexture();
				break;
			case 24:
				GLTextureID = tileTextureList[24]->getTexture();
				break;
			case 25:
				GLTextureID = tileTextureList[25]->getTexture();
				break;
			case 26:
				GLTextureID = tileTextureList[26]->getTexture();
				break;
			case 27:
				GLTextureID = tileTextureList[27]->getTexture();
				break;
			case 28:
				GLTextureID = tileTextureList[28]->getTexture();
				break;
			case 29:
				GLTextureID = tileTextureList[29]->getTexture();
				break;
			case 30:
				GLTextureID = tileTextureList[30]->getTexture();
				break;
			case 31:
				GLTextureID = tileTextureList[31]->getTexture();
				break;
			case 32:
				GLTextureID = tileTextureList[32]->getTexture();
				break;
			case 33:
				GLTextureID = tileTextureList[33]->getTexture();
				break;
			case 34:
				GLTextureID = tileTextureList[34]->getTexture();
				break;
			case 35:
				GLTextureID = tileTextureList[35]->getTexture();
				break;
			case 36:
				GLTextureID = tileTextureList[36]->getTexture();
				break;
			}
			
			setTextureDimensions(tileTextureList[0]->getTWidth(), tileTextureList[0]->getTHeight());
			setSpriteCentre();

			glPushMatrix();

			glTranslatef(tilePosXY.x, tilePosXY.y, 0.0f);

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, GLTextureID); // Binding of GLtexture name 

			glBegin(GL_QUADS);
			glColor3f(255.0f, 255.0f, 255.0f);
			glTexCoord2f(spriteTexCoordData[0].x, spriteTexCoordData[0].y);
			glVertex2f(0, 0);
			glTexCoord2f(spriteTexCoordData[1].x, spriteTexCoordData[1].y);
			glVertex2f(textureWidth, 0);
			glTexCoord2f(spriteTexCoordData[2].x, spriteTexCoordData[2].y);
			glVertex2f(textureWidth, textureHeight);
			glTexCoord2f(spriteTexCoordData[3].x, spriteTexCoordData[3].y);
			glVertex2f(0, textureHeight);

			glEnd();
			glDisable(GL_TEXTURE_2D);

			glPopMatrix();

			tilePosXY.x += cSprites::textureWidth;
		}
		tilePosXY.x = mapStartXY.x;
		tilePosXY.y += cSprites::textureHeight;
	}

}

void cJigsaw::renderGridLines()
{
	mapStartXY = spritePos2D;
	glm::vec2 tilePosXY = mapStartXY;
	for (int row = 0; row < 6; row++)
	{
		for (int column = 0; column < 6; column++)
		{

			glPushMatrix();

			glTranslatef(tilePosXY.x, tilePosXY.y, 0.0f);

			glBegin(GL_LINE_LOOP);
			glColor3f(0.0f, 0.0f, 255.0f);
			glVertex2f(0, 0);
			glVertex2f(textureWidth, 0);
			glVertex2f(textureWidth, textureHeight);
			glVertex2f(0, textureHeight);

			glEnd();

			glPopMatrix();

			tilePosXY.x += cSprites::textureWidth;
		}
		tilePosXY.x = mapStartXY.x;
		tilePosXY.y += cSprites::textureHeight;
	}

}
/*
=================================================================
Update the sprite position
=================================================================
*/

void cJigsaw::update()
{
	if (m_InputMgr->getLeftMouseBtn() == false)
	{
		glm::vec2 areaClicked = m_InputMgr->getMouseXY();
		if (tileToPlace > -1)
		{
			if (areaClicked.x > 100 && areaClicked.x < 612 && areaClicked.y > 100 && areaClicked.y < 612)
			{
				tileClickedRC.x = (int)(areaClicked.x - mapStartXY.x) / textureWidth;
				tileClickedRC.y = (int)(areaClicked.y - mapStartXY.y) / textureHeight;
				Jigsaw[tileClickedRC.y][tileClickedRC.x] = tileToPlace;
				if (answer[tileClickedRC.y][tileClickedRC.x] = tileToPlace)
				{
					score += 1;   //score is increased here
					PlaySound(TEXT("Sounds/Ding.wav"), NULL, SND_FILENAME); //Plays sound when score is increased
					PlaySound(TEXT("Sounds/MenuMusic.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //Continues to play game sound
				}
				tileToPlace = -1;
				tileSelected = false;
				m_InputMgr->clearBuffers(m_InputMgr->MOUSE_BUFFER); 
			}
		}
	}

}

/*
=================================================================
- Set the initial values for the map
=================================================================
*/
void cJigsaw::initialiseMap(int map[6][6])
{
	for (int row = 0; row < 6; row++)
	{
		for (int column = 0; column < 6; column++)
		{
			Jigsaw[row][column] = map[row][column];
		}
	}
	 
}
/*
=================================================================
- Load the texture list with the correct textures
=================================================================
*/
void cJigsaw::loadTextures()
{

}
/*
=================================================================
- set start position for tile map
=================================================================
*/
void cJigsaw::setMapStartXY(glm::vec2 startPosXY)
{
	mapStartXY = startPosXY;
}
/*
=================================================================
- get start pposition for tile map
=================================================================
*/
glm::vec2 cJigsaw::getMapStartXY()
{
	return mapStartXY;
}
/*
=================================================================
- get the tile map as a string
=================================================================
*/
string cJigsaw::getMap()
{
	string mapData = "";
	for (int row = 0; row < 6; row++)
	{
		for (int column = 0; column < 6; column++)
		{
			mapData += to_string(Jigsaw[row][column]) + ',';
		}
		mapData += '\n';
	}
	return mapData;
}