#include<cstdlib>
#include<iostream>
#include <windows.h>
#include"open.h"
#include <filesystem>
#include<fstream>
using namespace std;
namespace fs = std::filesystem;
using namespace fs;

void open_module(string input)
{   
    cout<<"目标文件:"<<input<<endl;
    ifstream path_part;
    path_part.open("moren_file.txt",ios::in);
    if(!path_part)
    {
        cout<<"找不到 'moren_file.txt' 文件"<<endl;
        return;
    }
    string pathhh;
    getline(path_part,pathhh);
    pathhh.append("\\");
    pathhh.append(input);
    pathhh.append(".cpp");
    cout<<pathhh<<endl;
    ifstream aim_path;
    aim_path.open(pathhh,ios::in);
    if(!aim_path)
    {
        cout<<"文件路径不存在"<<endl;
        aim_path.close();
    }
    else 
    {
        // ShellExecuteA(NULL, "open", input.c_str(), NULL, NULL, SW_SHOW);
        system(pathhh.c_str());
    }

    
}