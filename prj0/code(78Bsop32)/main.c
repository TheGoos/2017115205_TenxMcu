#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();
  VarsInit();
	//使能看门狗
	F_turnOnWDT();
	modeValue = 1; //初始值为1
	P_ledcom=0;
	P_led1 = 1;
	//P_led2=1;
	
	while(1){
		//清看门狗
		F_clearWDT();
		//业务代码
		TimeProcess();
		TaskSetting();
		TaskProcess();
		DisplayProcess();
	}
}

//=============================================================================
	void TimeProcess(){
		static uint8_t timer5ms = 0;
	
		if (b1ms) {
			// 1ms 执行一次
			b1ms = 0;
			timer5ms++;
		}
		
		if (timer5ms >= 5) {
			P1MODL = 0x8a;
			GetKeys();
		}
	}
//=============================================================================
	void TaskSetting(){	
	//**单端口复用控制LED亮灭**
	if (modeValue == 1){//模式标志为1时，该模式为推挽输出
		//LED状态转换
		if(D_keyValue1 == keyValue){
			Mode_Neg();		//模式标志为取反
		}
		P1MODL = 0xaa;		//将模式置为推挽输出，使LED显示
		} else {//否则，该模式为上拉输入
			if(D_keyValue1 == keyValue){
				Mode_Neg();		
			}
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
