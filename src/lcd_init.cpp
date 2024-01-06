#include "../inc/lcd_init.h"
#include "iostream"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lcd_init()
{
    bsp_init();
    LCD_RES_Clr();//复位
    delay(30);
    LCD_RES_Set();
    delay(100);
    LCD_BLK_Set();//打开背光
    delay(100);

      delay(100);
//	
	LCD_WR_REG(0x11); 
//	delay_ms(120); 
	LCD_WR_REG(0x36); 
	if(USE_HORIZONTAL==0)LCD_WR_DATA8(0x00);
	else if(USE_HORIZONTAL==1)LCD_WR_DATA8(0xC0);
	else if(USE_HORIZONTAL==2)LCD_WR_DATA8(0x70);
	else LCD_WR_DATA8(0xA0);

	LCD_WR_REG(0x3A);
	LCD_WR_DATA8(0x05);

	LCD_WR_REG(0xB2);
	LCD_WR_DATA8(0x0C);
	LCD_WR_DATA8(0x0C);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x33);
	LCD_WR_DATA8(0x33); 

	LCD_WR_REG(0xB7); 
	LCD_WR_DATA8(0x35);  

	LCD_WR_REG(0xBB);
	LCD_WR_DATA8(0x35);

	LCD_WR_REG(0xC0);
	LCD_WR_DATA8(0x2C);

	LCD_WR_REG(0xC2);
	LCD_WR_DATA8(0x01);

	LCD_WR_REG(0xC3);
	LCD_WR_DATA8(0x13);   

	LCD_WR_REG(0xC4);
	LCD_WR_DATA8(0x20);  

	LCD_WR_REG(0xC6); 
	LCD_WR_DATA8(0x0F);    

	LCD_WR_REG(0xD0); 
	LCD_WR_DATA8(0xA4);
	LCD_WR_DATA8(0xA1);

	LCD_WR_REG(0xD6); 
	LCD_WR_DATA8(0xA1);

	LCD_WR_REG(0xE0);
	LCD_WR_DATA8(0xF0);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x04);
	LCD_WR_DATA8(0x04);
	LCD_WR_DATA8(0x04);
	LCD_WR_DATA8(0x05);
	LCD_WR_DATA8(0x29);
	LCD_WR_DATA8(0x33);
	LCD_WR_DATA8(0x3E);
	LCD_WR_DATA8(0x38);
	LCD_WR_DATA8(0x12);
	LCD_WR_DATA8(0x12);
	LCD_WR_DATA8(0x28);
	LCD_WR_DATA8(0x30);

	LCD_WR_REG(0xE1);
	LCD_WR_DATA8(0xF0);
	LCD_WR_DATA8(0x07);
	LCD_WR_DATA8(0x0A);
	LCD_WR_DATA8(0x0D);
	LCD_WR_DATA8(0x0B);
	LCD_WR_DATA8(0x07);
	LCD_WR_DATA8(0x28);
	LCD_WR_DATA8(0x33);
	LCD_WR_DATA8(0x3E);
	LCD_WR_DATA8(0x36);
	LCD_WR_DATA8(0x14);
	LCD_WR_DATA8(0x14);
	LCD_WR_DATA8(0x29);
	LCD_WR_DATA8(0x32);
	
// 	LCD_WR_REG(0x2A);
//	LCD_WR_DATA8(0x00);
//	LCD_WR_DATA8(0x22);
//	LCD_WR_DATA8(0x00);
//	LCD_WR_DATA8(0xCD);
//	LCD_WR_DATA8(0x2B);
//	LCD_WR_DATA8(0x00);
//	LCD_WR_DATA8(0x00);
//	LCD_WR_DATA8(0x01);
//	LCD_WR_DATA8(0x3F);
//	LCD_WR_REG(0x2C);
	LCD_WR_REG(0x21); 
  
  LCD_WR_REG(0x11);
  delay(120);	
	LCD_WR_REG(0x29); 



}
void bsp_init()
{
    pinMode(RESET_PIN,OUTPUT);
    pinMode(DC_PIN,OUTPUT);
    pinMode(CS_PIN,OUTPUT);
    pinMode(BLK_PIN,OUTPUT);

    if (wiringPiSPISetupMode(SPI_CHAN,1,24000000,3)< 0) 
    {
    	printf("SPISetup failed:\n");
    }
    else
    {
        printf("spisetup successfully\n");
    }
  std::cout<<"lcd init over!"<<std::endl;
}

