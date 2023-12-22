#pragma once

struct tEvent
{
	EVENT_TYPE eEvent;
	DWORD lParam;
	DWORD wParam;
};

class CEventMgr
{
	SINGLETON( CEventMgr );

public:
	void update( );

private:
	std::vector<tEvent> m_vecEvent;
};
