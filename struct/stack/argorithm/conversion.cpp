// 进制转换
// Created by 洪磊 on 2019-07-10.
//

#include <cstdio>
#include <stack>

using namespace std;

/**
 * 十进制转化为八进制，打印
 * 参数为非负整数
 * @param val
 */
void transToEight(int val);

int main() {
    transToEight(15);
    return 0;
}

void transToEight(int val) {
    stack<int> s;
    do {
        int num = val%8;
        s.push(num);
        val /= 8;
    } while (val != 0);
    printf("0");
    while (!s.empty()) {
        printf("%d", s.top());
        s.pop();
    }
    printf("\n");
}