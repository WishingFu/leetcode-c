#define LOG_ON 1
#include "0_include.h"

#define REPEAT(arr, index, c, num) for(int i = 0; i < num; i++) {arr[index--] = c;}

/**
 * https://leetcode.com/problems/integer-to-roman/
 */ 
char * intToRoman(int num){ 
    static char result[17] = "";

    char * ROMAN_LETTERS = "IVXLCDM";

    int length = 0;
    int lindex = 0;
    int index = 15;

    while(num) {
        int n = num % 10;

        if(n == 9) {
            result[index--] = ROMAN_LETTERS[lindex + 2];
            result[index--] = ROMAN_LETTERS[lindex];
        } else if(n >= 5) {
            REPEAT(result, index, ROMAN_LETTERS[lindex], n - 5);
            result[index--] = ROMAN_LETTERS[lindex + 1];
        } else if(n == 4) {
            result[index--] = ROMAN_LETTERS[lindex + 1];
            result[index--] = ROMAN_LETTERS[lindex];
        } else {
            REPEAT(result, index, ROMAN_LETTERS[lindex], n);
        }

        lindex += 2;
        num /= 10;
    } 

    return result + (index + 1);
}

int main(int argc, char const *argv[])
{
    int val = 3999;
    char * res = intToRoman(val);
    LOG_RES("Integer: %d to roman: %s", val, res);
    return 0;
}
