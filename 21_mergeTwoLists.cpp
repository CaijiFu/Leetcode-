class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res=new ListNode;//res��Ϊ�������
        ListNode* pos=res;//posָ���Ѿ�merge�õ����һ��Ԫ��
        //��������������mergeһ�¾ͺã����ν���pos����
        while(l1!=NULL||l2!=NULL){
            if(l1==NULL) {
                pos->next=l2;
                break;
            }//l1������
            if(l2==NULL) {
                pos->next=l1;
                break;
            }//l2������
            if(l1->val<l2->val) {
               pos->next=l1;
               l1=l1->next;  
            }
            else{
                pos->next=l2;
                l2=l2->next;
            }
            pos=pos->next;
        }
        return res->next;//ȥ����ͷ�սڵ�
    }
};