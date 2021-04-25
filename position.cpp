#include "position.hpp"

template<typename T>
Point<T>::Point<T>(T x, T y) :
	X(x), Y(y)
{

}

template<typename T>
Point<T>::Point<T>(const Point<T>& point) :
	X(point.X), Y(point.Y)
{

}

template<typename T>
Point<T> Point<T>::operator +(const Point<T>& lhs)
{
	return Point<T>(X + lhs.X, Y + lhs.Y);
}

template<typename T>
Point<T> Point<T>::operator -(const Point<T>& lhs)
{
	return Point<T>(X - lhs.X, Y - lhs.Y);
}

template<typename T>
Point<T>& Point<T>::operator +=(const Point<T>& rhs)
{
	this->X += rhs.X; this->Y += rhs.Y;
	return *this;
}

template<typename T>
Point<T>& Point<T>::operator -=(const Point<T>& rhs)
{
	this->X -= rhs.X; this->Y -= rhs.Y;
	return *this;
}

template<typename T>
Point<T> Point<T>::operator *(const Point<T>& lhs)
{
	return Point<T>(X * lhs.X, Y * lhs.Y);
}

template<typename T>
Point<T> Point<T>::operator /(const Point<T>& lhs)
{
	return Point<T>(X / lhs.X, Y / lhs.Y);
}

template<typename T>
void Point<T>::operator *=(const Point<T>& lhs)
{
	X *= lhs.X; Y *= lhs.Y;
}

template<typename T>
void Point<T>::operator /=(const Point<T>& lhs)
{
	X /= lhs.X; Y /= lhs.Y;
}

template<typename T>
bool operator ==(const Point<T>& lhs, const Point<T>& rhs)
{
	return (lhs.X == rhs.X && lhs.Y == rhs.Y);
}

template<typename T>
bool operator !=(const Point<T>& lhs, const Point<T>& rhs)
{
	return (lhs.X != rhs.X || lhs.Y != rhs.Y);
}

Point<size_t> Point<size_t>::operator+(const Point<size_t>& rhs)
{
	return Point<size_t>(X + rhs.X, Y + rhs.Y);
}

Point<float>& Point<float>::operator+=(const Point<float>& rhs)
{
	this->X += rhs.X; this->Y += rhs.Y;
	return *this;
}

Point<float>::Point<float>(const Point<float>& p) :
	X(p.X), Y(p.Y)
{

}

Point<float>::Point<float>(float x, float y) :
	X(x), Y(y)
{

}

Point<int>::Point<int>(int x, int y) :
	X(x), Y(y)
{

}

Position::Position() :
	_map(Point<size_t>(0, 0)), _zone(Point<size_t>(0, 0))
{

}

Position::Position(Point<size_t> map, Point<size_t> zone) :
	_map(map), _zone(zone)
{

}

Position::Position(size_t mapX, size_t mapY, size_t zoneX, size_t zoneY) :
	_map(Point<size_t>(mapX, mapY)), _zone(Point<size_t>(zoneX, zoneY))
{

}

Point<size_t> Position::Map() const
{
	return _map;
}

void Position::Map(Point<size_t> position, bool offset)
{
	if (offset)
		_map = position;
	else
		_map += position;
}

Point<size_t> Position::Zone() const
{
	return _zone;
}

void Position::Zone(Point<size_t> position, bool offset)
{
	if (offset)
		if (_zone.X + position.X )
		_zone = position;
	else
		_zone += position;
}

Point<size_t> Position::World() const
{
	return Point<size_t>(_map.X * zoneWidth + _zone.X, _map.Y * zoneHeight + _zone.Y);
}

void Position::World(Point<size_t> mapPosition, Point<size_t> zonePosition, bool offset)
{
	if (offset)
	{
		_map += mapPosition;
		_zone += zonePosition;
	}
	else
	{
		_map = mapPosition;
		_zone = zonePosition;
	}
}
