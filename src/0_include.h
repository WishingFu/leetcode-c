#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#if LOG_ON
    #define LOG(...) {printf(__VA_ARGS__);printf("\n");}
#else
    #define LOG(...) {}
#endif

#define LOG_RES(...) {printf(__VA_ARGS__);printf("\n");}