#ifndef POSITION_H

#define POSITION_H
#include "constants.hpp"

template <typename T>
struct Point
{
	Point<T>(T x, T y);
	Point<T>(const Point<T>& point);

	T X;
	T Y;

	Point<T> operator +(const Point<T>& lhs);
	Point<T> operator -(const Point<T>& lhs);

	Point<T>& operator +=(const Point<T>& rhs);
	Point<T>& operator -=(const Point<T>& rhs);

	Point<T> operator *(const Point<T>& lhs);
	Point<T> operator /(const Point<T>& lhs);

	void operator *=(const Point<T>& lhs);
	void operator /=(const Point<T>& lhs);

	friend bool operator ==(const Point<T>& lhs, const Point<T>& rhs);
	friend bool operator !=(const Point<T>& lhs, const Point<T>& rhs);
};

struct Position
{
public:
	Position();
	Position(Point<size_t> map, Point<size_t> zone);
	Position(size_t mapX, size_t mapY, size_t zoneX, size_t zoneY);

	Point<size_t> Map() const;
	void Map(Point<size_t> position, bool offset = false);

	Point<size_t> Zone() const;
	void Zone(Point<size_t> position, bool offset = false);

	Point<size_t> World() const;
	void World(Point<size_t> mapPosition, Point<size_t> zonePosition, bool offset = false);

private:
	Point<size_t> _map;
	Point<size_t> _zone;

};

#endif
