// 2021-12-7.buaa�㷨��ҵ3������������������

/**��Ŀ����������һ����������nums���ҵ�һ���������͵����������飬���������Ͳ�������������±�***/
#include<iostream>
#include <vector>

using namespace std;

const int MAXS = 500;
int sum[MAXS][MAXS];

//3 5 -1 2 -7 -9 6 4		3 7 -2 -7 5 -1   1 -2 -4 2 -5
//-4 1 2 -5 3 4 -2 -1 4		2 -1 -1 -1 -1 3		-2 1 0

int getmSum1(int num[],const int len) {//len��1��ʼ
	int begin = 0, end = 0;//��¼�����������ֹ�±�	
	if (len > 1) {
		for(int i=0;i<len;i++)//�������i
			for (int j = i+1; j < len; j++) {//�����յ�j
				if (sum[i][j - 1] + num[j] < num[j]) {
					//�����￴������ʵֻ��Ҫ�жϵ�ǰsum�Ƿ�为������
					sum[i][j] = num[j];
				}
				else
					sum[i][j] = sum[i][j - 1] + num[j];
			}
		//�ӽ����õı����ҳ����ֵ��������к͵��±�
		int s=sum[0][0];
		for (int i = 0; i < len; i++)
			for (int j = i; j < len; j++) {
				if (s <= sum[i][j]) {//��¼��ǰ���Ŀ������
					begin = i;
					end = j;
					s = sum[i][j];
				}
			}
	}
	//for (int i = 0; i < len; i++) {
	//	cout << endl;
	//	for (int j = i; j < len; j++) {
	//		cout << sum[i][j]<<"  ";
	//	}
	//}	
	cout << endl << "getmSum1����������±�Ϊ��" << begin << "-->" << end << endl; 
	return sum[begin][end];
}

//�Ż�
int getmSum2(int num[], const int len) {
	int sum=num[0];//��¼��ǰ�ֲ�����
	int	max = sum;//��¼ȫ������
	bool has_pos = false;//��ʾnum�����Ƿ�ȫ������,��ʼĬ��ȫΪ������0
	for (int i = 1; i < len; i++) {
		if (sum > 0) {
			has_pos = true; //����������ʶ��Ϊtrue
			sum += num[i];
		}
		else  //���¼�¼�������
			sum = num[i];
		if (max < sum) //�޸����ֵ������
			max = sum;
	}
	if (!has_pos) {//û������
		for (int i = 0; i < len; i++) {//��Ϊ�����ֵ����
			if (max < num[i]) 
				max = num[i];
		}
	}
	return max;
}


int main1() {
	int nums[MAXS];
	int len; //��¼����Ԫ�ظ���
	while (1) {
		cout << "�������г���(����-1�˳�)��" << endl;
		cin >> len;
		if (len > 0) {
			cout << "�����������У�" << endl;

			//�������ݣ�ͬʱ��ʼ��sum��(�Խ���Ϊ��ʼֵ��ֻ�ñ�������ǲ���)
			for (int i = 0; i < len; i++) {
				cin >> nums[i];
				sum[i][i] = nums[i];
			}
			//Ѱ������������������	
			int s1 = getmSum1(nums, len);
			int s2 = getmSum2(nums, len);
			cout << "getmSum1���������ͣ�" << s1 << endl;
			cout << "getmSum2���������ͣ�" << s2 << endl;
			//if (s1 == s2)
			//	cout << "TRUE" << endl;
			//else
			//	cout << "FALSE" << endl;
		}
		else
			break;
		cout <<"********************************************************************"<< endl;
	}
	return 0;
}


//2th

//testcase:
// //3,5,-1,2,-7,-9,6,4    	3,7,-2,-7,5,-1   1,-2,-4,2,-5
// //-4, 1, 2, -5, 3, 4, -2, -1, 4		 2, -1, -1, -1, -1, 3	 	-2, 1, 0
//method 1--3loop, ������
int getSumij(int a[], int i, int j) {  //����ÿ�����еĺ�
	int sum = 0;
	while (i <= j) {
		sum += a[i++];
	}
	return sum;
}
int getmaxsum1(int a[], int len,int& left, int& right) {
	if (len < 1)
		return 0;
	int sum = a[0];
	for (int i = 0; i < len; i++) //i��ʾ�������
		for (int j = i; j < len; j++) {  //j��ʾ�����յ�
			int tem = getSumij(a, i, j);  //��������к�
			if (tem > sum) {  //Ŀǰ������¼�ú��������±�
				sum = tem;
				left = i;
				right = j;
			}
		}
	return sum;
}

//method 2--DP����̬�滮
int getmaxsum2(vector<int>& nums, int& left, int& right) {
	int len = nums.size();
	if (len < 1)
		return 0;
	vector<int> di(nums);	//di���ڴ洢ֱ����ǰλ�ô������ͣ���˳���˼·

	/*vector<int> di;
	di.reserve(nums.size());*/	//��ʹ�ø÷���Ԥ��di�ռ�(��ʱδ���κθ�ֵ)��Ȼ��ʹ��

	/*nums[3] = 465;	
	cout << di[3] <<" "<<nums[3] << endl;*/  //��֤vector������������

	di.at(0) = nums.at(0);	//at������"[]"������
	for (int i = 1; i < len; i++) {
		di.at(i) = max(nums.at(i), nums.at(i) + di.at(i - 1)); //DP�ݹ鹫ʽ��˼· 
		//�Ӹþ���Կ�����ֻ��Ҫ�жϵ�ǰ�Ӻ͵�������Ȼ�����ѡ�񼴿ɡ�
	}

	//�ҵ��������
	int maxsum = di[0];
	for(int i=0;i<len;i++)
		if (di.at(i) > maxsum) {
			maxsum = di.at(i);
			right = i;   //�Ҷ�����
		}
	//����Ѱ��������꣬��˵�һ��di[i]=nums[i]��Ϊ�������
	for (int i = right; i >= 0; --i) {
		if (nums.at(i) == di.at(i)) {
			left = i;
			break;
		}
	}
	return maxsum;
}

//DP�����Ż�(ֻ�õ����ͽ��)
int getmaxsum3(vector<int>& nums, int& left, int& right) {
	int sumk = 0, anssum = nums.at(0);
	//sumk��¼��ǰλ�õ����ֵ��anssum��¼ȫ�����ֵ
	for (auto e : nums) {
		sumk = max(e, e + sumk);
		anssum = max(anssum, sumk);
	}
	return anssum;
}


int main() {

#if 0
	//2th,��������������������
	int a[] = { -2,1,0 };
	int left = 0, right = 0; //��ʾ�±�
	int len = sizeof(a) / sizeof(int);
	int sum= getmaxsum1(a, len, left, right);
	cout << "sum="<<sum<<"\t" << "[" << left << ", " << right << "]" << endl;

	vector<int> v { -4, 1, 2, -5, 3, 4, -2, -1, 4 };
	int left = 0, right = 0; //��ʾ�±�
	int sum=getmaxsum2(v, left, right);
	cout << "sum=" << sum << "\t" << "[" << left << ", " << right << "]" << endl;
	sum = getmaxsum3(v, left, right);
	cout << "sum=" << sum << "\t" << "[" << left << ", " << right << "]" << endl;
#endif





	return 0;
}
