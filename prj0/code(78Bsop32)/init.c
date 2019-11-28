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
	
  // IO 状态初始化
	
}
//=============================================================================
void VarsInit() {}