#include <iostream>
using namespace std;

//todo classA �в�����Ĭ�Ϲ��캯��ʱ�����������к��л���ʱ��ʼ������ʹ�ó�ʼ���б�

class A{
public:
    A(int a, int b, int c) {
        cout<<"construct A"<<endl;
        A_a = a;
        A_b = b;
        A_c = c;
    }    
private:
    int A_a, A_b, A_c;
};

class B{
public:
    B(int a, int b):a(1,2,3),B_a(a),B_b(b){
        cout<<"construct B"<<endl;
    };

private:
    A a;
    const int B_a;
    int &B_b;
};

int main(){
    B b(1,2);



    return 0;
}