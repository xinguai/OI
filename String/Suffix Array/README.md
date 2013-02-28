后缀数组的基本应用 By strongoier

这个东西，基本是按罗穗骞的论文来学的。

这里的笔记基本只给出模型建立和转化，特定模型的做法请参考论文。

后缀数组：字符串的后缀排序。

height数组：相邻后缀的最长公共前缀。

解题关键：后缀的有序性。

一、直接应用：后缀排序

【例1】[BZOJ 1031 字符加密](http://www.lydsy.com/JudgeOnline/problem.php?id=1031)

将原字符串复制一遍进行后缀排序，就得到了原串旋转后的各个串的大小关系，然后按顺序输出即可。

二、单个字符串

1、重复子串：二分与分组。

【例2】[POJ 1743 Musical Theme](http://poj.org/problem?id=1743)

要求加减常数后相同的乐段，那么第一步要将原数组作差得到新数组，当然第一位是要特殊处理的，然后就转化为了不可重叠最长重复子串问题，不过要注意在判断的时候新数组相同段长度加1才是原数组相同段长度。

【例3】[POJ 3261 Milk Patterns](http://poj.org/problem?id=3261)

至少出现k次可重叠最长重复子串问题，由于输入的初始值较大，第一步可以通过sort完成后缀数组的初始化过程。

2、子串个数

【例4】SPOJ [DISUBSTR](http://www.spoj.com/problems/DISUBSTR/)/[SUBST1](http://www.spoj.com/problems/SUBST1/)

后缀排序后从小到大依次处理，发现和第i个公共前缀最长的必然是第i - 1个，故有height[i]个前缀已被之前计算过，那么它的贡献值为n - sa[i] - height[i]，求和即可。

3、回文子串：倒序复制，枚举中心。

【例5】[Ural 1297 Palindrome](http://acm.timus.ru/problem.aspx?space=1&num=1297)

最长回文子串问题，注意求i和j的最长公共前缀时比较i和j的大小，且实际上是RMQ(i + 1, j)。

4、连续重复子串：枚举与调整弥补。

【例6】[SPOJ REPEATS](http://www.spoj.com/problems/REPEATS/)

重复次数最多连续重复子串问题，枚举重复子串长度L，考虑至少重复两次的情况，枚举s[0], s[L], s[2 * L], ..., s[N / L * L]，当其中相邻两个（s[i]和s[i + L]）相等时，我们也就找到了可能连续重复的位置i。虽然我们不知道i是子串的哪一位，但是通过求LCP(i, i + L) / L可以得到重复次数的下限。同时我们可以发现除下来还有一个余数，只有当子串的起始位置向前调整L - 余数时，重复次数才会增加1，所以处理完这种情况就可以得到此时的答案。

【例7】[POJ 3693 Maximum repetition substring](http://poj.org/problem?id=3693)

和上一个题基本一样，但它要求输出字典序最小的方案，此时就不能只考虑次数了，而要依次将位置的前移进行枚举，将每次得到的答案进行字典序比较。

三、两个字符串：首尾相接

1、公共子串

【例8】[POJ 2774 Long Long Message](http://poj.org/problem?id=2774)

最长公共子串，相接后，我们发现，只有当起点在a串的后缀和起点在b串的后缀排名相邻时height才有意义，因为隔的越远height是只可能越小的，故直接扫一遍height数组即可。

2、子串个数

【例9】[POJ 3415 Common Substrings](http://poj.org/problem?id=3415)

求长度不小于k的公共子串的个数，相接后，如果起点分别在两串的两个后缀的最长公共前缀lcp >= k那么我们就要把lcp - k + 1累加入答案。按后缀大小顺序处理时，我们发现，一个后缀与前面各后缀的最长公共前缀是递减的，也就是说，当一个height较小时，前面再大的height都是没有意义的，所以我们要维护一个单调栈，使得每个height依次入栈且栈中元素递增，弹栈时注意累加对应项的个数，并对这一次的答案进行计算，方便计算答案，实现时要把细节处理好。这样，我们用每一个A串后缀与比它小的B串后缀答案加上每一个B串后缀与比它小的A串后缀答案就行了，注意答案要使用long long。

    #include <cmath>
    #include <cstdio>
    
    const double EPS = 1e-12;
    const int MAXN = 11, MAXM = 111111;
    
    struct state {
        double p;
        int bit, sum;
    
        inline state(double _p = 0, int _bit = 0, int _sum = 0) :
            p(_p), bit(_bit), sum(_sum) {}
    
        inline bool operator < (const state &x) {
            return fabs(p - x.p) < EPS && sum < x.sum || p < x.p;
        }
    };
    
    double a[MAXN][MAXM];
    int s[MAXM];
    priority_queue<state> f[2];
    
    int main() {
        //freopen("kobe.in", "r", stdin);
        //freopen("kobe.out", "w", stdout);
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i)
            scanf("%d", &s[i]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                scanf("%lf", &a[i][j]);
        f[1].push(state(1, 0, 0));
        for (int i = 0; i < m; ++i) {
            int p = i & 1, q = p ^ 1;
            for (int c = 0; !f[q].empty(); ++c, f[q].pop())
                for (int k = 0; c < n && k < n; ++k)
                    if (!((f[q].top().bit >> k) & 1))
                        f[p].push(state(f[q].top().p * a[k][i], f[q].top().bit ^ (1 << k), f[q].top().sum + s[i]));
        }
        printf("%.11lf\n%d\n", f[(m - 1) & 1][(1 << n) - 1], g[(m - 1) & 1][(1 << n) - 1]);
        return 0;
    }
