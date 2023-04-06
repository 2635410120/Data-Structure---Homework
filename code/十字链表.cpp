#include<iostream>
using namespace std;
int n, m,edge=0;
int Matrix[501][501];
struct pNode 
{
    int headvex, tailvex;//��β��ʼ�㣩-->��ͷ���յ㣩
    int info;//Ȩֵ��û�õ� 
    pNode* nxt_to = NULL;//ָ����һ����ͬͷ�ڵ�Ļ� 
    pNode* nxt_from = NULL;////ָ����һ����ͬβ���Ļ� 
};
pNode list[250000];   //ʮ������ı߱� 
pNode* head_from[501];//ָ��ö���ĵ�һ������  
pNode* head_to[501];//ָ��ö���ĵ�һ������
//ʮ������Ķ���� 
void LinkedList(int u, int v) 
{
    edge++;
    list[edge].tailvex = u;//��β��ʼ�㣩
    list[edge].headvex = v;//��ͷ���յ㣩
    //ͷ�巨���뻡���
    list[edge].nxt_from = head_from[u];
    list[edge].nxt_to = head_to[v];
    head_from[u] = &list[edge];
    head_to[v] = &list[edge];
    return ;
}
void change() //ת���ڽӾ���Ϊʮ������
{
    for (int i = n; i >= 1; i--) 
      for (int j = n; j >= 1; j--)
        if (Matrix[i][j]==1) //���i��j֮��ߴ��� 
            LinkedList(i, j);////ͷ�巨���뻡���
          else continue; 
    return ;
}
void print()//��ӡʮ������ 
{
	for (int i = 1; i <= n; i++) 
	{
        for (pNode* j = head_from[i]; j; j = j->nxt_from)//��ÿһ������Ϊһ�д�ӡ��� 
        //Ϊ�˷�������˼ά���±��1��ʼһֱ��n�� 
		{
            cout<<"��ǰ�߽ڵ��ַ��"<<j<<" "<<"����±�Ϊ"<<j->tailvex<<" "<<"�յ��±�Ϊ"<<j->headvex<<" ";
		    cout<<"ָ����һ����ͬͷ�ڵ�Ļ�:"<<j->nxt_to<<" ";
			cout<<"ָ����һ������ͬβ���Ļ� :"<<j->nxt_from<<" ";
        }
        if(head_from[i]!=0) cout<<endl;//�Ѿ�����ͬ���ı߽�����Ϣ�����ͬһ��
    }
    return ;
 } 
int main() 
{
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) 
            cin>>Matrix[i][j];     //�����ڽӾ��� 
    change();      //ת���ڽӾ���Ϊʮ������ 
    print();       //��ӡʮ������ 
    return 0;
}
