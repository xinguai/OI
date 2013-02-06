#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 2222;

char s[MAXN];
int c[MAXN], lg[MAXN], ht[MAXN][12], sa[MAXN], nsa[MAXN], rk[MAXN], nrk[MAXN][2];

inline int calc(int i, int j) {
    if (i > j)
        swap(i, j);
    int k = lg[j - i];
    return min(ht[i + 1][k], ht[j - (1 << k) + 1][k]);
}

int main() {
    gets(s);
    int m = strlen(s), n = (m << 1) + 1;
    ++c[s[m] = '#'];
    for (int i = 0; i < m; ++i) {
        c[s[i]] += 2;
        s[m + m - i] = s[i];
    }
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
            ht[rk[i]][0] = k ? k-- : k;
        }
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i - 1] + (1 << lg[i - 1] + 1 == i);
    for (int k = 1; 1 << k <= n; ++k)
        for (int i = 0; i + (1 << k) <= n; ++i)
            ht[i][k] = min(ht[i][k - 1], ht[i + (1 << k - 1)][k - 1]);
    int ans = 0, bg;
    for (int i = 0; i < m; ++i) {
        int len = calc(rk[i + 1], rk[m + m - i + 1]), t = (len << 1) + 1;
        if (t > ans) {
            ans = t;
            bg = i - len;
        }
        else if (t == ans && i - len < bg)
            bg = i - len;
    }
    for (int i = 1; i < m; ++i) {
        int len = calc(rk[i], rk[m + m - i + 1]), t = len << 1;
        if (t > ans) {
            ans = t;
            bg = i - len;
        }
        else if (t == ans && i - len < bg)
            bg = i - len;
    }
    for (int i = 0; i < ans; ++i)
        putchar(s[bg + i]);
    putchar('\n');
    return 0;
}
