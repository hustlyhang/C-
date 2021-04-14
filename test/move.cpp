#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class MyString {
  public:
    static size_t CCtor; //ͳ�Ƶ��ÿ������캯���Ĵ���
    // static size_t CCtor; //ͳ�Ƶ��ÿ������캯���Ĵ���
  public:
    // ���캯��
    MyString(const char *cstr = 0) {
        if (cstr) {
            m_data = new char[strlen(cstr) + 1];
            strcpy(m_data, cstr);
        } else {
            m_data = new char[1];
            *m_data = '\0';
        }
    }

    // �������캯��
    //? const MyString &str ������ֵ���ÿ��Խ�����ֵ��������һ�ο�������
    MyString(const MyString &str) {
        CCtor++;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
    }

    // �ƶ����캯��
    MyString(MyString &&str): m_data(str.m_data) {
        str.m_data = nullptr;
    }

    // ������ֵ���� =������
    MyString &operator=(const MyString &str) {
        if (this == &str) // �������Ҹ�ֵ!!
            return *this;

        delete[] m_data;
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
        return *this;
    }

    // �ƶ���ֵ���� =������
    //? MyString &&str ��ֵ����
    MyString &operator=(MyString &&str) {
        if (this == &str) // �������Ҹ�ֵ!!
            return *this;

        delete[] m_data;
        m_data = str.m_data;
        str.m_data = nullptr; //����ָ��֮ǰ����Դ��
        return *this;
    }

    ~MyString() { delete[] m_data; }

    char *get_c_str() const { return m_data; }

  private:
    char *m_data;
};

size_t MyString::CCtor = 0;

int main() {
    vector<MyString> vecStr;
    vecStr.reserve(
        1000); //�ȷ����1000���ռ䣬����ô�������õĴ�������Զ����1000
    for (int i = 0; i < 1000; i++) {
        MyString tmp("hello");
        vecStr.push_back(move(tmp));
        //! ��Ȼtmp��һ����ֵ�����������������ں̣ܶ�
        //! ����ͨ��move�������Ϊ��ֵ��Ȼ��Ϳ��Ե���mystring�е��ƶ����캯����
        //! ���Լ���ָ��ָ����˵���Դ��Ȼ�󽫱��˵�ָ���޸�Ϊnullptr
    }
    cout << MyString::CCtor << endl;

    return 0;
}