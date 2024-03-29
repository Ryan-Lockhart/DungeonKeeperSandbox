#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <raylib-cpp.hpp>
#include "glyph.hpp"

class Cell;
class Map;
class GlyphType;

class Actor
{
public:
	Actor(std::string name, Glyph glyph, Cell* startingCell, bool isPlayer = false);

	virtual void Act(int x, int y, Map& map);
	virtual void Draw(const GlyphType& glyphType, const raylib::Vector2 screenPosition) const;

	Cell* GetOccupiedCell()
	{ return m_CurrentCell; }
	raylib::Vector2 GetPosition()
	{ return m_Position; }

protected:
	virtual void Move(Cell* to);
	virtual void Attack(Actor* what);
	virtual void Defend(float accuracy, size_t damage);
	virtual void Mine(Cell* what);

	std::string m_Name;

	float m_MaxHealth;
	float m_CurrentHealth;

	float m_Damage;

	float m_Accuracy;
	float m_Dodge;

	raylib::Vector2 m_Position;
	Cell* m_CurrentCell;

	Glyph m_Glyph;
};

#endif
