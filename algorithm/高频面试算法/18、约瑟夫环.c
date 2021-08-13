#include<stdio.h>
#include<malloc.h>
 
void yusf(char **str, int count, int doom, int start){
    int *person;
    int i;
    int pre = start-2;
    int cur = start-1;
    int alive = count;
    int doomNumber = 0;
 
    if(start == 1){
        pre = count-1;
    }
 
    person = (int *)malloc(sizeof(int) * count);
    for(i = 0; i < count; i++){
        person[i] = (i+1)%count;  //循环数组
    }
 
    for(; alive > 0; cur = person[cur]){
        if(++doomNumber >= doom){
            printf("%s->出圈\n", str[cur]);
            alive--;
            doomNumber = 0;
            person[pre] = person[cur]; //出圈时的pre的保存
        }else{
            pre = cur;
        }
    }
}
 
int main(void){
    char *str[] = {"李大", "马二", "张三", "李四", "王五", "刘六", "吊七", "朱八", "杨九"};
    int count = sizeof(str)/sizeof(char *);
    int doom;  //恶运数字
    int start;  //从第几个人开始
 
    scanf("%d%d", &doom, &start);
    if(doom > count || doom <= 0 || start > count|| start <= 0){
        return;
    }
 
    yusf(str, count, doom, start); //count个元素,doom个厄运数字,从第start开始;
 
    return 0;
}