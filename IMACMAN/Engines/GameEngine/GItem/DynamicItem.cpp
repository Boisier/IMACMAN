//
//  DynamicItem.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 11/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#include "DynamicItem.hpp"

glm::vec2 DynamicItem::getNextPosition(glm::vec3 &translation) const
{
	glm::vec2 nextPos = this->getPosition();

	switch (m_currentDirection) {
		case DIRECTION::UP:
			nextPos.x += -1.f;
			nextPos.y += 0.f;
			translation = glm::vec3(-1.f, 0.f, 0.f);
			break;
		case DIRECTION::DOWN:
			nextPos.x += 1.f;
			nextPos.y += 0.f;
			translation = glm::vec3(1.f, 0.f, 0.f);
			break;
		case DIRECTION::LEFT:
			nextPos.x += 0.f;
			nextPos.y += -1.f;
			translation = glm::vec3(0.f, -1.f, 0.f);
			break;
		case DIRECTION::RIGHT:
			nextPos.x += 0.f;
			nextPos.y += 1.f;
			translation = glm::vec3(0.f, 1.f, 0.f);
			break;
		default:
			translation = glm::vec3(0.f, 0.f, 0.f);
			break;
	}
	return nextPos;
}

glm::vec2 DynamicItem::getNextPosition(const enum DIRECTION & nextDirection) const
{
	glm::vec2 nextPos = this->getPosition();

	switch (nextDirection) {
		case DIRECTION::UP:
			nextPos.x += -1.f;
			nextPos.y += 0.f;
			break;
		case DIRECTION::DOWN:
			nextPos.x += 1.f;
			nextPos.y += 0.f;
			break;
		case DIRECTION::LEFT:
			nextPos.x += 0.f;
			nextPos.y += -1.f;
			break;
		case DIRECTION::RIGHT:
			nextPos.x += 0.f;
			nextPos.y += 1.f;
			break;
		default:
			break;
	}
	return nextPos;
}
