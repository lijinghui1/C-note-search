#include <iostream>
#include <string>
#include "colorful_word_include.h"
using namespace std;
// 重置所有属性
#define RESET   "\033[0m"

// 前景色
#define BLACK   "\033[30m"//1
#define RED     "\033[31m"//2
#define GREEN   "\033[32m"//3
#define YELLOW  "\033[33m"//4
#define BLUE    "\033[34m"//5
#define MAGENTA "\033[35m"//6
#define CYAN    "\033[36m"//7
#define WHITE   "\033[37m"//8

// 背景色
#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

// 属性
#define BOLD      "\033[1m"//加粗(1)
#define UNDERLINE "\033[4m"//添加下划线(2)
#define BLINK     "\033[5m"//闪烁(3)
#define REVERSE   "\033[7m"//反显示(4)

struct word_attribute
{
    string words;
    int  color;
    int word_formate_attribute;
};

void word_set_API(string choice_word,int color_Code_name,int word_Formate_set)
{
    //设置色号，然后传给设置字符格式的函数
    //调用函数有顺序，
    word_attribute word_set;
    word_set.words = choice_word;
    word_set.color =color_Code_name;
    word_set.word_formate_attribute =word_Formate_set;
    //设置颜色
    word_set.words = colorful_word_set_color(word_set.words,word_set.color);
    //设置文字属性
    word_set.words = word_attribute_set(word_set.words,word_set.word_formate_attribute);
    //输出
    cout<<word_set.words<<RESET<<endl;
    
}

//设置格式  属性<<颜色<<背景<<"    "<<RESET<<endl;
word_attribute input_Handle;
//设置颜色，默认为白色（8）
string  colorful_word_set_color(string choice_word,int color_code_name=8)
{
    switch  (color_code_name)
    {
        case 1:
            choice_word = BLACK+choice_word;
            break;
        case 2:
            choice_word = RED+choice_word;
            break;
        case 3:
            choice_word = GREEN+choice_word;
            break;
        case 4:
            choice_word = YELLOW+choice_word;
            break;
        case 5:
            choice_word = BLUE+choice_word;
            break;
        case 6:
            choice_word = MAGENTA+choice_word;
            break;
        case 7:
            choice_word = CYAN+choice_word;
            break;
        case 8:
            choice_word = WHITE+choice_word;
            break;
    }
    return choice_word;
}

//设置文字属性，加粗，下划线，闪烁等
string word_attribute_set(string word,int attribute_code_name=0)
{
    switch (attribute_code_name)
    {
        case 0:
            break;
        case 1:
            word =BOLD+word;
            break;
        case 2:
            word =UNDERLINE+word;
            break;
        case 3:
            word =BLINK+word;
            break;
        case 4:
            word =REVERSE+word;
            break;
    }
    return word;
}