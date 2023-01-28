#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define NEW_LINE 13
#define ESC 27
#define CTRL_C 38

//Default array if no reference
string option[] = {"1. First", "2. Second", "3. Third", "4. Fourth", "5. Fifth", "6. Sixth", "7. Seventh", "8. Eighth"};
int ArraySize = sizeof(option)/sizeof(option[0]);
int defaultcolorcode = 249;     //Also Available: 0 to 255 different color codes
int line = 1;
int header = 0;
string headerval = "";

int writeline(string text,int checkcolor){
    if(checkcolor){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),defaultcolorcode);
        cout << text << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    }else{
        cout << text << endl;
    }
}

void options(string opt[],int ArraySize,int line){
    system("cls");
    if(header==1){
        cout << headerval << endl;
    }
    int a = 1 , i = 1;
    for(i=0;i<ArraySize;i++,a++){
        writeline(opt[i],a==line);
    }
}

void setcolor(int colorcode){
    defaultcolorcode = colorcode;
}

void setheader(string strref){
    header = 1;
    headerval = strref;
}

void setoptions(string opt[],int arraylength){
    copy(opt,opt+arraylength,option);
    ArraySize = arraylength;
}

int getselection(){
    int c = 1, totallines = ArraySize;
    while(1){
        options(option,ArraySize,line);
        switch(c = getch()){
            case KEY_UP:{
                (line>1&&line<=totallines)?line--:line= totallines;
                break;
            }
            case KEY_DOWN:{
                (line>0&&line<totallines)?line++:line=1;
                break;
            }
            case NEW_LINE:{
                system("cls");
                header = 0;
                return line;
                break;
            }
            //Escape or Ctrl + c to exit
            case ESC:
            case CTRL_C:{
                header = 0;
                system("cls");
                return 0;
            }
        }
    }
}
//Develope By DhruvChauhan
