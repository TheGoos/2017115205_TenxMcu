#define __main_c
#include "includeAll.h"
//=============================================================================
void main() {
  SysInit();
  VarsInit();
	
	modeValue = 1; //初始值为1
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
	//**单端口复用控制LED亮灭**
	if (modeValue == 1){//模式标志为1时，该模式为推挽输出
		//获取按键信息
		P1MODL = 0xa8;		//将模式置为上拉输入,感知按键是否按下，只要处理时间够短，不影响LED显示
		GetKeys();
		delayMs(100);		//此处延时为确保能成功获取按键
		//LED状态转换
		if(D_keyValue1 == keyValue){
			Mode_Neg();		//模式标志为取反
		}
		P1MODL = 0xaa;		//将模式置为推挽输出，使LED显示
		//delayMs(1000);
		} else {//否则，该模式为上拉输入
			P1MODL = 0xa8;	
			GetKeys();
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