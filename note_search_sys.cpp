#include <iostream>
#include <string>
// list功能呢块
#include "include_list.h"
// 颜色字模块
#include "colorful_word_include.h"
// help文档阅读功能呢块
#include "help_doc_.h"
// read功能呢块
#include "read_cpp_.h"
// search功能模块
#include "search_mode_.h"
#include<fstream>
// #include<windows.h>
#include <thread>
#include <chrono>
//open模块
#include"open.h"
#define line_fix "-------------------------------"
using namespace std;
class zhiling
{
private:
    // 一个用于存储拆分指令信息的结构
    struct mingling_information
    {
        // 指令类型
        string order;
        // 专用于list的指令信息
        string _list_path;
    };

    // 用于处理指令内容
    mingling_information shuru(const string &input)
    {
        int posi = input.length();
        for (int a = 0; a < input.length(); a++)
        {
            if (input[a] == ' ')
            {
                posi = a;
                break;
            }
        }

        mingling_information chaifen_hou_information;
        string input_order = input;
        // 拆分出指令类型存储在order里,注意长度长度处理

        chaifen_hou_information.order = input_order.substr(0, posi);
        // 拆分出地址存储在_llist_path 里
        if (input_order.length() > posi + 1)
        {
            chaifen_hou_information._list_path = input_order.substr(posi + 1);
        }
        else
            chaifen_hou_information._list_path = "";
        return chaifen_hou_information;
    }
    //fuck彩蛋
    void fuck()
    {
        ifstream fuck_egg;
        fuck_egg.open("the_egg.papa",ios::in);
        if(!fuck_egg)
        {
            cout<<"fuck you too(简配版)"<<endl;
        }
        else 
        {
            for(int a =0;a<2;a++)
            {
                word_set_API("YES!!!",4,3);
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            string fuck_line;
            int line_num =1;
            while(getline(fuck_egg,fuck_line))
            {
                if(line_num>=7)
                    break;
                word_set_API(fuck_line,4,3);
                line_num++;
            }
        }

    }

public:
    // 用于接受指令的内容同时调用 mingling_information shuru(string input,int n)
    // 调用后定向到各个单独执行函数
    void zhiling_dingxiang(string zhiling_neirong)
    {

        mingling_information chuli_houde_information = shuru(zhiling_neirong);

        if (chuli_houde_information.order == "/list")
        {
            // list功能
            cout << line_fix << endl;
            list_file_output(chuli_houde_information._list_path);
        }
        else if (chuli_houde_information.order == "/help")
        {
            // help功能
            cout << line_fix << endl;
            print_help_docx();
        }
        else if (chuli_houde_information.order == "/read")
        {
            // read功能
            read_cpp_note(chuli_houde_information._list_path);
        }
        else if (chuli_houde_information.order == "/search")
        {
            // search功能

            if (chuli_houde_information._list_path == "")
            {
                cout << "至少写一点东西呗" << endl;
                return;
            }
            final_using_API(chuli_houde_information._list_path);
        }
        else if (chuli_houde_information.order.length() >= 11)
        {
            word_set_API("一个人闲来无事想看看随便在输入栏里输入点东西会发生什么，你是真没得干啊", 5, 2);
        }
        else if (chuli_houde_information.order =="/fuck"||chuli_houde_information.order=="fuck"||chuli_houde_information.order=="FUCK")
        {
            fuck();
        }
        else if(chuli_houde_information.order =="/modify")
        {
            open_module(chuli_houde_information._list_path);
        }
        else
        {
            cout << "输入错误，请检查输入的命令是否存或键入 '/help' 查找帮助" << endl;
        }
    }
};

int main()
{
        // system("chcp 65001 > nul");
        ifstream main_access;
        main_access.open("the_egg.papa",ios::in);
        if(!main_access)
        {}
        else 
        {
            
            string main_line;
            int line_num =7;
            int first_begin =1;
            while(getline(main_access,main_line))
            {
                first_begin++;
                if(first_begin>=7)
                    word_set_API(main_line,3);
            }
        }
    cout<<endl;
    word_set_API("-C++ note search tool 3.2.2-",4);
    
    while (true)
    {
        cout << endl
             << line_fix << endl;
        string shuru_neirong;
        cout << "&~";
        getline(cin, shuru_neirong);
        if (shuru_neirong == "/exit")
            return 0;
        zhiling shuru;
        shuru.zhiling_dingxiang(shuru_neirong);
    }
}