//������ʱ�����淽��
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;
const int SIZEDATA = 10;
vector<double> dataX;
vector<double> dataY;

void regularE(double *theta0, double *theta1) {
	ifstream in("C:\\Users\\buaa203\\Desktop\\testX.txt");
	double tmp1, tmp0, xtx = 0;
	while (in >> tmp0 >> tmp1 && tmp1 != -1) {
		xtx += tmp0 * tmp0;
		dataX.push_back(tmp0);
		dataY.push_back(tmp1);
	}
	//in >> theta0 >> theta1;//���淽��ֱ�����theta������Ҫ��ֵ�����������ݶ��½������Ľ����ͬ
	xtx = 1 / xtx;
	tmp0 = tmp1=0;
	for (int i = 0; i < dataX.size(); i++) {
		tmp0 += dataY.at(i);
		tmp1 += dataX.at(i) * dataY.at(i);
	}
		
	*theta0 = tmp0;
	*theta1 = tmp1 * xtx;
	in.close();
}

	
