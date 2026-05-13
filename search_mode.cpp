#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
// 头文件
#include "search_mode_.h"
// 容器文件
#include <vector>

//颜色字模块
#include"colorful_word_include.h"
using namespace std;
namespace fs = std::filesystem;
using namespace fs;
/*
1.路径检查
2.扫描默认路径下的所有文件对象，存入一个字符串数组
3.对每一个文件进行逐行扫描，扫描到关键字符串的，记录下对应的文件和行数
4.列出所有出现的文件和行数同时打印出来
5.检测用户输入的数字，确认是哪一个文件
6.光标定位到对应的文件行数，开始打印到结束
*/

// 默认路径
string note_file;
// 要查找的字符串内容
string note_part = "hello world";
// 错误处理
int search_mode()
{
    // 进入先进行路径检查
    ifstream morenfile;
    morenfile.open("moren_file.txt", ios::in);
    string moren_file;
    // 先执行一遍路径检查
    if (morenfile)
    {

        getline(morenfile, moren_file);
        if (!exists(moren_file))
        {
            word_set_API("无法找到输入的路径，请检查路径是否存在或被占用", 2);
            return 0;
        }
        else
            note_file = moren_file;
    }
    else
    {
        word_set_API("无法打开文件'moren_file.txt' 请检查文件是否存在或被占用", 2);
        return 0;
    }
    return 1;
}

// 统计总共有多少个文件
static int exits_file_num = 0;
// 用于检测所以目录下的cpp文件，返回一个string数组
vector<string> input_contrast_write()
{
    // if (note_file == "")
    // {
    //     return ;
    // }
    // 检测目录下的所有文件
    // search_mode();
    int file_num = 0;
    cout << "-------------------------------" << endl;
    vector<string> path_of_note_file;
    path_of_note_file.reserve(100);
    for (auto &entry : fs::recursive_directory_iterator(note_file))
    {

        // 寻找所有路径下的文件，遇到cpp格式的再记录
        if (entry.is_regular_file() && entry.path().extension() == ".cpp")
        {
            // cout << entry.path() << endl;
            file_num++;
            // push_back类型得是个string类
            path_of_note_file.push_back(entry.path().string());
        }
    }
    exits_file_num = file_num;

    // cout<<"-------------------------------"<<endl;
    // for(auto diedaiqi = path_of_note_file.begin();diedaiqi!=path_of_note_file.end();diedaiqi++)
    // {
    //     cout<<*diedaiqi<<endl;
    // }
    // cout<<"-------------------------------"<<endl;
    return path_of_note_file;
}
// 字符串对照功能
int str_contrast_modle(string file_name)
{

    string line_str;
    ifstream file;
    file.open(file_name, std::ios::in);
    // 查找重复字符串并且记录行数
    int line_posi = 1;
    while (getline(file, line_str))
    {
        size_t pos = line_str.find(note_part);
        if (pos != string::npos)
        {
            // 如果找到就返回行号
            return line_posi;
        }
        line_posi++;
    }
    // return 0 说明没有写到这个字符串
    return 0;
}

void print_def(string path_,string construct_string);
#include <string>
#include <iostream>



// ai写的用于处理数字的函数
int safe_stoi(const std::string &s)
{
    try
    {
        return std::stoi(s);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "无法被转换为数字，请注意，输入的内容需为纯数字\n";
    }
    return 0;
}

//函数api
void final_using_API(string note_part_final)
{
    note_part = note_part_final;
    if (search_mode() == 0)
    {
        return;
    }
    vector<string> input_contrast_write_;
    input_contrast_write_ = input_contrast_write();

    struct file_list_information
    {
        string file_name;
        int line_num;
        int document_number;
        /* data */
    };
    //存储所有路径的信息，所有的都存入
    vector<file_list_information> file_list_information_;
    file_list_information_.resize(exits_file_num);
    int q = 0;
    for (auto file_path = input_contrast_write_.begin(); file_path != input_contrast_write_.end(); ++file_path)
    {
        file_list_information_[q].file_name = *file_path;
        file_list_information_[q].line_num = str_contrast_modle(*file_path);
        q++;
        if (q == exits_file_num)
        {
            break;
        }
    }
    int document_number = 1;
    //构建一个与上个vector字符串数组相同的数组，用于存储包含有用信息的字符串
    vector<file_list_information> final_note_file;
    final_note_file.resize(100);
    int qq=0;
    for(auto diedaiqi = file_list_information_.begin();diedaiqi!=file_list_information_.end();diedaiqi++)
    {
        if((*diedaiqi).line_num!=0)
        {
            final_note_file[qq].file_name= (*diedaiqi).file_name;
            final_note_file[qq].line_num= (*diedaiqi).line_num;
            qq++;
        }
    }
    for (int a = 0; a < exits_file_num; a++)
    {
        if (file_list_information_[a].line_num == 0)
            continue;
        else
        {
            cout << endl
                 << "~" << "文档标号: " << document_number << endl;
            document_number++;
            cout << "目标文件: " << file_list_information_[a].file_name << endl;
            cout << "目标文件中关键字出现的行数为: " << file_list_information_[a].line_num << endl;
        }
    }
    // cout<<exits_file_num<<endl;
    if (document_number == 1)
    {
        cout << "所有笔记文档都没有找到关键字: " << note_part << endl;
        return;
    }
    string page;

    posi_1:
    cout<<"-------------------------------"<<endl;
    cout << "你需要查阅哪一个标号的文档?" << endl;
    cin >> page;
    int aim_num =safe_stoi(page);
    if (page == "no" || page == "NO")
        return;
    // else if (page == "all" || page == "ALL")
    // {
    //     // 打印所有的文件
    // }
    else if (aim_num)
    {
        aim_num--;
        cout<<aim_num<<endl;
        //打印指定数字的文档
        if (aim_num>document_number)
        {
            cout<<"W无法查找的所输入的标号的文档!"<<endl;
            goto posi_1;
        }
        else 
        {
            string haha =final_note_file[aim_num].file_name;
            int line_num = final_note_file[aim_num].line_num;
            cout<<haha<<endl;
            print_def(haha,note_part);
        }
    }
    else 
    {
        cout<<"这家伙，说什么呢？"<<endl;
    }
}
//用于打印文件的模块,有颜色字功能
//在答应过程中遇到同样的字符串也用颜色字标注
int string_constract_line_num_return(string input,string construct);
//print_def 需要两个参数，一个是路径，另一个是需要对比的字符串
void print_def(string path_,string construct_string)
{
    ifstream path__;
    path__.open(path_,ios::in);
    string print_screem;
    while(getline(path__,print_screem))
    {
        if(string_constract_line_num_return(print_screem,construct_string))
        {
            word_set_API(print_screem,3);
        }
        else 
        {
            cout<<print_screem<<endl;
        }
    }
    cout<<"~~"<<endl;
    return;
}
int string_constract_line_num_return(string input_line,string construct)
{
    size_t pos = input_line.find(construct);
    
    if (pos != std::string::npos) {
        return 1;
    } 
    return 0;
}