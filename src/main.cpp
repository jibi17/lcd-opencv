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
#include "socket.hpp"

#define SPI_CHAN 4
//#define IN_PIN 8
uint8_t temp[4096];

//这个是第二个版本
//这个是第三个版本
int main(int argc, char **args)
{

	std::cout << "Hello, world!1\n";
	wiringPiSetup();


	lcd_init();
	LCD_Fill2(0,0,LCD_W,LCD_H,WHITE);
	delay(100);
	LCD_ShowPicture2(0,0,160,76,gImage_boran_lcd);
	

	int i=40;
	// 创建一个线程用于处理客户端连接和接收数据
    std::thread serverThread(serverThreadFunction);

    // 主线程可以执行其他操作

    // 等待服务器线程结束（实际上这里永远不会结束，因为 serverThreadFunction 包含一个无限循环）
    serverThread.join();

	// std::cout << "start fill2" << std::endl;
	// LCD_Fill2(0,0,LCD_W,LCD_H,WHITE);
	// delay(500);
	// LCD_Fill2(0,0,LCD_W,LCD_H,RED);
	// delay(500);
	// LCD_Fill2(0,0,LCD_W,LCD_H,GREEN);
	// delay(500);
	// LCD_Fill2(0,0,LCD_W,LCD_H,BLUE);
	// delay(500);
	// LCD_Fill2(0,0,LCD_W,LCD_H,WHITE);
	// delay(500);
	// std::cout << "fill2 end" << std::endl;
	// LCD_Fill2(0,0,LCD_W,LCD_H,WHITE);
	
	// wiringPiSPIDataRW(SPI_CHAN,temp,sizeof(temp));
	// printf("temp:%s",temp);
	return 0;
}
// aarch64-linux-gnu-g++-10