//
//  Player.hpp
//  IMACMAN
//
//  Created by Laurie Greinert on 22/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include "Utils/Enums.hpp"

class Player{
public:
	
	Player(enum PLAYER_TYPE type, std::string name) : m_type(type), m_name(name), m_life(3), m_score(0){};
	~Player();
	
	//SETTERS
	void setType(enum PLAYER_TYPE type);
	void setName(std::string name);
	void setLife(uint life);
	void setScore(double score);
	
	//GETTERS
	enum PLAYER_TYPE getPlayerType() const;
	std::string getName() const;
	uint getLife() const;
	double getScore() const;
	
private:
	PLAYER_TYPE m_type;
	std::string m_name;
	uint m_life;
	double m_score;
};

#endif /* Player_hpp */
