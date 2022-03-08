//��̤����---̰�����
#include<stdio.h>
#include<stdlib.h>

#define OK      1
#define TRUE    1
#define ERROR   0
#define FALSE   0

#define M 8

int direction[2][9] = { {0,-2,-1,1,2,2,1,-1,-2},{0,1,2,2,1,-1,-2,-2,-1} };       //�������� 
int pow[M][M];
int check[M][M], next[M][M];         //�������̣���ʼΪ0 
typedef struct Element //������ 
{
	int x, y; //x��,y��
	int d; //��һ���ķ���
}Element;
typedef struct LStack //��ջ
{
	Element data;
	struct LStack* next;
}*PLStack;

typedef struct check //���������ڵ������
{
	int x;
	int y;
}Check;

/*************ջ����****************/
int InitStack(PLStack& S)//�����ջ
{
	S = NULL;
	return OK;
}
int StackEmpty(PLStack S)//�ж�ջ�Ƿ�Ϊ��
{
	if (S == NULL)
		return OK;
	else
		return FALSE;
}
int Push(PLStack& S, Element e)//Ԫ����ջ
{
	PLStack p;
	p = (PLStack)malloc(sizeof(LStack));
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
int Pop(PLStack& S, Element& e) //Ԫ�س�ջ 
{
	PLStack p;
	if (!StackEmpty(S))
	{
		e = S->data;
		p = S;
		S = S->next;
		free(p);
		return OK;
	}
	else
		return FALSE;
}

/********̰��Ȩֵ����********/

void Printf(int p[M][M]) {          //��ӡȨֵ���� 
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++)
			printf(" %2d ", p[i][j]);
		printf("\n");
	}
}
void InitWeight() {    //����Ȩֵ���鲢��ʼ��ÿ��λ�õ�Ȩֵ 
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			pow[i][j] = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			for (int dir = 1; dir <= M; dir++) {
				int x1 = i + direction[0][dir];
				int y1 = j + direction[1][dir];
				if (x1 >= 0 && x1 <= M-1 && y1 >= 0 && y1 <= M -1)
					pow[i][j]++;
			}
		}
	}
}

void SetWeight(int x, int y) {   //λ�ã�x,y������Ϊ  ��ռ��  ʱ���޸�Ȩֵ���� ,��ռ��ʱΪ9 
	pow[x][y] = 9;
	for (int dir = 1; dir <= M; dir++) {
		int x1 = x + direction[0][dir];
		int y1 = y + direction[1][dir];
		if (x1 >= 0 && x1 <= M - 1 && y1 >= 0 && y1 <= M - 1 && pow[x1][y1] != 9)
			pow[x1][y1]--;
	}
}

void UnSetWeight(int x, int y) {  //λ�ã�x,y������Ϊ  δռ��  ʱ���޸�Ȩֵ����
	for (int dir = 1; dir <= M; dir++) {
		int x1 = x + direction[0][dir];
		int y1 = y + direction[1][dir];
		if (x1 >= 0 && x1 <= M - 1 && y1 >= 0 && y1 <= M - 1 && pow[x1][y1] != 9) {
			pow[x1][y1]++;
			pow[x][y]++;
		}

	}
}


/*******��̤���̺���*******/
int Step(Check start, PLStack& H) {
	Element *data=new Element;
	int x = start.x - 1, y = start.y - 1;//������λ�ý��飬�����0��0��ʼ�洢 
	int i = 1;
	while (i <= 64) {
		check[x][y] = i;     //����ǰ����д����������
		SetWeight(x, y);
		struct Element *t=new Element;
		int pow_min = 9;
		for (int dir = 1; dir <= M; dir++) {     //̽����һ�����ߵķ��� 
			int x1 = x + direction[0][dir];
			int y1 = y + direction[1][dir];
			if (x1 >= 0 && x1 <= M - 1 && y1 >= 0 && y1 <= M - 1 && pow[x1][y1] != 9)
			{
				if (pow_min > pow[x1][y1])       //�ҳ���һ��λ����Ȩֵ��С�� 
				{
					pow_min = pow[x1][y1];
					t->d = dir;  //��һ���ķ��� 
					t->x = x1;
					t->y = y1;
				}
			}

		}
		data->x = x;    //��ջ 
		data->y = y;
		data->d = t->d;
		Push(H, *data);
		x = t->x;        //������� 
		y = t->y;
		i++;         //�������� 
	}
	return OK;
}

//int main() {
//
//	for (int i = 0; i < M; i++)          //���̳�ʼ�� 
//		for (int j = 0; j < M; j++) {
//			check[i][j] = 0;       //���� 
//			next[i][j] = 0;     //�켣���� 
//		}
//	InitWeight();     //����Ȩֵ���� 
//
//	PLStack H;
//	InitStack(H);   //�����ջH
//
//	Check start;
//	printf("��������ʼ����x y��");
//	//scanf_s("%d%d", &start.x, &start.y);
//	for(int i=1;i<=M;i++)
//		for (int j = 1; j <= M; j++) {
//			start.x = i; 
//			start.y = j;
//			Step(start, H);
//		}
//	Printf(check);
//	return 0;
//}
