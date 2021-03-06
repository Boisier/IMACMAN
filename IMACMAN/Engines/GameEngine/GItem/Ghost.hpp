#ifndef GHOST_HPP
#define GHOST_HPP

#include "DynamicItem.hpp"

class Ghost: public DynamicItem {
private:
	bool m_isAlive;
	bool m_isAfraid;
	int m_afraidCounter;
	int m_waitCounter;

public:

	Ghost(Mesh * mesh, glm::vec2 position, std::string name, ITEM_SYNTAX type, uint score = 100, bool isAlive = true, bool isAfraid = false) :
		DynamicItem(mesh, position, name, score, type, DIRECTION::UP),
		m_isAlive(isAlive),
		m_isAfraid(isAfraid),
		m_afraidCounter(0)
	{}
	~Ghost() = default;

	//GETTERS
	inline bool isAlive() const { return m_isAlive; }
	inline bool isAfraid() const { return m_isAfraid; }
	inline int getDeathCounter() const { return m_waitCounter; }
	
	//SETTERS
	void setIsAlive(bool isAlive);
	void setIsAfraid(bool isAfraid);

	//METHODS
	inline void updateAfraidCounter() {
		m_afraidCounter > 0 ? --m_afraidCounter : m_isAfraid = false;
	}

	void updateDeathCounter(const int time);
};

#endif /* GHOST_HPP */
