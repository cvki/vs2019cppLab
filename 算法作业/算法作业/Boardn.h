#pragma once
class Boardn
{
private:
	int** board; //��������ָ��
	int n; //���̹�ģΪn by n,����n=2^k
	int dx; //����������
	int dy;
	Boardn& operator=(Boardn&);
public:
	Boardn();
	Boardn(int an);
	Boardn(const Boardn& bd);
	bool setGap(const int& x, const int& y); //������㣬ֵΪ-1��ʾ�õ�Ϊ���
	int getN()const; //�������̹�ģ
	int getDx() const; //��������������
	int getDy() const; 
	void setvp(int x, int y, int v); //Ϊ���̸������ֵ
	void show()const; //�������
	~Boardn();
};

