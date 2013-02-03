#include <cstdio>
#include <cstring>

const int MAXN = 55555;

char s[MAXN];
int c[MAXN], ht[MAXN], sa[MAXN], nsa[MAXN], rk[MAXN], nrk[MAXN][2];

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        gets(s);
        int n = strlen(s);
        memset(c, 0, sizeof c);
        for (int i = 0; i < n; ++i)
            ++c[s[i]];
        for (int i = 0; i < 333; ++i)
            c[i + 1] += c[i];
        for (int i = n - 1; i >= 0; --i)
            sa[--c[s[i]]] = i;
        rk[sa[0]] = 1;
        for (int i = 1; i < n; ++i)
            rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
        for (int k = 1; k < n; k <<= 1) {
            memset(c, 0, sizeof c);
            for (int i = 0; i < n; ++i) {
                nrk[i][0] = rk[i];
                ++c[nrk[i][1] = i + k < n ? rk[i + k] : 0];
            }
            for (int i = 0; i < n; ++i)
                c[i + 1] += c[i];
            for (int i = n - 1; i >= 0; --i)
                nsa[--c[nrk[i][1]]] = i;
            memset(c, 0, sizeof c);
            for (int i = 0; i < n; ++i)
                ++c[nrk[i][0]];
            for (int i = 0; i < n; ++i)
                c[i + 1] += c[i];
            for (int i = n - 1; i >= 0; --i)
                sa[--c[nrk[nsa[i]][0]]] = nsa[i];
            rk[sa[0]] = 1;
            for (int i = 1; i < n; ++i)
                rk[sa[i]] = rk[sa[i - 1]] + (nrk[sa[i]][0] != nrk[sa[i - 1]][0] || nrk[sa[i]][1] != nrk[sa[i - 1]][1]);
        }
        for (int i = 0, k = 0; i < n; ++i)
            if (--rk[i]) {
                int j = sa[rk[i] - 1];
                while (i + k < n && j + k < n && s[i + k] == s[j + k])
                    ++k;
                ht[rk[i]] = k ? k-- : k;
            }
        int ans = n - sa[0];
        for (int i = 1; i < n; ++i)
            ans += n - sa[i] - ht[i];
        printf("%d\n", ans);
    }
    return 0;
}
