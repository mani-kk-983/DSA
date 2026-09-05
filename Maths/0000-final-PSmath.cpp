#include <bits/stdc++.h>
using namespace std;

// 2. Basic Arithmetic Operations
void arithmetic(long long a, long long b) {
    cout << a + b << ' ';
    cout << a - b << ' ';
    cout << a * b << ' ';
    cout << a / b << ' ';
    cout << a % b << '\n';
}

// 3. Swap Two Numbers
void swapNumbers(long long &a, long long &b) {
    swap(a, b);
}

// 5. Greatest of Three Numbers
long long greatestOfThree(long long a, long long b, long long c) {
    return max({a, b, c});
}

// 6. Even or Odd
string evenOdd(long long n) {
    return (n % 2 == 0) ? "Even" : "Odd";
}

// 8. Divisibility Check
bool divisible(long long a, long long b) {
    return a % b == 0;
}

// 9. Leap Year
bool isLeapYear(long long year) {
    return year % 400 == 0 ||
           (year % 4 == 0 && year % 100 != 0);
}

// 11. Sum of First N Natural Numbers
long long sumFirstN(long long n) {
    return n * (n + 1) / 2;
}

// 13. Factorial
long long factorial(int n) {
    long long ans = 1;

    for (int i = 2; i <= n; i++)
        ans *= i;

    return ans;
}

// 15. Fibonacci - First N Terms
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

// 16. Count Digits
int countDigits(long long n) {
    if (n == 0) return 1;

    int count = 0;

    while (n > 0) {
        count++;
        n /= 10;
    }

    return count;
}

// 17. Sum of Digits
long long sumDigits(long long n) {
    long long sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

// 21. Reverse Number
long long reverseNumber(long long n) {
    long long rev = 0;

    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    return rev;
}

// 22. Palindrome Number
bool isPalindrome(long long n) {
    return n == reverseNumber(n);
}

// 23. Prime Number
bool isPrime(long long n) {
    if (n < 2) return false;

    if (n == 2) return true;

    if (n % 2 == 0) return false;

    for (long long i = 3; i <= n / i; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

// 24. Factors of a Number
vector<long long> getFactors(long long n) {
    vector<long long> ans;

    for (long long i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            ans.push_back(i);

            if (i != n / i)
                ans.push_back(n / i);
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

// 25. Prime Factorization
vector<long long> primeFactors(long long n) {
    vector<long long> ans;

    while (n % 2 == 0) {
        ans.push_back(2);
        n /= 2;
    }

    for (long long i = 3; i <= n / i; i += 2) {
        while (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    }

    if (n > 1)
        ans.push_back(n);

    return ans;
}

// 32. GCD
long long gcdNumber(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }

    return a;
}

// 33. LCM
long long lcmNumber(long long a, long long b) {
    return (a / gcdNumber(a, b)) * b;
}

// 34. Sum of Two Prime Numbers
pair<long long, long long> twoPrimeSum(long long n) {
    for (long long i = 2; i <= n / 2; i++) {
        if (isPrime(i) && isPrime(n - i))
            return {i, n - i};
    }

    return {-1, -1};
}

// 43. Decimal -> Binary
string decimalToBinary(unsigned long long n) {
    if (n == 0) return "0";

    string ans;

    while (n > 0) {
        ans += char('0' + n % 2);
        n /= 2;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}