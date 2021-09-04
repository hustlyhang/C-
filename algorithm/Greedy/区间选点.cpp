/*
905. ����ѡ��

���� N �������� [ai,bi]��������������ѡ�����ٵĵ㣬ʹ��ÿ�����������ٰ���һ��ѡ���ĵ㡣

���ѡ��ĵ����С������

λ������˵��ϵĵ�Ҳ���������ڡ�


�����ʽ
��һ�а������� N����ʾ��������

������ N �У�ÿ�а����������� ai,bi����ʾһ������������˵㡣

�����ʽ
���һ����������ʾ����ĵ����С������

���ݷ�Χ
1��N��105,
109��ai��bi��109

����������
3
-1 1
2 4
3 5
���������
2
*/ 

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
struct Range{
    int l, r;
    bool operator < (const Range& w) const {
        return r < w.r;
    }
}range[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }

    sort(range, range + n);
    int res = 0, ed = -2e9;

    for (int i = 0; i < n; ++i) {
        // �տ�ʼʱ��ѡһ����˵㣬Ȼ�����ed�������һ�ε���˵�С�ڵ���ed��ô˵�����غϣ����ù�
        // ������ڵĻ�˵�����µ�һ�Σ���Ҫres++�����Ҹ���ed
        if (range[i].l > ed) {
            res++;
            ed = range[i].r;
        }
    }
    printf("%d\n", res);
    return 0;
}