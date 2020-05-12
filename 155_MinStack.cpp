class MinStack {
public:
    /** initialize your data structure here. */
    MinStack(){
        base=(int*)malloc(1000*sizeof(int));//初始化元素中含有1000个元素
        if(!base) exit(0);
        head=base;
        nums=1000;
    }   
    void push(int x) {
        if(head-base==nums-1) {
            base=(int*)realloc(base,(nums+100)*sizeof(int));
            if(!base) exit(0);
            head=base+nums-1;
            nums+=100;}
        *head=x;
        head++;
    }
    
    void pop() {
        if(head==base) exit(0);
        head--;
    }
    
    int top() {
        if(head==base) return NULL;
        return *(head-1);
    }
    
    int getMin() {
        if(head==base) return NULL;
        return *min_element(base,head);
    }
private:
    int* head;
    int* base;
    int nums; //栈中存放最多元素个数,超过100要重新分配内存
}