/**
 * @brief LCD写入命令
 * 
 * @param dat 写入的命令
 */
void LCD_WR_REG(u8 dat)
{
	LCD_DC_Clr();//写命令
	LCD_Writ_Bus(dat);
	LCD_DC_Set();//写数据
}


/**
 * @brief LCD串行数据写入函数
 * 
 * @param dat 要写入的串行数据
 */
void LCD_Writ_Bus(u8 dat) 
{	
	LCD_CS_Clr();
	wiringPiSPIDataRW(SPI_CHAN,&dat,sizeof(dat));
	//delay(1);
	LCD_CS_Set();
}


/**
 * @brief LCD写入数据
 * 
 * @param dat 写入的数据
 */
void LCD_WR_DATA8(u8 dat)
{
	LCD_Writ_Bus(dat);
}


/**
 * @brief LCD写入数据16
 * 
 * @param dat 
 */
void LCD_WR_DATA(u16 dat)
{
	LCD_Writ_Bus(dat>>8);
	LCD_Writ_Bus(dat);
}
/**
 * @brief 设置起始和结束地址
 * 
 * @param x1 x1,x2 设置列的起始和结束地址
 * @param y1 y1,y2 设置行的起始和结束地址
 * @param x2 
 * @param y2 
 */
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2)
{
	if(USE_HORIZONTAL==0)
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1+34);
		LCD_WR_DATA(x2+34);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1);
		LCD_WR_DATA(y2);
		LCD_WR_REG(0x2c);//储存器写
	}
	else if(USE_HORIZONTAL==1)
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1+34);
		LCD_WR_DATA(x2+34);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1);
		LCD_WR_DATA(y2);
		LCD_WR_REG(0x2c);//储存器写
	}
	else if(USE_HORIZONTAL==2)
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1);
		LCD_WR_DATA(x2);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1+34);
		LCD_WR_DATA(y2+34);
		LCD_WR_REG(0x2c);//储存器写
	}
	else
	{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1);
		LCD_WR_DATA(x2);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1+34);
		LCD_WR_DATA(y2+34);
		LCD_WR_REG(0x2c);//储存器写
	}
}
/**
 * @brief use spi to send a frame
 * 
 * @param data 
 */

void spi_send_frame(u8 *data,int sizeOfData)
{
	LCD_CS_Clr();
	uint8_t temp[4096];	
	//std::cout << "at spi_send_frame:"<<sizeOfData<< std::endl;

	
	for(int i=0;i<sizeOfData;i=i+sizeof(temp))
	{
		//std::cout << "number of tmep:"<<i<< std::endl;
		if(i<=sizeOfData && (i+sizeof(temp))>=sizeOfData)
		{
			
			int size_least=sizeOfData-i;
			memmove(temp,data+i,(uint32_t)size_least);
			if(wiringPiSPIDataRW(SPI_CHAN,temp,size_least)==-1)
			{
				printf ("SPI failure:2 \n") ;
			}
#if DEBUG			
			std::cout << "send last buf:" << size_least<<std::endl;
#endif			
			break;

		}
		
		memmove(temp,data+i,sizeof(temp));
		if(wiringPiSPIDataRW(SPI_CHAN,temp,sizeof(temp))==-1)
		{
		 	printf ("SPI failure:1 \n") ;
		}
		else
		{
			//printf("%x\n",*(data+i) );
		}
	
		
	}
	// if(wiringPiSPIDataRW(SPI_CHAN,data,sizeof(data))==-1)
	// {
	// 	 printf ("SPI failure: \n") ;
	// }
	
	LCD_CS_Set();
}