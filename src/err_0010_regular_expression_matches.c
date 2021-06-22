#define LOG_ON 1
#include "0_include.h"

#define ANY_CHAR '.'
#define NUM_CHAR '*'

/**
 * https://leetcode.com/problems/regular-expression-matching/
 * '.' Matches any single character.​​​​
 * '*' Matches zero or more of the preceding element.
 */ 
bool isMatch(char * s, char * p){
    int state = 0; // char: 1, .any: 2, *char: 3, .*: 4 

    char matcher = *p++;
    state = matcher == ANY_CHAR ? 2 : 1;
    if(*p == NUM_CHAR) {
        state += 2;
        p += 1;
    }

    LOG("Present char: %c, present matcher: %c, present state: %d", *s, matcher, state);

    while(*s) {
        if(state == 4) {
            return true;
        }

        if(*s != matcher && matcher != ANY_CHAR) {
            if(state != 3) {
                return false;
            }
            goto next_matcher;
        }

        s++;

        if(*s && state != 3) {
            next_matcher: 
                if(!*p) {
                    return false;
                }
                matcher = *p++;
                state = matcher == ANY_CHAR ? 2 : 1;
                if(*p == NUM_CHAR) {
                    state += 2;
                    p += 1;
                }
        }
    }

    LOG("Next char: %d, next matcher: %d", *s, *p);

    return !*s && !*p;
}

int main(int argc, char const *argv[])
{
    char * str = "ab";
    char * exp = ".*c";
    bool res = isMatch(str, exp);
    LOG_RES("String: '%s' matches expression '%s': %d", str, exp, res);
    return 0;
}
