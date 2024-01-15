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
// 在这里进行实际的定义
const int QUEUE_SIZE = 10;
std::queue<uint8_t*> imageQueue;
std::mutex mtx;
std::condition_variable var;
void create()
{
    // Use the pointer array (image2) as needed
    //打开视频
    cv::VideoCapture cap("./avi.mp4");
    // 检查视频是否成功打开
    if (!cap.isOpened()) {
        std::cerr << "Error opening video file." << std::endl;
        return ;
    }

    cv::Mat frame;
    
    while(1){
        //先生成以一个image
        
        cap >> frame;  // 从视频捕获设备读取一帧

        // 检查是否成功读取一帧
        if (frame.empty()) {
            std::cerr << "End of video" << std::endl;
            break;
        }



        cv::Mat grayImage;
        cv::cvtColor(frame, grayImage, cv::COLOR_BGR2GRAY);

        // 使用阈值将非黑色区域设为白色，以便找到边界
        cv::Mat thresholded;
        cv::threshold(grayImage, thresholded, 1, 255, cv::THRESH_BINARY);

        // 寻找边界框
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(thresholded, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        // 找到包围整个图像的矩形边界框
        cv::Rect boundingBox = cv::boundingRect(contours[0]);

        // 裁剪图像，去掉边框
        cv::Mat croppedImage = frame(boundingBox);





        // 缩放图像为320x172
        cv::Mat resizedImage;
        cv::resize(croppedImage, resizedImage, cv::Size(320, 172),cv::INTER_CUBIC);
        //cv::imshow("Resized RGB565 Image", resizedImage);
        
        //转换为RGB565格式
        cv::Mat rgb565Image;
        cv::cvtColor(resizedImage, rgb565Image, cv::COLOR_BGR2BGR565);
        // 获取图像的宽度和高度
        int width = rgb565Image.cols;
        int height = rgb565Image.rows;
    // cout<<"wideth:"<<width<<endl;
    // cout<<"height:"<<height<<endl;
        //int width = imageWidth;
        //int height = imageHeight;
        // 遍历图像像素并写入数组
        uint8_t* imageData = new uint8_t[110080];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                // 获取RGB565值
                uint16_t rgb565Value = rgb565Image.at<uint16_t>(y, x);

                // 分开高位和低位，并写入数组
                uint8_t highByte = (rgb565Value >> 8) & 0xFF;
                uint8_t lowByte = rgb565Value & 0xFF;
                imageData[(y * width + x) * 2]=highByte;
                imageData[(y * width + x) * 2 + 1]=lowByte;
                // outputArray << "0X" << std::hex << std::uppercase << static_cast<int>(highByte) << ",";
                // outputArray << "0X" << std::hex << std::uppercase << static_cast<int>(lowByte) << ",";
            }
        }

        //现在获得到了image——temp要把他放到队列里面去
        // 生产者获取锁
        std::unique_lock<std::mutex> lock(mtx);
        // 检查队列是否满
        var.wait(lock, [] { return imageQueue.size() < QUEUE_SIZE; });
         // 将图片放入队列
        imageQueue.push(imageData);
        var.notify_one();
       // std::cout<<"进入一次生产者"<<std::endl;


    }


}