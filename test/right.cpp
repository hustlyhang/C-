
#include <iostream>
using namespace std;

class Copyable {
  public:
    Copyable() {}
    Copyable(const Copyable &o) { cout << "Copied" << endl; }
};
Copyable ReturnRvalue() {
    return Copyable(); //����һ����ʱ����
}
void AcceptVal(Copyable a) {}
void AcceptRef(const Copyable &a) {}

int main() {
    cout << "pass by value: " << endl;
    //? ReturnRvalue()�᷵��һ����ʱ����Ȼ��
    /*
        * ������AcceptVal(ReturnRvalue())��Ҫ�������ο������캯����һ����ReturnRvalue()�����У�
        * �������Copyable���󣬷��ص�ʱ�����ÿ������캯������һ����ʱ�����ڵ���AcceptVal()ʱ��
        * �ֻὫ������󿽱��������ľֲ�����a��һ�����������ο������캯������AcceptRef()�Ĳ�ͬ�����β�
        * �ǳ�����ֵ���ã����ܹ�����һ����ֵ�����Ҳ���Ҫ������
        * ��ʵ�ʵĽ���ǣ��������ַ�ʽ��һ�ο������캯����û�е��ã�
    */
    AcceptVal(ReturnRvalue()); // Ӧ�õ������ο������캯��
    cout << "pass by reference: " << endl;
    AcceptRef(ReturnRvalue()); //Ӧ��ֻ����һ�ο������캯��

    return 0;
}
