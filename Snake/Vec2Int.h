#ifndef VEC2INT_H_
#define VEC2INT_H_

struct Vec2Int
{
	int x;
	int y;

	inline Vec2Int& operator+=(const Vec2Int& rhs)
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}

	inline bool operator==(const Vec2Int& rhs)
	{
		return x == rhs.x && y == rhs.y;
	}
};

#endif // VEC2INT_H_



