//
//  Core.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 21/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Core.hpp"


/**
 Ignite all the library and the game Object

 @param appPath appPath
 */
void Core::ignite(std::string appPath)
{
	Igniter igniter = Igniter();

	igniter.igniteGameObject(appPath);
	igniter.igniteSDL();
	igniter.igniteOpenGL();

	//Init random generator
	srand((uint)time(NULL));
}

/**
 Main loop of the program
 */
void Core::main()
{
	std::chrono::high_resolution_clock::time_point start, end;

	//Load the first scene
	sceneConsole::load();

	while(GameObj->isRunning())
	{
		////////////////////////////////
		//The main loop

		start = std::chrono::high_resolution_clock::now();

		//Actions
		GameObj->gameEngine->executeScenes();

		//Render
		GameObj->gameEngine->renderScenes();

		end = std::chrono::high_resolution_clock::now();

		//Tempo
		Core::tempo(start, end);

		//
		/////////////////////////////////
		SDL_Delay(400);
	}

	//End of game, clear everything
	GameObj->gameEngine->reset();
}

/**
 Tempo for the event
 */
void Core::tempo(std::chrono::high_resolution_clock::time_point start, std::chrono::high_resolution_clock::time_point end)
{
	std::chrono::milliseconds elapsed, toWait;

	elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	if(elapsed.count() < FRAMERATE)
	{
		toWait = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::milliseconds(FRAMERATE) - elapsed);
		std::this_thread::sleep_for(toWait);
	}
}

