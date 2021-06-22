#define LOG_ON 1
#include "0_include.h"

#define MAX(a, b) a>b?a:b
/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * 解决思路: 滑窗
 */
int lengthOfLongestSubstring(char * s) {
    int strLength = strlen(s);
    if(strLength == 0 || strLength == 1) {
        return strLength;
    }

    int indexes[255];
    int maxLength = 0, start = 0, end = 0;
    memset(indexes, 255, sizeof(indexes));
    for(int i = 0; i < strLength; i++) {
        char c = s[i];
        if(indexes[c] != -1 && indexes[c] >= start) {
            int subLen = end - start;
            maxLength = MAX(maxLength, subLen);
            LOG("Repeat: %d, prev: %d, now: %d", c, indexes[c], i);
            start = indexes[c] + 1;
        }
        indexes[c] = i;
        end += 1;
        LOG("Sliding windows, start: %d, end: %d", start, end);
    }

    maxLength = MAX(maxLength, end - start);
    return maxLength;
}

int main(int argc, char const *argv[])
{
    char * str = "abcabcbb";
    int res = lengthOfLongestSubstring(str);
    LOG_RES("Longest substring length: %d.", res);
    return 0;
}