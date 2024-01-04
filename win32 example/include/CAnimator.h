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
	void Play( const std::wstring& _name, bool _repeat );

	CObject* GetObj( ) { return m_pOwner; }

private:
	std::map<std::wstring, CAnimation*> m_mapAnim;		// 모든 Animation
	CAnimation* m_pCurAnim;								// 현재 재생 중인 Animation
	CObject* m_pOwner;									// Animator 소유 오브젝트
	bool m_repeat;										// 반복재생 여부

	friend class CObject;
};
