#pragma once
struct Color
{
	int r;
	int g;
	int b;
	int a;

	inline static Color green()
	{
		return Color{0, 255, 0, 255};
	}

	inline static Color red()
	{
		return Color{ 255, 0, 0, 255 };
	}

	inline static Color blue()
	{
		return Color{ 0, 0, 255, 255 };
	}

	inline static Color white()
	{
		return Color{ 255, 255, 255, 255 };
	}

};

