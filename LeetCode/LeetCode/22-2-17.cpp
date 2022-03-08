#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<list>
//#include<hash_map>  //不能使用，否则报错，使用unordered_map代替
#include <unordered_map>


using namespace std;

//1. 只出现一次的数字
/**给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
示例 1:
输入: [2,2,1]
输出: 1
示例 2:
输入: [4,1,2,1,2]
输出: 4
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number  **/

//法1: 排序后查找(垃圾答案)
int singleNumber1(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	if (nums.size() == 1)
		return nums[0];
	int i = 0;
	//for (; i < nums.size() && nums[i] != nums[j]; i += 2, j += 2) {};
	while (i < nums.size() && nums[i] == nums[i+1]) {
		i += 2; 
	}
	return nums[i];
}
//法2：使用异或(优秀答案)
int singleNumber2(vector<int>& nums) {
	int res = 0;	//初值为0才不影响最后结果，因为0异或any=any
	for (auto e : nums)
		res^=e;  //异或运算^=
	return res;
}


int main1() {

	//1. 只出现一次的数字
	vector<int>	v1 = {1,5,3,4,3,2,5,1,2};
	cout<<singleNumber2(v1)<<endl;
	/*for (auto e : v1)
		cout << e << " ";*/
	return 0;
}

/****2. 两数相加
给你两个 非空 的链表，表示两个 非负 的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例 1：
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807

示例 2：
输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：
输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]

提示：
每个链表中的节点数在范围 [1, 100] 内
0 <= Node.val <= 9
题目数据保证列表表示的数字不含前导零****/


 // Definition for singly-linked list.
  struct ListNode { //不带头结点
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {} //浅拷贝
  };

//思路：表头为低位，输出为倒序输出。因此直接从表头开始相加，短表末位补0，加完的数尾插至结果表，注意进位

  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	  //为方便操作，将链表加头结点
	  ListNode* res, * p, * q;
	  res = new ListNode;
	  //res->next = nullptr;
	  p = new ListNode;
	  p->next = l1;
	  l1 = p;
	  p = new ListNode;
	  p->next = l2;
	  l2 = p;

	  p = res;
	  int cr = 0;
	  while (l1 && l2) {
		  int num = l1->val + l2->val + cr;
		  if (num > 9) {
			  num -= 10;
			  cr = 1;
		  }
		  else
			  cr = 0;
		  q = new ListNode;
		  q->val = num;
		  p->next = q;
		  p = q;
		  l1 = l1->next;
		  l2 = l2->next;
	  }
	  while (l1) {
		  int num = l1->val + cr;
		  if (num > 9) {
			  num -= 10;
			  cr = 1;
		  }
		  else
			  cr = 0;
		  q = new ListNode;
		  q->val = num;
		  p->next = q;
		  p = q;
		  l1 = l1->next;
	  }
	  while (l2) {
		  int num = l2->val + cr;
		  if (num > 9) {
			  num -= 10;
			  cr = 1;
		  }
		  else
			  cr = 0;
		  q = new ListNode;
		  q->val = num;
		  p->next = q;
		  p = q;
		  l2 = l2->next;
	  }
	  if (cr) {
		  q = new ListNode;
		  q->val = 1;
		  p->next = q;
		  p = q;
	  }
	  p->next = nullptr;
	  return res->next;
  }


