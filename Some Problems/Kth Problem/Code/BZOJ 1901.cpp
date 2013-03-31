#include <cstdio>

const int MAXC = 1000000000, MAXN = 11111, MAXT = MAXN * 900;

int n, tot, a[MAXN], root[MAXN], u[MAXN], v[MAXN], l[MAXT], r[MAXT], s[MAXT];

void insert(int &x, int f, int t, int v, int d) {
    if (!x)
        x = ++tot;
    s[x] += d;
    if (f == t)
        return;
    int mid = f + t >> 1;
    if (v <= mid)
        insert(l[x], f, mid, v, d);
    else
        insert(r[x], mid + 1, t, v, d);
}

inline void update(int x, int v, int d) {
    for (; x <= n; x += x & -x)
        insert(root[x], 0, MAXC, v, d);
}

inline int getsum(int x) {
    int ret = 0;
    for (; x; x -= x & -x)
        ret += s[l[u[x]]];
    return ret;
}

inline void init(int x) {
    for (; x; x -= x & -x) {
        u[x] = root[x];
        v[x] = 0;
    }
}

inline void turnl(int x, int cnt) {
    for (; x; x -= x & -x)
        if (v[x] != cnt) {
            u[x] = l[u[x]];
            v[x] = cnt;
        }
}

inline void turnr(int x, int cnt) {
    for (; x; x -= x & -x)
        if (v[x] != cnt) {
            u[x] = r[u[x]];
            v[x] = cnt;
        }
}

int main() {
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        update(i, a[i], 1);
    }
    while (m--) {
        char op;
        int i, j, k;
        scanf(" %c%d%d", &op, &i, &j);
        if (op == 'C') {
            update(i, a[i], -1);
            update(i, a[i] = j, 1);
        }
        else {
            scanf("%d", &k);
            init(j);
            init(i - 1);
            int f = 0, t = MAXC, cnt = 0;
            while (f < t) {
                ++cnt;
                int mid = f + t >> 1, cur = getsum(j) - getsum(i - 1);
                if (k <= cur) {
                    t = mid;
                    turnl(j, cnt);
                    turnl(i - 1, cnt);
                }
                else {
                    f = mid + 1;
                    k -= cur;
                    turnr(j, cnt);
                    turnr(i - 1, cnt);
                }
            }
            printf("%d\n", f);
        }
    }
    return 0;
}
