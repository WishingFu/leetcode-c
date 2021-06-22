#define LOG_ON 1
#include "0_include.h"

#define MAX 0x7fffffff
#define MIN 0x80000000

#define WHITE_SPACE ' '
#define MIN_CHAR '0'
#define MAX_CHAR '9'
#define POS_SIGN '+'
#define NEG_SIGN '-'

/**
 * https://leetcode.com/problems/string-to-integer-atoi/
 */ 
int my_a2i(char * s) {
    int result = 0;
    int length = strlen(s);

    int status = 0; // 0 符号查找, 1 数值查找
    char neg = 0;

    int pos = 0;
    while (pos < length)
    {
        char pc = s[pos];
        if(status == 0) {
            if(pc == POS_SIGN) {
                status = 1;
            } else if(pc == NEG_SIGN) {
                status = 1;
                neg = 1;
            } else if(pc >= MIN_CHAR && pc <= MAX_CHAR) {
                status = 1;
                continue;
            } else if(pc != WHITE_SPACE) {
                break;
            }
        } else {
            if(pc < MIN_CHAR || pc > MAX_CHAR) {
                break;
            }
            if(!neg && (result > MAX / 10 || (result == MAX / 10 && pc >= '7'))) {
                return MAX;
            }
            if(neg && (result > MIN / 10 || (result == MIN / 10 && pc >= '8'))) {
                return MIN;
            }
            result = result * 10 + (pc - MIN_CHAR);
        }
        pos += 1;
    }
    return neg ? -result : result;
}

int main(int argc, char const *argv[])
{
    char * str = "-2147483648";
    int res = my_a2i(str);
    LOG_RES("String: %s to integer: %d", str, res);
    return 0;
}
