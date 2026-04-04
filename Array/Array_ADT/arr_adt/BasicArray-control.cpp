#include <iostream>
using namespace std;

// 1 Print array
void printArray(int A[], int n)
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

// 2 Find length
int lengthArray(int n)
{
    return n;
}

// 3 Find maximum element
int findMax(int A[], int n)
{
    int max=A[0];

    for(int i=1;i<n;i++)
        if(A[i]>max)
            max=A[i];

    return max;
}

// 4 Find minimum element
int findMin(int A[], int n)
{
    int min=A[0];

    for(int i=1;i<n;i++)
        if(A[i]<min)
            min=A[i];

    return min;
}

// 5 Sum of elements
int sumArray(int A[], int n)
{
    int sum=0;

    for(int i=0;i<n;i++)
        sum+=A[i];

    return sum;
}

// 6 Average of elements
double averageArray(int A[], int n)
{
    return (double)sumArray(A,n)/n;
}

// 7 Get element at index
int getElement(int A[], int index)
{
    return A[index];
}

// 8 Update element at index
void updateElement(int A[], int index,int value)
{
    A[index]=value;
}

int main()
{
    int A[]={4,7,2,9,5};
    int n=5;

    cout<<"Array: ";
    printArray(A,n);

    cout<<"Length: "<<lengthArray(n)<<endl;

    cout<<"Max: "<<findMax(A,n)<<endl;
    cout<<"Min: "<<findMin(A,n)<<endl;

    cout<<"Sum: "<<sumArray(A,n)<<endl;
    cout<<"Average: "<<averageArray(A,n)<<endl;

    cout<<"Element at index 2: "<<getElement(A,2)<<endl;

    updateElement(A,2,100);
    cout<<"After update: ";
    printArray(A,n);

}