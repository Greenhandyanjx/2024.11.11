#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int lengthLongestPath(string input) {
        if (input.find('.') == -1)return 0;
        int idx = 0;
        int res = 0;
        int n = input.length();
        stack<int>st;
        while (idx < n) {
            int degree = 1;
            while (idx < n && input[idx] == '\t') {
                idx++;
                degree++;
            }
            bool isFile = false;
            int len = 0;
            while (idx < n && input[idx] != '\n') {
                if (input[idx] == '.')isFile = true;
                idx++;
                len++;
            }
            idx++;
            while (st.size() >= degree)st.pop();
            if (!st.empty()) {
                len += st.top() + 1;
            }
            if (isFile) {
                res = max(res, len);
            }
            else {
                st.push(len);

            }
        }
        return res;
    }
};
//class Solution {
//public:
//    int lengthLongestPath(string input) {
//        if (input.find('.') == -1)return 0;
//        int sum = 0,res=0;
//        stack<pair<int, int>>st;
//        int len = 0;
//        int degree = 0;
//        int i = 0;
//        int n = input.length();
//        for (i = 0; i < input.length(); i++) {
//            len++;
//            if (input[i] == '\n')break;
//        }
//        st.push({ len,0 });
//        sum += len;
//        res = max(sum, res);
//        len = 0;
//        while (!st.empty()&&i<n) {
//            for (; i < input.length(); i++) {
//                len++;
//                if (input[i] == '\n')break;
//            }
//            for (; i < input.length(); i++) {
//                if (input[i] == '\t')degree++;
//                else break;
//            }
//            if (degree == st.top().second)
//            {
//                sum += len;
//            }
//            else {
//
//            }
//        }
//    }
//};
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int>hash{ {'a',0} };
        for (auto& i : s)hash[i]++;
        for (int i = 0;i<s.length();i++) {
            if (hash[s[i]] == 1)return i;
        }
        return -1;
    }
};
class Solution {
public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.rfind(s[i]) == s.find(s[i]))return i;
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int t = 0;
        vector<int>res;
        for (int i = 1; i < 10; i++) {
            while (n >= i * pow(10, t)) {
                for (int j = i * pow(10, t); j <= min(n, int((i + 1) * pow(10, t))); j++) {
                    res.push_back(j);
                }
                t++;
            }
        }
        return res;
    }
};