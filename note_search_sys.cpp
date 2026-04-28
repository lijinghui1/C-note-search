#include <iostream>
#include <string>
#include "include_list.h"
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
            //
            // string qita;
        };

        //用于处理指令内容
        mingling_information shuru(const string &input,int n)
        {
            mingling_information chaifen_hou_information;
            string input_order = input;
            //拆分出指令类型存储在order里,注意长度长度处理
            
            chaifen_hou_information.order =input_order.substr(0,n);
            //拆分出地址存储在_llist_path 里
            if(input_order.length()>n+1)
            {
                chaifen_hou_information._list_path = input_order.substr(n+1);
            }  
            return chaifen_hou_information;
        }
    public:
        //用于接受指令的内容同时调用 mingling_information shuru(string input,int n)
        //调用后定向到各个单独执行函数
        void zhiling_dingxiang(string zhiling_neirong)
        {
            mingling_information chuli_houde_information =shuru(zhiling_neirong,5);
            if(chuli_houde_information.order=="/list")
            {
                list_file_output(chuli_houde_information._list_path);
            }
            else if(chuli_houde_information.order =="/help")
            {
                cout<<chuli_houde_information.order<<endl;
            }
            else 
            {
                cout<<"wrong command ,please check if the command list or enter '/help' for help"<<endl;
            }
        }
    
        
        
};
int main()
{
    cout<<"C++ note search sys 2.0.0"<<endl;
    while(true)
    {
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