#include <queue>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int fst = 0, sec = 0, thr = 0; // �ֱ��¼������������ǰ�����پ���
        vector<int> ob(4, 0); // ��¼ ��������������λ��֮��������ϰ�λ��
        int cur = 2; // ��¼���ܵ�ǰ����
        int ret = 0;
        /*
          ÿһ����������ѡ��ob����Զ���谭�� ͬʱ���ܵ�ǰλ�ø��������谭� ����֮�����ob
        */
        
        //����map����������ϰ�
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        for (int i = 0; i < obstacles.size(); ++i) {
            if (obstacles[i] != 0){
                m[obstacles[i]].push(i);
            }
        }
        for (int i = 1; i < 4; ++i) {
            if (m.count(i) == 0) {
                if(i == 2) return 0;
                else return 1;
            }
        }
        
        
        int i = 0; //��¼���ܵ�ǰ��λ��
        while (i < obstacles.size() - 1) {
            // ����ѡ������
            
            int tmp = 0, dis = 0;
            for (auto d : m) {
                int td = 0;
                if (d.second.empty()) {
                    td = obstacles.size() - i;
                    //cout<<"is empty"<<endl;
                }
                else{
                    td = d.second.top() - i;
                }
                
                if (td > dis && obstacles[i] != d.first) {
                    dis = td;
                    tmp = d.first;
                }
            }
            
            if (tmp != cur) {
                ret++;
                cur = tmp;
            }
            // ����m��ֵ��
            //cout<<"i =" <<i<<endl;
            
            // �������ܵ�λ��
            i += (dis - 1);
            for (auto &d : m) {
                while (!d.second.empty() && d.second.top() <= i) {
                    //cout<<d.first<<"top ="<<d.second.top()<<endl;
                    d.second.pop();
                    //cout<<"pop"<<endl;
                }
            }
            //cout<<"i =" <<i<<endl;
        }
        return ret;
    }
};
//! dp
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(obstacles.size(), vector<int>(3, 0));
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 1;
        for (int i = 1; i < obstacles.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                // �ֱ���ÿһ��λ��
                // �����ǰλ�����ϰ�,���ɴ��Ϊ���ֵ
                int m = 10000000;
                if (obstacles[i] == j + 1) {dp[i][j] = 10000000;}
                else {
                    // ��ǰλ��û���ϰ�����ô��ȡ����ǰ�����С��������
                    
                    for (int k = 0; k < 3; ++k) {
                        if (k == j) m = min(dp[i - 1][k], m);
                        else {
                            // �ж��ܲ�����
                            if (obstacles[i - 1] != j + 1) m = min(dp[i - 1][k] + 1, m);
                        }
                    } 
                }
                
                dp[i][j] = m;
                //cout<<"dp["<<i<<']'<<'['<<j<<"] ="<<dp[i][j]<<endl;
                
            }
        }
        return min({dp[obstacles.size()-1][0],dp[obstacles.size()-1][1],dp[obstacles.size()-1][2]});
    }
};