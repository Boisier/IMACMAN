//
//  GameObject.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 21/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "GameObject.hpp"
#include "Scenes/Scene.hpp"

#include <iostream>

GameObject * GameObj = nullptr;
bool GameObject::m_instanciated = false;

void GameObject::instanciate(std::string appPath)
{
	if(m_instanciated) {
		return;
	}

	GameObj = new GameObject(appPath + "/");

	m_instanciated = true;
}

void GameObject::removeScene(Scene * scene)
{
	std::cout << "removing scene " << scene->getUUID() << std::endl;

	for(std::vector<Scene *>::iterator it = m_scenes.begin(); it != m_scenes.end(); ++it)
	{
		if((*it) == scene)
		{

			std::cout << "removing scene " << (*it)->getUUID() << std::endl;
			delete (*it);
			m_scenes.erase(it);
			return;
		}
	}
}

