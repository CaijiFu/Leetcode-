class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //�������ȶ���lst��С�ѣ��Ѷ�Ԫ��Ϊ��С�ģ�pairǰ��Ԫ��Ϊֵ�Ͷ�Ӧ�б�ŵ�����
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> lst;
        pair<int,int> cah;
        int index;
        ListNode* res=new ListNode;//�����ͷָ��
        ListNode* pos=res;//posΪָ���������Ԫ��ָ��
        for(int i=0;i!=lists.size();i++){
            if(lists[i]!=NULL){
            cah.first=lists[i]->val;
            cah.second=i;
            lst.push(cah);
            lists[i]=lists[i]->next;
            }
        }//��ʼ����ÿ������ͷԪ�ؽ��������ȶ���
        while(!lst.empty()){
           cah=lst.top();
           ListNode* cur=new ListNode(cah.first);
           pos->next=cur;
           pos=cur;
           index=cah.second;
           lst.pop();
           if(lists[index]!=NULL){
            cah.first=lists[index]->val;
            cah.second=index;
            lst.push(cah);
            lists[index]=lists[index]->next;
           }  
        }
        return res->next;//������ʼ�Ŀսڵ�
    }
};