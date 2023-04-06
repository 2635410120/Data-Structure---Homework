#include<iostream>
using namespace std;

#define max 100
#define maxInt 32767

//����ͼ
typedef struct {
	char vexs[1000];  //�����
	int arcs[1000][1000];  //����
	int vexnum;  //����ֵ
	int arcnum;  //��ֵ
}AMGraph;

//Ȩֵ��С��
struct POINT{
	char adjvex;  //����
	int lowcost;  //Ȩֵ
}closeedge[1000];

//ȷ��λ�ú���
int LocalVex(AMGraph G, char v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vexs[i] == v)
		{
			return i;
		}
	}
	return -1;
}


//��������ͼ
void CreatUDN(AMGraph & G) {
	int i, j, k;
	cout << "please input the num of vex and arcs of Graph��seperate them with spece key��" << endl;
	cin >> G.vexnum >> G.arcnum;  //���붥�����ͱ���
	cout << endl;
	//���붥����Ϣ
	cout << "please input name of vexs as a��" << endl;
	for ( i = 0; i < G.vexnum; i++)
	{
		cout << "please the name of " << (i + 1) << " vex��";
		cin >> G.vexs[i];
	}
	cout << endl;
	
	//����Ȩֵ
	//��ʼ��
	for (i = 0; i < G.vexnum; i++) {
		//����
		for ( j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j] = maxInt; //��Ϊ���ֵ
		}
	}

	//�ߵ�����
	cout << "please input the vexs of arc and corresponding weight as a b 1:" << endl;
	for (k = 0; k < G.arcnum; k++) {
		char v1, v2;
		int weight;
		cout << "please input the vex name and weight of" << (k + 1) << "arc:";
		cin >> v1 >> v2 >> weight;
		
		i = LocalVex(G, v1);
		j = LocalVex(G, v2);
		G.arcs[i][j] = weight;  //��Ȩֵ��ֵ
		G.arcs[i][j] = G.arcs[i][j];
	}
}

//Ȩֵ��С��
int Min(AMGraph G) {
	int index = -1;
	int min = maxInt;
	for (int i = 0; i < G.vexnum; i++) {
		if (min > closeedge[i].lowcost && closeedge[i].lowcost != 0) { //�ҳ���С���Լ�����ͬһ�����е�
			min = closeedge[i].lowcost;
			index = i;
		}
	}
	return index;
}

//��С�������㷨
void prime(AMGraph G, char u) {
	//�ȹ�����ʼ����
	int k, i, j;
	char u0, v0;
	k = LocalVex(G, u);
	for (j = 0; j < G.vexnum; j++)
	{
		if (j != k) {
			closeedge[j].adjvex = u;
			closeedge[j].lowcost = G.arcs[k][j];
		}
	}
	closeedge[k].lowcost = 0;
	for (i = 1; i < G.vexnum; i++)
	{
		k = Min(G); //�ҳ���̱�
		u0 = closeedge[k].adjvex;  //�ҳ���̱߶�Ӧ�Ķ���
		v0 = G.vexs[k];
		cout << "arc " << u0 << "---->" << v0 << endl;
		closeedge[k].lowcost = 0;

		//��������
		for (j = 0; j < G.vexnum; j++)
		{
			if (G.arcs[k][j] < closeedge[j].lowcost)
			{
				closeedge[j].adjvex = G.vexs[k];
				closeedge[j].lowcost = G.arcs[k][j];
			}
		}
	}
}

int main() 
{
	AMGraph G;
	CreatUDN(G);
	prime(G,'a');
	return 0;
}


