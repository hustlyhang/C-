#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    int n = 0, m = 0;

    cin>>n>>m;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
    }

    long long ret = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            //! ���������ȼ�С�ڱȽ������
            if ((nums[i] ^ nums[j]) > m) {
                ret++;
            }
        }
    }


    cout<<ret;

    return 0;
}