#pragma once

struct Vec2
{
	Vec2( )
		: x{ 0.f }
		, y{ 0.f }
	{}

	Vec2( float _x, float _y )
		: x{ _x }
		, y{ _y }
	{}

	Vec2( LONG _x, LONG _y )
		: x{ (float)_x }
		, y{ (float)_y }
	{}

	Vec2( const POINT& _pt )
		: x{ (float )_pt.x }
		, y{ (float )_pt.y }
	{}

	float x;
	float y;
};