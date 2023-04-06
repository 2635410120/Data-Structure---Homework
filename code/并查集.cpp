#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<list>
#include<queue>
#include<ctime>
using namespace std; 
//202100460065 ��� 
int f[1000],rank[1000];
/*int findx(int x)  //�Ѳ�ѯ����
{
    if(f[x] != x)
    f[x] = findx(f[x]);  // ·��ѹ���Ż�,
    return f[x];         //��ÿ��Ԫ��ֱ���������ڼ��ϵĸ���
}*/
int findx(int x)  //δ�Ż��Ĳ�ѯ���� 
{
	if(x == f[x])
        return x;
    return findx(f[x]);
 } 
//���صĲ��鼯��ʱ����Ҫ�˷��ڲ�ѯ�����ϣ�ԭ�����ڵ�������Ҫ��ѯĳ���ڵ�ĸ�ʱ��
//��Ҫ�Ӹýڵ���������ϵĲ�ѯ����Ԫ��ֱ���ҵ����ڵ㡣
int findx_good(int x)  //·��ѹ���Ż���ѯ����
{
    if(f[x] != x)
    f[x] = findx(f[x]);  // ·��ѹ���Ż�,
    return f[x];         //��ÿ��Ԫ��ֱ���������ڼ��ϵĸ���
}
//���ð��Ⱥϲ������Ⱥϲ�����Ҫ���������нڵ㶼����һ��Ȩֵ�����Ա�ʾ�ýڵ��������еĸ߶ȣ�������rank[x]=3��ʾ x �ڵ��������ĸ߶�Ϊ3��������һ�����ںϲ�������ʱ�����ͨ�����Ȩֵ�Ĵ�С������˭��˭���ϼ���
//�ںϲ�������ʱ�򣬼�����Ҫ�ϲ����������ϵĴ���Ԫ�ֱ�Ϊ x �� y����ֻ��Ҫ��f[x] = y ����f[y] = x ���ɡ�������Ϊ��ʹ�ϲ�������������˻�������ʹ����������������Ȳ����С����
//��ô����ÿһ��Ԫ�� x ������һ��rank[x]���飬���Ա������ x �ĸ߶ȡ��ںϲ�ʱ�����rank[x] < rank[y]������f[x] = y��������f[y] = x��
void uni(int x,int y) //�ϲ����� 
{
  f[findx(x)] = findx(y);
}
void unioni_good(int x,int y)
{
    x=findx(x);							//Ѱ�� x�Ĵ���Ԫ
    y=findx(y);							//Ѱ�� y�Ĵ���Ԫ
    if(x==y) return ;					//��� x�� y�Ĵ���Ԫһ�£�˵�����ǹ���ͬһ���ϣ�����Ҫ�ϲ���ֱ�ӷ��أ�����ִ��������߼�
    if(rank[x]>rank[y]) f[y]=x;		//��� x�ĸ߶ȴ��� y������ y���ϼ�Ϊ x
    else								//����
    {
        if(rank[x]==rank[y]) rank[y]++;	//��� x�ĸ߶Ⱥ� y�ĸ߶���ͬ������ y�ĸ߶ȼ�1
        f[x]=y;						//�� x���ϼ�Ϊ y
    }
}
bool same(int x, int y)
{
    return findx(x) == findx(y);
}
int main()
{
	int n,m;
	cin>>n>>m;
    for(int i=1;i<=n;i++) //���鼯��ʼ��,ÿ������Ϊһ������ ��ͬʱ��ʼ���� 
      {
      	f[i] = i; 
      	rank[i]=1;
	  }
    for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		unioni_good(a,b);
	 } 
    for(int i=1;i<=n;i++)
    {
    	if(findx(i)==i)
    	{
    		cout<<i<<" ";
    		for(int j=1;j<=n;j++)
    		{
    			if(findx(j)==i&&i!=j)
    			  cout<<j<<" ";
			}
		cout<<endl;
		}
	}
    return 0;
}
//202100460065 ��� 
