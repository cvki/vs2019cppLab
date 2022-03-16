/***2021-11-9.buaa�㷨��ҵ������ȱ���̸�������
* ע��������̨�������UI������ʾ��
**/
#include<iostream>
#include<iomanip>
using namespace std;

//��������
const int MAXS = 1024;
const int MINX = 16;
int SIZE=MINX; //���̹�ģ
int board[MAXS][MAXS];//����
int xbd, ybd;//�������
int counts = 0; //������������

//���̸��ǲ���
void setvp(int x,int y,int v) {
	board[x][y] = v;
}
//�������ݴ���
bool input(int size, int x, int y) {//��������0��ʼ
	if (size > MINX && size <= MAXS)
		SIZE = size;
	if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
		//board[x][y] = 0;  //ֵΪ0��ʾ���
		xbd = x;
		ybd = y;
		return true;
	}
	cerr << "��������" << endl;
	return false;
}
//�����������
void show() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (j)
				cout <<setw(3) << board[i][j];
			else
				cout << setw(3) << board[i][j];
		}
		cout << endl;
	}
}

//�������̹������߼�,a��ʾ����ԭ�����꣨����ȡ���Ϸ���Ϊԭ�㣩��d��ʾ������꣬step��ʾ���̺��ݳ�
void cover(int ax, int ay, int step, int dx, int dy) {
	//++counts;
	if (step == 1)
		return;
	else {//����
		step /= 2; //��������
		int nextx = ax + step;
		int nexty = ay + step;
		//���������λ�ý��з�������
		if (dx < nextx && dy < nexty) {//����
			//���������������̽�����α��㣬��λ��ǡ������һ����λ���
			setvp(nextx - 1, nexty, 1); //����
			setvp(nextx, nexty - 1, 1); //����
			setvp(nextx, nexty, 1);	//����
			++counts;
			//�ݹ�������
			cover(ax, ay, step, dx, dy);//�ݹ�����
			cover(ax, nexty, step, nextx - 1, nexty);//�ݹ�����
			cover(nextx, ay, step, nextx, nexty - 1);//�ݹ�����
			cover(nextx, nexty, step, nextx, nexty);//�ݹ�����
		}
		else if (dx < nextx && dy >= nexty) {//����
			//ͬ��
			setvp(nextx - 1, nexty - 1, 2);
			setvp(nextx, nexty - 1, 2);
			setvp(nextx, nexty, 2);
			++counts;
			cover(ax, ay, step, nextx - 1, nexty - 1);
			cover(ax, nexty, step, dx, dy);
			cover(nextx, ay, step, nextx, nexty - 1);
			cover(nextx, nexty, step, nextx, nexty);
		}
		else if (dx >= nextx && dy < nexty) {//����
			setvp(nextx - 1, nexty - 1, 3);
			setvp(nextx - 1, nexty, 3);
			setvp(nextx, nexty, 3);
			++counts;
			cover(ax, ay, step, nextx - 1, nexty - 1);
			cover(ax, nexty, step, nextx - 1, nexty);
			cover(nextx, ay, step, dx, dy);
			cover(nextx, nexty, step, nextx, nexty);
		}
		else {//����
			setvp(nextx - 1, nexty - 1, 4);
			setvp(nextx - 1, nexty, 4);
			setvp(nextx, nexty - 1, 4);
			++counts;
			cover(ax, ay, step, nextx - 1, nexty - 1);
			cover(ax, nexty, step, nextx - 1, nexty);
			cover(nextx, ay, step, nextx, nexty - 1);
			cover(nextx, nexty, step, dx, dy);
		}
	}
}

int main() {
	int size,x,y;
	cout << "���������̹�ģ���������(size,x,y):" << endl;
	cin >> size >> x >> y;
	if (input(size, x, y)) {
		cover(0, 0, SIZE, xbd, ybd);
		show();
	}	
	cout << "counts=" << counts << endl;
	system("pause");
	return 0;
}