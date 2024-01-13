cmake_minimum_required(VERSION 3.0.0)
#SET(CMAKE_C_COMPILER aarch64-linux-gnu-gcc-10)

#SET(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++-10)

project(demo2)
#add_subdirectory(print)

add_subdirectory(src)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)
# add_executable(demo2 main.cpp ${SRC_LIST})


#link_directories("/usr/local/lib")
#link_libraries("/usr/local/lib")


# target_link_libraries(demo2 pthread)

# target_link_libraries(demo2 wiringPi)
#target_link_libraries(demo2 crypto)
# target_link_libraries(demo2 rt)
# target_link_libraries(demo2 crypt)
#target_link_libraries(demo2 wiringPiDev)

#target_link_libraries(demo2 PRINT)

#find_library(WIRINGPI_LIBRARIES NAMES libwiringPi)
#target_link_libraries(demo2 ${WIRINGPI_LIBRARIES})

#link_libraries("/usr/local/lib/libcrypt.so")
#link_libraries("/usr/local/lib/libwiringPiDev.so")
#link_libraries("/usr/local/lib/libpthread.so")
#link_libraries("/usr/local/lib/libpthread.a")
#link_libraries("/usr/local/lib/libcrypt.so")

#target_link_libraries(demo2 glib)
#target_link_libraries(demo2 wiringPiDev)


