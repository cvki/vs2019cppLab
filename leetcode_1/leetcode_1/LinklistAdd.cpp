#include<iostream>
#include"listNodeAdd.h"

using namespace std;
/***
* �������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
���룺l1 = [2,4,3], l2 = [5,6,4]
�����[7,0,8]
���ͣ�342 + 465 = 807.
ʾ�� 2��

���룺l1 = [0], l2 = [0]
�����[0]
ʾ�� 3��

���룺l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
�����[8,9,9,9,0,0,0,1]

ע�⣺
ÿ�������еĽڵ����ڷ�Χ [1, 100] ��
0 <= Node.val <= 9
��Ŀ���ݱ�֤�б��ʾ�����ֲ���ǰ����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/add-two-numbers
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
***/

int length(ListNode* L) {//�������ͷ���
    int count = 0;
    while (L) {
        count++;
        L = L->next;
    }
    return count;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {//����Ŀ����ͷ���
    ListNode* result = new ListNode;
    ListNode* tmpL = result;
    int out = 0, lth = 0, lth1 = length(l1), lth2 = length(l2);
    while (l1 || l2) {
        int val1 = 0,val2=0;
        if (l1)
            val1 = l1->val;
        if (l2)
            val2 = l2->val;
        int vtmp = val1 + val2 + out;
        if (vtmp <= 9) {
            out = 0;
        }
        else {
            vtmp = vtmp % 10;
            out = 1;
        }
        ListNode* tmpNode = new ListNode;
        tmpNode->val = vtmp;
        tmpL->next = tmpNode;
        tmpL = tmpNode;
        lth++;
        if(l1)
            l1 = l1->next;
        if(l2)
        l2 = l2->next;
    }
    if (out) {
        ListNode* tmpNode = new ListNode;
        tmpNode->val = out;
        tmpL->next = tmpNode;
    }
    tmpL = result;
    result = result->next;
    delete tmpL;
    //cout << "lth:" << lth << endl;
    return result;//����result���´����ı�����ʱ����ͷ��㣬��ɲ�������Ҫɾ��ͷ���
}

ListNode* creatList() {//��ͷ��㽨��
    ListNode* L = new ListNode;
    ListNode* p = L;
    int x;
    cin >> x;
    while (x != -1) {
        ListNode* tmp = new ListNode;
        tmp->val = x;
        p->next = tmp;
        p = tmp;
        cin >> x;
    }
    p = L;
    L = L->next;
    delete p;
    return L;//����ʱȥ��ͷ��㣬�Ժ�������еı�ͷ����ֱ�ӿ��Բ�������
}

void showL(ListNode* L) {//�����ͷ���
    int count = 1;
    cout << "[";
    while (L) {
        if (count == 1) {
            cout << L->val;
        }
        else {
            cout << ',' << L->val ;
        }
        count++;
        L = L->next;
    }
    cout << "]"<<endl;
}