//错误思路
#if 0
/***思路：1. 低位(表尾)补0补齐，使得A,B同长 
		 2. A逆置，B逆置，得A', B'
		 3. 结果C=A’+ B', C使用头插法建立  
			过程中注意进位的处理**/

 //链表输出(不带头结点)
  void showL(ListNode* L) {
	  while (L) {
		  cout << L->val << " ";
		  L = L->next;
	  }
	  cout << endl;


  void headInsert(ListNode*& L) { //头插法就地逆置(带头结点)
	  if (L->next) {
		  ListNode* p, * q;
		  p = L->next;
		  L->next = nullptr;
		  while (p) {
			  q = p;
			  p = p->next;
			  q->next = L->next;
			  L->next = q;
		  }
	  }
  }

  void addNode(ListNode*& L, int n) {//(低位/表尾补0),从原表尾进行尾插
	  ListNode* p, * q;
	  p = L;
	  while (p->next)
		  p = p->next;
	  while (n--) {
		  q = new ListNode;
		  q->val = 0;
		  p->next = q;
		  p = p->next;
	  }
	  p->next = nullptr;
  }

  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	  //先给链表添加头结点(原表不含头结点)
	  ListNode* p;
	  p = new ListNode;
	  p->next = l1;
	  l1 = p;
	  p = new ListNode;
	  p->next = l2;
	  l2 = p;

	  p = l1;
	  //记录两个表长
	  int len1(0), len2(0);
	  while (p) {
		  p = p->next;
		  len1++;
	  }
	  p = l2;
	  while (p) {
		  p = p->next;
		  len2++;
	  }
	  int n = abs(len1 - len2);

	  //对短表进行0补齐
	  p = len1 > len2 ? l2 : l1;
	  if (n) {
		  addNode(p, n);
		  headInsert(l1);
		  headInsert(l2);
	  }

	  //两表相加
	  int cr = 0,flag=0;
	  ListNode* res=new ListNode; //res作为带头结点的表指针
	  res->next = nullptr;
	  while (l1) {
		  if (flag++) {
			  int num = l1->val + l2->val + cr;
			  if (num > 9) {
				  num -= 10;
				  cr = 1;
			  }
			  else
				  cr = 0;
			  p = new ListNode;
			  p->val = num;
			  p->next = res->next;
			  res->next = p;
		  }
			  l1 = l1->next;
			  l2 = l2->next;
	  }
	  //加完后仍有进位，添加一个结点
	  if (cr) {
		  p = new ListNode;
		  p->val = 1;
		  p = res->next;
		  res = p;
	  }
	  return res->next;
  }


//测试,（带头结点的尾插建表）
  ListNode* tailCreateL() {
	  ListNode *L, *p, *q;
	  int x;
	  L = new ListNode;
	  p = L;
	  cin >> x;
	  while (x!=-1) {
		  q = new ListNode;
		  q->val = x;
		  p->next = q;
		  p = q;
		  cin >> x;
	  }
	  p->next = nullptr;
	  return L->next; //题目中的链表不包含头结点
  }


int main2() {
	ListNode* l1, *l2, *res, *tmp;
	l1 = tailCreateL();
	l2 = tailCreateL();

	/*showL(l1);
	showL(l2);*/
	res = addTwoNumbers(l1, l2);
	showL(res);
	
	cout << endl;
	return 0;
}
#endif

enum string {
	x1,
	x2,
	x3 = 10,
	x4,
	x5,
} x;
void main01() {
	
	cout << x << endl;

	unsigned char* p1;
	unsigned long* p2;
	p1 = (unsigned char*)0x801000;
	p2 = (unsigned long*)0x810000;
	cout << p1 + 5 <<endl;
	cout << p2 + 5 << endl;


}
//class A
//{
//public:
//	void FuncA()
//	{
//		printf("FuncA called\n");
//	}
//	virtual void FuncB()
//	{
//		printf("FuncB called\n");
//	}
//};
//class B : public A
//{
//public:
//	void FuncA()
//	{
//		A::FuncA();
//		printf("FuncAB called\n");
//	}
//	virtual void FuncB()
//	{
//		printf("FuncBB called\n");
//	}
//};
//void main(void)
//{
//	B	b;
//	A* pa;
//	pa = &b;
//	A* pa2 = new A;
//	pa->FuncA();
//		pa->FuncB(); 
//		pa2->FuncA(); 
//		pa2->FuncB();
//	delete pa2;
//}


