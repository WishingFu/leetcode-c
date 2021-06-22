#define LOG_ON 1
#include "0_include.h"

#define MIN(x, y) (x>y?y:x)
#define MAX(x, y) (x>y?x:y)

/**
 * https://leetcode.com/problems/container-with-most-water/
 */ 
int maxArea(int* height, int heightSize){

    int start = 0, end = heightSize - 1;

    int max = 0;
    while (start != end)
    {
        int area = MIN(height[start], height[end]) * (end - start);
        max = MAX(max, area);

        LOG("start: %d, height: %d, end: %d, height: %d, min: %d, area: %d", start, height[start], end, height[end], MIN(height[start], height[end]), area);

        if(height[start] > height[end]) {
            end--;
        } else {
            start++;
        }
    }
    
    return max;
}

int main(int argc, char const *argv[])
{
    int val[] = {1,8,6,2,5,4,8,3,7};
    int res = maxArea(val, sizeof(val) / 4);
    LOG_RES("Most water: %d", res);
    return 0;
}
