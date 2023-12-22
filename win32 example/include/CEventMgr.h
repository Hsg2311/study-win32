#pragma once

struct tEvent
{
	EVENT_TYPE eEvent;
	DWORD_PTR lParam;	// 솔루션 플랫폼에 따라 전처리기에서 자료형의 크기를 정해줄 수 있는 자료형 사용
	DWORD_PTR wParam;
};

class CEventMgr
{
	SINGLETON( CEventMgr );

public:
	void update( );
	void AddEvent( const tEvent& _event ) { m_vecEvent.push_back( _event ); }

private:
	std::vector<tEvent> m_vecEvent;
	std::vector<CObject*> m_vecDead;

	void Execute( const tEvent& _event );
};
