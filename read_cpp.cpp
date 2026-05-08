#include<iostream>
#include<string>
#include<fstream>
#include "read_cpp_.h"
#include "colorful_word_include.h"
#include<filesystem>
using namespace std;

#define line_fix "-------------------------------"
void read_cpp_note(string path)
{
    //存储默认路径的字符串
    string file_str;
    //开始文件处理
    ifstream moren_file_wenjian;
    moren_file_wenjian.open("moren_file.txt",ios::in);
    //文件打开错误处理
    if(!moren_file_wenjian)
    {
        word_set_API("Missing important file 'moren_file.txt' ",2);
        return;
    }
    //文字拼接处理
    getline(moren_file_wenjian,file_str);
    file_str.append("\\");
    file_str.append(path);
    namespace fs = std::filesystem;
    fs::path read_doc_file;
    read_doc_file= file_str;
    cout<<line_fix<<endl;
    cout<<"aim path:"<<read_doc_file<<endl;
    cout<<line_fix<<endl;
    if(!fs::exists(read_doc_file))
    {
        word_set_API("Please check the path of file_note cpp",4);
        return;
    }
    else 
    {
        ifstream note_doc_open;
        note_doc_open.open(read_doc_file,ios::in);
        string note_doc;
        while(getline(note_doc_open,note_doc))
        {
            cout<<note_doc<<endl;
        }
    }
}