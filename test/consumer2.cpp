#include <Windows.h>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

using namespace std;

class MultiThreadProduceConsume {
  private:
    //! ��Ҫ���������������������˲��Ϻ�Ҫ֪ͨ���������ѣ����Ѻ�Ҫ֪ͨ����������
    condition_variable produce_msgQueue;
    condition_variable consume_msgQueue;
    mutex mtx;

    //! �̳߳أ���������̺߳������߳�
    vector<std::thread> tpool;

  private:
    //! ���ڴ�������Ĳ���
    queue<int> item_buff;
    //! �������еĳ���
    const int buffsize;
    //! �����Ĳ��ϵı��
    static int item_id;
    //! �����̺߳������̵߳ĸ���
    int c_no, p_no;

  private:
    void producItem() {
        while (true) {
            std::unique_lock<mutex> lck(mtx);
            while (item_buff.size() == buffsize) {
                produce_msgQueue.wait(lck);
            }
            Sleep(10);
            item_id = item_id++ % buffsize;
            item_buff.push(item_id);
            cout << "product item id: " << item_id << endl;

            consume_msgQueue.notify_all();
            //lck.unlock();
        }
    }
    void consumeItem() {
        while (true) {
            std::unique_lock<mutex> lck(mtx);
            while (item_buff.empty()) {
                cout << "wait product" << endl;
                consume_msgQueue.wait(lck);
            }
            Sleep(10);
            cout << "customer id : " << this_thread::get_id() << endl;
            cout << "consume Item id: " << item_buff.front() << endl;
            item_buff.pop();
            produce_msgQueue.notify_one();
            //lck.unlock();
        }
    }

  public:
    //? ��ʼ��
    MultiThreadProduceConsume(int size = 10, int pno = 1, int cno = 5) : buffsize(size), p_no(pno), c_no(cno){};

    void run() {
        //? �������ߺ��������̼߳��뵽�̳߳���
        productTask();
        customerTask();
        //? Ȼ�������̵߳ȴ��̳߳��е��߳�
        for (auto &i : tpool) {
            i.join();
        }
    }

    //! ע���߳������Ա������Ϊ����ʱ��ʼ������
    void productTask() {
        for (int i = 0; i < p_no; i++) {
            tpool.emplace_back(
                thread(&MultiThreadProduceConsume::producItem, this));
        }
    }
    void customerTask() {
        for (int i = 0; i < c_no; i++) {
            tpool.emplace_back(
                thread(&MultiThreadProduceConsume::consumeItem, this));
        }
    }
};
int MultiThreadProduceConsume::item_id = 0;

int main() {
    MultiThreadProduceConsume t;
    t.run();
    system("pause");
    return 0;
}
