AC�Զ��� By strongoier

һ����ģʽ��ƥ��

�����Ƽ�http://www.cnblogs.com/Booble/archive/2010/12/05/1897121.html��

����1��HDOJ 2222 Keywords Search

��Ŀ���⣺

����N(1 <= N <= 10000)��Сд��ĸģʽ����ÿ�����Ȳ�����50����һ���ı��������Ȳ�����1000000�������ı��������˶��ٸ�ģʽ����

�㷨������

����AC�Զ�����ע��ƥ��Ĺ����з����ҵ�ģʽ��ʱҪ���������к�׺����������failһֱ������Ҳȫ����𰸣�ͬʱ���ϱ�ǣ��Ա�֤ÿ������ֻͳ��һ�Ρ�ʱ�临�Ӷ�O(L)��

����2��SPOJ JZPGYZ

��Ŀ���⣺

����N(1 <= N <= 10000)���ı������ܳ�������100000����Q(1 <= Q <= 60000)��ģʽ�����ܳ�������360000������ÿ��ģʽ���ڶ��ٸ��ı�������ֹ���

�㷨������

����һ�����ƣ�����AC�Զ�����ע��ƥ��Ĺ����з����ҵ�ģʽ��ʱҪ�����������к�׺����������failһֱ�������Ĵ𰸣�ͬʱ���ϱ�ǣ��Ա�֤ÿ������ֻ����һ�Ρ�
ע��char�ַ���Ϊ128��ʱ�临�Ӷ�O(L)��

����3��BZOJ 2754 �������ϵĵ���

��Ŀ���⣺

����N(1 <= N <= 20000)���˵��մ�����������M(1 <= M <= 50000)�ε�����ֻҪ��Ĵ���ĳ�����մ����������Ӵ�������˾ͻᱻ�㵽����ÿ�λ�㵽���ٸ��˺�ÿ���˻ᱻ�㵽���Ρ�

�㷨������

����ֱ��ʹ��AC�Զ���ƥ��Ϳ����ˣ������ڴ���10000���ڵ����֣����ֱ�ӱ���ö��10000���Ӷ��ǽ����*10000�ᱬʱ�ա�

����������ֻҪ�������õľ����ˣ���map���Ժܺõ�ʵ�֣������Ļ���iteratorҲû���⡣ʱ�临�Ӷ�O(LlogC)��

����4��symbol ��������

��Ŀ���⣺

��������ΪN(1 <= N <= 10^7)���ı�����M(1 <= M <= 10^5)��ģʽ����ÿ�����Ȳ�����100������ÿ��ģʽ����ǰ׺���ı����ϵ��ƥ�䳤�ȡ�

�㷨������

��ģʽ������AC�Զ����󣬽��ı�����ƥ�䵽�����н�㼰���׺�����ϱ�ǣ������AC�Զ�����BFSһ�������ÿ������β��·�����ı���ƥ����ǰ׺�����ֻҪ���ÿ��ģʽ���Ľ������Ĵ𰸼��ɡ�ʱ�临�Ӷ�O(L)��

��������Fail��

������BZOJ 2434 ����Ĵ��ֻ�

��Ŀ���⣺

����һ�����ֻ��Ĳ������У��ܳ�������10^5�����ڲ�β��һСд��ĸ��ɾ�����һ��ĸ���۲��䣬��ӡ��ǰ�С���֤��ӡ������N(1 <= N <= 10^5)�Ρ�����M(1 <= M <= 10^5)��ѯ��(x, y)����ѯ��x�δ�ӡ�Ĵ��ڵ�y�δ�ӡ�Ĵ��г����˼��Ρ�

�㷨������

���Ȱ���Щ��ȫ���������ǲ���ʵ�ģ���ô�����뵽ʹ��Trie�����洢����������AC�Զ�����

���ǰ�failָ��ȫ�������γɵ�һ������Ϊfail����

����ѯ��(x, y)��ʵ�ʾ�����fail���ϣ�����x��ĩ���Ϊ���������ϣ��ж��ٸ������AC�Զ�����root -> y��ĩ����·���ϡ�

��ô�����ٴδ����������У��Ϳ��Ժܷ����ģ���ÿһ��root -> yĩ���·���ϵĽ�㶼���Ϊ1�����Σ�����������Ҫ������Ӧ��x��ѯ�ʡ�

����Ҫ�����ǲ�ѯһ�������ĺͣ����Ǿ����DFS�� + ��״����ά�����ڴ˲���׸������ô�����ǰ�������y��Ӧ��x�𰸶������������ɡ�

ʱ�临�Ӷ�O(L + MlogL)��

������϶�̬�滮

��һ��ȫ������

����1��POJ 3691 DNA repair

��Ŀ���⣺

����N(1 <= N <= 50)�����Ȳ�����20���²�DNAƬ�Σ�����һ������ΪM��������1000����DNAƬ�Σ�Ҫ���޸����ٵ��ַ�ʹ�ø�DNAƬ�β������κ��²�DNAƬ�Ρ�

�㷨������

