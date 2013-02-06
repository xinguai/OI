#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 22222;

int a[MAXN], c[MAXN], ht[MAXN], sa[MAXN], nsa[MAXN], rk[MAXN], nrk[MAXN][2];
pair<int, int> d[MAXN];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        d[i] = make_pair(a[i], i);
    }
    sort(d, d + n);
    for (int i = 0; i < n; ++i) {
        sa[i] = d[i].second;
        rk[sa[i]] = i ? rk[sa[i - 1]] + (d[i].first != d[i - 1].first) : 1;
    }
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
            while (i + k < n && j + k < n && a[i + k] == a[j + k])
                ++k;
            ht[rk[i]] = k ? k-- : k;
        }
    int l = 0, r = n + 1;
    while (l + 1 < r) {
        bool b = false;
        int mid = l + r >> 1;
        for (int i = 1; i < n && !b; ++i)
            if (ht[i] >= mid) {
                int cnt = 2;
                for (++i; i < n && ht[i] >= mid; ++i)
                    ++cnt;
                if (cnt >= m)
                    b = true;
            }
        if (b)
            l = mid;
        else
            r = mid;
    }
    printf("%d\n", l);
    return 0;
}
