/*
==========================================================================
cFont.h
==========================================================================
*/

#ifndef _CFONT_H
#define _CFONT_H

// OpenGL Headers
#include "GameConstants.h"

using namespace std;

class cFonts
{
private:
	FTFont* theFont;


public:
	cFonts();
	cFonts(LPCSTR fontFileName, int fontSize);
	~cFonts();
	FTFont* getFont();
	void printText(LPCSTR text, FTPoint textPos);

};
#endif