#define LOG_ON 1
#include "0_include.h"

/**
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 * 
 * 
 */ 
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int total = nums1Size + nums2Size;
    char even = total % 2 == 0;
    int mid = total / 2 + !even;

    int p1 = 0, p2 = 0, last = 0, p1p = 0, p2p = 0;
    while(p1 + p2 < mid) {
        if(p1 >= nums1Size) {
            last = nums2[p2];
            p2 ++;
        } else if (p2 >= nums2Size) {
            last = nums1[p1];
            p1 ++;
        } else {
            p1p = nums1[p1];
            p2p = nums2[p2];
            if(p1p > p2p) {
                p2 ++;
                last = p2p;
            } else {
                p1 ++;
                last = p1p;
            }
        }
        LOG("After iterate, p1: %d, p2: %d, last: %d", p1, p2, last);
    }
    LOG("Finish iterate, p1: %d, p2: %d, last: %d", p1, p2, last);
    if(!even) {
        return last;
    }
    if(p1 >= nums1Size) {
        LOG("p1 reached max");
        return (last + nums2[p2]) / 2.0f;
    } else if(p2 >= nums2Size) {
        LOG("p2 reached max");
        return (last + nums1[p1]) / 2.0f;
    } else {
        p1p = nums1[p1];
        p2p = nums2[p2];
        int min = p1p > p2p ? p2p : p1p;
        return (last + min) / 2.0f;
    }
}

int main(int argc, char const *argv[])
{
    int nums1[] = {1};
    int nums2[] = {};

    double res = findMedianSortedArrays(nums1, sizeof(nums1) / 4, nums2, sizeof(nums2) / 4);

    LOG_RES("Median of array: %f", res);

    return 0;
}
