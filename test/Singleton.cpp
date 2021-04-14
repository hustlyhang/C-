#include <iostream>
#include <mutex>
//#include <pthread.h>
using namespace std;

//mutex m;


/*************************������*************************************/
class Singleton{
private:
    static Singleton* instance;
    Singleton(){cout<<"construct��"<<endl;};
    ~Singleton(){cout<<"destruct!"<<endl;};
    //? �������캯���Ϳ�����ֵ��������Ҫ����Ϊ˽��
    Singleton(const Singleton&);
    Singleton& operator = (const Singleton& a);
public:
    static Singleton* get() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

//? ��ʼ����̬��Ա
Singleton* Singleton::instance = nullptr;
/*
    * ����ģʽ�����ڴ�й©�����⣬��Ϊ�����������ᱻ���ã�����Ϊ˽��
    * ����ʹ������ָ�����ʹ�þ�̬��Ƕ�������
*/

/*************************������**��̬��Ƕ�������*�����ڴ�й©************************************/
class Singleton1{
private:
    static Singleton1* instance1;
    Singleton1(){cout<<"construct��"<<endl;};
    ~Singleton1(){cout<<"destruct!"<<endl;};
    Singleton1(const Singleton1& a);
    Singleton1& operator =(const Singleton1& a);

    //? ע�����û��static
    class deleter{
    public:
        deleter(){};
        ~deleter(){
            cout<<"in deleter"<<endl;
            if (Singleton1::instance1) {
                delete Singleton1::instance1;
            }
        };
    }; 
    static deleter Deleter;
public:
    static Singleton1* get() {
        //? �̰߳�ȫ ˫�����DCL
        if (instance1 == nullptr) {
            //lock_guard<mutex> lock(m);//? ��������������������������Զ�����
            if (instance1 == nullptr) {
                instance1 = new Singleton1();
            }
        }
        
        return instance1;
    }
};
//? ��ʼ����̬��Ա
Singleton1* Singleton1::instance1 = nullptr;
/*
    * �ڳ������н���ʱ��ϵͳ����þ�̬��Ա����������������������ɾ��������Ψһʵ����ʹ�����ַ����ͷŵ�������������������
    * �ڵ������ڲ�����ר�е�Ƕ���ࡣ
    * �ڵ������ڶ���˽�е�ר�������ͷŵľ�̬��Ա��
    todo ���ó����ڽ���ʱ����ȫ�ֱ��������ԣ�ѡ�����յ��ͷ�ʱ����

*/
/**************************************��õ�����ģʽ*********************************************************/
class Singleton2{
private:
    Singleton2(){cout<<"construct!"<<endl;};
    ~Singleton2(){};
    Singleton2(const Singleton2&);
	Singleton2& operator=(const Singleton2&);
public:
    static Singleton2& get() {
        static Singleton2 instance2;
        return instance2;
    }
};

/*************************************����ģʽ*********************************************************/
class Singleton3{
private:
    static Singleton3 instance3;
    Singleton3(){cout<<"construct!"<<endl;};
    ~Singleton3(){};
    Singleton3(const Singleton&){};
    Singleton3& operator=(const Singleton3&) {};

public:
    static Singleton3& get() {
        return instance3;
    }
};

Singleton3 Singleton3::instance3;


void test1(){
    Singleton1* instance1 = Singleton1::get();
    Singleton1* instance2 = Singleton1::get();
    return;
}
void test2(){
    Singleton2& isntance1 = Singleton2::get();
    Singleton2& isntance2 = Singleton2::get();

    return;
}
void test3(){
    Singleton3& isntance1 = Singleton3::get();
    Singleton3& isntance2 = Singleton3::get();

    return;
}
int main() {
    // Singleton* instance = Singleton::get();
    // Singleton* instance2 = Singleton::get();

    //test1();
    test3();

    return 0;
}