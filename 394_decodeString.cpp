#include "malloc.h"
#include"stdlib.h"
#include<string>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	string produce_str(int i, string c){
		string s;
		for (int j = 0; j != i; j++){
			s += c;
		}
		return s;
	}
	string decodeString(string s) {
		stack<char> character;
		string res, addtion;
		for (auto i : s){
			if (i == ']'){
				string current;
				int times = 0;
				while (isalpha(character.top())) {
					current = character.top() + current;
					character.pop();
				}
				character.pop();
				int power = 0;
				while (!character.empty() && isdigit(character.top())){
					times += (character.top() - '0')*pow(10, power++);
					character.pop();
				}
				current = produce_str(times, current);
				if (character.empty()) res += current;
				else for (auto j : current) character.push(j);
			}
			else character.push(i);
		}
		while (!character.empty()) {
			addtion = character.top() + addtion;
			character.pop();
		}
		return res + addtion;
	}
};