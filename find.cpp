#include "find.h"

long find(double (*f)(long), double y, long a, long b) {
    while (a <= b) {
        /* truncates the range to the middle */
        long middleIndex = a + (b - a) / 2;

        /* check if f(middleIndex) is equal to y */
        double valueAtMid = f(middleIndex);

        /* if f(middleIndex) is equal to y, return middleIndex */
        if (valueAtMid == y) {
            return middleIndex;
        } 
        /* if f(middleIndex) is less than y, search in the right half */   
        else if (valueAtMid < y) {
            a = middleIndex + 1;
        }
        /* if f(middleIndex) is greater than y, search in the left half */    
        else {
            b = middleIndex - 1;
        }    
    }
    /* if the value is not found, return -1 */
    return -1;
}
