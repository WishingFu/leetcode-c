#define LOG_ON 1
#include "0_include.h"

#define MAX 0x7fffffff
#define MIN (int)0x80000000

/**
 * https://leetcode.com/problems/reverse-integer/
 */ 
int reverse(int x) {
    int64_t result = 0;

    while (x != 0)
    {
        if(result >= MAX / 10 || result <= MIN / 10) {
            return 0;
        }
        result = result * 10 + x % 10;
        x /= 10;
    }   

    return result;
}

int main(int argc, char const *argv[])
{
    int num = 1463847412;
    int res = reverse(num);
    LOG_RES("Reverse integer %d to %d", num, res);
    return 0;
}
