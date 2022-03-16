#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <deque>
#include <list>
#include <set>
#include<functional>
using namespace std;


////String
// ��string str���ַ����ָ��ŵ�vector��
int testStr1(string &str) {
	vector<string> v;
	vector<string>::iterator it;
	int start(0),pos(0) ;
	//cout << str.length()<<endl;
	while (true)
	{
		pos = str.find(".",start);
		if (pos == -1) {
			v.push_back(str.substr(start,str.length() - start));
			break;
		}
		string tmp = str.substr(start, pos - start);
		v.push_back(tmp);
		start = pos+1;
	}
	for (it= v.begin(); it != v.end(); it++)
		cout << *it<<endl;
	return 0;
}
 

void testStr2() {
	string s = "dugba";
	char& a = s[1];
	char& b = s[2];
	char* chv = const_cast<char *>(s.c_str());
	//cout << chv;	�ɹ���ǿת��Ч
	char& c = chv[1];
	char& d = chv[2];
	cout << &s << endl;
	cout << &chv << endl;

	s = "uiorhgnmeudhdka";
	for (int i = 0; i < 30; i++) {
		//�ѳ��ȸĳ��㣬���ֶ�̬�ڴ���������ʧЧ����
		chv[i] = 't';
	}
	cout << chv << endl;
	

	a = '9';
	b = '8';
	c = '7';
	d = '6';
	cout << s << endl << chv << endl;
	cout << &s << endl;
	cout << &chv << endl;
}

void testStr3(string& s) {
	//����д��ĸת��ΪСд,�����ִ�Сд����
	int v = 'a' - 'A';
	cout << s << endl;
	for (int i = 0; i < s.length(); i++) {
		/*if (s[i] <= 'Z' && s[i] >= 'A') {
			s[i] += v;
		}*/
		s[i] = tolower(s[i]);	//toupper
	}
	cout << s << endl;
}




/// vector 	
//vector���ݷ�ʽ�鿴,��ʱ����������
void testVector1() {
	vector<int> v1;
	vector<int>::iterator it1;
	for (int i = 0; i < 20; i++) {
		v1.push_back(i);
		cout << "vi=" << i << endl;
		cout << "v_capacity=" <<v1.capacity() << endl;
	}
}

//vectorͳһ����ӿ�, ��һ���ᱨ��
//template<typename T>
//void printVct(const vector<T> &v) {
//	vector<T>::iterator it = v.begin();
//	for (; it != v.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}

void printVct(vector<int>& v) {//�����б��const�ᱨ��
	vector<int>::iterator it = v.begin();
	for (; it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void testVector2() {
	//vector��ʼ������
	vector<int> v1;
	vector<int>::iterator it1;
	v1 = vector<int>(4, 6);//��4��6��ʼ��

	int arr[] = {2, 4, 6, 1, 3, 7};
	////��ʵ����Ҳ����v.begin,v.end���й����
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));  //��ͬ��forѭ��append

	////assign��������ֵ����
	v1.assign(2, 5);  //��2��5��ֵ��v1���������Ǹ�һ��

	//v1 = vector<int>(v2.begin(), v2.end()); //��v2��ֵ��v1
	////ͬ��Ч����
	//v2 = v1; //��Ϊ��������"="
	//v1.assign(v2.begin(), v2.end());

	vector<int>v3(3,7);
	v3.swap(v2);	//�ý����ͳ����޹�

	//β�巨��βɾ��push_back(),pop_back()
	//ɾ��������ɾ����erase().

	printVct(v1);
	printVct(v2);
	printVct(v3);
}

