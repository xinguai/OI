��k������ By strongoier

���ڸ����ݽṹ��ʹ�������вο����ϣ��ɳ־û����ݽṹ�Ƽ������ܵġ��ɳ־û����ݽṹ�о�����

����1��SPOJ MKTHNUM�������k�������⣨���޸ģ�����ѯ�ʣ�

�㷨һ��ʹ�ö��� + �鲢����ʱ�临�Ӷ�O(Nlog^3N)��

�㷨����ʹ�ÿɳ־û��߶���/��������ʱ�临�Ӷ�O(NlogN)��

����2��BZOJ 1901 Dynamic Rankings�������k�������⣨���޸ģ�����ѯ�ʣ�

�㷨һ��ʹ�ö��� + �߶�����ƽ������ʱ�临�Ӷ�O(Nlog^3N)��

�㷨����ʹ����״�����׿ɳ־û��߶�����ʱ�临�Ӷ�O(Nlog^2N)��

���ݿɳ־û��߶�����һ�㶨�壬������T_i��ʾ����a_1, a_2, ..., a_i���γɵ�Ȩֵ�߶�������ô������ͨ��T_(i - 1)����a_i�õ���

��A_i��ʾ������a_i�γɵ�Ȩֵ�߶���������Ȩֵ�߶���֧�ּӷ�����ô������ȫ���԰���ЩȨֵ�߶�������һά�ṹ��

����û���޸Ĳ�����������T_i��ʾA_1, A_2, ..., A_i�ĺͣ���ǰ׺�ͣ�T_i = T_(i - 1) + A_i����ô��T_r - T_(l - 1)�Ϳ��Եõ�����[l, r]��Ȩֵ�߶�����

�������޸Ĳ��������綯̬ά������Ĳ��ֺ�һ������̬��ǰ׺�������ǲ��еģ�������ǿ���ʹ����״����ά����T_i��ʾ�ķ�Χ��ͬ����״�������S_i����ÿһ���޸�A_i��Ҫ��logN��T_i�����޸ġ�

����3��SPOJ COT��·����k�������⣨���޸ģ�����ѯ�ʣ�

������T_i��ʾ�������i·���ϵ����γɵ�Ȩֵ�߶�������ô������ͨ��T_father(i)����a_i�õ����׵ã�·��u -> v�ϵ����γɵ�Ȩֵ�߶���T = T_u + T_v - T_LCA(u, v) - T_father(LCA(u, v))���ٲ�ѯ��k�󼴿ɡ�

����LCA����ʹ�ñ����㷨ʵ�֣���Ҫע����ǣ���������a_i��˳��ҲҪ����DFS������ʱ�临�Ӷ�ΪO(NlogN)��

����4��CF 191E Thwarting Demonstrations����k���Ӷκ����⣨���޸ģ���ѯ�ʣ�

ֱ���������ǲ���ʵ�ģ���������뵽���ִ�C�ٽ�����֤�����ڵ���C�������ڵ���K��������C��Ϊ�𰸡�

����Ҫ���ǵ���������������ڵ���C�����ĸ�������������������ӶΣ����Ǻ������뵽Ҫö���Ӷε��Ҷ˵㡣

���ǲ��ֺ�s_0, s_1, ..., s_N�������Ҷ˵�i������ֻҪ֪����s_0, s_1, ..., s_(i - 1)��С�ڵ���s_i - C�����ĸ������ɡ�

�����Ļ����ͱ��һ���ø߼����ݽṹ��ά���������ˡ�

ת������һ�����ϲ�ѯa_i, a_(i + 1), ..., a_j��С�ڵ���C�����ĸ�������ô��Ȼ������ɢ�����ÿɳ־û��߶�����ά����

ת������������β�ѯa_1��a_2, ..., a_(i - 1)��С�ڵ���C�����ĸ�����������a_i����ô��������ֱ����ƽ������ά����������ɢ��������״������ά����

���Ϸ�����ʱ�临�ӶȾ�ΪO(Nlog^2N)��