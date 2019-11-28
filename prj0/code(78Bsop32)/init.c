#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
  //时钟初始化
  CLKCON = 0x03; // Clock div 1  7.3728Mhz
  STPPCK = 0;
  STPFCK = 0;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  SELFCK = 1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  // IO 模式初始化
	//P1MODL = 0xaa;		//将模式置为推挽输出
	P1MODL = 0xa8;		//将模式置为上拉输入
	P1_0 = 1;
  // IO 状态初始化
	F_ledOff();		//初始化为低电位（不亮）
}
//=============================================================================
void VarsInit() {}