//int FindSubString(char* pch) {
//	int   count = 0;
//	char* p1 = pch;
//	while (*p1 != '\0') {
//		if (*p1 == p1[1] - 1) {
//			p1++;
//			count++;
//		}
//		else {
//			break;
//		}
//	}
//	int count2 = count;
//	while (*p1 != '\0') {
//		if (*p1 == p1[1] + 1) {
//			p1++;
//			count2--;
//		}
//		else {
//			break;
//		}
//	}
//	if (count2 == 0)
//		return(count);
//	return(0);
//}
//void ModifyString(char* pText) {
//	char* p1 = pText;
//	char* p2 = p1;
//	while (*p1 != '\0') {
//		int count = FindSubString(p1);
//		if (count > 0) {
//			*p2++ = *p1;
//			printf_s(p2, "%i", count);
//			while (*p2 != '\0') {
//				p2++;
//			}
//			p1 += count + count + 1;
//		}
//		else {
//			*p2++ = *p1++;
//		}
//	}
//}
//void main(void) {
//	char text[32] = "XYBCDCBABABA";
//	ModifyString(text);
//	printf(text);
//}


void prim(int m, int n)
{
	if (m >= n)
	{
		while (m%n) n++;
		(m/=n);
		prim(m, n);
		cout << n << endl;
	}
}

void main02() {
	prim(96, 3);
}


//DP-最大子数组和-th3

// 1. 暴力
int maxSubArr(vector<int> v) {
	if (v.empty())
		return INT_MIN;
	int len = v.size();
	int maxnum = *v.begin(),tmp=0,left=0,right=0;
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			tmp += v[j];
			if (maxnum < tmp) {
				maxnum = tmp;
				left = i;
				right = j;
			}
		}
		tmp = 0;
	}
	cout << "[" << left << ", " << right << "]" << endl;
	return maxnum;
}


//DP
int maxSubArr2(vector<int> v) {
	if (v.empty())
		return INT_MIN;
	int len = v.size();
	int maxnum = *v.begin(),left=0,right=0;
	int* sumx = new int[len]; //记录当下最大和
	sumx[0] = *v.begin();
	for (int i = 1; i < len; i++) { //填DP数组
		sumx[i] = max(sumx[i - 1] + v[i],v[i]);
	}
	//回溯DP表，找到最大和与下标
	right = len - 1;
	maxnum = sumx[right];
	for (int i = len - 1; i >= 0; i--) 
		if (maxnum < sumx[i]) { //最大值和右下标
			maxnum = sumx[i];
			right = i;
		}
	//寻找左下标的循环不能和上面的循环合并，否则会出错，如[-1，-2]	
	for (int i = right; i >= 0; i--)
		if (sumx[i] == v[i]) { //左下标
			left = i;
			break;
		}
	cout << "[" << left << ", " << right << "]" << endl;

	delete[] sumx;
	return maxnum;
}

//在线处理
int maxSubArr3(vector<int> v) {
	//该方法缺点：1.下标不容易记录，2.全负数时特殊处理
	if (v.empty())
		return INT_MIN;
	int len = v.size();

	//首先判断是不是全负数，如果为全负数则返回最大值
	bool flag = false; //默认是全负数
	for (int e : v) {
		if (e > 0) {//只要出现正数，则可以在线处理
			flag = true;
			break;
		}
	}

	int maxnum = *v.begin(), tmp = 0;
	if (flag) {
		for (int i = 0; i < len; i++) {
			tmp += v[i]; //累加
			maxnum = tmp > maxnum ? tmp : maxnum; //每轮都需比较一次
			if (tmp < 0) //加到<0时，舍弃 (此处如果数组全负数，则出问题)
				tmp = 0;
		}
	}

	else {	//全负数时，选取最大值
		for (int i = 0; i < len; i++) {
			if (maxnum < v[i]) 
				maxnum = v[i];
		}
	}
	return maxnum;
}

