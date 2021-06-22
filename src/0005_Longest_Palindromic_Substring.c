#define LOG_ON 1
#include "0_include.h"

#define MIN(a, b) a>b?b:a
/**
 * https://leetcode.com/problems/longest-palindromic-substring/
 * 
 * 
 */ 
char * longestPalindrome(char * s){
    int strLen = strlen(s);
    if(strLen == 1 || strLen == 0) {
        return s;
    }

    int maxLength = 0;
    int maxStart = 0, maxEnd = 0;
    for(int i = 0; i < strLen; i++) {
        int start = i, end = i;
        while(start > 0 && end < strLen - 1) {
            start -= 1;
            end += 1;
            if(s[start] != s[end]) {
                start += 1;
                end -= 1;
                LOG("Iter end, %d, start: %d, val: %d, end: %d, val: %d", i, start, s[start], end, s[end]);
                break;
            }
            LOG("%d, start: %d, val: %d, end: %d, val: %d", i, start, s[start], end, s[end]);
        }
        if(start != end) {
            int length = end - start;
            if(maxLength < length) {
                maxLength = length;
                maxStart = start;
                maxEnd = end;
            }
        }
        start = i, end = i + 1;
        if(s[start] == s[end]) {
            while(start > 0 && end < strLen - 1) {
                start -= 1;
                end += 1;
                if(s[start] != s[end]) {
                    start += 1;
                    end -= 1;
                    break;
                }
            }
            if(start != end) {
                int length = end - start;
                if(maxLength < length) {
                    maxLength = length;
                    maxStart = start;
                    maxEnd = end;
                }
            }
        }
    }
    LOG("End, start: %d, end: %d", maxStart, maxEnd);
    s[maxEnd + 1] = '\0';
    return s + maxStart;
}

int main(int argc, char const *argv[])
{
    char str[100] = "cbbd";
    char * res = longestPalindrome(str);
    LOG_RES("Longest palindromic substring: %s.", res);
    return 0;
}
