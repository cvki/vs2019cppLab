/***������ʹ��C++ʵ��3~5�ֲ�ͬ�����㷨���������¸��Ӷ�������һ�֣�O(n^2),O(nlogn),O(n)***/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1. O(n^2):bubble\select\insert
void bubblesort(vector<int>& v) {
	//��Ҫ˼·���ӵ�һ��Ԫ�ؿ�ʼ�����κͺ���Ԫ�������Ƚϣ���¼;����������ֵ�������両����������õ���һ������Ԫ��
	//֮���Դ����ƣ�����ʣ��len-1������Ԫ�أ�ֱ������
	int len = v.size();
	for (int i{}; i < len-1; ++i) {	//i��ʾ��i������(��ֵ)�����ʣһ��Ԫ��Ϊ����
		for (int j{}; j < len - 1 - i; ++j) {	//j��ʾÿ������Ԫ������
			//�����������Ԫ��
			if (v[j] > v[j + 1]) { 
				int tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
		}
	}
}

void selectsort(vector<int>& v) {
	//��Ҫ˼·���ӵ�0λ��ʼ����κ͸��������Ԫ�ؽ��бȽϣ�������ֵ�䵽��λ��
	//Ȼ���Դ����ƣ��ӵڶ�λ��ʼ���ҵ�ǰ��ֵ...ֱ������
	int len = v.size();
	for (int i(0); i < len; ++i) 	//��i��ѭ��
		for (int j = i + 1; j < len; ++j)  //����i֮�������Ѱ�ҵ�ǰ��ֵ
			if (v[i] > v[j])  // v[i]��Ϊ��ǰ��ֵ
				swap(v[i], v[j]);
}

void insertsort(vector<int>& v) {
	//��Ҫ˼·��һ��Ԫ��ʱΪ��������ʱ�����з�Ϊ�������к��������У������������е�Ԫ�����β������������У��ұ�������������Ȼ����
	int count = 0; //��¼������������
	int len = v.size();
	for (int i{}; i < len-1; ++i) {//i��¼��������ͷ��
		int j = i + 1; //jָ�������Ԫ��(����������Ԫ��)
		int dest = v[j]; //��¼����Ԫ��
		for (; j > 0; --j) {
			if (dest < v[j - 1])
				v[j] = v[j - 1];
			else  //����ԭ��
				break;
			count++;
		}
		v[j] = dest; //����Ԫ��
	}
	/*cout << "count= " << count << endl;*/
}

//shellsort O(n^2)��O(n^1.3)
void shellsort(vector<int>& v) {
	//�Բ���������Ż��������������϶�ʱ��һ��������������
	//��Ҫ˼�룺�Ƚ��оֲ�����Ȼ������������ͨ������Ķ�̬�仯��ʵ��
	int count = 0; //��¼������������
	int len = v.size();
	int delta = len / 2; //��ʼ������ã�����򵥱仯Ϊÿ��/2
	while (delta) {
		//ÿ�����ֱ�Ӳ�������
		for (int i = 0; i < delta; ++i) { //����ÿ��ͷ��ѭ��
			for (int j = i; j + delta < len; j += delta) {//ÿһ����б���
				int index = j + delta; //���ŵ�һ���������±�
				int tmp = v[index];
				while (index > i){ //��0������������б���
					if (tmp < v[index - delta]) {	//Ŀ��ֵ��ͬ��ֵ�Ƚϣ������������ʽ
						v[index] = v[index - delta]; //Ԫ�غ���
						index -= delta;
					}
					else
						break;
					count++;
				}
				v[index] = tmp; //���뵽Ӧ�õ�λ��
				/*for (int e : v)
					cout << e << " ";
				cout << endl << "count= " << count << endl;*/
			}
		}
		delta /= 2;
	}
}

//2. O(nlogn):quicksort\mergesort\heapsort
void quicksort(vector<int>& v, int begin, int end) {
	//��Ҫ˼·��ѡ��tagֵ��˫ָ��ָ����β��ͬ���������ҵ��е�ֵ�󣬲���tag���ݹ�����е����Ҳ���
	if (begin < end) { //��ָ�벻����ʱ(����Ԫ��>1)
		int tagnum = v.at(begin), left = begin, right = end;
		while (left < right) {
			while (left<right && v[right]>tagnum) //�Ӻ���ǰ
				--right;
			v[left++] = v[right];
			while (left < right && v[left] < tagnum) //��ǰ����
				++left;
			v[right--] = v[left];
		}
		v[left] = tagnum;	//tag����
		quicksort(v, begin, right); //�ݹ��󲿷�
		quicksort(v, right+1, end);  //�ݹ��Ҳ���
	}
}


//3. O(n):bucketsort 
//���������ݽ��ƾ��ȷֲ�������������ݹ�ģ��ȷ��ʱ��������Ϻ�
/**��Ҫ˼�룬�������ݹ�ģ�����ݷֲ�ȷ��Ͱ�ĸ�������Ӧ������ӳ�䵽��ͬͰ�У�ʹ��Ͱ��Ͱ֮������
֮���ڸ���Ͱ������Ȼ����������**/
const int BKNUM = 5;  //5��Ͱ
const int BKSIZE = 20;	//ÿ��Ͱ������
void bucketsort(vector<int>& v) {
	int bk[BKNUM][BKSIZE]{};//Ͱ
	int len[BKNUM]{};//��¼ÿ��Ͱ��ʵ�ʴ洢��Ŀ
	for (int e : v) {
		//��ÿ��Ͱ��10������0-9��10-19��20-29...
		bk[e / 10][len[e / 10]] = e; //����ָ��Ͱ��
		++len[e / 10]; //ÿ��Ͱ�ڼ�������
	}
	for (int i{}; i < BKNUM; ++i) 
		//ÿ��Ͱ������
		sort(bk[i], bk[i] + len[i]);
	v.erase(v.begin(), v.end()); //���ԭ����
	//���Ƶ�v��
	for (int i=0; i<BKNUM; ++i)
		for (int j=0; j< len[i]; ++j)
			v.push_back(bk[i][j]);
}



//test
int main() {
	vector<int> v{ 38,12,22,23,21,17,6,31,33,16,21,5,7,1,6,40,0 };
	//vector<int> v{4,3,1,2};
	for (int e : v)
		cout << e << " ";
	cout << endl << "after sorted��" << endl;
	
	//bubblesort(v);
	//selectsort(v);
	//insertsort(v);
	//shellsort(v);
	//quicksort(v,0,v.size()-1);
	//bucketsort(v);
	
	for (int e : v)
		cout << e << " ";

	return 0;
}