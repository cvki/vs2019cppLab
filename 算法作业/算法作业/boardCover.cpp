#include<iostream>
#include"Boardn.h"
using namespace std;



void cover(Boardn& bd,int ax, int ay, int step, int dx, int dy) {
	//�������̹������߼�,a��ʾ����ԭ�����꣨����ȡ���Ϸ���Ϊԭ�㣩��d��ʾ������꣬step��ʾ���̺��ݳ�
	if (step == 1)
		return;
	else {//����
		step /= 2; //��������
		int nextx = ax + step;
		int nexty = ay + step;
		//���������λ�ý��з�������
		if (dx < nextx && dy < nexty) {//����
			//���������������̽�����α��㣬��λ��ǡ������һ����λ���
			bd.setvp(nextx-1, nexty,1); //����
			bd.setvp(nextx, nexty-1,1); //����
			bd.setvp(nextx, nexty,1);	//����
			//�ݹ�������
			cover(bd,ax, ay, step, dx, dy);//�ݹ�����
			cover(bd,ax, nexty, step, nextx-1, nexty);//�ݹ�����
			cover(bd, nextx, ay, step, nextx, nexty-1);//�ݹ�����
			cover(bd, nextx, nexty, step, nextx, nexty);//�ݹ�����
		}
		else if(dx>nextx&&dy<nexty){//����
			//ͬ��
			bd.setvp(nextx-1, nexty - 1,2); 
			bd.setvp(nextx, nexty-1,2); 
			bd.setvp(nextx, nexty,2);
			cover(bd, ax, ay, step, nextx - 1, nexty - 1);
			cover(bd, ax, nexty, step, dx, dy);
			cover(bd, nextx, ay, step, nextx, nexty-1);
			cover(bd, nextx, nexty, step, nextx, nexty);
		}
		else if (dx < nextx && dy > nexty) {//����
			bd.setvp(nextx-1, nexty - 1,3);
			bd.setvp(nextx-1 , nexty,3);
			bd.setvp(nextx, nexty,3);
			cover(bd, ax, ay, step, nextx - 1, nexty - 1);
			cover(bd, ax, nexty, step, nextx-1, nexty);
			cover(bd, nextx, ay, step, dx, dy);
			cover(bd, nextx, nexty, step, nextx, nexty);
		}
		else {//����
			bd.setvp(nextx-1, nexty - 1,4);
			bd.setvp(nextx-1 , nexty,4);
			bd.setvp(nextx, nexty-1,4);
			cover(bd, ax, ay, step, nextx - 1, nexty - 1);
			cover(bd, ax, nexty, step, nextx - 1, nexty);
			cover(bd, nextx, ay, step, nextx,nexty-1);
			cover(bd, nextx, nexty, step, dx,dy);
		}
	}
}