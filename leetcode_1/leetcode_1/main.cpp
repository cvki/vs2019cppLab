#include<iostream>
#include<string>
#include"listNodeAdd.h"

using namespace std;

//��һ��
ListNode* creatList();
void showL(ListNode* L);
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

//�ڶ���
int lengthOfLongestSubstring(string s);

int main() {
#if 0
    ListNode* l1 = creatList();
    ListNode* l2 = creatList();
    showL(l1);
    showL(l2);
    //cout << "L1���ȣ�" << length(l1) << "\t" << "L2���ȣ�" << length(l2) << endl;
    ListNode* l = addTwoNumbers(l1, l2);
    showL(l);
#endif
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}