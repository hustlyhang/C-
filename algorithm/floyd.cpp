/*
��ʵ�Ƕ�̬�滮
���µ�ʱ����
d[i, j] = min(d[i][j], d[i][k] + d[k][j])
- todo
*/


/*
�����ʽ
��һ�а����������� n,m,k��

������ m �У�ÿ�а����������� x,y,z����ʾ����һ���ӵ� x ���� y ������ߣ��߳�Ϊ z��

������ k �У�ÿ�а����������� x,y����ʾѯ�ʵ� x ���� y ����̾��롣

�����ʽ
�� k �У�ÿ�����һ����������ʾѯ�ʵĽ������ѯ������䲻����·��������� impossible��

���ݷ�Χ
1��n��200,
1��k��n2
1��m��20000,
ͼ���漰�߳�����ֵ�������� 10000��

*/
// ���Դ���Ȩ�ߣ����ǲ����и�Ȩ��

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N];

void floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}


int main() {
    scanf("%d%d%d", &n, &m, &Q);

    // ��ʼ���������Ի�
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    // �����ر�
    while (m --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);
    }

    floyd();

    while (Q --) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (d[a][b] > INF / 2) printf("impasible\n");
        else printf("%d\n", d[a][b]);
    }
    return 0;
}