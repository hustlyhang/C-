#include <string>
#include <iostream>
using namespace std;
/*
    * �Լ�ʵ�ּ򵥵�vector��
    * ע����Ҫ �� ��ǰԪ�ظ������ܵ���������ʼ������ �Լ�һ��ָ�룬ָ������һ���ַ��
    * ���캯����Ҫ��ʼ�� thesize, thecapacity, �Լ�dataָ��
    * ���ƹ��캯�� ע��ʹ��memcpy����
    * ���ظ�ֵ�������±����������
    * ���·��亯������Ҫ������������
    * push_back���� ÿ��Ҫ�ж������͵�ǰԪ�ظ����� ���������Ļ�Ҫ��������
    *
*/

template<class T>
class vec {
public:
    //* ���캯��
    vec(int size = 0) : theSize(size), theCapacity(size + INIT_CAPACITY) {
        cout<<"���빹�캯��"<<endl;
        //? ���ù��캯��ʱ����Ҫ�����ַ
        data = new T[theCapacity];
    }
    
    //* ���ƹ��캯��
    vec(const vec& other): theSize(0), theCapacity(0), data(nullptr) {
        theSize = other.theSize;
        theCapacity = other.theCapacity;
        data = new T[theCapacity];
        //? �ڴ濽��
        memcpy(data, other.data, theSize* sizeof(T));
    }

    //* ���ظ�ֵ����
    vec& operator = (const vec& other) {
        cout << "�������ظ�ֵ���������" << endl;
        //? �ж��ǲ���ͬһ������
        if (this == &other) return *this;
        else {
            //? ɾ��ԭ����
            delete [] data;
            //? ���·���
            theSize = other.theSize;
            theCapacity = other.theCapacity;
            data = new T[theCapacity];

            //memcpy(data, other.data, sizeof(T)*theSize);

            for (int i = 0; i < theSize; i++)
			{
				data[i] = other.data[i];
			}
			return *this;
        }
    }

    //* �����±������
    T& operator [](int index) {
        if (index >= theSize) cerr << "��������߽�" << endl;
        return data[index];
    }

    //* ���·���ռ�
    void reServe(int newCapacity) {
        cout<<"���·���ռ�"<<endl;
        if (newCapacity <= theCapacity) return;
        theCapacity = newCapacity;

        //? ����һ����ʱָ��洢ԭ������λ��
        T* tmp = data;
        data = new T[theCapacity];
        memcpy(data, tmp, theSize*sizeof(T));
        delete [] tmp;
    }
    

    void push_back(T value)
	{
		cout << "����push_back����" << endl;
		if (theCapacity==theSize)
		{
			reServe(2 * theCapacity + 1);
		}
		data[theSize++] = value;
	}

    void pop_back() {
        if (theSize == 0) {
            cerr<<"����Ϊ��"<<endl;
            return;
        }
        theSize--;
    }

    int size() 
	{
		return theSize;
	}

	int capacity()
	{
		return theCapacity;
	}
    
    void assign(int num,T value)
	{
		if (num >= theCapacity)
		{
			reServe(theCapacity * 2 + 1);
		}
		theSize = 0;//����֮ǰassign������num��ֵ�����ǣ�����num��ֵ���ڣ�����theSizeʹ���Ƿ��ʲ������ͺ�������һ����
		for (int i=0; i < num; i++)
		{
			data[i] = value;
			theSize++;
		}
	}

    T* get_address()
	{
		return data;
	}

	T at(int index)
	{
		if (index >= theSize)
		{
			cerr << "�����߽�" << endl;
			return -1;
		}
		return data[index];
	}
	T& back()
	{
		return data[theSize - 1];
	}
	T& begin()
	{
		return data[0];
	}

	~vec() {
		cout<<"�����������ͷſռ�"<<endl;
		if (data != NULL)
		{
			cout<<"this.data address:"<<data<<endl;
			delete[] data;
		}
	}

private:
    const int INIT_CAPACITY = 5;    //! ÿ����չvecʱ���ӵĴ�С
    int theSize;                    //! ��ǰvec���ô�С
    int theCapacity;                //! �ܴ�С
    T* data;                        //! ����ָ��
public:
    T* iterator;
};



int main()
{
	vec<int> v1;
	cout <<"size:"<< v1.size() << endl;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	cout<<"v1 size:"<<v1.size()<<"  v1 capacity:"<<v1.capacity()<<"  v1 address:"<<&v1<< "  v1.data address:" <<v1.get_address()<<endl;
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	cout << "===============" << endl;
	vec<int> v2(v1);
	cout << "v2 size:" << v2.size() << "  v2 capacity:" << v2.capacity() << "  v2 address:" << &v2 << "  v2.data address:" <<v2.get_address()<< endl;
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
	cout << "===============" << endl;
	vec<int> v3;
	v3= v1;
	cout << "v3 size:" << v3.size() << "  v3 capacity:" << v3.capacity() << "  v3 address:" << &v3 << "  v3.data address:" <<v3.get_address()<< endl;
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	//cout << "============TEST====FUNC===============" << endl;
	//hn_vector<int> v4;
	//v4.assign(7, 100);
	//for (int i = 0; i < v4.size(); i++)
	//{
	//	cout << v4[i] << " ";
	//}
	//cout << endl;
	//v4.assign(6, 66);
	//cout << "v4 size:" << v4.size() << "  v4 capacity:" << v4.capacity() << "  v4 address:" << &v4 << "  v4.data address:" << v4.get_address() << endl;
	//for (int i = 0; i <= v4.size(); i++)
	//{
	//	cout << v4[i] << " ";
	//}
	//cout << endl;
	//cout << "at func:"<<v4.at(5)<<endl;
	//cout << "back func:" << v4.back() << endl;
	//cout << "begin func:" << v4.begin() << endl;
}