#include "include_list.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#define line_fix "-------------------------------"

//dayin_shaixuan()使用的头文件
#include <filesystem>
namespace fs =std::filesystem;
//颜色字
#include "colorful_word_include.h"

//函数有默认参数，默认参数为一个设定的路径
//当输入一个路径后就在默认参数路径后添加这个路径，用来列出底下的所有文件夹
void list_file_output(string moren_file="")
{

    //存储默认路径的字符串
    string file_str;
    //开始文件处理
    ifstream moren_file_wenjian;
    moren_file_wenjian.open("moren_file.txt",ios::in);
    //文件打开错误处理
    if(!moren_file_wenjian)
    {
        cout<<line_fix<<endl;
        word_set_API("找不到路径存放文件 'moren_file.txt' !",2);
        return;
    }
    getline(moren_file_wenjian,file_str);
    //关闭文件
    moren_file_wenjian.close();
    //默认参数
    if (moren_file =="")
    {
        moren_file = file_str;
        dayin_shaixuan(moren_file);
    }
    else 
    {
        file_str.append("\\");
        file_str.append(moren_file);
        string puzzle_file =file_str;
        dayin_shaixuan(puzzle_file);
    }
}

//
void dayin_shaixuan(string final_file)
{
    fs::path Final_file =fs::path(final_file);
    //错误处理
    cout<<Final_file<<endl;
    cout<<line_fix<<endl;
    if(!fs::exists(Final_file))
    {
        
        word_set_API("找不到文件路径，请检查笔记文件！",4);
        return;
    }
    for (auto& i : fs::directory_iterator(Final_file)) 
    {
		string output =i.path().filename().string();
        cout<<"~"<<output<<endl;
	}

}