# Learn
- [ostringstream](https://blog.csdn.net/qq1987924/article/details/7671154)
  - sstream�ⶨ���������ࣺistringstream��ostringstream��stringstream���ֱ����������������롢������������������
  - ʹ��string�����������ַ����顣�������Ա��⻺���������Σ�ա����ң����������Ŀ���������ͱ��Զ��Ƶ���������ʹʹ���˲���ȷ�ĸ�ʽ����Ҳû��Σ�ա�
---
- [unique_ptr](https://blog.csdn.net/qq_19895789/article/details/116102762)
  - ����Ҫ֪��unique_ptr��shared_ptr���Զ���deleter��ʽ����һ����unique_ptrΪ���Ż�������Ҫ�ṩdeleter�����͡�
    ```
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
