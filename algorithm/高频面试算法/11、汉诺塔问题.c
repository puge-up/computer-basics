#include<stdio.h>
 
void Hanoii(int n, char s, char a, char t);
 
void Hanoii(int n, char s, char a, char t)
{
    if(n > 0)
    {
        Hanoii(n-1, s, t, a);
        printf("%d : %c -> %c\n", n, s, t);
        Hanoii(n-1, a, s, t);
    }
}
 
void main(void)
{
    Hanoii(4, 'A', 'B', 'C');
}