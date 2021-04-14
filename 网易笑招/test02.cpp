#include <vector>
#include <algorithm>
#include <algorithm>
using namespace std;


class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ����������֮��ľ��룬���ص�������������ĳ��еı�ţ�����޷����⼸������֮��ѡ�����������ĳ��У���ô����-1��
     * @param distancePairs int����vector<vector<>> ��ά���飬ÿ�������鶼������������ɵģ�ǰ��������������еı�ţ����������������������еľ���
     * @param CityNum int���� ���е�������ÿ�����еı�ŷֱ���0~CityNum-1
     * @return int����
     */
    long long dij(vector<vector<int>>& distance, vector<bool>& isV, vector<int>& dis, int start) {
        int n = isV.size();
        for (int i = 0; i < n; ++i) {
            int m = -1, mm = INT_MAX;
            for (int j = 0; j < n; ++j) {
                if (isV[j] == false && dis[j] < mm) {
                    mm = dis[j];
                    m = j;
                }
            }
            if (m == -1) return -1;
            else {
                isV[m] = true;
            }
            for (int k = 0; k < n; ++k) {
                if (isV[k] == false && distance[m][k] != INT_MAX && dis[m] + distance[m][k] < dis[k]) {
                    dis[k] = dis[m] + distance[m][k];
                }
            }
        }
        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            ret+=dis[i];
        }
        return ret;
    }

    int GetBestWarehouseLocate(vector<vector<int> >& distancePairs, int CityNum) {
        // write code here
        vector<vector<int>> distance(CityNum, vector<int>(CityNum,INT_MAX));
        for (int i = 0; i < distancePairs.size(); ++i) {
            distance[distancePairs[i][0]][distancePairs[i][1]] = distancePairs[i][2];
            distance[distancePairs[i][1]][distancePairs[i][0]] = distancePairs[i][2];
        }

        vector<bool> isV(CityNum, false);
        vector<int> dis(CityNum, INT_MAX);
        
        long long ret = INT_MAX;

        int rr = 0;
        for (int i = 0; i < CityNum; ++i) {
            dis.assign(CityNum, INT_MAX);
            isV.assign(CityNum, false);
            dis[i] = 0;
            long long e = dij(distance, isV, dis, i);
            if (e == -1) continue;
            if (e < ret) {
                ret = e;
                rr = i;
            }
        }
        return (int)ret;
    }
};


int main() {
    vector<vector<int>> distancePairs{{0, 1, 3}, {1, 2, 2}};
    int city = 3;
    Solution s;
    s.GetBestWarehouseLocate(distancePairs,city);

}