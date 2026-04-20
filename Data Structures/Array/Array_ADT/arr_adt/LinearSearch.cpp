#include <iostream>
using namespace std;

// 1 Linear Search
int linearSearch(int A[], int n, int key)
{
    for(int i=0;i<n;i++)
        if(A[i]==key)
            return i;

    return -1;
}

// 2 Count occurrences of element
int countOccurrences(int A[], int n, int key)
{
    int count=0;

    for(int i=0;i<n;i++)
        if(A[i]==key)
            count++;

    return count;
}

// 3 Check if element exists
bool contains(int A[], int n, int key)
{
    for(int i=0;i<n;i++)
        if(A[i]==key)
            return true;

    return false;
}

// 4 First occurrence
int firstOccurrence(int A[], int n, int key)
{
    for(int i=0;i<n;i++)
        if(A[i]==key)
            return i;

    return -1;
}

// 5 Last occurrence
int lastOccurrence(int A[], int n, int key)
{
    for(int i=n-1;i>=0;i--)
        if(A[i]==key)
            return i;

    return -1;
}

// 6 Count even numbers
int countEven(int A[], int n)
{
    int count=0;

    for(int i=0;i<n;i++)
        if(A[i]%2==0)
            count++;

    return count;
}

// 7 Count odd numbers
int countOdd(int A[], int n)
{
    int count=0;

    for(int i=0;i<n;i++)
        if(A[i]%2!=0)
            count++;

    return count;
}

int main()
{
    int A[]={4,7,2,7,5,8};
    int n=6;

    cout<<"Index of 7: "<<linearSearch(A,n,7)<<endl;

    cout<<"Occurrences of 7: "<<countOccurrences(A,n,7)<<endl;

    cout<<"Contains 5? "<<(contains(A,n,5)?"Yes":"No")<<endl;

    cout<<"First 7: "<<firstOccurrence(A,n,7)<<endl;

    cout<<"Last 7: "<<lastOccurrence(A,n,7)<<endl;

    cout<<"Even count: "<<countEven(A,n)<<endl;

    cout<<"Odd count: "<<countOdd(A,n)<<endl;
}