int main03() {
	vector<int> v;
	int num;
	while (cin >> num)
		v.push_back(num);
	cout<<maxSubArr(v)<<endl;
	cout << maxSubArr2(v) << endl;
	cout << maxSubArr3(v) << endl;
	return 0;
}


/***1. 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]

示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]
 
提示：
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？**/


//1. 暴力法，O(n^2),略

//2.先将vector转换成multimap，key=值，val=下标，然后排序，然后双指针查找，复杂度O(nlogn)+O(n)
vector<int> twoSum1(vector<int>& nums, int target) {
	if(nums.empty())
		return vector<int>{-1};
	list<multimap<int, int>> plist;
	int len = nums.size();

	for (int i = 0; i < len; i++) {//转换为multimap
		multimap<int,int> pmap;
		pmap.emplace(nums[i], i); 
		//这里使用insert函数会报错，网上说inert会调用拷贝构造，而emplace和emplace_hint直接调用构造函数并插入，它们效率更高，其中emplace_hint还需指定插入位置
		plist.push_back(pmap);
	}

	//排序 O(nlogn)
	plist.sort(); //因为这里的key实际上是int类型，因此无需重写compare比较规则

	//测试排序后的输出
	for (const auto& e : plist) //const+&, 安全高效，遍历得到multimap对象
		for (const auto& v : e) //e为multimap对象，遍历e得到的v是其中内容
			cout << "[ "<<v.first << ",  " << v.second <<" ]" << endl;

	//查找 O(n)
	list<multimap<int, int>>::iterator itbegin = plist.begin();
	list<multimap<int, int>>::iterator itend = plist.end();
	--itend; //end指向最后一个元素的下一个位置
	while (itbegin!=itend) {
		if (itbegin->begin()->first + itend->begin()->first == target) //找到了
			return vector<int>{itbegin->begin()->second, itend->begin()->second}; 
		if (itbegin->begin()->first + itend->begin()->first < target) //比target小时，左指针右移
			++itbegin;
		if (itbegin->begin()->first + itend->begin()->first > target) //比target大时，右指针左移
			--itend;
	}
	return vector<int>{-1};
}


/****    3. 哈希表解法。每次遇到一个数a,首先在hash表中查询target-a，如果存在，返回a和target-a的坐标
如果hash表中不存在target-a，就将target-a和它的下标放入表中。一次循环就能找到，由于hash表，时间复杂O(n)，空间O(n)**/
vector<int> twoSum2(vector<int>& nums, int target) {
	if (nums.empty())
		return vector<int>{-1};

	//hash_map<int, int> htmp; //有的编译器和系统不支持hash_map，即将被unordered_map替代，跨平台时不要用
	unordered_multimap<int, int> numhashmap;  //c++11新标准加入，底层为哈希结构的map，建议使用它
	//注意这里key为数组值，val为数组下标，因此需要用multimap，不是map

	int len = nums.size();
	vector<int> res;
	unordered_multimap<int, int>::iterator itmap = numhashmap.begin();
	for (int i{}; i < len; i++) {
		int tmp;
		if (numhashmap.empty()) { //向哈希表中放入第一个值
			tmp = target - nums[i];
			numhashmap.emplace(tmp, i);
		}
		else { //表不为空(不是第一次查找)时，开始查找
			int j;
			if (numhashmap.find(nums[i]) != numhashmap.end()) { //找到了
				j = numhashmap.find(nums[i])->second; //记录下标(确保解是两个，不能自己和自己)
				if (i != j) { //找到了且不是自身
					res.push_back(i);
					res.push_back(j);
					break;
				}
			}
			else { //没找到
				tmp = target - nums[i]; //压入target-nums[i]
				numhashmap.emplace(tmp, i);
			}
		}
	}
	return res;
}


