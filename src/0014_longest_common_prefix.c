#define LOG_ON 1
#include "0_include.h"

char nextChar(char ** strs, char index, int size) {
    char result = *(*strs + index);
    for(int i = 1; i < size; i++) {
        if(result != *(*(strs + i) + index)) {
            return 0;
        }
    }
    return result;
}

/**
 * https://leetcode.com/problems/longest-common-prefix/
 */ 
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 1) {
        return *strs;
    }
    static char result[200] = "";
    result[0] = 0;
    char index = 0;
    char next = 1;
    
    while ((next = nextChar(strs, index, strsSize)))
    {
        result[index++] = next;
    }
    result[index] = 0;
    return result;
}

int main(int argc, char const *argv[])
{
    char * strs[] = {"dog","racecar","car"};
    char * res = longestCommonPrefix(strs, sizeof(strs) / sizeof(char *));
    LOG_RES("Longest common prefix: %s.", res);
    return 0;
}
