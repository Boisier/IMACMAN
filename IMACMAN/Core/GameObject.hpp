//
//  GameObject.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 21/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

//Forward declaration
class RessourcesEngine;
class RenderEngine;
class GameEngine;

class GameObject
{
public:

	//Singleton constructor
	static void instanciate();

	GameEngine * gameEngine;
	RessourcesEngine * ressourceEngine;
	RenderEngine * renderEngine;

	//The window, managed by SDL
	SDL_Window * mainWindow;

	//Getters
	bool isRunning();

private:
	//Singleton
	GameObject() {};
	bool static m_instanciated;


	//Game states
	bool m_running = true;

};

extern GameObject * GameObj;

#endif /* GameObject_hpp */
