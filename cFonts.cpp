/*
==========================================================================
cFont.cpp
==========================================================================
*/
#pragma warning ( disable : 4996 )
#include "cFonts.h"
using namespace std;

/*
==========================================================================
Default Constructor
==========================================================================
*/
cFonts::cFonts()
{
	theFont = NULL;
}
/*
==========================================================================
Overloaded constructor
==========================================================================
*/
cFonts::cFonts(LPCSTR fontFileName, int fontSize)
{
	theFont = new FTTextureFont(fontFileName);

	if (theFont == NULL)
	{
		MessageBox(NULL, "Unable to create the required Font!", "An error occurred", MB_ICONERROR | MB_OK);
		delete theFont;
	}

	if (!theFont->FaceSize(fontSize))
	{
		MessageBox(NULL, "Unable to set desired size for Font!", "An error occurred", MB_ICONERROR | MB_OK);
		delete theFont;
	}
}

/*
==========================================================================
Destructor
==========================================================================
*/
cFonts::~cFonts()
{
	delete theFont;
}
/*
==========================================================================
get the pointer to the font
==========================================================================
*/
FTFont* cFonts::getFont()
{
	return theFont;
}

/*
==========================================================================
Render the text using the desired font
==========================================================================
*/
void cFonts::printText(LPCSTR text, FTPoint textPos)
{
	glPushMatrix();

	glTranslatef(textPos.X(), textPos.Y(), 0 );
	glScalef(1, -1, 1);
	glColor3f(0.0f, 0.0f, 255.0f);
	theFont->Render(text);

	glPopMatrix();
}
