/*
==================================================================================
mazeMaker.cpp
==================================================================================
*/

#include "jigsawMaker.h"

int tileToPlace = -1;
int gtextureID = 0;
bool tileSelected = false;
int answer[6][6] = { { 17, 22, 31, 14, 25, 36 },    //If number on map matches image ID +1 to score and a sound is played
{ 7, 8, 9, 10, 11, 12 },
{ 13, 14, 15, 16, 17, 18 },
{ 19, 20, 21, 22, 23, 24 },
{ 25, 26, 27, 28, 29, 30 },
{ 31, 32, 33, 34, 35, 36 } };

int score = 0; //sets score