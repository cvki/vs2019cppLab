#include<iostream>
#include<easyx.h>
#pragma comment(lib,"winmm.lib")

using namespace std;

#if 0
int x1() {
	//1.��������
	initgraph(640, 640);

	//2.���ꡣ�������Ͻ�Ϊ����ԭ�㣬������x��������y

	//3.��ɫ��������ɫ�ú궨�壬��WHITE BLACK BLUE RED, ������ɫ��RGB�ϳɣ��磺RGB(0,255,255)

	//ˢ�£�
	setbkcolor(RGB(233, 211, 222));	//���ñ�����ɫ
	cleardevice();	//����豸��ʹ��ָ����ɫˢ��

	//����:(���ִ�����windows api�ģ�ֻ��easyX��װ�˲���win API)
	//1. �����ļ��� ͷ�ļ�(ʹ��include����)��mmsystem.h    ���ļ�(������ʽ��#pragma comment(lib,"winmm.lib"))��winmm.lib�����ļ��İ�����C����Ԥ����������
	//�����ӿڣ�mciSendString();  //media control interface, send, string,ý����ƽӿ��У����������ַ�����һ������
	//�����ļ����ڸ�cpp���ڵ��ļ�Ŀ¼��(��cpp�������ļ�Ӧ��ͬ��������������·��)

	/***�ú����ᱨ��(��ʦֱ���õ��������)��ʹ������ĺ�����ȷ
	mciSendString("open xxx.mp3", 0, 0, 0); //xxx.mp3Ϊ�����ļ���
	mciSendString("play xxx.mp3", 0, 0, 0);
	mciSendString("pause xxx.mp3", 0, 0, 0);
	mciSendString("close xxx.mp3", 0, 0, 0);
	***/
	
	//ע�������ļ���Ҫ��1.���������صĲ���(������ѹ���ĸ�ʽ��һ��Ĳ�һ����windows���API��ȡ����)��2.�ļ��������пո�  3.�ļ�ȫ��  4.�ú���ֻ�ܶ�ȡmp3��ʽ��Ƶ

	mciSendStringA("open xxx.mp3", 0, 0, 0); //xxx.mp3Ϊ�����ļ�������������ļ��Ĵ򿪣����ţ���ͣ���رա�
	mciSendStringA("play xxx.mp3", 0, 0, 0);
	mciSendStringA("pause xxx.mp3", 0, 0, 0);
	mciSendStringA("close xxx.mp3", 0, 0, 0);

	//ͼƬ
	/*1.��ͨ��ͼ
	* 2.������ͼ
	* 3.͸����ͼ
	***/
	// 1. ��ͨ��ͼ
	IMAGE pic1; //����ͼƬ����
	//loadimage(&pic1, "im.jpg",640,640); //�ᱨ�������ʾ�ö��Ŀ�͸ߴ洢���ͼƬ��Ϊ��ͼƬ��ʾЧ������ñ���ԭ��ͼƬ�ĵȱ�����
	loadimage(&pic1, L"im.jpg", 640, 640);
	putimage(0, 0, &pic1);//��ʾԭ���ڣ�0��0����������pic1ͼƬ

	//2.������ͼ
	BeginBatchDraw();//��ʼ������ͼ
	
	putimage(0, 0, &pic1);//ԭ�������еĻ�ͼ�����м�

	EndBatchDraw();//����������ͼ

	//3. ͸����ͼ
	//a ׼��2��ͼƬ���ڵװ���Ͱ׵ײ���
	IMAGE picx, picy;
	loadimage(&picx, "11.jpg", 50, 50);
	loadimage(&picy, "22.jpg", 50, 50);
	//b ����ͼ����ͬһλ��
	putimage(320, 240, &picx);
	putimage(320, 240, &picy);
	//c �ֱ�ʹ��SRCPAINT,SRCAND ��ͼ��ʽ
	putimage(320, 240, &picx, SRCPAINT);
	putimage(320, 240, &picy, SRCAND);


	system("pause");
	return 0;
}
#endif
int x2() {
	int a[3] = { 4, 5, 6 };
	cout << 0[a] << 2[a]<<endl; 
	cout << a[0] << a[2]<<endl;
	return 0;
}

int main() {


	return 0;
}