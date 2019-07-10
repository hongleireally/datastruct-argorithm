// 最大公约数
// Created by 洪磊 on 2019-07-10.
//

#include <stdio.h>

int maxCommonDivisor(int a, int b);

int main() {
    printf("%d\n", maxCommonDivisor(300,600));
    return 0;
}

/**
 * 辗转相除法求最大公约数
 * @param a
 * @param b
 * @return
 */
int maxCommonDivisor(int a, int b) {
    if (a<b) {
        return maxCommonDivisor(b, a);
    }
    int c;
    while ((c = a%b) != 0) {
        a = b;
        b = c;
    }
    return b;
}


