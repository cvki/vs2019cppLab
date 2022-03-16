//21-12-07  buaa�㷨��ҵ4����̤��������

//��д�ĵ��ˣ���дһ�¸�����͸������̰�Ĳ���
/**�����������Թ����⣬��Ҫ�Եݹ�ͻ��ݷ�Ϊ��������ĵݹ���63��ѭ������������ʹ�û��ݷ���Ч�ʷǳ��ͣ����Ϊ8^(N*N)���Ӷȣ�����ʹ��̰���㷨�Ż���
* ̰�Ĳ����ڵ������ݵĻ����ϣ����´�ѡ��·�������Ż���������һ�㷽���İ�������仯�������н���������
* ̰�Ĳ��Զ��´�����·�����´ο�ѡ��·����Ŀ����ͳ�ƣ�Ҳ�������´γ�·��Ŀ��ȡ����Ϊ̰��Ȩ�أ�������Ȩ��С��ѡ��·����
* ��Ϊ��·����Ȩ��С����ζ����������·�������´��ٹ����ĸ��ʾͺ�С��Ҳ����˵�ܿ��ܸ�λ�����Ժ�ı����ж���������������Ҫ���ݺܳ������ٹ�������͵���ʱ�临�Ӷȴ��������
* ��Ȼ����´ο�ѡ·��ֻ��һ������ֱ���ߣ�����´ο�ѡ·����Ȩ������ȣ����԰���ʼ��������仯������˳�����ߣ����Ӱ�첻��
***/
#include<iostream>
#include<iomanip>
using namespace std;

typedef struct coordinate { //�����¼����
    int x;
    int y;
}codnt;

int chessboard[8][8] = { 0 }; //���̣��洢·����ţ��������

bool travel(codnt *start) {
    codnt move[8] = { {-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2} }; //ÿ��λ�õ��´�����仯��
    codnt next[8] = { 0 };  //��¼�´ο��ߵ�·��
    int ways[8] = { 0 };   //��¼�´ο���·���ĳ�·��
    codnt *tmp=new codnt;
    int count, counttmp, min, tmp1;     //count��¼��ǰλ�ÿ��ߵĳ�·����min��¼���´�·�������ٵ�·���±꣬����̰��ѡ��
    chessboard[start->x][start->y] = 1;     //��һ��Ϊ��ʼλ�� 
    for (int n = 2; n <= 64; n++) {     //ѭ��2~64��λ�� 
        for (int m = 0; m < 8; m++) {
            ways[m] = 0;    //��ո�λ�õĳ�·�� 
        }
        counttmp = 0;
        for (int j = 0; j < 8; j++) {   //��̽8������ 
            tmp->x = start->x + move[j].x;
            tmp->y = start->y + move[j].y;
            if (tmp->x < 0 || tmp->y < 0 || tmp->x>7 || tmp->y>7)  continue; //�ô��޳���ʱ
            if (chessboard[tmp->x][tmp->y] == 0) {
                next[counttmp] = *tmp;  //�����ߵ�λ�ñ�����next�� 
                counttmp++;     //��λ�ó������� 
            }
        }
        count = counttmp;
        if (count == 0) return false;  //�޳�·λ��
        else if (count == 1) min = 0;   //�´�ֻ��һ��·����ѡ
        else {   //�´��ж�����·��ѡʱ
            for (int m = 0; m < count; m++) {
                for (int j = 0; j < 8; j++) {
                    tmp->x = next[m].x + move[j].x;
                    tmp->y = next[m].y + move[j].y;
                    if (tmp->x < 0 || tmp->y < 0 || tmp->x>7 || tmp->y>7)  continue;
                    if (chessboard[tmp->x][tmp->y] == 0)  ways[m]++;    //����λ�õĳ�·���� 
                }
            }
            //�����´γ�·����ΪȨ�أ�����̰��ѡ��ѡ����СȨ����·����Ϊ�´�·��
            tmp1 = ways[0];
            min = 0;
            for (int m = 1; m < count; m++) {   //�ҳ�����λ���г�·�������ٵ�·���±��min
                if (ways[m] < tmp1) {
                    tmp1 = ways[m];
                    min = m;
                }
            }
        }
        *start = next[min]; //��������·�������ٵ�λ�� 
        chessboard[start->x][start->y] = n; //��������·��
    }
    delete tmp;
    return true;
}

int main() {
    codnt *start=new codnt;
    cout << "���������ʼ����λ��(��1��ʼ)��";
    cin >> start->x >> start->y;
    if (start->x < 1 || start->y < 1 || start->x>8 || start->y>8) {
        cout << "��������������������룡" << endl;
        exit(0);
    }
    start->x -= 1;
    start->y -= 1;
    if (travel(start)) {
        cout << "������˳���ߣ�" << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << setw(3) << chessboard[i][j];
            }
            cout << endl;
        }
    }
    else {
        cout << "����ʧ��" << endl;
    }
    delete start;
    system("pause");
    return 0;
}

