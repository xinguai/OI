#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 111111;

char s[MAXN], res[MAXN], tmp[MAXN];
int cs, c[MAXN], lg[MAXN], ht[MAXN][17], sa[MAXN], nsa[MAXN], rk[MAXN], nrk[MAXN][2];

inline int lcp(int i, int j) {
    if (i > j)
        swap(i, j);
    int k = lg[j - i];
    return min(ht[i + 1][k], ht[j - (1 << k) + 1][k]);
}

inline void work() {
    int n = strlen(s);
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; ++i)
        ++c[s[i]];
    for (int i = 0; i < 222; ++i)
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
    for (int k = 1; 1 << k <= n; ++k)
        for (int i = 0; i + (1 << k) <= n; ++i)
            ht[i][k] = min(ht[i][k - 1], ht[i + (1 << k - 1)][k - 1]);
    int ans = 1;
    res[0] = s[0];
    for (int i = 1; i < n; ++i)
        if (s[i] < res[0])
            res[0] = s[i];
    res[1] = 0;
    for (int k = 1; k <= n; ++k)
        for (int i = 0; i + k < n; i += k)
            for (int j = 0; j < k && i - j >= 0 && s[i - j] == s[i - j + k]; ++j) {
                int t = lcp(rk[i - j], rk[i - j + k]) / k + 1;
                if (t > ans) {
                    ans = t;
                    strncpy(res, s + i - j, t * k);
                    res[t * k] = 0;
                }
                else if (t == ans) {
                    strncpy(tmp, s + i - j, t * k);
                    tmp[t * k] = 0;
                    if (!~strcmp(tmp, res))
                        strcpy(res, tmp);
                }
            }
    printf("Case %d: %s\n", ++cs, res);
}

int main() {
    for (int i = 2; i < MAXN; ++i)
        lg[i] = lg[i - 1] + (1 << lg[i - 1] + 1 == i);
    while (gets(s) && strcmp(s, "#"))
        work();
    return 0;
}
