# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.8)

# 项目信息
project(conquest_c_pointer_kmaebashi)

set(CMAKE_C_STANDARD 99)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 添加子目录
# add_subdirectory(chapter_1)
add_subdirectory(chapter_5/word_count_array)

# 指定生成目标
add_executable(conquest_c_pointer_kmaebashi chapter_5/word_count_array/main.c)

# 添加链接库
target_link_libraries(conquest_c_pointer_kmaebashi word_count_array)
