#include <cstdio>
#include <cstring>

const double INF = -1e10;
const int MAXN = 111;

double q[MAXN][MAXN], r[MAXN][MAXN], w[MAXN];

inline void checkmax(double &x, double y) {
    if (y > x)
        x = y;
}

int main() {
    int n, m, v;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &w[i]);
        for (int j = 1; j <= n; ++j)
            q[i][j] = INF;
        q[i][i] = 0;
    }
    double u, ans = 0;
    scanf("%d%lf", &v, &u);
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        q[x][y] = w[y] * u;
    }
    for (int c = 0; c < 25; ++c, u *= u) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                r[i][j] = INF;
                for (int k = 1; k <= n; ++k)
                    checkmax(r[i][j], q[i][k] + q[k][j] * u);
            }
        memcpy(q, r, sizeof r);
    }
    for (int i = 1; i <= n; ++i)
        checkmax(ans, q[v][i] + w[v]);
    printf("%.1lf\n", ans);
    return 0;
}
