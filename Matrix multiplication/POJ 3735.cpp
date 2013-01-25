#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 111;

long long p[MAXN], q[MAXN][MAXN], r[MAXN][MAXN];

int main() {
    int n, m, c;
    while (scanf("%d%d%d", &n, &m, &c) && n) {
        memset(q, 0, sizeof q);
        for (int i = 0; i <= n; ++i)
            q[i][i] = 1;
        while (c--) {
            char op;
            int i, j;
            scanf(" %c%d", &op, &i);
            if (op == 'g')
                ++q[i][0];
            else if (op == 'e')
                for (int k = 0; k <= n; ++k)
                    q[i][k] = 0;
            else {
                scanf("%d", &j);
                for (int k = 0; k <= n; ++k)
                    swap(q[i][k], q[j][k]);
            }
        }
        memset(p, 0, sizeof p);
        p[0] = 1;
        for (; m; m >>= 1) {
            if (m & 1) {
                for (int i = 0; i <= n; ++i) {
                    r[0][i] = 0;
                    for (int j = 0; j <= n; ++j)
                        r[0][i] += q[i][j] * p[j];
                }
                memcpy(p, r[0], sizeof r[0]);
            }
            memset(r, 0, sizeof r);
            for (int i = 0; i <= n; ++i)
                for (int k = 0; k <= n; ++k)
                    if (q[i][k])
                        for (int j = 0; j <= n; ++j)
                            r[i][j] += q[i][k] * q[k][j];
            memcpy(q, r, sizeof r);
        }
        for (int i = 1; i < n; ++i)
            printf("%I64d ", p[i]);
        printf("%I64d\n", p[n]);
    }
    return 0;
}
