#include<iostream>
using namespace std;
 
// 存在线程安全的问题;`
class Singelton{
    private:
        Singelton(){
            cout<<"Singelton 构造函数执行"<<endl;
        }   
    public:
        static Singelton *getInstance(){
            if(m_psl == NULL){
                m_psl = new Singelton;  // 申请了一个对象的入口地址;
            }   
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
        static Singelton *m_psl; // 静态变量,必须在类外进行初始化,此时才会分配内存空间!!!
};
 
Singelton *Singelton::m_psl = NULL;
 
int main(void){
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