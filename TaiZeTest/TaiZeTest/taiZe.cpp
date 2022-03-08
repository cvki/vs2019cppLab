/***描述：使用C++实现3~5种不同排序算法，其中以下复杂度至少有一种：O(n^2),O(nlogn),O(n)***/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//1. O(n^2):bubble\select\insert
void bubblesort(vector<int>& v) {
	//主要思路，从第一个元素开始，依次和后面元素两两比较，记录途中遇到的最值，最终其浮动到最顶部，得到第一个有序元素
	//之后以此类推，排序剩余len-1个无序元素，直至结束
	int len = v.size();
	for (int i{}; i < len-1; ++i) {	//i表示第i轮排序(最值)，最后剩一个元素为有序
		for (int j{}; j < len - 1 - i; ++j) {	//j表示每轮排序元素索引
			//浮动该轮最大元素
			if (v[j] > v[j + 1]) { 
				int tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
		}
	}
}

void selectsort(vector<int>& v) {
	//主要思路，从第0位开始，逐次和各后面各个元素进行比较，最终最值落到该位。
	//然后以此类推，从第二位开始再找当前最值...直至结束
	int len = v.size();
	for (int i(0); i < len; ++i) 	//第i轮循环
		for (int j = i + 1; j < len; ++j)  //遍历i之后的序列寻找当前最值
			if (v[i] > v[j])  // v[i]记为当前最值
				swap(v[i], v[j]);
}

void insertsort(vector<int>& v) {
	//主要思路，一个元素时为有序，排序时将序列分为有序序列和无序序列，将无序序列中的元素依次插入至有序序列，且保持有序序列仍然有序
	int count = 0; //记录基本操作次数
	int len = v.size();
	for (int i{}; i < len-1; ++i) {//i记录无序序列头部
		int j = i + 1; //j指向待插入元素(无序序列首元素)
		int dest = v[j]; //记录待插元素
		for (; j > 0; --j) {
			if (dest < v[j - 1])
				v[j] = v[j - 1];
			else  //呆在原处
				break;
			count++;
		}
		v[j] = dest; //插入元素
	}
	/*cout << "count= " << count << endl;*/
}

//shellsort O(n^2)、O(n^1.3)
void shellsort(vector<int>& v) {
	//对插入排序的优化，对于数据量较多时，一个间隔的排序较慢
	//主要思想：先进行局部有序，然后再深入排序，通过间隔的动态变化来实现
	int count = 0; //记录基本操作次数
	int len = v.size();
	int delta = len / 2; //初始间隔设置，这里简单变化为每次/2
	while (delta) {
		//每组采用直接插入排序
		for (int i = 0; i < delta; ++i) { //按照每组头部循环
			for (int j = i; j + delta < len; j += delta) {//每一组进行遍历
				int index = j + delta; //待排第一个数和其下标
				int tmp = v[index];
				while (index > i){ //往0方向在有序表中遍历
					if (tmp < v[index - delta]) {	//目标值和同组值比较，这里采用升序方式
						v[index] = v[index - delta]; //元素后移
						index -= delta;
					}
					else
						break;
					count++;
				}
				v[index] = tmp; //插入到应该的位置
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
	//主要思路：选定tag值，双指针指向首尾，同向搜索，找到中点值后，插入tag，递归遍历中点左右部分
	if (begin < end) { //两指针不相遇时(区间元素>1)
		int tagnum = v.at(begin), left = begin, right = end;
		while (left < right) {
			while (left<right && v[right]>tagnum) //从后往前
				--right;
			v[left++] = v[right];
			while (left < right && v[left] < tagnum) //从前往后
				++left;
			v[right--] = v[left];
		}
		v[left] = tagnum;	//tag插入
		quicksort(v, begin, right); //递归左部分
		quicksort(v, right+1, end);  //递归右部分
	}
}


//3. O(n):bucketsort 
//适用于数据近似均匀分布的情况，当数据规模不确定时，用链表较好
/**主要思想，根据数据规模和数据分布确定桶的个数，相应的数据映射到不同桶中，使得桶与桶之间有序，
之后在各个桶内排序，然后整体有序**/
const int BKNUM = 5;  //5个桶
const int BKSIZE = 20;	//每个桶的容量
void bucketsort(vector<int>& v) {
	int bk[BKNUM][BKSIZE]{};//桶
	int len[BKNUM]{};//记录每个桶的实际存储数目
	for (int e : v) {
		//设每个桶存10个数：0-9，10-19，20-29...
		bk[e / 10][len[e / 10]] = e; //放入指定桶中
		++len[e / 10]; //每个桶内计数个数
	}
	for (int i{}; i < BKNUM; ++i) 
		//每个桶内排序
		sort(bk[i], bk[i] + len[i]);
	v.erase(v.begin(), v.end()); //清空原数据
	//复制到v中
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
	cout << endl << "after sorted：" << endl;
	
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