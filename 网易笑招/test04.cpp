
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * �÷�������һ��������root��һ������·��path������һ�����飬��������������е�������·����ÿ������Ԫ�ص�ֵ����������нڵ��val
     * @param root TreeNode�� ��ʾһ�Ŷ������ĸ��ڵ�root������Ϊ��
     * @param path int����vector ����·��path������Ϊ��
     * @return int����vector
     */
    vector<TreeNode*> tmp;
    vector<vector<TreeNode*>> p;
    void hs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            p.push_back(tmp);
            return;
        }
        if (root->left) {
            tmp.push_back(root->left);
            hs(root->left);
            tmp.pop_back();
        }
        if (root->right) {
            tmp.push_back(root->right);
            hs(root->right);
            tmp.pop_back();
        }
    }
    bool suit(vector<TreeNode*>& tmp, vector<int> &path) {
        int i = 0, j = 0;
        while (i < tmp.size() && j < path.size()) {
            while (path[j] != tmp[i]->val) i++;
            int tmpi = i;
            while (i < tmp.size() && j < path.size() && path[j] == tmp[i]->val) {
                i++;
                j++;
            }
            if (j == path.size()) return true;
            else {
                i = tmpi + 1;
                j = 0;
            }
        }
        return false;
    }
    vector<int> solution(TreeNode *root, vector<int> &path) {
        // write code here
        hs(root);

        vector<int> ret;
        int l  = 0;
        for (auto x : p) {
            if (suit(x, path) && x.size() > l) {
                l = x.size();
                ret.clear();
                for (auto s : x) {
                    ret.push_back(s->val);
                }
            }
        }
        return ret;
    }
};