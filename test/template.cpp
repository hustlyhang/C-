#include <iostream>
#include <string>
using namespace std;

template<typename T>
T Max(T a, T b) {
    if (a > b) return a;
    else return b;
}
//! ģ���ػ�
//? ��ʾ�ؼ���template��һ�Լ�����<>��Ȼ���Ǻ���ģ���ػ��Ķ��� �ö���ָ���˷���ֵ ��ģ�������������ػ�ģ���ģ��ʵ�Σ��Լ�����������ͺ�����

typedef const char* CCP;
template <> CCP Max<CCP> (CCP a, CCP b) {
    return (strcmp(a, b) > 0 ? a : b);
}

//! ����ƫ�ػ�
template <typename T> void MM(int a, T b) {

}


//! ���ػ�
template <class T>
class all{

};
template <> class all<char*> {

};


//! ��ƫ�ػ�
//! ��ģ��
template<class T1, class T2>
class nn{

};

//! ��ƫ�ػ�,֮ǰ�����ȶ�����ģ��
template<class T> 
class nn<int, T> {

};

int main() {
    string s2("def");
    string s1("abc");
    CCP p = Max<CCP> ("abc", "def");
    string i = Max (s1, s2);
    cout<<p<<endl;
    cout<<i<<endl;

    return 0;
}