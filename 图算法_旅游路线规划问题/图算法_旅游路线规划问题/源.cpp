#include<iostream>

using namespace std;

const int MAXSIZE = 500;
int route[MAXSIZE][MAXSIZE];//·��Ȩֵ�ڽӾ���
int cost[MAXSIZE][MAXSIZE];//����Ȩֵ�ڽӾ���
int res[MAXSIZE][MAXSIZE];//���·������ڽӾ���

int getMinRoute(int citysize,int begin,int end) {
	//�������·����Ŀ

};

int getMinCost() {
	//�������·���з������ٵĽ⣬�����Ž�

};

int main() {
	int begin, end;
	int citysize, routesize;
	//��ʼ������
	cin >> citysize >> routesize >> begin >> end;
	for (int i = 0; i < routesize; i++) {
		int b1, e1, r1, c1;
		cin >> b1 >> e1 >> r1 >> c1;
		route[b1][e1] = r1;
		cost[r1][e1] = c1;
	}
	//�õ����·��
	int count=getMinRoute(citysize,begin,end);
	//�õ����Ž�
	int cost=getMinCost();
	cout << endl;

	return 0;
}