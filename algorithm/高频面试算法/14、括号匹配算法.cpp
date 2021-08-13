#include<iostream>
#include<stack>
using namespace std;
 
typedef unsigned char boolean;
#define    TRUE    1
#define FALSE    0
 
boolean backetMatch(char *str);
boolean backetMatch(char *str){
    stack<int> s;
    int i = 0;
     
    while(str[i]){
        if(s.empty()){
            s.push(str[i]);
        }else{
            if(s.top() == ')' || s.top() == ']' || s.top() == '}'){
                return FALSE;  //首先出现右括号的，肯定是不匹配的；
            }
 
            if(s.top() == '('){ //为'('的情况
                if(str[i] == ')'){
                    s.pop();
                }else{
                    s.push(str[i]);
                }
            }else if(s.top() == '['){ //为'['的情况
                if(str[i] == ']'){
                    s.pop();
                }else{
                    s.push(str[i]);
                }
            }else if(s.top() == '{'){ //为'{'的情况
                if(str[i] == '}'){
                    s.pop();
                }else{
                    s.push(str[i]);
                }
            }
        }
            i++;
    }
 
    if(s.empty()){
        return TRUE;
    }else{
        return FALSE;
    }
}
 
int main(void){
    char *str = "({[])}";
    boolean flag;
 
    flag = backetMatch(str);
    if(flag){
        printf("括号匹配\n");
    }else{
        printf("括号不匹配\n");
    }
     
    return 0;
}