bool isValidSudoku() {
	//��ά������ʼ���ͱ���
	vector<vector<char>>row(9, vector<char>(9,'0'));

	vector<vector<char>> ::iterator itrow;
	vector<char> vctrow;
	for (itrow = row.begin(); itrow != row.end(); itrow++) {
		vctrow = *itrow;
		for (vector<char>::iterator ittmp = vctrow.begin(); ittmp != vctrow.end(); ittmp++)
			cout << *ittmp<<' ';
		cout << endl;
	}
	return 0;
}


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//����ָ��ɾ��������n���ڵ�,Ҳ����ջ������������(��Ҫ��������)
ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (head) {
		ListNode* quick, * slow, * tmp;
		quick = slow = head;
		while (n-- && quick)
			quick = quick->next;
		if (++n)   //n����������
			return head;
		if (!quick) { //ǡ��ɾ��ͷ���
			tmp = head;
			head = head->next;
		}
		else {
			while (quick->next) {
				quick = quick->next;
				slow = slow->next;
			}
			tmp = slow->next;
			slow->next = tmp->next;
		}
		delete tmp;
	}
	return head;
}

//���������Ƿ��л������жϻ���λ��
ListNode* detectCycle(ListNode* head) {
	ListNode* quick, * slow, * cross=nullptr;
	quick = slow = head;
	while (quick && quick->next) { //ע���ж��������ж�˳��
		quick = quick->next->next;
		slow = slow->next;
		if (quick == slow) {
			cross = quick;
			break;
		}
	}
	if (quick == NULL || quick->next == NULL)
		return NULL;
	slow = head;
	quick = cross;
	while (slow != quick) {
		slow = slow->next;
		quick = quick->next;
	}
	return quick;
}

#if 0
//С��Ŀ����4��ѡ��ABCD��10λ��ί�ֱ�����֣�
//ȥ��ÿ���˵���߷ֺ���ͷ֣���ÿ���˵�ƽ���֡�
//���ݽṹ
struct Cpn {
public:
	string name;
	float score[10];
	Cpn(string n, float sc[10]) :name(n) {
		for (int i = 0; i < 10; i++)
			score[i] = sc[i];
	};
	void operator=(float sc[10]) {
		for (int i = 0; i < 10; i++)
			score[i] = sc[i];
	}
	void printCpn() {
		cout << "name:"<<name << endl;
		for (int i = 0; i < 10; i++)
			cout << score[i] << " ";
		cout << endl;
	}
};

void testApp1() {
	float score1[10] = { 1, 2, 3, 4, 5, 6, 7, 9, 8, 43 };
	float score2[10] = { 2, 3, 4, 5, 6, 7, 9, 8, 10,22 };
	float score3[10] = { 3, 4, 5, 6, 7, 9, 8, 9, 5, 11 };
	float score4[10] = { 2, 3, 4, 5, 6, 7, 9, 1, 3, 6 };
	Cpn p1("zs", score1);
	Cpn p2 = p1;
	p2.name = "lisi";
	float v[10] = { 11,22,33,44,55,66,77,88,99,10 };
	p2 = v;
	p1.printCpn(); //���������p2�ĸı䲢δ��p1����Ӱ�졣�������p2�������p1��
	p2.printCpn();
}

//��Ҫ�������,�д�����Ϊ����������ֵʱ���ᵼ���м�ֵ�岻��ȥ,���ǵ���sort
float setArr2Deq(float score1[10]) {
	deque<float> deqScore;
	//����
	deque<float>::iterator itsc=deqScore.begin();
	deqScore.push_back(score1[0]);
	for (int i = 1; i < 10; i++) {
		if (score1[i] <= deqScore.front()) {
			deqScore.push_front(score1[i]);
			continue;
		}
		if (score1[i] >= deqScore.back()) {
			deqScore.push_back(score1[i]);
			continue;
		}
	}
	//ɾ����ֵ
	deqScore.pop_back();
	deqScore.pop_front();
	for (; itsc != deqScore.end(); itsc++) {
		cout << *itsc << " ";
	}
	cout << endl;
	float sum = 0;
	for (int i = 0; i < 8; i++) {
		sum += deqScore.at(i);
	}
	sum /= 8;
	return sum;
}

