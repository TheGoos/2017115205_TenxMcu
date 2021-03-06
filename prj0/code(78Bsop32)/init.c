#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
	F_clearWDT();
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
	P1MODL = 0xaa;		//将模式置为推挽输出
	P1MODH = 0xaa;
	P3MODL = 0xaa;
	P3MODH = 0x2a;
  // IO 状态初始化
	P1_7 = 1;
	P1_2 = 1;
	
	//T2初始化
	TH2 = (65536 - 922) / 256; //频率改为4kHz
  RCP2H = TH2;
  TL2 = (65536 - 922) % 256;
  RCP2L = TL2;
  TR2 = 1;
  ET2 = 1;
  EA = 1; 
}
//=============================================================================
void VarsInit() {}