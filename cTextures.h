/*
=================
cTexture.h
- Header file for class definition - SPECIFICATION
- Header file for the cD3DXTexture class
=================
*/
#ifndef _CTEXTURE_H
#define _CTEXTURE_H
#include "GameConstants.h"

class cTextures
{
private:
	GLuint GLTextureID;
	GLuint aTextureInfo;
	GLsizei textureWidth;
	GLsizei textureHeight;
	ILuint ilTextureID;
	ILubyte *txData;

public:
	cTextures();
	cTextures(LPCSTR theFilename);
	~cTextures();
	bool createTexture(LPCSTR theFilename);		// create the texture for use.
	GLuint getTexture();						// return the texture.
	GLsizei getTWidth();						// Return width of texture;
	GLsizei getTHeight();						// Return height of texture;
};
#endif