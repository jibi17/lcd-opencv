
#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>


// 定义循环队列的大小
extern const int QUEUE_SIZE;

// 定义循环队列
extern std::queue<uint8_t*> imageQueue;

// 定义互斥锁和条件变量
extern std::mutex mtx;
extern std::condition_variable var;


void create();