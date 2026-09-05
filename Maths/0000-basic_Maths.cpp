#include <bits/stdc++.h>
using namespace std;

// 1. Print a Number
void printNumber(long long n) {
    cout << n << '\n';
}

// 2. Basic Arithmetic Operations
void arithmeticOperations(long long a, long long b) {
    cout << "Sum: " << a + b << '\n';
    cout << "Difference: " << a - b << '\n';
    cout << "Product: " << a * b << '\n';
    cout << "Quotient: " << a / b << '\n';
    cout << "Remainder: " << a % b << '\n';
}

// 3. Swap Two Numbers
void swapNumbers(long long &a, long long &b) {
    swap(a, b);                 // STL
}

// 4. Greatest of Two Numbers
long long greatestOfTwo(long long a, long long b) {
    return max(a, b);           // STL
}

// 5. Greatest of Three Numbers
long long greatestOfThree(long long a, long long b, long long c) {
    return max({a, b, c});      // STL
}

// 6. Even or Odd
string evenOrOdd(long long n) {
    return (n % 2 == 0) ? "Even" : "Odd";
}

// 7. Positive, Negative or Zero
string signOfNumber(long long n) {
    if (n > 0) return "Positive";
    if (n < 0) return "Negative";
    return "Zero";
}

// 8. Divisibility Check
bool isDivisible(long long a, long long b) {
    return a % b == 0;
}

// 9. Leap Year
bool isLeapYear(long long year) {
    return (year % 400 == 0) ||
           (year % 4 == 0 && year % 100 != 0);
}

// 10. Print Numbers from 1 to N
void printOneToN(long long n) {
    for (long long i = 1; i <= n; i++) {
        cout << i << ' ';
    }
    cout << '\n';
}

// 11. Sum of First N Natural Numbers
long long sumFirstN(long long n) {
    return n * (n + 1) / 2;
}

// 12. Sum of Numbers in a Range
long long sumRange(long long l, long long r) {
    return (r * (r + 1) / 2) -
           ((l - 1) * l / 2);
}

// 13. Factorial of N
long long factorial(int n) {
    long long ans = 1;

    for (int i = 2; i <= n; i++) {
        ans *= i;
    }

    return ans;
}

// 14. Power of a Number
long long power(long long a, int b) {
    long long ans = 1;

    while (b--) {
        ans *= a;
    }

    return ans;
}

// 15. Fibonacci up to N Terms
void fibonacci(int n) {
    long long a = 0, b = 1;

    for (int i = 0; i < n; i++) {
        cout << a << ' ';

        long long next = a + b;
        a = b;
        b = next;
    }

    cout << '\n';
}

