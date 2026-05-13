#include<iostream>
#include<fstream>
#include "colorful_word_include.h"
#include "help_doc_.h"
using namespace std;
void print_help_docx()
{
    ifstream help_doc;
    help_doc.open("help_doc.txt",ios::in);
    //文件路径不存在报错
    if (!help_doc)
    {
        word_set_API("找不到'help_doc'文件 ,请联系管理员",4);
        return;   
    }
    string line_string;
    while(getline(help_doc,line_string))
    {
        cout<<line_string<<endl;
    }
    help_doc.close();
}
