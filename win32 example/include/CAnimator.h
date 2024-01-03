#pragma once

class CAnimation;
class CObject;

class CAnimator
{
public:
	CAnimator( );
	~CAnimator( );

	void CreateAnimation( );
	void FindAnimation( );
	void Play( );

private:
	std::map<std::wstring, CAnimation*> m_mapAnim;
	CObject* m_pOwner;

	friend class CObject;
};
