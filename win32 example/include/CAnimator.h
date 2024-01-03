#pragma once

class CAnimation;
class CObject;
class CTexture;

class CAnimator
{
public:
	CAnimator( );
	~CAnimator( );

	void update( );
	void render( HDC _dc );

	void CreateAnimation( const std::wstring& _name, CTexture* _pTex, Vec2 _LT, 
						Vec2 _sliceSize, Vec2 _step, float _duration, UINT _frameCount );
	CAnimation* FindAnimation( const std::wstring& _name );
	void Play( );

private:
	std::map<std::wstring, CAnimation*> m_mapAnim;		// ��� Animation
	CAnimation* m_pCurAnim;								// ���� ��� ���� Animation
	CObject* m_pOwner;									// Animator ���� ������Ʈ

	friend class CObject;
};
