/*
906. �������

���� N �������� [ai,bi]�����㽫��Щ����ֳ������飬ʹ��ÿ���ڲ�����������֮�䣨�����˵㣩û�н�������ʹ������������С��

�����С������

�����ʽ
��һ�а������� N����ʾ��������

������ N �У�ÿ�а����������� ai,bi����ʾһ������������˵㡣

�����ʽ
���һ����������ʾ��С������

���ݷ�Χ
1��N��105,
?109��ai��bi��109
����������
3
-1 1
2 4
3 5
���������
2
*/

// ���������䰴����˵��С��������
// ��ǰ������ÿ�����䣬�ж��ܷ���ŵ�ĳ�����е�����l[i] > max_r
// ����������������飬�Ϳ����飬����Ž�ȥ
// �����������飬����Ž�ȥ�������µ�ǰ��max_r

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n;
struct Range{
    int l, r;
    bool operator < (const Range& w)const {
        return l < w.l;
    }
}range[N];


int main() {
    cin >>n;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin>>l>>r;
        range[i] = {l, r};
    }

    sort(range, range + n);
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i = 0; i < n; ++i) {
        auto r = range[i];
        if (q.empty() || q.top() >= r.l) q.push(r.r);// ˵��û�п������ɵ�ǰ����ķ��飬��Ҫ�¿�һ������
        else {
            // ���¶Ѷ�
            q.pop();
            q.push(r.r);
        }
    }
    // �ѵĴ�С�ʹ������ж��ٸ�����
    printf("%d\n", q.size());
    return 0;
}
