#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class test{
  public:
    int numSquares(int n){
        vector<int> list;
        // �൱������ô�����Ʒ��
        for (int i = 1; i * i <= n; ++i) {
            list.push_back(i * i);
        }

        // ��ȫ�������⣬
        vector<vector<int>> dp(list.size(), vector<int>(n + 1, INT_MAX/2));

        // �ȿ��ǵ�һ����Ʒ����ʼ��
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = i;
        }
        // ����ÿһ����Ʒ
        for (int i = 1; i < list.size(); ++i) {
            for (int j = list[i]; j <= n; ++j) {
                // ֻ�е���ǰ��������������Ʒ����ʱ���ܷŽ�ȥ
                
                dp[i][j] = min(dp[i - 1][j], dp[i][j - list[i]] + 1);
                
            }
        }
        int ret = INT_MAX;
        for (int i = 0; i < list.size(); ++i) {
            ret = min(ret, dp[i][n]);
        }
        return ret;


    }



}; 

int main(){
    test t;
    cout<<t.numSquares(5);

    return 0;
}