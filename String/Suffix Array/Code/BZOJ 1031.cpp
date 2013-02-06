#include <cstdio>
#include <cstring>

const int MAXN = 222222;

char s[MAXN];
int c[MAXN], sa[MAXN], nsa[MAXN], rk[MAXN], nrk[MAXN][2];

int main() {
    gets(s);
    int n = strlen(s), m = n << 1;
    for (int i = 0; i < n; ++i) {
        c[s[i]] += 2;
        s[i + n] = s[i];
    }
    for (int i = 0; i < 333; ++i)
        c[i + 1] += c[i];
    for (int i = m - 1; i >= 0; --i)
        sa[--c[s[i]]] = i;
    rk[sa[0]] = 1;
    for (int i = 1; i < m; ++i)
        rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
    for (int k = 1; k < n; k <<= 1) {
        memset(c, 0, sizeof c);
        for (int i = 0; i < m; ++i) {
            nrk[i][0] = rk[i];
            ++c[nrk[i][1] = i + k < m ? rk[i + k] : 0];
        }
        for (int i = 0; i < m; ++i)
            c[i + 1] += c[i];
        for (int i = m - 1; i >= 0; --i)
            nsa[--c[nrk[i][1]]] = i;
        memset(c, 0, sizeof c);
        for (int i = 0; i < m; ++i)
            ++c[nrk[i][0]];
        for (int i = 0; i < m; ++i)
            c[i + 1] += c[i];
        for (int i = m - 1; i >= 0; --i)
            sa[--c[nrk[nsa[i]][0]]] = nsa[i];
        rk[sa[0]] = 1;
        for (int i = 1; i < m; ++i)
            rk[sa[i]] = rk[sa[i - 1]] + (nrk[sa[i]][0] != nrk[sa[i - 1]][0] || nrk[sa[i]][1] != nrk[sa[i - 1]][1]);
    }
    int cnt = 0;
    for (int i = 0; i < m && cnt < n; ++i)
        if (sa[i] < n) {
            ++cnt;
            putchar(s[sa[i] + n - 1]);
        }
    putchar('\n');
    return 0;
}
