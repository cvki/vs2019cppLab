#pragma once

#include<string>

using namespace std;

const int MAXSIZECITY = 34;
//34ʡ�����
string s[MAXSIZECITY]{ "����","���","�Ϻ�","����","����","��³ľ��","����","���ͺ���","����","������","����",
					"����","ʯ��ׯ","̫ԭ","����","����","֣��","�Ͼ�","�Ϸ�","����","����",
					"�ϲ�","��ɳ","�人","����","̨��","����","����","����","�ɶ�","����",
					"����","���","����" };

class City {
	string name;//������
	double x;//����
	double y;//γ��
public:
	City(string s, double x, double y) :name(s), x(x), y(y) {};
	string getname()const { return name; }
	double caldis(const City& c)const;
};

class CityGph {
	static string nameCity[MAXSIZECITY];//���б�
	int lenCity;//������Ŀ
	double** dis;//�ڽӾ���
public:
	CityGph(int sizeCity, double** dis);
	CityGph(const CityGph& c);
	~CityGph();
	int getSizeCity()const { return lenCity; }
	double getDis (const City& c1, const City& c2)const;
	bool setDis(const City& c1, const City& c2,double v);
};