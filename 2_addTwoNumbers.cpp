class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* res = l1;
		ListNode*fin = NULL;//��l1��������Ϊ������أ�fin��¼���ڵ� λ��
		ListNode* front = NULL;
		ListNode* lat = NULL;//��l1��l2�̵�ʱ��洢�ϵ�ǰ��λ��
		int i = 0;//i��ʾ��λ
		while (l1 != NULL || l2 != NULL)
		{
			if (l2 != NULL&&l1 != NULL&&l1->next == NULL&&l2->next != NULL) {
				front = l1;
				lat = l2->next;//��l1��l2�̵�ʱ��洢�ϵ�ǰ��λ��
			}
			if (l1 == NULL) {
				if (l2->next == NULL)  fin = l2;////�洢���ڵ�λ��
				l2->val = l2->val + i;
				i = l2->val / 10;
				l2->val = l2->val % 10;
				l2 = l2->next;
			}
			else if (l2 == NULL){
				if (l1->next == NULL)  fin = l1;//�洢���ڵ�λ��
				l1->val = l1->val + i;
				i = l1->val / 10;
				l1->val = l1->val % 10;
				l1 = l1->next;
			}
			else{
				if (l1->next == NULL) fin = l1;//��������һ����ʱ����¼���ڵ�λ��
				l1->val = l1->val + l2->val + i;
				i = l1->val / 10;
				l1->val = l1->val % 10;
				l1 = l1->next;
				l2 = l2->next;
			}
		}
		if (i != 0) fin->next = new ListNode(i);//�����н�λʱ�򴴽��½ڵ�ӵ�l1
		if (front != NULL) front->next = lat;
		return res;
	}
};