#ifndef SEARCH_MODE
#define SEARCH_MODE

#include <string>
#include<vector>

// 初始化：读取 moren_file.txt 并设置 note_file
int search_mode();

// 遍历 note_file 目录下的所有文件
std::vector<std::string> input_contrast_write();

// 在指定文件中查找 note_part
int str_contrast_modle(std::string file_name);
void final_using_API(std::string note_part_final);
#endif