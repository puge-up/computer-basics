#include<iostream>
using namespace std;
 
// 饿汉式,线程安全
class Singelton{
    private:
        Singelton(){
            cout<<"Singelton 构造函数执行"<<endl;
        }   
    public:
        static Singelton *getInstance(){
            return m_psl;
        }   
        static void freeInstance(){
            if(m_psl){
                cout<<"释放对象空间"<<endl;
                delete m_psl;
                m_psl = NULL;
            }   
        }   
    private:
        static Singelton *m_psl; // 此时C++编译器并没有分配内存!!!
};
 
Singelton *Singelton::m_psl = new Singelton;
 
int main(void){
    cout<<"*********************"<<endl;  // 执行顺序：先执行静态变量的初始化(此时也就是构造函数),在执行主函数中的代码!!!
    Singelton *p1 = Singelton::getInstance();
    Singelton *p2 = Singelton::getInstance();
 
    if(p1 == p2){
        cout<<"是同一个对象"<<endl;
    }else{
        cout<<"不是同一个对象"<<endl;
    }
 
    Singelton::freeInstance();
    return 0;
}