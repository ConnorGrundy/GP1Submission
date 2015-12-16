/*
=================
cSprite.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cSprites.h"
/*
=================
- Data constructor initializes the cSprite to the data passed to 
- the constructor from the paramater sPosition.
- Is always called, thus ensures all sprite objects are in a consistent state.
=================
*/
cSprites::cSprites() 			// Default constructor
{

	cSprites::spritePos2D.x = 0.0f;
	cSprites::spritePos2D.y = 0.0f;
	cSprites::setSpriteTexCoordData();
	cSprites::spriteTranslation = glm::vec2(0.0f, 0.0f);
	cSprites::spriteScaling = glm::vec2(1.0f, 1.0f);
	cSprites::spriteRotation = 0.0f;
	cSprites::spriteCentre = glm::vec2(0.0f, 0.0f);
}

/*
=================
- Destructor 
=================
*/
cSprites::~cSprites()			// Destructor
{
}
/*
=================
- Return the sprites current position.
=================
*/

glm::vec2 cSprites::getSpritePos()  // Return the sprites current position
{
	return cSprites::spritePos2D;
}

/*
=================
- set the position of the sprite.
=================
*/

void cSprites::setSpritePos(glm::vec2 sPosition)  // set the position of the sprite
{
	cSprites::spritePos2D = sPosition;
}

/*
=================
- Return the sprites current image.
=================
*/

GLuint cSprites::getTexture()  // Return the sprites current image
{
	return GLTextureID;
}

/*
=================
- set the image of the sprite.
=================
*/

void cSprites::setTexture(GLuint GLtexID)  // set the image of the sprite
{
	GLTextureID = GLtexID;
}

/*
=================================================================================
  set the amount of movement on the x & y axis
=================================================================================
*/
void cSprites::setSpriteTranslation(glm::vec2 translation)
{
	spriteTranslation = translation;
}

/*
=================================================================================
  get the amount of movement on the x & y axis
=================================================================================
*/
glm::vec2 cSprites::getSpriteTranslation()
{
	return spriteTranslation;
}
/*
=================================================================================
  Set the sprites centre point
=================================================================================
*/
void cSprites::setSpriteCentre()
{
	spriteCentre.x = textureWidth / 2;
	spriteCentre.y = textureHeight / 2;
}

/*
=================================================================================
  return the sprites centre point
=================================================================================
*/
glm::vec2 cSprites::getSpriteCentre()
{
	return spriteCentre;
}
/*
=================================================================================
Default render function
=================================================================================
*/
void cSprites::render()
{
	glPushMatrix();

	glTranslatef(spritePos2D.x, spritePos2D.y, 0.0f);
	glRotatef(spriteRotation, 0.0f, 0.0f,1.0f);
	glScalef(spriteScaling.x, spriteScaling.y, 1.0f);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, GLTextureID); // Binding of GLtexture name 

	glBegin(GL_QUADS);
		glColor3f(255.0f, 255.0f, 255.0f);
		glTexCoord2f(spriteTexCoordData[0].x, spriteTexCoordData[0].y);
		glVertex2f(0, 0);
		glTexCoord2f(spriteTexCoordData[1].x, spriteTexCoordData[1].y);
		glVertex2f( textureWidth, 0);
		glTexCoord2f(spriteTexCoordData[2].x, spriteTexCoordData[2].y);
		glVertex2f(textureWidth, textureHeight);
		glTexCoord2f(spriteTexCoordData[3].x, spriteTexCoordData[3].y);
		glVertex2f(0, textureHeight);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}
void cSprites::setSpriteTexCoordData()
{
	spriteTexCoordData[0] = glm::vec2(0.0f, 0.0f);
	spriteTexCoordData[1] = glm::vec2(1.0f, 0.0f);
	spriteTexCoordData[2] = glm::vec2(1.0f, 1.0f);
	spriteTexCoordData[3] = glm::vec2(0.0f, 1.0f);
}

void cSprites::setTextureDimensions(int texWidth, int textHeight)
{
	textureWidth = texWidth;
	textureHeight = textHeight;
}

/* 
=================================================================
   Attach the input manager to the sprite
=================================================================
*/
void cSprites::attachInputMgr(cInputMgr* inputMgr)
{
	m_InputMgr = inputMgr;
}

