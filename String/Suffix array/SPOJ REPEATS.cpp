#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 51111;

char s[MAXN];
int c[MAXN], lg[MAXN], ht[MAXN][16], sa[MAXN], nsa[MAXN], rk[MAXN], nrk[MAXN][2];

inline int lcp(int i, int j) {
    if (i > j)
        swap(i, j);
    int k = lg[j - i];
    return min(ht[i + 1][k], ht[j - (1 << k) + 1][k]);
}

inline void work() {
    int n;
    scanf("%d", &n);
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; ++i) {
        scanf(" %c", &s[i]);
        ++c[s[i]];
    }
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
    for (int k = 1; k <= n; ++k)
        for (int i = 0; i + k < n; i += k)
            if (s[i] == s[i + k]) {
                int t = lcp(rk[i], rk[i + k]), j = i - k + t % k;
                ans = max(ans, t / k + 1 + (j >= 0 && lcp(rk[j], rk[j + k]) >= k - t % k));
            }
    printf("%d\n", ans);
}

int main() {
    for (int i = 2; i < MAXN; ++i)
        lg[i] = lg[i - 1] + (1 << lg[i - 1] + 1 == i);
    int t;
    scanf("%d", &t);
    while (t--)
        work();
    return 0;
}
