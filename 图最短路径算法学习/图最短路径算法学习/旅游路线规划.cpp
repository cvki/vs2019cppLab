/**2021-11-23��buaa�㷨��ҵ-2��������·�滮����(ͼ�㷨��Դ����·��--Dijkstra)**/

#include<iostream>

using namespace std;

const int INF = 1e7;//��ʾ����ͨ�ڵ��Ȩֵ
const int MAXSIZE = 500;//�ڵ������Ŀ

int route[MAXSIZE][MAXSIZE]; //�洢·��Ȩֵ�ڽӾ���
int cost[MAXSIZE][MAXSIZE]; //�洢����Ȩֵ�ڽӾ���
int dis[MAXSIZE]; //�洢�����е����С·��ֵ
int costV[MAXSIZE]; //�洢�����е����С����ֵ

bool sign[MAXSIZE] = { false };//��־λ����¼�ýڵ��Ƿ񱻼����ѷ��ʵĽڵ㼯����
int minV=INF;

void Dijkstra(int v0, int v, int d) {
	dis[v0] = 0;
	sign[v0] = true;
	for (int i = 0; i < v; i++) {
		minV = INF;
		for (int k = 0; k < v; k++) {
			//�ҳ�����ǰ����С·��ֵ
			if (!sign[k]) {
				if (dis[k] < minV) {
					minV = dis[k];
					v0 = k;
				}
			}
		}
		sign[v0] = true;
		for (int k = 0; k < v; k++) {
			//�ҳ�����ǰ����С·������С����ֵ
			if (!sign[k] && minV + route[v0][k] < dis[k]) {
				dis[k] = minV + route[v0][k];
				costV[k] = costV[v0] + cost[v0][k];
			}
			else if (!sign[k] && minV + route[v0][k] == dis[k] && costV[k] > costV[v0] + cost[v0][k]) {
				costV[k] = costV[v0] + cost[v0][k];
			}
		}
	}
}
int main() {
	int v, e, s, d;
	cin>>v>>e>>s>>d;

	//��ʼ������ͼ
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++) {
			route[i][j] = route[j][i] = INF;
			cost[i][j] = cost[j][i] = INF;
		}

	//����·��Ȩֵ�ͷ���Ȩֵ
	for (int i = 0; i < e; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		route[a][b] = route[b][a] = c;
		cost[a][b] = cost[b][a] = d;

	}

	for (int i = 0; i < v; i++) {
		//route[i][s]Ϊ��i����ʼ��ľ���
		dis[i] = route[i][s];
		costV[i] = cost[i][s];
	}
	Dijkstra(s, v, d);
	cout << dis[d] << " " << costV[d] << endl;
	system("pause");
	return 0;
}