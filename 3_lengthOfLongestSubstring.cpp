class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		/*�ַ���������˫�˶��У�����һ���Ѿ��ڶ����У��Ӷ���ͷ��ɾ��Ԫ�أ�һֱ��ɾ�����ظ�Ԫ��*/
		deque<char> re;//�洢
		int maxsize = 0;
		for (auto i : s){
			if (find(re.begin(), re.end(), i) == re.end()) re.push_back(i);
			else{
				if (re.size()>maxsize) maxsize = re.size();
				while (re.front() != i) re.pop_front();//����ͷ��Ԫ��
				re.pop_front();//������ͬԪ��
				re.push_back(i);//��ǰ�ظ�Ԫ����ջ
			}
		}
		if (re.size()>maxsize) return re.size();
		else return maxsize;
	}
};