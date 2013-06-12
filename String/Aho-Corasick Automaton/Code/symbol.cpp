#include <cstdio>

const int MAXL = 11111111, MAXM = 111111;

bool v[MAXL];
char text[MAXL];
int nxt[MAXL][4], p[MAXL], q[MAXL], f[MAXL], d[MAXL], id[MAXM], no[222];

int main() {
    freopen("symbol.in", "r", stdin);
    freopen("symbol.out", "w", stdout);
    int n, m, tot = 0, r = -1;
    scanf("%d%d%s ", &n, &m, text);
    no['E'] = 0, no['S'] = 1, no['W'] = 2, no['N'] = 3;
    for (int i = 0; i < m; ++i) {
        int &x = id[i];
        for (char c; (c = getchar()) != '\n' && c != EOF; x = nxt[x][no[c]])
            if (!nxt[x][no[c]])
                nxt[x][no[c]] = ++tot;
    }
    for (int k = 0; k < 4; ++k)
        if (nxt[0][k])
            q[++r] = nxt[0][k];
    for (int l = 0; l <= r; ++l)
        for (int k = 0; k < 4; ++k)
            if (nxt[q[l]][k]) {
                q[++r] = nxt[q[l]][k];
                int x = p[q[l]];
                for (; x && !nxt[x][k]; x = p[x]);
                p[q[r]] = nxt[x][k];
            }
    for (int i = 0, x = 0; i < n; ++i) {
        for (; x && !nxt[x][no[text[i]]]; x = p[x]);
        for (int t = x = nxt[x][no[text[i]]]; t && !v[t]; t = p[t])
            v[t] = true;
    }
    r = q[0] = 0;
    for (int l = 0; l <= r; ++l) {
        if (v[q[l]])
            f[q[l]] = d[q[l]];
        for (int k = 0; k < 4; ++k)
            if (nxt[q[l]][k]) {
                d[q[++r] = nxt[q[l]][k]] = d[q[l]] + 1;
                f[q[r]] = f[q[l]];
            }
    }
    for (int i = 0; i < m; ++i)
        printf("%d\n", f[id[i]]);
    return 0;
}