�������Ƚ��²�DNAƬ�ν���AC�Զ�����������ת�ƺ�����

��f[i][j]��ʾ���е���iλ��AC�Զ����е���j��������С�𰸣���ô����ת�Ƶ�f[i + 1][nxt[j][k]]��

ע����nxt[j][k]��β��·�����ܰ����²�DNAƬ�Σ����ڼ���failָ��Ĺ�����Ӧ˳�����ݡ�

ʱ�临�Ӷ�O(ML)��

����2��POJ 1625 Censored!

��Ŀ���⣺

������СΪN(1 <= N <= 50)���ַ�����P(0 <= P <= 10)�����Ȳ�����10�ķǷ����ʣ���ΪM(1 <= M <= 50)�ĺϷ����Ӹ�����

�㷨������

����һ�����Ƶأ���f[i][j]��ʾ���е���iλ��AC�Զ����е���j�����ķ���������Ҫʹ�ø߾��ȡ�

��Ҫע����ǣ��������ַ���128~255֮�䣬Ҫ��unsigned char��

ʱ�临�Ӷ�O(NML)��

����3��POJ 2778 DNA Sequence

��Ŀ���⣺

����M(0 <= M <= 10)�����Ȳ�����10���²�DNAƬ�Σ��󳤶�ΪN(1 <= N <= 2 * 10^9)�Ĳ������κ��²�DNAƬ�ε�DNAƬ�θ�����

�㷨������

����һ�����Ƶأ���f[i][j]��ʾ���е���iλ��AC�Զ����е���j�����ķ�������

����N�ܴ����ǿ��԰�ת�ƿ�������һ������ͼ�����A��B����K���ߵ�·������

�����һ������ľ���˷������ˣ������ڽӾ����Գ�K�Σ������ݸ㶨��

ʱ�临�Ӷ�O(L^3logN)��

���������ٰ���һ��

����1��BZOJ 1030 �ı�������

��Ŀ���⣺

����N(1 <= N <= 60)�����Ȳ�����100�ĵ��ʣ��󳤶�ΪM(1 <= M <= 100)�����ٰ���һ�����ʵ��ı��ĸ�����

�㷨������

�������Ƚ����ʽ���AC�Զ�����������ת�ƺ�����

��f[0/1][i][j]��ʾ�Ƿ���������ʣ����ı���iλ��AC�Զ����ϵ�j�����ʱ�ķ���������������Ȼ�ġ�

ʱ�临�Ӷ�O(ML)��

����2��SPOJ GEN

��Ŀ���⣺

����N(1 <= N <= 10)�����Ȳ�����6�ĵ��ʣ��󳤶�ΪM(1 <= M <= 1000000)�����ٰ���һ�����ʵ��ı��ĸ�����

�㷨������

�������һ�����Ƶأ���f[0/1][i][j]��ʾ�Ƿ���������ʣ����ı���iλ��AC�Զ����ϵ�j�����ʱ�ķ�������״̬��120�����ڴ����лᳬʱ��

���Ǽ�һ����ֹ���ʾ�Ѿ������˵��ʣ���ô����nxtָ�򵥴ʽ�β�����ǰ����ת�Ƶ���ֹ���ϣ�����ֹ�㵽��ֹ���ת�ƾ���26�֣���ΪֻҪ������һ��������ô�Ժ�������ˡ�

����״̬��ֻ��60����ʱ�临�Ӷ�O(L^3logM)��

������ȫ����

����1��BZOJ 1195 ���ĸ��

��Ŀ���⣺

����N(1 <= N <= 12)�����Ȳ�����50���ַ�������������ֵ�����С���ַ�����ʹ��֮ǰN���ַ������������Ӵ���

�㷨������

����Ҫȫ���������ǿ���ʹ��״̬ѹ����̬�滮��

��f[i][j]��ʾ��AC�Զ����ϵ�i����㣬�����Ӵ���״̬Ϊj����С����

Ϊ�˱�֤ÿ��״ֻ̬��ת��һ���ұ���Ϊ��С����������Ϊ�ع涨ת��˳�򣬼��ӿճ�����ÿ�δ�С���������һ���ַ������µ����״̬��

��ô���������BFS�Ǻ�����ʵ�ֵģ�ʱ�临�Ӷ�O(L * 2^N)��

����2��BZOJ 1559 ����

��Ŀ���⣺

�������볤��M(1 <= M <= 25)���Ѿ��۲쵽��N(1 <= N <= 10)�����Ȳ�����10���Ӵ���������۲�Ҫ��������������С�ڵ���42�����ֵ���������н⡣

�㷨������

��f[i][j][k]��ʾ�������iλ��AC�Զ����ϵ�j����㣬�����Ӵ���״̬Ϊk�ķ�������ת������Ȼ�ġ�

ͳ�Ƴ������Ժ��緢��С�ڵ���42����������Ҫ�ٵ��Ž�DP��ת�ƹ�ϵȫ����¼���������̱ȽϷ�����ϸ�ڽ϶ࡣ

������е��ַ������򼴿ɡ�ʱ�临�Ӷ�O(ML * 2^N)��