#include <iostream>
#include <cassert>
#include "find.h"

/*  * test function 1: identity -> f(n) = n
    * This function is strictly increasing for n >= 0.
    * It returns the input number itself.   
*/
double mainIdentity(long n) {
    return static_cast<double>(n);
}

/* 
    * test function 2: square -> f(n) = n * n
    * This function is strictly increasing for n >= 0.
    * It returns the square of the input number.
*/
double mainSquare(long n) {
    return static_cast<double>(n * n);
}

int main() {
    /* Test 1: expected result is 5 */
    assert(find(mainIdentity, 5.0, 0, 10) == 5);

    /* Test 2: expected result is -1 */
    assert(find(mainIdentity, 11.0, 0, 10) == -1);

    /* Test 3: expected result is 7 */
    assert(find(mainSquare, 49.0, 0, 20) == 7);

    /* Test 4: expected result is -1 */
    assert(find(mainSquare, 50.0, 0, 20) == -1);

    /* Test 5: expected result is 3 */
    assert(find(mainIdentity, 3.0, 3, 3) == 3);

    /* Test 6: expected result is -1 */
    assert(find(mainIdentity, 4.0, 3, 3) == -1);
    
    /* Test 7: expected result is -1.
       The function is strictly increasing, but since it returns only integers,
       and we're checking for exact equality, 500.3 will never match f(n).
    */
    assert(find(mainIdentity, 500.3, 10, 1000) == -1);

    std::cout << "All tests passed successfully.\n";
    return 0;
}
