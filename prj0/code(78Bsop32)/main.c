#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();
  VarsInit();
	
	while(1){
		/*
		F_ledOn();
		delayMs(500);
		F_ledOff();
		delayMs(500);
		*/
		GetKeys();
		if(D_keyValue1 == keyValue){
			F_ledNeg();
		}
	}
}
//=============================================================================
void delayMs(uint16_t time){
	uint16_t i,j;
	for(i=0; i<time; i++){
		for(j=0; j<1000; j++){
		}
	}
}
//=============================================================================

