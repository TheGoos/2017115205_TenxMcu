#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();
  VarsInit();
	
	while(1){
		//业务代码
		TimeProcess();
		TaskSetting();
		TaskProcess();
		DisplayProcess();
	}
}

//=============================================================================
	void TimeProcess(){
	
	}
//=============================================================================
	void TaskSetting(){
		/* LED闪烁
		F_ledOn();
		delayMs(500);
		F_ledOff();
		delayMs(500);
		*/
		//获取按键信息
		GetKeys();
		//LED状态转换
		if(D_keyValue1 == keyValue){
			F_ledNeg();
		}
	}
//=============================================================================
	void TaskProcess(){
	
	}
//=============================================================================
	void DisplayProcess(){
	
	}
//=============================================================================
//延时函数
void delayMs(uint16_t time){
	uint16_t i,j;
	for(i=0; i<time; i++){
		for(j=0; j<1000; j++){
		}
	}
}