Manacher By strongoier

ѧϰ�㷨ԭ���μ�http://www.felix021.com/blog/read.php?2040��

����1��POJ 3974 Palindrome

��Ŀ���⣺

����һ������ΪN(1 <= N <= 1000000)���ַ�������������Ӵ��ĳ��ȡ�

�㷨������

ֱ��ʹ��Manacher�㷨��ʱ�临�Ӷ�O(N)��

����2��BZOJ 2565 �˫���Ĵ�

��Ŀ���⣺

����һ������ΪN(2 <= N <= 100000)���ַ��������˫�����Ӵ�T�ĳ��ȣ����ɽ�T��Ϊ�ǿ�����������X, Y����X��Y���ǻ��Ĵ���

�㷨������

����������Manacher�㷨Ԥ��������iΪ��������İ뾶��

����ö�ٷֽ��i������Ҫʹ����iΪ�ұ߽硢��߽�Ļ����Ӵ������Ҳ����Ҫ�ֱ��ҵ���i����������i��Զ�Ļ��İ뾶�ɸ�����i�ĵ㡣

��ô����������Ϊ�������Ǵ�������ɨ�裬ͬʱά��һ����ǰ���������ұ߽硣�����i������İ뾶Ϊr����ô����ֻҪ���´ӵ�ǰ�ұ߽絽i + r��η�Χ��ģ�ͬʱ�����ұ߽�Ϊi + r��

����ȷ������Ȼ�ģ���Ϊ�����������ͬʱ���ǵ�һ��λ�ã���ôѡ����Ǹ���Ȼ�Ǹ��ŵġ����Ҳ��ͬ����ʱ�临�Ӷ�O(N)��

����3��BZOJ 2160 ����������

��Ŀ���⣺

����һ������ΪN(1 <= N <= 1000000)���ַ����������г���Ϊ�����Ļ����Ӵ������Ƚ��������ǰK�����ȵĳ˻���

�㷨������

����������Manacher�㷨Ԥ��������iΪ��������İ뾶�����Ƿ��֣����Ȳ�����N�֡���ˣ����ǿ��Ժ����׵���������ͳ�Ƴ�ÿ�ֳ��ȵĸ�����

�������Ӹߵ���ȡǰk����ÿ��ʹ�ÿ����ݼ��ɡ�ʱ�临�Ӷ�O(NlogN)��

����4��BZOJ 2342 ˫������

��Ŀ���⣺

���ַ���w�ĵ���Ϊr(w)����w = r(w)�����w���ġ���x = wr(w)wr(w)�����x˫�����ġ��󳤶�ΪN(1 <= N <= 500000)���ַ������˫�������Ӵ���

�㷨������

����������Manacher�㷨Ԥ��������iΪ��������İ뾶��ö������i��������Ҫ�ҵ���С��������j(j < i)��ʹ��j������İ뾶�ܸ��ǵ�i������i��j�ľ����2�����ܳ���i������İ뾶��

��i������İ뾶�����ǿ��Ժ����׵õ���i��j�ľ����2�����ܳ���i������İ뾶����j����߽�k����ô������Ҫ�ҵľ�����k�Ҳ���k���������İ뾶�ܸ��ǵ�i��j��

���Ǻ������뵽�ò��鼯ά������Ҳ����ֵ����������ֵ���ܸ��ǵ�i�Ͱ����ֵ���ƣ���Ϊ������ֵ�������ٱ������i���ã���

����ÿ������౻ɾһ�Σ���ѯ����Ч�����Ҳֻ��N�����ټ��ϲ��鼯��ʱ�临�Ӷȣ�����ʱ�临�Ӷ�O(NlogN)��