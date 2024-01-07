#!/bin/bash

# 复制文件到目标机器
scp ./src/demo2 orangepi@192.168.10.135:/home/orangepi/code/lcd_1.47/

# 远程执行命令（更改文件权限）
ssh orangepi@192.168.10.135 'chmod +x /home/orangepi/code/lcd_1.47/demo2'
