#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include<windows.h> 
using namespace std;
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void quickSort1(long long a[], long long left, long long right)
{
    if (left >= right)
        return;
    long long i = left, j = right;
    while (i < j)
    {
        while (j > i && a[j] >= a[left])
            j--;
        while (i < j && a[i] <= a[left])
            i++;
        swap(a[i], (i == j) ? a[left] : a[j]);  //i��j������������Ԫ�ؽ���������a[i]��a[j]����
    }
    quickSort1(a, left, i-1);
    quickSort1(a, j+1, right);
}
void quickSort2(long long a[], long long left, long long right)
{
    if (left >= right)
        return;
    long long i = left, j = right, pivot = rand() % (right - left + 1) + left;
    swap(a[left], a[pivot]);
    while (i < j)
    {
        while (j > i && a[j] >= a[left])
            j--;
        while (i < j && a[i] <= a[left])
            i++;
        swap(a[i], (i == j) ? a[left] : a[j]);
    }
    quickSort2(a, left, i-1);
    quickSort2(a, j+1, right);
}
int main()
{
	long long n; 
	cin>>n;
    long long *arr = new long long[n];
    for (long long i = 0; i < n; i++) 
		arr[i] = rand() % n;
	DWORD t1 = GetTickCount();
	quickSort1(arr, 0, n-1);
    DWORD t2 = GetTickCount();
    cout<<"ѡȡ�����Ϊ��ֵ��������н�������ʱ�俪����"<<t2-t1<<"ms"<<endl;
   // for(int i=0;i<n;i++)  cout<<arr[i]<<" ";
    //cout<<endl;
    for (long long i = 0; i < n; i++)
		arr[i] = rand() % n;
	DWORD t3 = GetTickCount();
    quickSort2(arr, 0, n-1);
    DWORD t4 = GetTickCount();
    //for(int i=0;i<n;i++)  cout<<arr[i]<<" ";
    cout<<"ѡȡ�������Ϊ��ֵ��������н�������ʱ�俪����"<<t4-t3<<"ms"<<endl; 
    return 0;
}
