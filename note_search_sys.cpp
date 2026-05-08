#include <iostream>
#include <string>
//list功能呢块
#include "include_list.h"
//颜色字模块
#include "colorful_word_include.h"
//help文档阅读功能呢块
#include "help_doc_.h"
//read功能呢块
#include "read_cpp_.h"

#define line_fix "-------------------------------"
using namespace std;
class zhiling
{
    private:
        //一个用于存储拆分指令信息的结构
        struct mingling_information
        {
            //指令类型
            string order;
            //专用于list的指令信息
            string _list_path;
        };

        //用于处理指令内容
        mingling_information shuru(const string &input)
        {
            int posi = input.length();
            for(int a =0;a<input.length();a++)
            {
                if(input[a]==' ')
                {
                    posi =a;
                    break;
                }
            }

            mingling_information chaifen_hou_information;
            string input_order = input;
            //拆分出指令类型存储在order里,注意长度长度处理
            
            chaifen_hou_information.order =input_order.substr(0,posi);
            //拆分出地址存储在_llist_path 里
            if(input_order.length()>posi+1)
            {
                chaifen_hou_information._list_path = input_order.substr(posi+1);
            }  
            else 
                chaifen_hou_information._list_path ="";
                return chaifen_hou_information;
        }
    public:
        //用于接受指令的内容同时调用 mingling_information shuru(string input,int n)
        //调用后定向到各个单独执行函数
        void zhiling_dingxiang(string zhiling_neirong)
        {
            mingling_information chuli_houde_information =shuru(zhiling_neirong);
            if(chuli_houde_information.order =="/list")
            {
                cout<<line_fix<<endl;
                list_file_output(chuli_houde_information._list_path);
            }
            else if(chuli_houde_information.order =="/help")
            {
                cout<<line_fix<<endl;
                print_help_docx();
            }
            else if (chuli_houde_information.order =="/read")
            {
                read_cpp_note(chuli_houde_information._list_path);
            }
            else 
            {
                cout<<"wrong command ,please check if the command list or enter '/help' for help"<<endl;
            }
        }
};

int main()
{
    system("chcp 65001 > nul");
    cout<<"-C++ note search sys 2.0.0-"<<endl;
    cout<<line_fix<<endl;
    while(true)
    {
        cout<<line_fix<<endl;
        string shuru_neirong;
        cout<<"&~";
        getline(cin,shuru_neirong);
        if(shuru_neirong.length()<5)
            continue;
        if(shuru_neirong=="/exit")
            return 0;
        zhiling shuru;
        shuru.zhiling_dingxiang(shuru_neirong);
    }
}