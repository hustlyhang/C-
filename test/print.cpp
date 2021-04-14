// /*��������������������ַ�����ready������ĸ��߳����������ready==0ʱ��func1�̴߳�ӡA��
// �������1�Ļ������������������ϵȴ�����func1�̴߳�ӡ��ɺ󣬸�ready+1������һ���̴߳�ӡB���Դ�����*/
#include <condition_variable>
#include <iostream>
#include <thread>
using namespace std;

mutex mtx;
condition_variable cv;
int ready = 0;

void func1() {
    unique_lock<mutex> ul(mtx);
    int cnt = 0;
    while (cnt < 10) {
        while (ready != 0)
            cv.wait(ul);
        cout << "A"
             << " ";
        ready = 1;
        cnt++;
        cv.notify_all();
    }
}
void func2() {
    unique_lock<mutex> ul(mtx);
    int cnt = 0;
    while (cnt < 10) {
        while (ready != 1)
            cv.wait(ul);
        cout << "B"
             << " ";
        cnt++;
        ready = 2;
        cv.notify_all();
    }
}
void func3() {
    unique_lock<mutex> ul(mtx);
    int cnt = 0;
    while (cnt < 10) {
        while (ready != 2)
            cv.wait(ul);
        cout << "C"
             << " ";
        ready = 0;
        cnt++;
        cv.notify_all();
    }
}
int main() {
    thread t1(func1);
    thread t2(func2);
    thread t3(func3);
    t1.join();
    t2.join();
    t3.join();

    return 0;
}

