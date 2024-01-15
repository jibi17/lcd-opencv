#include "thread_display.hpp"
#include "thread_create_frame.hpp"



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

#include <fstream>
#include <vector>
#include "opencv2/opencv.hpp"

void display()
{
    while(1){
        
        {std::unique_lock<std::mutex> lock(mtx);
        // 使用条件变量等待，直到队列非空或达到一定大小
        var.wait(lock, [] { return !imageQueue.empty() || imageQueue.size() >= QUEUE_SIZE; });
        
        
        // 取出队列中的数据进行处理
         uint8_t* imageData = nullptr;
      
        
            
        imageData = imageQueue.front();
        imageQueue.pop();
        
        LCD_ShowPicture2(0,0,320,172,imageData);
        delete[] imageData;
        }
        delay(0);
        
        var.notify_one();
        //std::cout<<"进入一次消费者"<<std::endl;
    }
     

}