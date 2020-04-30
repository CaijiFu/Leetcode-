class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		/*字符串依次入双端队列，遇到一个已经在队列中，从队列头部删除元素，一直到删除掉重复元素*/
		deque<char> re;//存储
		int maxsize = 0;
		for (auto i : s){
			if (find(re.begin(), re.end(), i) == re.end()) re.push_back(i);
			else{
				if (re.size()>maxsize) maxsize = re.size();
				while (re.front() != i) re.pop_front();//弹出头部元素
				re.pop_front();//弹出相同元素
				re.push_back(i);//当前重复元素入栈
			}
		}
		if (re.size()>maxsize) return re.size();
		else return maxsize;
	}
};