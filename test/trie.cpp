#include <string>
#include <vector>
#include <iostream>
using namespace std;

class trie {
private: 
    trie* next[26] = {nullptr};
    bool is_string = false;
public:
    //? ���캯��
    trie(){
        is_string = false;
    };


    //? ����
    void insert(const string& s) {
        trie* root = this;
        for (auto c : s) {
            if (root->next[c - 'a'] == nullptr) {
                //? ˵����û�������ĸ
                root->next[c - 'a'] = new trie();
            }
            //? ����root
            root = root->next[c - 'a'];
        }
        root->is_string = true;
    }

    //? ����
    bool search(const string& s) {
        trie* root = this;
        for (auto c : s) {
            if (root->next[c -'a'] == nullptr) return false;
            else {
                root = root->next[c - 'a'];
            }
        }
        if (root->is_string == true) return true;
        else return false;
    }

    //? ����ǰ׺
    bool startsWith(const string& prefix)//
	{
		trie* root = this;
		for (const auto& p : prefix) {
			if (root->next[p - 'a'] == nullptr)return false;
			root = root->next[p - 'a'];
		}
		return true;
	}


};