int main04() {

	//{ 3,2,0,-5,7,1,3,8,7,3,6 }

	vector<int> v = {7,3,4,1,3,-7,6};
	vector<int> res;
	int target = 6;
	//res=twoSum1(v, target);
	res = twoSum2(v, target);
	for (int& e : res)
		cout << e << " ";
	cout << endl;

#if 0
	//unordered_map test
	unordered_multimap<int, int> mt1{ {-2,0},{1,2},{6,3},{-1,4}, {6,5} };
	for (auto& e : mt1) {
		cout << mt1.find(6)->first << ", " << mt1.find(6)->second << endl; 
		//这里find只找到第一个满足key的元素，比如这里依6，只找到3或5就结束了，另一个找不到
		cout << "***************************************************" << endl;
		cout << e.first << ", " << e.second <<endl;
	}
#endif	

	return 0;
}

/***88. 合并两个有序数组
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

示例 1：
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。

示例 2：
输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]
解释：需要合并 [1] 和 [] 。
合并结果是 [1] 。

示例 3：
输入：nums1 = [0], m = 0, nums2 = [1], n = 1
输出：[1]
解释：需要合并的数组是 [] 和 [1] 。
合并结果是 [1] 。
注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。

提示：
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？**/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

}

/***350. 两个数组的交集 II
给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。

示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]

示例 2:
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]

提示：
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
 
进阶：
如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小，哪种方法更优？
如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？***/
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	return vector<int>{0};
}

/***给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

示例 1：
输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
示例 2：
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。

提示：
1 <= prices.length <= 105
0 <= prices[i] <= 104
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。**/

//方法1.暴力法，直接遍历，找到所有profit,复杂度太高，超时
int maxProfit1(vector<int>& prices) {
	int len = prices.size();
	int tmp=0,profit=0;
	for (int i = 0; i < len-1; i++) {	//买入时间
		for (int j = i+1; j < len; j++) {	//卖出时间
			tmp = prices[j] - prices[i];
			if (tmp > profit)
				profit = tmp;
		}
	}
	return profit;
}

//方法2：先对数组元素和下标放入map，再对map按key=值进行排序，然后从头和尾部进行做差，首先val=下标>0时停止，记录maxprofit，循环终止条件：val<=0(或迭代器判断)。
//最后，将起点迭代器再往前推一步，终点迭代器再往前推一步，得到四个值profit(仍按上面的逻辑)(包括profit)，比较这四个值的最大值即为所求
int maxProfit2(vector<int>& prices) {
	int len = prices.size();
	int profit1(0),profit2(0);
	list<multimap<int, int>> lst;
	
	for (int i{}; i < len; i++) {
		multimap<int, int> mulmap;	//放在外面会出错
		mulmap.emplace(prices[i],i);
		lst.push_back(mulmap);
	}
		

	lst.sort();	//排序，默认升序，由于键为int类型，不需要自定义排序规则

	////排序后数据输出观察
	//for (auto& v : lst)
	//	for (auto& e : v)
	//		cout << "[ " << e.first << ", " << e.second << "]" << endl;

	list<multimap<int, int>>::iterator lstbegin = lst.begin();
	list<multimap<int, int>>::iterator lstend = lst.end();
	list<multimap<int, int>>::iterator tmpbegin;
	list<multimap<int, int>>::iterator tmpend;
	--lstend; //指向最后一个元素
	while (lstbegin != lstend) {
		if (lstbegin != lstend&&lstend->begin()->second - lstbegin->begin()->second > 0) {
			profit1 = lstend->begin()->first - lstbegin->begin()->first;
			tmpbegin = lstbegin;
			break;
		}
		++lstbegin;
		if (lstbegin != lstend&&lstend->begin()->second - lstbegin->begin()->second > 0) {
			profit2 = lstend->begin()->first - lstbegin->begin()->first;
			tmpend = lstend;
			break;
		}
		--lstend;
	//这里有问题，lstbegin和lstend怎么变化出现了问题
	}
	
	return profit1>profit2?profit1:profit2;
}

