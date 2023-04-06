#include<iostream>
using namespace std;
class lxqueue 
{
public:
	int* heap;
	int size,lxn;
	void swap(int x, int y)
	{
		int lx= heap[x];
		heap[x] = heap[y];
		heap[y] = lx;
	}
	lxqueue(int num[], const int m, const int n) 
	{
		size = m;
		lxn = n;
		heap = new int[size];
		for (int i = 0; i < lxn; i++) 
			heap[i] = num[i];
		for (int i = lxn / 2 - 1; i >= 0; i--) 
			down(i);
	}
	int LeftChild(int pos){return 2 * pos + 1;}
	int RightChild(int pos) {return 2 * pos + 2;}
	int Parent(int pos) {return (pos - 1) / 2;}
	int lxpop() 
	{
		swap(0, --lxn);
		if (lxn > 1) 
			down(0);
		return heap[lxn];
	}
	void down(int pos) 	//��pos��ʼ����ɸѡ
	{
		int i = pos;
		int j = LeftChild(i);
		int temp = heap[i];
		while (j < lxn) 
		{
			if ((j < lxn - 1) && (heap[j] > heap[j + 1])) 
				j++;
			if (temp > heap[j]) 
			{
				heap[i] = heap[j];
				i = j;
				j = LeftChild(j);
			}
			else 
				break;
		}
		heap[i] = temp;
	}
};
void replace(int num[], int n, int RAM) 
{
	lxqueue T(num, RAM, RAM);
	int remain = RAM;//ʣ�������Ԫ������
	int count = 1;//��������
	cout << endl << "��" << count << "�飺 ";
	while (remain < n) 
	{
		cout << T.heap[0] << " ";
		if (num[remain] >= T.heap[0]) 
		{
			T.heap[0] = num[remain++];
		}
		else 
		{
			T.heap[0] = T.heap[--T.lxn];
			T.heap[T.lxn] = num[remain++];
		}
		if (T.lxn > 0)
		 {
			T.down(0);
		}
		else //���½���
		{
			T.lxn = T.size;
			for (int i = T.lxn / 2 - 1; i >= 0; i--) 
			{
				T.down(i);
			}
			cout << endl << "��" << ++count << "�飺 ";
		}
	}
	if (T.lxn == T.size) 	//���ʣ��Ķ���Ԫ��
	{
		while (T.lxn > 0) 
		{
			cout << T.heap[0] << " ";
			T.lxpop();
		}	
	}
	else 
	{
		int leftover = T.size - T.lxn;
		while (T.lxn > 0) 	//������е�Ԫ��
		{
			cout << T.heap[0] << " ";
			T.lxpop();
		}
		T.lxn = leftover;
		for (int i = 0; i < T.lxn; i++) //��ʣ�µ�Ԫ����������
			T.heap[i] = T.heap[T.size - leftover + i];
		for (int i = T.lxn / 2 - 1; i >= 0; i--) //���¹�����
			T.down(i);
		cout << endl << "��" << ++count << "�飺 ";
		while (T.lxn > 0) 
		{
			cout << T.heap[0] << " ";
			T.lxpop();
		}
	}
}
int main() 
{
	int n, RAM;
	cin>>n;
	int* num= new int[n];
	for (int i = 0; i < n; i++) 
		cin >> num[i];
	cin >> RAM;
	replace(num, n, RAM);
}
