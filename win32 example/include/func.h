#pragma once

class CObject;

void CreateObject( CObject* _other, GROUP_TYPE _eGroup );
void DeleteObject( CObject* _other );
void ChangeScene( SCENE_TYPE _eNext );

template<class T>
void Safe_Delete_Vec( std::vector<T>& _vec )
{
	for ( size_t i = 0; i < _vec.size( ); ++i )
	{
		if ( _vec[ i ] != nullptr )
		{
			delete _vec[ i ];
		}
	}

	_vec.clear( );
}