#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_QUEUE_SIZE 200
typedef int ElemType;
//��������
//�������ڵ�
typedef struct Node
{
	int data;
	struct Node* leftChild;
	struct Node* rightSibling;
} Node, * Tree;
//���򴴽���
int CreateForest(Tree* T)
{
	ElemType ch;
	ElemType temp;
	scanf("%d", &ch);
	temp = getchar();
	if (ch == -1)
		* T = NULL;
	else 
	{
		*T = (Tree)malloc(sizeof(Node));
		if (!(*T))
			exit(-1);
		(*T)->data = ch;
		printf("����%d��������", ch);
		CreateForest(&(*T)->leftChild);  //��ߵ�һ������ 
		printf("����%d���ֵܣ�", ch);
		CreateForest(&(*T)->rightSibling); //�ұߵ�һ���ֵ� 
	}return 1;
}
//�ȸ�����ɭ�֣���Ӧ���������������
void TraverseForest(Tree T)
{
	if (T == NULL)return;
	printf("%d ", T->data);
	TraverseForest(T->leftChild);
	TraverseForest(T->rightSibling);
}
//�������ɭ�֣���Ӧ��������������� 
void PostOrderForest(Tree T)
{
	if (T == NULL)return;
	PostOrderForest(T->leftChild);
    printf("%d ", T->data);
    PostOrderForest(T->rightSibling);

}

// �����ú����ֵܱ�ʾ���洢��ɭ�ֵ�Ҷ�ӽ��ĸ���
// �ݹ��˼·������޺�����ý���ΪҶ�ӽ��
bool isLeaf(Tree T) 
{
		if (T->leftChild == NULL) 
			return true;
		else 
			return false;
}
int CountLeaves(Tree root)
{
	if (!root) 
	{
		return 0;
	}
	else
	{
	    int count = 0;
		while (root != NULL) 
		{
			if (isLeaf(root)) 
			{
				count++;
			}
			count += CountLeaves(root->leftChild);
			root = root->rightSibling;
		}
		return count;
	}
}

int height(Tree root)
{
	//int hchild, hsibling;
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int depth = 0;
		int childdepth = height(root->leftChild);
		int brotherdepth = height(root->rightSibling);
		depth = childdepth + 1 > brotherdepth ? childdepth + 1 : brotherdepth;
		return depth;
	}
}
//������
int main(void)
{
	Tree T;

	int deepth, num = 0;
	printf("�������һ������ֵ,-1��ʾû�ж�Ӧ����:\n");
	CreateForest(&T);
	printf("�������ɭ��:\n");
	TraverseForest(T);
	printf("\n");
	printf("�������ɭ��:\n");
	PostOrderForest(T);
	printf("\n");

	num = CountLeaves(T);
	printf("ɭ�ֵ�Ҷ�ӽ�����Ϊ:%d", num);
	printf("\n");

	deepth = height(T);
	printf("ɭ�ֵĸ߶�Ϊ:%d", deepth);
	printf("\n");

	return 0;
}
