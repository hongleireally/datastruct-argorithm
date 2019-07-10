// 括号匹配
// ([{}])
// Created by 洪磊 on 2019-07-11.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkMatch(string brackets);
bool checkInner(char c);
bool checkMiniMatch(char a, char b);

int main() {
    string brackets;
    cin>>brackets;
    if (checkMatch(brackets)) {
        printf("ok");
    } else {
        printf("error");
    }
    return 0;
}

bool checkMatch(string brackets) {
    stack<char> s;
    for (int i=0; i<brackets.size(); i++) {
        if (s.empty() || !checkInner(brackets[i])) {
            s.push(brackets[i]);
        } else {
            char a = s.top();
            if (checkMiniMatch(a, brackets[i])) {
                s.pop();
            } else {
                s.push(brackets[i]);
            }
        }
    }
    if (s.empty()) {
        return true;
    } else {
        return false;
    }
}

bool checkInner(char c) {
    if (c == ')' || c == ']' || c == '}') {
        return true;
    } else {
        return false;
    }
}

bool checkMiniMatch(char a, char b) {
    if (a == '(' && b == ')') {
        return true;
    }
    if (a == '[' && b == ']') {
        return true;
    }
    if (a == '{' && b == '}') {
        return true;
    }
    return false;
}