void testApp2() { //��������Ŀ���н�
	float score1[10] = { 1, 2, 3, 4, 5, 6, 7, 9, 8, 43 };
	float score2[10] = { 2, 3, 4, 5, 6, 7, 9, 8, 10,22 };
	float score3[10] = { 3, 4, 5, 6, 7, 9, 8, 9, 5, 11 };
	float score4[10] = { 2, 3, 4, 5, 6, 7, 9, 1, 3, 6 };
	Cpn p1("zs", score1);
	Cpn p2("lisi", score2);
	Cpn p3("wang5", score3);
	Cpn p4("c6", score4);
	
	// �������
	float avg[4];
	avg[0] = setArr2Deq(p1.score);
	avg[1] = setArr2Deq(p2.score);
	avg[2] = setArr2Deq(p3.score);
	avg[3] = setArr2Deq(p4.score);

	for (int i = 0; i < 4; i++) {
		cout << avg[i]<<' ';
	}
	cout << endl;
}
#endif

class Mycompare {  //�൱���ڽ��ĺ������� less<int>(),��������greater<int>()
public:
	bool operator()(int v1, int v2)const {
		//�������������Ƿº������ұ����const�����򱨴�
		return v1 > v2;
	}
};

int main() {
	//string str1= "dasx.rer.uuipb.k";
	//string str3 = "fa23HVkjiOpB6Umv";
	//testStr1(str);
	//testStr2();
	//testStr3(str3);

	//Vector
	//testVector1();
	//testVector2();
	//isValidSudoku();
	//isValidSudoku();

	//deque
	//testApp1();
	//testApp2();
	

	//�����������srandҲ���漴�ɹ�����������v��Ԫ����ͬ�����v�Ǹ���ά���顣����ÿ�ж�һ��
	//��ˣ����ڶ�����������ʱ��srand�ز����١�������v1,v2,v3...��srand�ͻ������
	//srand(time(0));
	//int v[10];
	//for(int i =0;i<10;i++)
	//	v[i]= rand()%41+60;//���ﲻ������forִ�е�̫���ʹ��v��Ԫ�ض�һ����
	//for (int i = 0; i < 10; i++)
	//	cout << v[i]<<" ";
	//cout << endl;


	//stack
	//����(Ĭ�ϣ�����)��size��empty,top,pop,push...�޵�����


	//queue
	//ͬ�����죬push��pop��empty��size��������βfront,back...�޵�����


	//list
	//��ʼ��: ���캯��
	//list<int> l; //���壬�п��ٿռ��ָ��l����lָ��Ĵ洢���ݿռ�û��
	//cout << l.size() << endl;
	////��ʼ���б� initializer_list,������������ʼ������һ����push����
	//list<int> lst1{ 1,3,4,1,6,2 };
	//for (auto itlst = lst1.begin(); itlst != lst1.end();) {//auto�ؼ��ֵ�ʹ��
	//	cout << *itlst++ << " ";
	//}
	// �����������
	/*list<int> lst2{ 9,3,1,5,6,2,1 };
	for (auto itlst2 = lst2.rbegin(); itlst2 != lst2.rend();)
		cout << *itlst2++ << " ";*/

	
	//set
	set<int, Mycompare> set1{ 5,2,6,1,9,4 };
	for (auto itset = set1.begin(); itset != set1.end();)
		cout << *itset++ << " ";  //*itset��ָ�ĵ�һ����������intֵ
	cout << endl;
	//���⣬�����Զ������ͣ�Ҫָ�����������ΪsetĬ�ϻ�Լ���������Զ������Ͳ�ָ�������������֪����ô�žͻᱨ��
	
	set<int, less<int>> set2{ 3,6,8,1,0 };  //�����less<int>()�����ȥ��С���žͶ��ˡ�Ϊʲô��
	for (auto numx: set2)
		cout << numx << " ";

	return 0;
}



