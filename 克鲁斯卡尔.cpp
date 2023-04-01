#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXV = 1000;	//��󶥵���
const int INF = 1000000000;		//��INFΪһ���ܴ����
 
//�߼����岿�� 
struct edge {
	int u,v;	//�ߵ������˵���
	int cost;	//��Ȩ 
}E[MAXV]; 	//�����MAXV���� 
 
bool cmp(edge a,edge b)
{
	return a.cost < b.cost;
} 
//���鼯���� 
int father[MAXV];	//���鼯����
int findFather(int x)
{	//���鼯��ѯ���� 
	int a=x;
	while(x != father[x]){
		x = father[x];
	}
	//·��ѹ��
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[x] = x; 
	} 
	return x;
} 
 
//kruskal����������С�������ı�Ȩ֮�ͣ�����nΪ���������mΪͼ�ı���
int kruskal(int n,int m)
{
	//ansΪ�����Ȩ֮�ͣ�Num_EdgeΪ��ǰ�������ı���
	int ans = 0, Num_Edge = 0;
	for(int i=1; i<= n;i++)
	{	//������Ŀ�ж��㷶ΧΪ[1,n] 
		father[i] = i;	//���鼯��ʼ�� 
	} 
	sort(E,E+m,cmp);	//���б߰���Ȩ��С��������
	for(int i=0;i<m;i++){	//ö�����б� 
		int faU = findFather(E[i].u);	//��ѯ���Ա����ڵļ��ϸ����
		int faV = findFather(E[i].v);
		if(faU != faV){		//�������һ������ 
			father[faU] = faV;	//�ϲ����ϣ����Ѳ��Ա߼�����С�������У� 
			ans += E[i].cost;	//��Ȩ֮�����Ӳ��Աߵı�Ȩ
			Num_Edge++;	//�������ı���+1
			if(Num_Edge == n-1)	//�������ڶ�������һʱ�����㷨 
				break; 
		}
	} 
	if(Num_Edge != n-1)
		return -1;	//�޷���ͨ������-1
	else
		return ans;	//������С�������ı�Ȩ֮�� 
} 
 
int main(){
	int n,m;
	scanf("%d%d",&n,&m);	//��������������������
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].cost);	//�����˵��š���Ȩ 
	} 
	int ans = kruskal(n,m);	// kruskal�㷨���
	printf("%d\n",ans);
	return 0; 
} 

