#define __keys_c
#include "includeAll.h"
//=============================================================================
//按键信息获取
void GetKeys() {
	static uint8_t tempKeyValue = D_keyNull;
	
	if(P_key4==0 || P_key3==0){
		tempKeyValue = D_keyValue1;
		
		//检测按下哪个按键
		if(P_key4==0)
			keySelect = 4;
		else if(P_key3==0)
			keySelect = 3;
		
	}	
	else{
		keyValue = tempKeyValue;
		tempKeyValue = D_keyNull;
	}
}