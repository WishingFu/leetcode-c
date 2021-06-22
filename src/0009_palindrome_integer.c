#define LOG_ON 1
#include "0_include.h"

/**
 * https://leetcode.com/problems/palindrome-number/
 */ 
bool isPalindrome(int x){
    if(x < 0) {
        return false;
    }
    int palin = 0;
    int xx = x;
    while(xx) {
        if(palin > ((0x7fffffff) / 10)) {
            return false;
        }
        palin = palin * 10 + xx % 10;
        xx /= 10;
    }   
    return x == palin;
}

int main(int argc, char const *argv[])
{
    int val = 1234567899;
    bool res = isPalindrome(val);
    LOG_RES("Integer: %d is palindrome: %d", val, res);
    return 0;
}
