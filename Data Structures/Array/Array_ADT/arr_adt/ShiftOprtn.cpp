#include <iostream>
using namespace std;

void printArray(int A[], int n)
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}


// ---------- LEVEL 2 ----------

// Insert element
void insertElement(int A[], int &n,int index,int value)
{
    for(int i=n;i>index;i--)
        A[i]=A[i-1];

    A[index]=value;
    n++;
}

// Delete element
void deleteElement(int A[], int &n,int index)
{
    for(int i=index;i<n-1;i++)
        A[i]=A[i+1];

    n--;
}

// Left shift
void leftShift(int A[], int n)
{
    for(int i=0;i<n-1;i++)
        A[i]=A[i+1];

    A[n-1]=0;
}

// Right shift
void rightShift(int A[], int n)
{
    for(int i=n-1;i>0;i--)
        A[i]=A[i-1];

    A[0]=0;
}

// Rotate left
void rotateLeft(int A[], int n)
{
    int temp=A[0];

    for(int i=0;i<n-1;i++)
        A[i]=A[i+1];

    A[n-1]=temp;
}

// Rotate right
void rotateRight(int A[], int n)
{
    int temp=A[n-1];

    for(int i=n-1;i>0;i--)
        A[i]=A[i-1];

    A[0]=temp;
}

// Reverse array
void reverseArray(int A[], int n)
{
    int i=0,j=n-1;

    while(i<j)
    {
        swap(A[i],A[j]);
        i++;
        j--;
    }
}


// ---------- LEVEL 3 ----------

// Check palindrome
bool isPalindrome(int A[], int n)
{
    int i=0,j=n-1;

    while(i<j)
    {
        if(A[i]!=A[j])
            return false;

        i++;
        j--;
    }

    return true;
}

// Swap alternate
void swapAlternate(int A[], int n)
{
    for(int i=0;i<n-1;i+=2)
        swap(A[i],A[i+1]);
}

// Move negatives left
void moveNegatives(int A[], int n)
{
    int i=0,j=n-1;

    while(i<j)
    {
        if(A[i]<0)
            i++;
        else if(A[j]>=0)
            j--;
        else
            swap(A[i],A[j]);
    }
}

// Move zeros to end
void moveZeros(int A[], int n)
{
    int k=0;

    for(int i=0;i<n;i++)
    {
        if(A[i]!=0)
        {
            swap(A[i],A[k]);
            k++;
        }
    }
}

// Partition array
void partitionArray(int A[], int n,int pivot)
{
    int boundary=0;

    for(int i=0;i<n;i++)
    {
        if(A[i]<pivot)
        {
            swap(A[i],A[boundary]);
            boundary++;
        }
    }
}


// ---------- MAIN ----------

int main()
{
    int A[20]={3,-2,0,5,-7,0,8};
    int n=7;

    cout<<"Original: ";
    printArray(A,n);

    moveNegatives(A,n);
    cout<<"Negatives Left: ";
    printArray(A,n);

    moveZeros(A,n);
    cout<<"Zeros End: ";
    printArray(A,n);

    swapAlternate(A,n);
    cout<<"Swap Alternate: ";
    printArray(A,n);

    reverseArray(A,n);
    cout<<"Reverse: ";
    printArray(A,n);

    rotateLeft(A,n);
    cout<<"Rotate Left: ";
    printArray(A,n);

    rotateRight(A,n);
    cout<<"Rotate Right: ";
    printArray(A,n);

    cout<<"Palindrome? "<<(isPalindrome(A,n)?"Yes":"No")<<endl;

    partitionArray(A,n,3);
    cout<<"Partition <3: ";
    printArray(A,n);

}