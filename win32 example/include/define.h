#pragma once

#define SINGLETON( type ) public:\
							static type* GetInst( )\
							{\
								static type mgr;\
								return &mgr;\
							}\
						 private:\
							type( );\
							~type( );