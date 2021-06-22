#define LOG_ON 1
#include "0_include.h"

/**
 * https://leetcode.com/problems/container-with-most-water/
 */ 
int maxArea(int* height, int heightSize){

    return 0;
}

int main(int argc, char const *argv[])
{
    int val[] = {1, 2, 3};
    int res = maxArea(val, sizeof(val) / 4);
    LOG_RES("Most water: ", res);
    return 0;
}
