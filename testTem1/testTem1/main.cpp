#include<iostream>
using namespace std;

//extern class A;

void gradientDescent();
void gdecent2();
void regularE(double* theta0, double* theta1);

int main() {
	//���캯������
	//A a(2), b;
	//b = a + 5;
	//cout << a << endl << b << endl;

	//�����ݶ��½��㷨
	gdecent2();
	cout << "*******************************************" << endl;
	gradientDescent();
	cout << "*******************************************" << endl;
	double x0,x1;
	regularE(&x0, &x1);
	cout << "theta0: " << x0 << "\t" << "theta1: " << x1<<endl;
	return 0;
}