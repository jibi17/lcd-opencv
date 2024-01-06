#include <iostream>
#include "../wiringOP/wiringPi/wiringPi.h"
#include "pthread.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "../wiringOP/wiringPi/wiringPiSPI.h"
#include "../inc/lcd_init.h"
#include "lcd.h"
#include "pic.h"
#include <unistd.h>

#define SPI_CHAN 4
//#define IN_PIN 8
uint8_t temp[4096];

//这个是第二个版本

int main(int argc, char **args)
{

	std::cout << "Hello, world!1\n";
	wiringPiSetup();
	std::cout << "Hello, world!2\n";
	//pinMode(2, OUTPUT);
	std::cout << "Hello, world!3\n";
	//pinMode(IN_PIN, INPUT);
	std::cout << "Hello, world!4\n";
	// pullUpDnControl(IN_PIN,PUD_UP);
	std::cout << "Hello, world!5\n";



    



	lcd_init();

	std::cout << "Hello, world!\n";

	LCD_Fill2(0,0,LCD_W,LCD_H,WHITE);
	delay(100);
	LCD_ShowPicture2(0,0,160,76,gImage_boran_lcd);
	int i=40;
	while (1)
	{
		sleep(1);
		// for(int i=200;i>20;i=i-10)
		// {
		// 	printf("i=%d\r\n",i);
		// 	for(int j=0;j<3;j++)
		// 	{
			while(1)
			{

			LCD_Fill2(0,0,LCD_W,LCD_H,WHITE);
			delay(i);
			LCD_Fill2(0,0,LCD_W,LCD_H,RED);
			delay(i);
			LCD_Fill2(0,0,LCD_W,LCD_H,GREEN);
			delay(i);
			LCD_Fill2(0,0,LCD_W,LCD_H,BLUE);
			delay(i);
			LCD_Fill2(0,0,LCD_W,LCD_H,YELLOW);
			delay(i);
			LCD_Fill2(0,0,LCD_W,LCD_H,GRAY);
			delay(i);
			LCD_Fill2(0,0,LCD_W,LCD_H,BROWN);
			delay(i);
			LCD_Fill2(0,0,LCD_W,LCD_H,BRED);
			delay(i);


			}
		
			//}

			
		//}
		
		// LCD_Fill2(0,0,LCD_W,LCD_H,WHITE);
		// delay(500);
		// LCD_Fill2(0,0,LCD_W,LCD_H,RED);
		// delay(500);
		// LCD_Fill2(0,0,LCD_W,LCD_H,GREEN);
		// delay(500);
		// LCD_Fill2(0,0,LCD_W,LCD_H,BLUE);
		// delay(500);
		// 		LCD_Fill2(0,0,LCD_W,LCD_H,YELLOW);
		// delay(500);
		// 		LCD_Fill2(0,0,LCD_W,LCD_H,GRAY);
		// delay(500);
		// 		LCD_Fill2(0,0,LCD_W,LCD_H,BROWN);
		// delay(500);
		// 		LCD_Fill2(0,0,LCD_W,LCD_H,BRED);
		// delay(500);
	
	}

	 
	std::cout << "start fill2" << std::endl;
	LCD_Fill2(0,0,LCD_W,LCD_H,WHITE);
	delay(500);
	LCD_Fill2(0,0,LCD_W,LCD_H,RED);
	delay(500);
	LCD_Fill2(0,0,LCD_W,LCD_H,GREEN);
	delay(500);
	LCD_Fill2(0,0,LCD_W,LCD_H,BLUE);
	delay(500);
	LCD_Fill2(0,0,LCD_W,LCD_H,WHITE);
	delay(500);
	std::cout << "fill2 end" << std::endl;
	LCD_Fill2(0,0,LCD_W,LCD_H,WHITE);
	// uint8_t temp[4096];
	// wiringPiSPIDataRW(SPI_CHAN,temp,sizeof(temp));
	// printf("temp:%s",temp);
}
// aarch64-linux-gnu-g++-10