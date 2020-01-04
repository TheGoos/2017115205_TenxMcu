#define __display_c
#include "includeAll.h"

//该数组依次代表数码管0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F,.,全灭,全亮,N
code const uint8_t displayFonts[20] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x80,0x00,0xff,0x37};

void SMG_Select(uint8_t position, uint8_t number)
{
    //选择数码管的位置
    //根据电路图，电平为低时该位被选中
    if (position == 1)
    {
        SMG_COM1 = 0;
        SMG_COM2 = 1;
    }
    else if (position == 2)
    {
        SMG_COM1 = 1;
        SMG_COM2 = 0;
    }

    //数位赋值
    SMG_A = 0x01 & (displayFonts[number] >> 0);
    SMG_B = 0x01 & (displayFonts[number] >> 1);
    SMG_C = 0x01 & (displayFonts[number] >> 2);
    SMG_D = 0x01 & (displayFonts[number] >> 3);
    SMG_E = 0x01 & (displayFonts[number] >> 4);
    SMG_F = 0x01 & (displayFonts[number] >> 5);
    SMG_G = 0x01 & (displayFonts[number] >> 6);
    SMG_DG = 0x01 & (displayFonts[number] >> 7);
}

void SMG_Display(uint8_t number)
{
		//数码管两位显示
		uint8_t i,j;
		
		if(number>100)
			return;
		//个位
		j = number % 10;
		SMG_Select(2, j);
		delayMs(1);
		//十位
		i = (number - j)/10;
		SMG_Select(1, i);
		delayMs(1);
}

void SMG_ON_or_OFF(uint8_t status)
{
		if(status == 1){ //显示ON
			SMG_Select(2, 19);
			delayMs(1);
			
			SMG_Select(1, 0);
			delayMs(1);
			
		}
		else if(status == 0){ //显示OF
			SMG_Select(2, 15);
			delayMs(1);
			
			SMG_Select(1, 0);
			delayMs(1);
			
		}
}

void Set_Pin_Sta(void)
{
		//引脚状态设置
		P1_2 = 1;
		P1_7 = 1;
}

//未使用到
void Set_Pin_Sta1(uint8_t number)
{
		P1_2 = 0x01 & (displayFonts[number] >> 5);
		P1_7 = 0x01 & (displayFonts[number] >> 3);
}

