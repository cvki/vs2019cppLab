#include"swapTest.hpp"
#include<iomanip>
#include "sortA.cpp"



//


int main() {

#if(0)
	int a, b;
	char c1, c2;
	string s1, s2;
	cout << "input int num:" << endl;
	cin >> a >> b;
	cout << "input char num:" << endl;
	cin >> c1>>c2;
	//Ϊʲôc1��c2֮�䲻��getchar(),c2Ҳ���������룿��Ϊcin��scanf��ͬ��cin���Կո񲢽�����Ϊ������־����������c1����������ո�cinҲ��������ŵ�c2���Ϊʲôû�е�����������>>c2���³����أ�
	//��Ϊcin�����ո�����ֹ��ǰ�����룬Ҳ����c1֮������룬������Ӱ���������c2�����룬cin�����հ׷��ǰ��������ˣ���������ֹ������߶����������������ݲ���Ӱ�졣

	getchar();//���λ�ñ������getchar()������getline(s1)�������س�����s1=NULL
	cout << "input string num:" << endl;
	getline(cin, s1);
	getline(cin, s2);
	swapT(a, b);
	swapT(c1, c2);
	swapT(s1, s2);

	cout << "after swap():" << endl;
	cout << a << "\t" << b << endl << c1 << "\t" << c2 << endl << s1 << "\t" << s2 << endl;
	//cout << s1 << "\t" << s2 << endl;
#endif

	int a[8] = { 7,3,0,9,2,6,5,4 };
	int b[8] = { 7,3,0,9,2,6,5,4 };
	int c[8] = { 7,3,0,9,2,6,5,4 };
	int d[8] = { 7,3,0,9,2,6,5,4 };
	int e[8] = { 7,3,0,9,2,6,5,4 };
	//int a[3] = { 7,6,1};
	sortA<int> s1;

	int len = sizeof(a) / sizeof(*(a));
	cout << "len: " << len << endl;

	s1.bubbleSortA(a, len);
	cout << "bubbleSort(): " << endl;
	s1.show(a, len);

	s1.selectSortA(b, len);
	cout << "selectSortA(): " << endl;
	s1.show(b, len);

	//quickSorttt(c, 0, len - 1);
	
	s1.quickSortA(c, 0, len - 1);
	cout << "quicksortA(): " << endl;
	s1.show(c, len);

	s1.insertSortA(d, len);
	cout << "insertSortA(): " << endl;
	s1.show(d, len);

	s1.mergeSortA(e, len);
	cout << "mergeSortA(): " << endl;
	s1.show(e, len);

	return 0;
}