#ifndef FIND_H
#define FIND_H

/**
 * find
 *
 * Given a strictly increasing function f: long -> double,
 * a range [a, b], and a value y,
 * returns the integer n such that f(n) == y, or -1 if not found.
 */
long find(double (*f)(long), double y, long a, long b);

#endif // FIND_H
