#pragma once

struct Vec2
{
public:
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

public:
	float Length( )
	{
		return sqrt( x * x + y * y );
	}
	
	Vec2& Nomalize( )
	{
		float fLen = Length( );

		assert( fLen != 0 );

		x /= fLen;
		y /= fLen;

		return *this;
	}

public:
	Vec2& operator =( const POINT& _pt )
	{
		x = (float)_pt.x;
		y = (float)_pt.y;
	}

	Vec2 operator +( const Vec2& _vOther )
	{
		return Vec2{ x + _vOther.x, y + _vOther.y };
	}

	void operator +=( const Vec2& _other )
	{
		x += _other.x;
		y += _other.y;
	}

	Vec2 operator -( const Vec2& _vOther )
	{
		return Vec2{ x - _vOther.x, y - _vOther.y };
	}

	Vec2 operator *( const Vec2& _vOther )
	{
		return Vec2{ x * _vOther.x, y * _vOther.y };
	}

	Vec2 operator *( int i )
	{
		return Vec2{ x * (float)i, y * (float)i };
	}

	Vec2 operator /( const Vec2& _vOther )
	{
		assert( !( _vOther.x == 0.f || _vOther.y == 0.f ) );

		return Vec2{ x / _vOther.x, y / _vOther.y };
	}

public:
	float x;
	float y;
};