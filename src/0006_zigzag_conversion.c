#define LOG_ON 1
#include "0_include.h"

/**
 * 直接按规律读
 */
char * convert_2_solution(char * s, int numRows) {
    int size = strlen(s);

    if(size == 0 || size == 1|| numRows == 1) {
        return s;
    }

    char * result = calloc(1, size + 1);
    
    int temp = (numRows - 2) * 2 + 2;

    int step = numRows - 1, result_pos = 0;
    for(int row = 0; row < numRows; row++) {
        int col = 0, pos = 0;
        if(row == 0 || row == step) {
            do {
                pos = col * temp + row;
                
                if(pos < size) {
                    result[result_pos++] = s[pos];
                    //LOG("Row: %d, col: %d, value: %c", row, col, s[pos]);
                    col += 1;
                }
            } while(pos < size);
        } else {
            do {
                // first
                pos = col * temp + row;

                if(pos < size) {
                    result[result_pos++] = s[pos];
                    //LOG("Row: %d, col: %d, value: %c", row, col, s[pos]);

                     // second
                    pos = col * temp + numRows + (numRows - 2 - row);
                    if(pos < size) {
                        result[result_pos++] = s[pos];
                        //LOG("Row: %d, col: %d, value: %c", row, col, s[pos]);
                        col += 1;
                    }
                }
            } while(pos < size);
        }
    }

    return result;
}

/**
 * https://leetcode.com/problems/zigzag-conversion/
 * 按zigzag遍历
 */ 
char * convert(char * s, int numRows){
    int size = strlen(s);

    if(size == 0 || size == 1|| numRows == 1) {
        return s;
    }

    int pr = 0, pc = 0;
    int max = numRows - 1;
    char ** data = calloc(numRows, sizeof(char *));

    for(int i = 0; i < numRows; i++) {
        data[i] = calloc(1, size);
    }

    int * pos = calloc(numRows, sizeof(int));
    for(int i = 0; i < size; i++) {
        // LOG("Cur post, row: %d, col: %d", pr, pc);
        data[pr][pos[pr]++] = s[i];
        if(pc % max == 0) {
            pr += 1;

            if(pr == numRows) {
                pr -= 2;
                pc += 1;
            }
        } else {
            pr -= 1;
            pc += 1;
        }
    }

    s[0] = '\0';
    for(int i = 0; i < numRows; i++) {
        strcat(s, data[i]);
        free(data[i]);
    }

    free(data);
    free(pos);

    return s;
}

int main(int argc, char const *argv[])
{   
    char str[200] = "PAYPALISHIRING";
    char *(*solution)(char *, int) = &convert_2_solution;
    char * res = solution(str, 3);
    LOG_RES("Result of zigzag conversion: %s", res);
    return 0;
}
