#include <cstdio>
#include <cstring>

typedef long long LL;

const int MAXN = 111, MAXR = 55;

int a[MAXN];
LL r[MAXR][MAXN][MAXN], p[MAXN], q[MAXN];

inline void checkmin(LL &x, LL y) {
    if (y < x)
        x = y;
}

int main() {
    int n, c;
    LL t, ans = 0;
    scanf("%d%lld", &n, &t);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            r[0][i][j] = t + 1;
    for (int i = 1, x, y, z; i <= n; ++i) {
        scanf("%d%d", &x, &y);
        for (int j = 1; j <= x; ++j)
            scanf("%d", &a[j]);
        for (int j = 1; j <= x; ++j) {
            scanf("%d", &z);
            checkmin(r[0][i][a[j]], y + z);
        }
    }
    for (c = 1; c < MAXR; ++c) {
        LL u = t + 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                r[c][i][j] = t + 1;
                for (int k = 1; k <= n; ++k)
                    checkmin(r[c][i][j], r[c - 1][i][k] + r[c - 1][k][j]);
                checkmin(u, r[c][i][j]);
            }
        if (u > t)
            break;
    }
    for (--c; c >= 0; --c) {
        LL u = t + 1;
        for (int i = 1; i <= n; ++i) {
            q[i] = t + 1;
            for (int j = 1; j <= n; ++j)
                checkmin(q[i], p[j] + r[c][j][i]);
            checkmin(u, q[i]);
        }
        if (u <= t) {
            ans += 1LL << c;
            memcpy(p, q, sizeof q);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
