#include <cstdio>
#include <cstring>

const int MAXN = 22222;

int a[MAXN], x[MAXN], c[MAXN], sa[MAXN], nsa[MAXN], rk[MAXN], nrk[MAXN][2], ht[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        memset(c, 0, sizeof c);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x[i]);
            ++c[a[i] = i ? x[i] - x[i - 1] + 100 : 200];
        }
        for (int i = 0; i < 222; ++i)
            c[i + 1] += c[i];
        for (int i = n - 1; i >= 0; --i)
            sa[--c[a[i]]] = i;
        rk[sa[0]] = 1;
        for (int i = 1; i < n; ++i)
            rk[sa[i]] = rk[sa[i - 1]] + (a[sa[i]] != a[sa[i - 1]]);
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
        memset(ht, 0, sizeof ht);
        for (int i = 0, k = 0; i < n; ++i)
            if (--rk[i]) {
                int j = sa[rk[i] - 1];
                while (i + k < n && j + k < n && a[i + k] == a[j + k])
                    ++k;
                ht[rk[i]] = k ? k-- : k;
            }
        int l = -1, r = n + 1;
        while (l + 1 < r) {
            bool b = false;
            int mid = l + r >> 1;
            for (int i = 1; i < n && !b; ++i)
                if (ht[i] + 1 >= mid) {
                    int mx = sa[i - 1], mn = sa[i - 1];
                    for (; i <= n && ht[i] + 1 >= mid; ++i) {
                        if (sa[i] > mx)
                            mx = sa[i];
                        if (sa[i] < mn)
                            mn = sa[i];
                    }
                    if (mx - mn >= mid)
                        b = true;
                }
            if (b)
                l = mid;
            else
                r = mid;
        }
        printf("%d\n", l > 4 ? l : 0);
    }
    return 0;
}
