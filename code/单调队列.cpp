#include <iostream>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	int* a = new int[n];
	int* q = new int[k];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int left = 0, right = -1;      //�ݼ����е����ұ߽�
	for (int i = 0; i < n; i++)
	{
		while (right >= left && a[i] > a[q[right]])
			right--;		//���������Ԫ��
		q[++right] = i;
		if (q[right] - q[left] + 1 > k)
			left++;	//��֤���������ֻ��k��Ԫ��
		if (i - k + 1 >= 0)
			cout << a[q[left]] << " ";	//���ֵ��left��
	}
	delete a; delete q;
	return 0;
}