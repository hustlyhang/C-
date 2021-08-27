# Learn
- [ostringstream](https://blog.csdn.net/qq1987924/article/details/7671154)
  - sstream�ⶨ���������ࣺistringstream��ostringstream��stringstream���ֱ����������������롢������������������
  - ʹ��string�����������ַ����顣�������Ա��⻺���������Σ�ա����ң����������Ŀ���������ͱ��Զ��Ƶ���������ʹʹ���˲���ȷ�ĸ�ʽ����Ҳû��Σ�ա�
---
- [unique_ptr](https://blog.csdn.net/qq_19895789/article/details/116102762)
  - ����Ҫ֪��unique_ptr��shared_ptr���Զ���deleter��ʽ����һ����unique_ptrΪ���Ż�������Ҫ�ṩdeleter�����͡�
    ```C++
    struct FileCloserStruct {
		void operator()(FILE* fp) const {
			if (fp != nullptr) {
				fclose(fp);
			}
		}
	};
 
	void FileCloserFunc(FILE* fp) {
		if (fp != nullptr) {
			fclose(fp);
		}
	}
 
	auto FileCloserLambda = [](FILE* fp) {
		if (fp != nullptr) {
			fclose(fp);
		}
	};
 
	int main() {
 
		std::unique_ptr<FILE, FileCloserStruct> uptr1(fopen("test_file.txt", "w"));
		std::cout << sizeof(uptr1) << std::endl;// 4
 
		std::unique_ptr<FILE, void(*)(FILE*)> uptr2(fopen("test_file1.txt", "w"), FileCloserFunc);
		std::cout << sizeof(uptr2) << std::endl;// 8
 
		std::unique_ptr<FILE, std::function<void(FILE*)>> uptr3(fopen("test_file2.txt", "w"), FileCloserLambda);
		std::cout << sizeof(uptr3) << std::endl;// 48
 
		std::unique_ptr<FILE, decltype(FileCloserLambda)> uptr4(fopen("test_file3.txt", "w"), FileCloserLambda);
		std::cout << sizeof(uptr4) << std::endl;// 4
 
		return 0;
	}
    ```
-----
- [std::bind](https://www.jianshu.com/p/82407fb43475)
  - bind��������һ���ɵ��ö�������һ���µĿɵ��ö���������ԭ����
  - [bind��װ��Ա����](https://blog.csdn.net/albertsh/article/details/99845666)
-----
- [std::function](https://www.jianshu.com/p/4ea00ee0dabd)
  - ���ǿ���ʹ��std::function����ͬ���͵Ŀɵ��ö�����ͬһ�ֵ�����ʽ��
------  
- ���������
  - https://www.jb51.net/article/72424.htm
  - [���������](https://www.cnblogs.com/Mayfly-nymph/p/9034936.html#:~:text=%E4%BD%9C%E4%B8%BA%E5%8F%8B%E5%85%83%E5%87%BD%E6%95%B0%E9%87%8D%E8%BD%BD%20%E8%80%8C%E5%AF%B9%E4%BA%8E%E7%AC%AC%E4%BA%8C%E7%A7%8D%E5%BD%A2%E5%BC%8F%E7%9A%84%E9%87%8D%E8%BD%BD%EF%BC%9A,%E5%8F%8B%E5%85%83%E5%87%BD%E6%95%B0%EF%BC%88%E5%8F%8B%E5%85%83%E5%87%BD%E6%95%B0%E5%88%99%E6%98%AF%E6%8C%87%E6%9F%90%E4%BA%9B%E8%99%BD%E7%84%B6%E4%B8%8D%E6%98%AF%E7%B1%BB%E6%88%90%E5%91%98%E5%8D%B4%E8%83%BD%E5%A4%9F%E8%AE%BF%E9%97%AE%E7%B1%BB%E7%9A%84%E6%89%80%E6%9C%89%E6%88%90%E5%91%98%E7%9A%84%E5%87%BD%E6%95%B0%EF%BC%89%E8%BF%9B%E8%A1%8C%E9%87%8D%E8%BD%BD%EF%BC%8C%E9%82%A3%E4%B9%88%E5%AE%83%E5%B0%B1%E4%B8%8D%E5%AD%98%E5%9C%A8this%E6%8C%87%E9%92%88%E4%BA%86%EF%BC%8C%E6%89%80%E4%BB%A5%E9%9C%80%E8%A6%81%E5%AE%9A%E4%B9%89%E4%B8%A4%E4%B8%AA%E5%8F%82%E6%95%B0%E6%9D%A5%E8%BF%90%E7%AE%97%EF%BC%88%E5%AF%B9%E4%BA%8E%E5%8F%8C%E7%9B%AE%E8%BF%90%E7%AE%97%E7%AC%A6%EF%BC%89%EF%BC%8C%20%E8%80%8C%E5%8F%8B%E5%85%83%E5%87%BD%E6%95%B0%E7%9A%84%E5%AE%9E%E7%8E%B0%E5%8F%AF%E4%BB%A5%E5%9C%A8%E5%A4%96%E9%9D%A2%E5%AE%9A%E4%B9%89%EF%BC%8C%E4%BD%86%E5%BF%85%E9%A1%BB%E5%9C%A8%E7%B1%BB%E5%86%85%E9%83%A8%E5%A3%B0%E6%98%8E%20%E3%80%82)
-----
- tuple	Ԫ�飬��ģ�庯����Ҫ���� 1 ���䳤����ʱ��ʹ��tupleЧ�����ԡ�  
  - https://www.cnblogs.com/gudushishenme/archive/2013/09/22/3332582.html  
  - https://www.cnblogs.com/xueqiuqiu/articles/12955797.html  
-----
- initializer_list
  -	https://blog.csdn.net/fengxinlinux/article/details/72614874
-----
- std::index_sequence<I...>
  - https://blog.csdn.net/dboyguan/article/details/51706357
-----
- �䳤����
  -	https://bygeek.cn/2018/09/28/variable-arguments-in-c-c/
-----
- ���ù���
  -	https://bygeek.cn/2018/09/05/what-is-calling-convention/
-----
- [std::decay](https://blog.csdn.net/luoshabugui/article/details/109853418)
  - #include<type_traits>
  - �����Ƴ������е�һЩ���ԣ��������á�������volatile
  - ������ T Ӧ����ֵ����ֵ�����鵽ָ�뼰������ָ����ʽת�����Ƴ� cv �޶�����������������Ϊ��Ա typedef type
-----
- std::bind  
  - �������ɵ��ö����������һ����а󶨡��󶨺�Ľ������ʹ�� std::function���б��棬���ӳٵ��õ��κ�������Ҫ��ʱ��
  - ���ɵ��ö����������һ��󶨳�һ���º�����
  - ����Ԫ����������Ϊ n�� n>1���ɵ��ö���ת��һԪ���ߣ� n-1��Ԫ�ɵ��ö��󣬼�ֻ�󶨲��ֲ�����  
-----
- std::enable_if
  - ֻ�е���һ��ģ�����Ϊ true ʱ��type ���ж��壬����ʹ�� type ������������	
  - `template <bool Cond, class T = void> struct enable_if;`
------
- [int (*a)[]; int (*a)(int)](https://www.cnblogs.com/xiaojingang/p/4451089.html)
  - ָ�����������ָ��
-------
- [�βΰ�](https://zh.cppreference.com/w/cpp/language/parameter_pack)
  - ģ���βΰ��ǽ���������ģ��ʵ�Σ������͡����ͻ�ģ�壩��ģ���βΡ�����ģ���βΰ��ǽ��������ຯ��ʵ�εĺ����βΡ�������һ���βΰ���ģ�屻�������ģ�塣
  - ����
	```C++
	template<class ...Us> void f(Us... pargs) {}
	template<class ...Ts> void g(Ts... args) {
		f(&args...);		// ��&args...�� �ǰ�չ��
					// ��&args�� ����ģʽ
	}
	g(1, 0.2, "a");		// Ts... args չ���� int E1, double E2, const char* E3
				// &args... չ���� &E1, &E2, &E3
				// Us... չ���� int* E1, double* E2, const char** E3    
	```
  - չ������  
    - ����ʵ���б�
    - �����ų�ʼ����
    - �����Ű�Χ�ĳ�ʼ����
    - ģ��ʵ���б�
    - �����β��б�
    - ģ���β��б�
    - ����˵�������Ա��ʼ�����б�
    - Lambda ����
    - sizeof... �����
    - ��̬�쳣˵��
    - ����˵����...
  - ����
    ```C++
	template<typename... Ts> void func(Ts... args){
		const int size = sizeof...(args) + 2;
		int res[size] = {1,args...,2};
		// ��Ϊ��ʼ�����б�֤˳������������ڰ�˳��԰���ÿ��Ԫ�ص��ú�����
		int dummy[sizeof...(Ts)] = { (std::cout << args, 0)... };
		std::cout<<std::endl;
		for (auto x : dummy) std::cout<<x<<' ';
	}

	int main() {
		func(1,2,3,4);
		return 0;
	}

	// 1234
	// 0 0 0 0 
	```