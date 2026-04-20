#include <iostream>
#include <vector>
using namespace std;


/* -------- Utility -------- */

void print(vector<int> v)
{
    for(int x : v)
        cout << x << " ";
    cout << endl;
}


/* =========================
        LEVEL 4
   Sorted Array Logic
========================= */

// 1 Check if sorted
bool isSorted(vector<int> A)
{
    for(int i=1;i<A.size();i++)
        if(A[i] < A[i-1])
            return false;

    return true;
}


// 2 Binary Search
int binarySearch(vector<int> A,int key)
{
    int l=0,r=A.size()-1;

    while(l<=r)
    {
        int mid=(l+r)/2;

        if(A[mid]==key)
            return mid;

        else if(A[mid] < key)
            l=mid+1;

        else
            r=mid-1;
    }

    return -1;
}


// 3 Find insertion position
int insertionPosition(vector<int> A,int key)
{
    int l=0,r=A.size()-1;

    while(l<=r)
    {
        int mid=(l+r)/2;

        if(A[mid] < key)
            l=mid+1;

        else
            r=mid-1;
    }

    return l;
}


// 4 First occurrence
int firstOccurrence(vector<int> A,int key)
{
    int l=0,r=A.size()-1;
    int ans=-1;

    while(l<=r)
    {
        int mid=(l+r)/2;

        if(A[mid]==key)
        {
            ans=mid;
            r=mid-1;
        }

        else if(A[mid] < key)
            l=mid+1;

        else
            r=mid-1;
    }

    return ans;
}


// 5 Last occurrence
int lastOccurrence(vector<int> A,int key)
{
    int l=0,r=A.size()-1;
    int ans=-1;

    while(l<=r)
    {
        int mid=(l+r)/2;

        if(A[mid]==key)
        {
            ans=mid;
            l=mid+1;
        }

        else if(A[mid] < key)
            l=mid+1;

        else
            r=mid-1;
    }

    return ans;
}



/* =========================
        LEVEL 5
   Two Array Operations
========================= */


// 1 Merge two sorted arrays
vector<int> mergeArrays(vector<int> A,vector<int> B)
{
    int i=0,j=0;
    vector<int> C;

    while(i<A.size() && j<B.size())
    {
        if(A[i] < B[j])
            C.push_back(A[i++]);
        else
            C.push_back(B[j++]);
    }

    while(i<A.size()) C.push_back(A[i++]);
    while(j<B.size()) C.push_back(B[j++]);

    return C;
}


// 2 Union
vector<int> unionArray(vector<int> A,vector<int> B)
{
    int i=0,j=0;
    vector<int> U;

    while(i<A.size() && j<B.size())
    {
        if(A[i] < B[j])
            U.push_back(A[i++]);

        else if(A[i] > B[j])
            U.push_back(B[j++]);

        else
        {
            U.push_back(A[i]);
            i++; j++;
        }
    }

    while(i<A.size()) U.push_back(A[i++]);
    while(j<B.size()) U.push_back(B[j++]);

    return U;
}


// 3 Intersection
vector<int> intersectionArray(vector<int> A,vector<int> B)
{
    int i=0,j=0;
    vector<int> I;

    while(i<A.size() && j<B.size())
    {
        if(A[i] < B[j])
            i++;

        else if(A[i] > B[j])
            j++;

        else
        {
            I.push_back(A[i]);
            i++; j++;
        }
    }

    return I;
}


// 4 Difference A - B
vector<int> differenceArray(vector<int> A,vector<int> B)
{
    int i=0,j=0;
    vector<int> D;

    while(i<A.size() && j<B.size())
    {
        if(A[i] < B[j])
            D.push_back(A[i++]);

        else if(A[i] > B[j])
            j++;

        else
        {
            i++;
            j++;
        }
    }

    while(i<A.size())
        D.push_back(A[i++]);

    return D;
}


// 5 Check equality
bool arraysEqual(vector<int> A,vector<int> B)
{
    if(A.size()!=B.size())
        return false;

    for(int i=0;i<A.size();i++)
        if(A[i]!=B[i])
            return false;

    return true;
}



/* =========================
            MAIN
========================= */

int main()
{
    vector<int> A={1,2,2,3,4,5};
    vector<int> B={2,3,5,7};

    cout<<"Is Sorted: "<<isSorted(A)<<endl;

    cout<<"Binary Search 3 index: "<<binarySearch(A,3)<<endl;

    cout<<"Insertion position of 6: "<<insertionPosition(A,6)<<endl;

    cout<<"First occurrence of 2: "<<firstOccurrence(A,2)<<endl;

    cout<<"Last occurrence of 2: "<<lastOccurrence(A,2)<<endl;

    cout<<"Merged: ";
    print(mergeArrays(A,B));

    cout<<"Union: ";
    print(unionArray(A,B));

    cout<<"Intersection: ";
    print(intersectionArray(A,B));

    cout<<"Difference A-B: ";
    print(differenceArray(A,B));

    cout<<"Arrays equal? "<<arraysEqual(A,B)<<endl;
}