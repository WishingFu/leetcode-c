#define LOG_ON 1
#include "0_include.h"

/**
 * https://leetcode.com/problems/roman-to-integer/
 */ 
int romanToInt(char * s){
    int result = 0;
    char * letters = "MDCLXVI";

    int vals[] = {1000, 500, 100, 50, 10, 5, 1};

    int cur_index = 0;
    while(*s) {
        LOG("cursor: %d, symbol: %c, current data: %c, current result: %d", cur_index, letters[cur_index], *s, result);

        if(*s == letters[cur_index]) {
            result += vals[cur_index];
        } else if(*s == letters[cur_index + 2] && (*(s + 1) == letters[cur_index] || *(s + 1) == letters[cur_index + 1])) {
            result -= vals[cur_index + 2];
        } else {
            cur_index += 1;
            s -= 1;
        }

        s += 1;
    }
    return result;
}

int main(int argc, char const *argv[])
{   
    char * val = "IV";
    int res = romanToInt(val);
    LOG_RES("String: %s to integer: %d", val, res);
    return 0;
}
