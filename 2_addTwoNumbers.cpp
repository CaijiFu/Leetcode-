class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* res = l1;
		ListNode*fin = NULL;//用l1的链表作为结果返回，fin记录最后节点 位置
		ListNode* front = NULL;
		ListNode* lat = NULL;//当l1比l2短的时候存储断点前后位置
		int i = 0;//i表示进位
		while (l1 != NULL || l2 != NULL)
		{
			if (l2 != NULL&&l1 != NULL&&l1->next == NULL&&l2->next != NULL) {
				front = l1;
				lat = l2->next;//当l1比l2短的时候存储断点前后位置
			}
			if (l1 == NULL) {
				if (l2->next == NULL)  fin = l2;////存储最后节点位置
				l2->val = l2->val + i;
				i = l2->val / 10;
				l2->val = l2->val % 10;
				l2 = l2->next;
			}
			else if (l2 == NULL){
				if (l1->next == NULL)  fin = l1;//存储最后节点位置
				l1->val = l1->val + i;
				i = l1->val / 10;
				l1->val = l1->val % 10;
				l1 = l1->next;
			}
			else{
				if (l1->next == NULL) fin = l1;//两个链表一样长时，记录最后节点位置
				l1->val = l1->val + l2->val + i;
				i = l1->val / 10;
				l1->val = l1->val % 10;
				l1 = l1->next;
				l2 = l2->next;
			}
		}
		if (i != 0) fin->next = new ListNode(i);//整体有进位时候创建新节点接到l1
		if (front != NULL) front->next = lat;
		return res;
	}
};