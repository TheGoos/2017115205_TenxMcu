#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();
  VarsInit();
	//使能看门狗
	F_turnOnWDT();
	modeValue = 1; //初始值为1
	buzzCounter = 0; //初始值为0
	P_ledcom = 0;
	P_led1 = 1;
	//P_led2 = 1;
	//BuzzCount(3); //参数3代表设置蜂鸣器响3下
	keySelect = 0;  //初始值为0
	
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
		static uint8_t timer5ms = 0;  //按键计时
		static uint8_t timer250ms = 0;  //蜂鸣器计时
	
		if (b1ms) {
			// 1ms 执行一次
			b1ms = 0;
			timer250ms++;
			timer5ms++;
			
			if (buzzLastTimer > 0) {
				buzzLastTimer--;
			}
		}
		
		if (timer250ms >= 250){
			timer250ms = 0;
			if (buzzCounter > 0) { //为0时蜂鸣器不响
				Buzz();
				buzzCounter--;
			}
		}
		
		if (timer5ms >= 5) {
			timer5ms = 0;
			P1MODL = 0x8a;  //将模式置为上拉输入
			GetKeys();
			}
	}
//=============================================================================
	void TaskSetting(){
		switch(keySelect) {
			case 4:
				//**单端口复用控制LED亮灭**
				if(modeValue == 1){//模式标志为1时，该模式为推挽输出
					//LED状态转换
					if(D_keyValue1 == keyValue){
						Mode_Neg();		//模式标志为取反
					}
					P1MODL = 0xaa;		//将模式置为推挽输出，使LED显示
				}
				else {//否则，该模式为上拉输入
					if(D_keyValue1 == keyValue){
						Mode_Neg();		
					}
				}
			  break;
			case 3:
				if(modeValue == 1){
					if(D_keyValue1 == keyValue){ //按键控制蜂鸣器
						BuzzCount(1);
					}
					P1MODL = 0xaa;
				}
				else {
					if(D_keyValue1 == keyValue){ //按键控制蜂鸣器
						BuzzCount(1);
					}
					P1MODL = 0x8a;
				}
		  	break;
			case 0:
				if(modeValue == 1){
					P1MODL = 0xaa;
				}
				else {
					P1MODL = 0x8a;
				}
				break;
		}//switch
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
