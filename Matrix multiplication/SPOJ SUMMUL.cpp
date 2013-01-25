#include <cstdio>
#include <cstring>

const int MOD = 1000000007;

long long p[2], q[2][2], r[2][2];

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        p[0] = q[0][0] = q[0][1] = q[1][0] = 1;
        q[1][1] = p[1] = 2;
        for (int c = n - 1; c; c >>= 1) {
            if (c & 1) {
                for (int i = 0; i < 2; ++i) {
                    r[0][i] = 0;
                    for (int j = 0; j < 2; ++j)
                        r[0][i] += q[i][j] * p[j];
                    r[0][i] %= MOD;
                }
                memcpy(p, r[0], sizeof r[0]);
            }
            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 2; ++j) {
                    r[i][j] = 0;
                    for (int k = 0; k < 2; ++k)
                        r[i][j] += q[i][k] * q[k][j];
                    r[i][j] %= MOD;
                }
            memcpy(q, r, sizeof r);
        }
        printf("%d\n", (p[0] - n + MOD) % MOD);
    }
    return 0;
}
