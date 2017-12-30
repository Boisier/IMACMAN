//
//  GameObject.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 21/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "GameObject.hpp"

GameObject * GameObj = nullptr;
bool GameObject::m_instanciated = false;

void GameObject::instanciate()
{
	if(m_instanciated)
		return;

	GameObj = new GameObject();

	m_instanciated = true;
}

void GameObject::removeScene(Scene * scene)
{
	for(std::vector<Scene *>::iterator it = m_scenes.begin(); it != m_scenes.end(); ++it)
	{
		if((*it) == scene)
		{
			m_scenes.erase(it);
			return;
		}
	}
}

