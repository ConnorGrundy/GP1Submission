#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#define GLX_GLXEXT_LEGACY //Must be declared so that our local glxext.h is picked up, rather than the system one


#include <windows.h>
#include "windowOGL.h"
#include "GameConstants.h"
#include "cWNDManager.h"
#include "cInputMgr.h"
#include "cSprites.h"
#include "cBackground.h"
#include "cFontMgr.h"
#include "jigsawMaker.h"
#include "cFileHandler.h"
#include "cButtons.h"
#include <MMSystem.h>

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR cmdLine,
                   int cmdShow)
{

    //Set our window settings
    const int windowWidth = 1024;
    const int windowHeight = 768;
    const int windowBPP = 16;



    //This is our window
	static cWNDManager* pgmWNDMgr = cWNDManager::getInstance();

	// This is the input manager
	static cInputMgr* theInputMgr = cInputMgr::getInstance();
	
	// This is the Font manager
	static cFontMgr* theFontMgr = cFontMgr::getInstance();


    //The example OpenGL code
    windowOGL theOGLWnd;
	
    //Attach our the OpenGL window
	pgmWNDMgr->attachOGLWnd(&theOGLWnd);

	// Attach the keyboard manager
	pgmWNDMgr->attachInputMgr(theInputMgr);

    //Attempt to create the window
	if (!pgmWNDMgr->createWND(windowWidth, windowHeight, windowBPP))
    {
        //If it fails

        MessageBox(NULL, "Unable to create the OpenGL Window", "An error occurred", MB_ICONERROR | MB_OK);
		pgmWNDMgr->destroyWND(); //Reset the display and exit
        return 1;
    }

	if (!theOGLWnd.initOGL(windowWidth, windowHeight)) //Initialize our example
    {
        MessageBox(NULL, "Could not initialize the application", "An error occurred", MB_ICONERROR | MB_OK);
		pgmWNDMgr->destroyWND(); //Reset the display and exit
        return 1;
    }

	//Clear key buffers
	theInputMgr->clearBuffers(theInputMgr->KEYS_DOWN_BUFFER | theInputMgr->KEYS_PRESSED_BUFFER | theInputMgr->MOUSE_BUFFER);


	int map[6][6] = { { 0, 0, 0, 0, 0, 0 },  //The map to place pieces
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0 } };

	bool resetValues = false;  //So that values aren't always reset
	

	// load game fontss
	// Load Fonts
	LPCSTR gameFonts[2] = { "Fonts/digital-7.ttf", "Fonts/space age.ttf" };

	theFontMgr->addFont("SevenSeg", gameFonts[0], 24);
	theFontMgr->addFont("Space", gameFonts[1], 24);

	// Create vector array of textures
	vector<cTextures*> textureList;
	LPCSTR texturesToUse[] = { "Images/blank.png", "Images/Pieces/p17.png", "Images/Pieces/p22.png", "Images/Pieces/p31.png", "Images/Pieces/p14.png", "Images/Pieces/p25.png", "Images/Pieces/p36.png","Images/Pieces/p15.png", "Images/Pieces/p28.png", "Images/Pieces/p9.png", "Images/Pieces/p19.png", "Images/Pieces/p24.png", "Images/Pieces/p32.png" ,"Images/Pieces/p13.png", "Images/Pieces/p27.png", "Images/Pieces/p7.png", "Images/Pieces/p16.png", "Images/Pieces/p1.png", "Images/Pieces/p35.png" ,"Images/Pieces/p10.png", "Images/Pieces/p23.png", "Images/Pieces/p21.png", "Images/Pieces/p2.png", "Images/Pieces/p20.png", "Images/Pieces/p11.png" ,"Images/Pieces/p33.png", "Images/Pieces/p26.png", "Images/Pieces/p5.png", "Images/Pieces/p8.png", "Images/Pieces/p30.png", "Images/Pieces/p29.png" ,"Images/Pieces/p3.png", "Images/Pieces/p12.png", "Images/Pieces/p4.png", "Images/Pieces/p34.png", "Images/Pieces/p18.png", "Images/Pieces/p6.png" };
	for (int tCount = 0; tCount < 37; tCount++)
	{
		textureList.push_back(new cTextures());
		textureList[tCount]->createTexture(texturesToUse[tCount]);
	}

	//Include game sounds
	LPCSTR gameSounds[2] = { "Sounds/MenuMusic.wav", "Sounds/Ding.wav" };

	PlaySound(TEXT("Sounds/MenuMusic.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //Loop the theme song

	// Create vector array of textures
	vector<cTextures*> textureBkgList;
	LPCSTR bkgTexturesToUse[] = { "Images/JigsawBkg.png", "Images/JigsawStartBkg.png", "Images/JigsawEndBkg.png" };
	for (int tCount = 0; tCount < 3; tCount++)
	{
		textureBkgList.push_back(new cTextures());
		textureBkgList[tCount]->createTexture(bkgTexturesToUse[tCount]);
	}

	cTextures transSprite;
	transSprite.createTexture("Images/blank.png");

	//positioning backgrounds

	cBackground spriteBkgd;
	spriteBkgd.setSpritePos(glm::vec2(0.0f, 0.0f));
	spriteBkgd.setTexture(textureBkgList[0]->getTexture());
	spriteBkgd.setTextureDimensions(textureBkgList[0]->getTWidth(), textureBkgList[0]->getTHeight());

	cBackground spriteStartBkgd;
	spriteStartBkgd.setSpritePos(glm::vec2(0.0f, 0.0f));
	spriteStartBkgd.setTexture(textureBkgList[1]->getTexture());
	spriteStartBkgd.setTextureDimensions(textureBkgList[1]->getTWidth(), textureBkgList[1]->getTHeight());

	cBackground spriteEndBkgd;
	spriteEndBkgd.setSpritePos(glm::vec2(0.0f, 0.0f));
	spriteEndBkgd.setTexture(textureBkgList[2]->getTexture());
	spriteEndBkgd.setTextureDimensions(textureBkgList[2]->getTWidth(), textureBkgList[2]->getTHeight());

	cJigsaw tileMap(textureList, map);
	tileMap.attachInputMgr(theInputMgr); // Attach the input manager to the sprite
	tileMap.setSpritePos(glm::vec2(100.0f, 100.0f));

	cPiecePicker roadMap(textureList, map);
	roadMap.attachInputMgr(theInputMgr); // Attach the input manager to the sprite
	roadMap.setSpritePos(glm::vec2(512.0f, 100.0f));

	cPieces tileToDrag;
	tileToDrag.attachInputMgr(theInputMgr);
	tileToDrag.setSpritePos(glm::vec2(0.0f, 00.0f));
	tileToDrag.setTexture(transSprite.getTexture());
	tileToDrag.setTextureDimensions(transSprite.getTWidth(), transSprite.getTHeight());

	// Create vector array of button textures
	vector<cTextures*> btnTextureList;
	LPCSTR btnTexturesToUse[] = { "Images/Buttons/exitBtn.png", "Images/Buttons/instructionsBtn.png", "Images/Buttons/loadBtn.png", "Images/Buttons/playBtn.png", "Images/Buttons/saveBtn.png", "Images/Buttons/settingsBtn.png"};
	for (int tCount = 0; tCount < 6; tCount++)
	{
		btnTextureList.push_back(new cTextures());
		btnTextureList[tCount]->createTexture(btnTexturesToUse[tCount]);
	}

	cButtons saveButton;
	saveButton.attachInputMgr(theInputMgr);
	saveButton.setTexture(btnTextureList[4]->getTexture());
	saveButton.setTextureDimensions(btnTextureList[4]->getTWidth(), btnTextureList[4]->getTHeight());

	cButtons exitButton;
	exitButton.attachInputMgr(theInputMgr);
	exitButton.setTexture(btnTextureList[0]->getTexture());
	exitButton.setTextureDimensions(btnTextureList[0]->getTWidth(), btnTextureList[0]->getTHeight());

	cButtons playButton;
	playButton.attachInputMgr(theInputMgr);
	playButton.setTexture(btnTextureList[3]->getTexture());
	playButton.setTextureDimensions(btnTextureList[3]->getTWidth(), btnTextureList[3]->getTHeight());

	

	cFileHandler theFile("Data/usermap.dat");
	string mapData;

	string outputMsg;
	string strMsg[] = { "Solve the jigsaw puzzle!","Drag and Drop the pieces.", "Jigsaw Puzzle", "Thanks for playing!","See you again soon!" };

	if (!theFile.openFile(ios::in)) //open file for input output
	{
		MessageBox(NULL, "Could not open specified file.", "An error occurred", MB_ICONERROR | MB_OK);
	}
	else
	{
		mapData = theFile.readDataFromFile();
		theFile.closeFile();
		// Fill map with data from file
		int strPos = 0;
		for (int row = 0; row < 6; row++) 
		{
			for (int column = 0; column < 6; column++)
			{
				if (mapData[strPos] != ',')
				{
					map[row][column] = mapData[strPos] - 48;
					strPos+= 2;
				}
			}
		}
	}

	tileMap.initialiseMap(map);

	gameState theGameState = MENU;
	btnTypes theBtnType = EXIT;
	string msgScore = "";  //display score

	//This is the mainloop, we render frames until isRunning returns false
	while (pgmWNDMgr->isWNDRunning())
    {
		pgmWNDMgr->processWNDEvents(); //Process any window events

        //We get the time that passed since the last frame
		float elapsedTime = pgmWNDMgr->getElapsedSeconds();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		switch (theGameState)
		{
		case MENU:

			{
				theGameState = playButton.update(theGameState, PLAYING);
				exitButton.update();
			}

			spriteStartBkgd.render();

			playButton.setSpritePos(glm::vec2(433.0f, 300.0f));
			exitButton.setSpritePos(glm::vec2(433.0f, 375.0f));
			playButton.render();
			exitButton.render();

			theGameState = playButton.update(theGameState, PLAYING);
			exitButton.update();


			outputMsg = strMsg[2];
			theFontMgr->getFont("Space")->printText(outputMsg.c_str(), FTPoint(10, 15, 0.0f));
			outputMsg = strMsg[0];
			theFontMgr->getFont("Space")->printText(outputMsg.c_str(), FTPoint(283, 175, 0.0f));
			outputMsg = strMsg[1];
			theFontMgr->getFont("Space")->printText(outputMsg.c_str(), FTPoint(283, 225, 0.0f));
			if (exitButton.getClicked())
			{
				SendMessage(pgmWNDMgr->getWNDHandle(), WM_CLOSE, NULL, NULL);
			}
			
			
			break;
		case PLAYING:

			if (resetValues)
			{
				score = 0;
				tileMap.initialiseMap(map);
				resetValues = false;
			}

			spriteBkgd.render();

			roadMap.update();
			roadMap.render();
			tileMap.update();
			tileMap.render();
			tileMap.renderGridLines();
			tileToDrag.update();
			tileToDrag.render();

			// render button and reset clicked to false
			saveButton.setSpritePos(glm::vec2(740.0f, 500.0f));
			saveButton.render();
			saveButton.update("Data/usermap.dat", tileMap.getMap());

			exitButton.setSpritePos(glm::vec2(740.0f, 575.0f));
			exitButton.render();
			theGameState = exitButton.update(theGameState, END);

			msgScore = to_string(score);
			outputMsg = strMsg[2];
			theFontMgr->getFont("Space")->printText(outputMsg.c_str(), FTPoint(10, 15, 0.0f));
			theFontMgr->getFont("Space")->printText(msgScore.c_str(), FTPoint(800, 15, 0.0f));

			break;

		case END:
			spriteEndBkgd.render();

			playButton.setClicked(false);
			exitButton.setClicked(false);

			playButton.setSpritePos(glm::vec2(433.0f, 300.0f));
			exitButton.setSpritePos(glm::vec2(433.0f, 375.0f));
			playButton.render();
			exitButton.render();

			theGameState = playButton.update(theGameState, PLAYING);
			exitButton.update();

			outputMsg = strMsg[2];
			theFontMgr->getFont("Space")->printText(outputMsg.c_str(), FTPoint(10, 15, 0.0f));
			outputMsg = strMsg[3];
			theFontMgr->getFont("Space")->printText(outputMsg.c_str(), FTPoint(283, 100, 0.0f));
			outputMsg = strMsg[4];
			theFontMgr->getFont("Space")->printText(outputMsg.c_str(), FTPoint(283, 150, 0.0f));
			if (exitButton.getClicked())
			{
				SendMessage(pgmWNDMgr->getWNDHandle(), WM_CLOSE, NULL, NULL);
			}
			if (playButton.getClicked()) //game resets if player presses play in end scene
			{
				resetValues = true;
			}
			break;
		}

		pgmWNDMgr->swapBuffers();
		//theInputMgr->clearBuffers(theInputMgr->KEYS_DOWN_BUFFER | theInputMgr->KEYS_PRESSED_BUFFER | theInputMgr->MOUSE_BUFFER);
    }

	theOGLWnd.shutdown(); //Free any resources
	pgmWNDMgr->destroyWND(); //Destroy the program window

    return 0; //Return success
}
