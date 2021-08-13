#include<iostream>
using namespace std;
 
//´æÔÚÏß³Ì°²È«µÄÎÊÌâ;`
class Singelton{
    private:
        Singelton(){
            cout<<"Singelton ¹¹Ôìº¯ÊýÖ´ÐÐ"<<endl;
        }   
    public:
        static Singelton *getInstance(){
            if(m_psl == NULL){
                m_psl = new Singelton;  //ÉêÇëÁËÒ»¸ö¶ÔÏóµÄÈë¿ÚµØÖ·;
            }   
            return m_psl;
        }   
        static void freeInstance(){
            if(m_psl){
                cout<<"ÊÍ·Å¶ÔÏó¿Õ¼ä"<<endl;
                delete m_psl;
                m_psl = NULL;
            }
        }
    private:
        static Singelton *m_psl; //¾²Ì¬±äÁ¿,±ØÐëÔÚÀàÍâ½øÐÐ³õÊ¼»¯,´ËÊ±²Å»á·ÖÅäÄÚ´æ¿Õ¼ä!!!
};
 
Singelton *Singelton::m_psl = NULL;
 
int main(void){
    Singelton *p1 = Singelton::getInstance();
    Singelton *p2 = Singelton::getInstance();
 
    if(p1 == p2){
        cout<<"ÊÇÍ¬Ò»¸ö¶ÔÏó"<<endl;
    }else{
        cout<<"²»ÊÇÍ¬Ò»¸ö¶ÔÏó"<<endl;
    }
 
    Singelton::freeInstance();
    return 0;
}