//方法3：DP，主要思想：将前i-1个看成一个整体，第i个处的最大差和前i-1个的最小值相关，可以是第i-1处的DP最大差，也可以是price[i]-前i个的最小值。这里为了避免重复求前i个的最小值，
//就将前i个的最小值存起来。DP表：1. mu[i]:存储到第i个时的最大差，2. minx[i]：存储到第i个时的最小值
//公式：mu[i]=max{mu[i-1],prices[i]-minx[i-1]}, minx[i]=min{minx[i-1],prices[i]}, 从公式看出，两个DP表先更新谁都行。
int maxProfit3(vector<int>& prices) {
	int len = prices.size(),res=0;
	if (len < 2)
		return 0;
	int* minx = new int[len](); //存储前i个序列中的最小值
	int* mu = new int[len](); //存储前i个序列中的顺序最大差
	//初始化DP表
	minx[0] = prices[0];
	mu[0] = 0;
	//填表
	for (int i = 1; i < len; i++) {
		minx[i] = min(minx[i - 1],prices[i]);
		mu[i] = max(mu[i - 1], prices[i] - minx[i - 1]);
	}
	for (int i = 0; i < len; i++) 
		if (mu[i] > res)
			res = mu[i];
	return res;
}


int main05() {
	vector<int> v{ 7,1,5,3,6,4 };
	cout << maxProfit3(v) << endl;
	return 0;
}

/***566. 重塑矩阵
在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。
给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。
重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。
如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。

示例 1：
输入：mat = [[1,2],[3,4]], r = 1, c = 4
输出：[[1,2,3,4]]

示例 2：
输入：mat = [[1,2],[3,4]], r = 2, c = 4
输出：[[1,2],[3,4]]

提示：
m == mat.length
n == mat[i].length
1 <= m, n <= 100
-1000 <= mat[i][j] <= 1000
1 <= r, c <= 300***/
void showMat(const vector<vector<int>>& mat) {
	int m = mat.size();	//行数
	int n = mat.at(0).size(); //列数
	cout << "[";
	for (int i = 0; i < m; i++) {
		cout << "[";
		for (int j{}; j < n; j++) {
			if (j)
				cout << "," << mat[i][j];
			else
				cout << mat[i][j];
		}
		cout << "]";
		if (i != m - 1)
			cout << ",";
	}
	cout << "]"<<endl;
}

//主要思路，先把原矩阵转成行向量/列向量(这里使用行向量)，再将行向量转成所需矩阵
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
	int m = mat.size();
	int n = mat.at(0).size();
	//cout << m << ", " << n << endl;
	if (r * c != m * n) {
		showMat(mat);
		return mat;
	}
	vector<int> vec;
	for (auto v : mat)	//为不改变原矩阵，这里不用引用
		for (auto e : v)
			vec.push_back(e);

	//这里两种方法：1.根据行列要求直接对行向量进行输出，2.利用行向量和输出要求，创建一个新矩阵进行输出
	vector<vector<int>> res;
	for (int i = 0; i < r; i++) {
		vector<int> tmp;
		for (int j{}; j < c; j++) {
			tmp.push_back(vec.at(i*c+j));
		}
		res.push_back(tmp);
	}
	
	showMat(res);
	return res;
}

int main06() {
	int m, n; //行列
	vector<vector<int>> mat; //矩阵
	cin >> m >> n;
	int elem;

	for (int j = 0; j < m; j++) {
		vector<int> v;
		for (int i{}; i < n; i++) {
			cin >> elem;
			v.push_back(elem);
		}
		mat.push_back(v);
	}
	
	for (auto& v : mat) {
		for (auto& e : v)
			cout << e << " ";
		cout << endl;
	}

	matrixReshape(mat,1,1);

	//showMat(mat);
	return 0;
}


