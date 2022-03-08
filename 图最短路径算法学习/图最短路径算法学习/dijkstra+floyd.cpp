/**���㷨����Ը�������㣬�õ���
�����е㵽���������·��**/
#include<iostream>

using namespace std;

template<typename T1, typename T2>
void showDk(T1** graph, T1*& dist, T2*& pre, int* sign, int vnum) {
	for (int i = 0; i < vnum; i++)
		cout << "dist: " << dist[i] << " ";
	cout << endl;
	for (int i = 0; i < vnum; i++)
		cout << "pre: " << pre[i] << " ";
	cout << endl;
	for (int i = 0; i < vnum; i++)
		cout << "sign: " << sign[i] << " ";
	cout << endl << "********************************************************************" << endl;
}

template<typename T1, typename T2>
void dijsktra(T1** graph, T1*& dist, T2*& pre, T2 begin, int* sign, int vnum) {
	for (int i = 0; i < vnum; i++) {
		for (int j = 0; j < vnum && !sign[i]; j++) {
			if (dist[j] > dist[i] + graph[i][j]) {
				dist[j] = dist[i] + graph[i][j];
				pre[j] = i;
			}
			//show(graph, dist, pre, sign, vnum);
		}
		sign[i] = 1;
	}
}

//floyd�㷨�����ڶ�Դ��㵽����������·����ʱ�临�Ӷ�:O(n^3)���ռ临�Ӷ�:O(n^2)��
//�����ڳ���ͼ���ڳ���ͼ�е�Ч��Ҫ����V�ε�Dijkstra�㷨������VΪ�ڵ���Ŀ
template<typename T1>

void floyd(T1** graph, int vnum) {
	//����������ά���飬�ֱ�洢��ǰ���·�������·�������Ľڵ�
	T1 **gph=new T1*[vnum];//�洢�ڵ��ľ���
	int **pre = new int* [vnum];//�洢ǰ���ڵ�

	//��ʼ��
	for (int i = 0; i < vnum; i++) {
		gph[i] = new T1[vnum];
		pre[i] = new int[vnum];
		for (int j = 0; j < vnum; j++) {
			gph[i][j] = graph[i][j];
			pre[i][j] = -1;
			
		}
	}
	for (int k = 0; k < vnum; k++) {
		for (int i = 0; i < vnum; i++)
			for (int j = 0; j < vnum; j++)
			{//��̬�滮����k��Ϊ�м�ڵ㣬��̽�Ƿ���ͨ��k�س�i��j�����·��
				if (gph[i][j] > gph[i][k] + gph[k][j]) {
					gph[i][j] = gph[i][k] + gph[k][j];//�������·��
					pre[i][j] = k;//����ǰ���ڵ�
				}
			}
	}	

	//���
	for (int i = 0; i < vnum; i++) {
		for (int j = 0; j < vnum; j++) {
			cout << gph[i][j]<<" ";
		}
		cout <<endl;
	}
	for (int i = 0; i < vnum; i++) {
		for (int j = 0; j < vnum; j++) {
			if (pre[i][j] != -1)
				cout << pre[i][j] << " ";
			else
				cout << "X" << " ";
		}
		cout << endl;
	}
}

int test_1() {//main����
	int vnum;//�ڵ���
	cout << "��������Ŀ��" << endl;
	cin >> vnum;
	float** graph = new float* [vnum];;//�ڽӾ���
	cout << "�����ڽӾ���(��·��������999)��" << endl;
	for (int i = 0; i < vnum; i++) {
		graph[i] = new float[vnum];
		for (int j = 0; j < vnum; j++) {
			cin >> graph[i][j];
		}
	}

	float* dist = new float[vnum];//�洢ÿ���ڵ�����·��ֵ
	int* pre = new int[vnum];//�洢ÿ���ڵ����һ���ڵ�
	int* sign = new int[vnum]();//��¼��ǰ�ڵ��Ƿ��ѱ����ʼ���
	int begin;// ��ʼ�ڵ�

	cout << "����������(��0��ʼ)��" << endl;
	cin >> begin;

	//��ʼ�� 
	pre[begin] = -1;
	for (int i = 0; i < vnum; i++) {
		if (i != begin)
			pre[i] = begin;
		sign[i] = 0;
		dist[i] = graph[begin][i];
	}
	//dist[begin] = 0;//��㵽���ľ���Ϊ0
	//sign[begin] = 1;//��ʾ����Ѿ������ʼ���

	dijsktra(graph, dist, pre, begin, sign, vnum);

	//���
	showDk(graph, dist, pre, sign, vnum);

	floyd(graph, vnum);

	return 0;
}

