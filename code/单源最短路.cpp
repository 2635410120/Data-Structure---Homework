#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
struct Node
{
    double x,y;
}location[1001];//�������� 
double dis[1001];//�������飬��ʾ����㵽����Ϊi�ĵ�����·�� 
int vis[1001];//��ǵ�ǰ���Ƿ񱻷��� 
int n,m;//��,�ߵĸ��� 
int from,to;//����յ� 
double map[101][101];//�ڽӾ����ͼ  
priority_queue< pair<double,int> > q;//����pair���� dis[i]��i�Ĺ�ϵ�� 
/*void Dijkstra(int u)
{
     for(int i=1;i<=n;i++)
        dis[i]=map[u][i];//���γ�ʼ��dis 
     dis[u]=0;
     vis[u]=1;
     for(int i=1;i<=n;i++)//ѭ��n��
     {
         double minn=99999999;
         int k=-1;//kʹd[k]��С��minn��Ÿ���С��d[k]��ֵ 
         for(int j=1;j<=n;j++) //�ҵ�δ���ʵĶ�����d[j]��С��
         {
             if((dis[j]<=minn)&&vis[j]==0)
             {
                minn=dis[j];//��¼��ǰ��С��d[k]����d[j]����ֵ 
                k=j;//��¼��ǰ��С��d[k] 
            }
        }
         vis[k]=1;//���kΪ�ѷ���
        for(int j=1;j<=n;j++)
         {
         	 //���jδ���� && k�ܵ���j && ��kΪ�н�����ʹdis[j]����
             if((dis[j]>=dis[k]+map[k][j])&&vis[j]==0&&map[k][j]!=1000000)
               dis[j]=dis[k]+map[k][j];//�Ż�d[j]
			  
         }
     }
}*/
void Dijkstra_queue(int u)
{
	q.push(make_pair(0,u));
    dis[u]=0;
    while(!q.empty())
    {
        int k=q.top().second;//���׳���
        q.pop();
        if(vis[k]==1) continue;
        vis[k]=1;
        for(int j=1;j<=n;j++)
         {
         	 //���jδ���� && k�ܵ���j && ��kΪ�н�����ʹdis[j]����
             if((dis[j]>=dis[k]+map[k][j])&&vis[j]==0&&map[k][j]!=1000000)
               {
			     dis[j]=dis[k]+map[k][j];//�Ż�d[j]
			     q.push(make_pair(-dis[j],j));
		       }
         }
    }
}
void readpoint()
{
 	cin>>n;//��ȡ�ڵ���� 
    for(int i=1;i<=n;i++)         
	  cin>>location[i].x>>location[i].y;//�ѽڵ���������� 
    cin>>m;//��ȡ���ߣ��ߣ� ���� 
    for(int i=1;i<=m;i++)
    {
        int p,q;
        cin>>p>>q;
        double y=sqrt(pow(location[p].x-location[q].x,2)+pow(location[p].y-location[q].y,2));//��һ�³��� 
        map[p][q]=y;//����ͼ˫���� 
        map[q][p]=y;
    }
}
 int main()
 {
     memset(map,1000000,sizeof(map));//��ʼ������ (�ޱ��򳬼���)
     memset(dis,1000000,sizeof(dis));//��ʼ���������� ��û�Թ��򳬼��� 
     memset(vis,0,sizeof(vis));//���ʳ�ʼ�����޷�����Ϊ0�� 
     readpoint();
     cin>>from>>to;
     //Dijkstra(from);
     Dijkstra_queue(from);//���Ż� 
     printf("%0.2lf",dis[to]);
     return 0;
 }
