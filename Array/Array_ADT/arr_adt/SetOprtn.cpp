#include <iostream>
#include <vector>
using namespace std;

// 1. Merge two sorted arrays
vector<int> mergeArrays(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int i = 0, j = 0;

    while(i < A.size() && j < B.size())
    {
        if(A[i] <= B[j])
            C.push_back(A[i++]);
        else
            C.push_back(B[j++]);
    }

    while(i < A.size())
        C.push_back(A[i++]);

    while(j < B.size())
        C.push_back(B[j++]);

    return C;
}


// 2. Union of two arrays
vector<int> unionArray(vector<int> &A, vector<int> &B)
{
    vector<int> U;
    int i = 0, j = 0;

    while(i < A.size() && j < B.size())
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

    while(i < A.size())
        U.push_back(A[i++]);

    while(j < B.size())
        U.push_back(B[j++]);

    return U;
}


// 3. Intersection
vector<int> intersectionArray(vector<int> &A, vector<int> &B)
{
    vector<int> I;
    int i = 0, j = 0;

    while(i < A.size() && j < B.size())
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


// 4. Difference (A - B)
vector<int> differenceArray(vector<int> &A, vector<int> &B)
{
    vector<int> D;
    int i = 0, j = 0;

    while(i < A.size() && j < B.size())
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

    while(i < A.size())
        D.push_back(A[i++]);

    return D;
}


// 5. Check equality
bool areEqual(vector<int> &A, vector<int> &B)
{
    if(A.size() != B.size())
        return false;

    for(int i = 0; i < A.size(); i++)
        if(A[i] != B[i])
            return false;

    return true;
}


// Utility function to print arrays
void printVector(vector<int> &V)
{
    for(int x : V)
        cout << x << " ";
    cout << endl;
}


int main()
{
    vector<int> A = {1,2,4,5};
    vector<int> B = {2,3,5,6};

    cout << "Merged: ";
    vector<int> M = mergeArrays(A,B);
    printVector(M);

    cout << "Union: ";
    vector<int> U = unionArray(A,B);
    printVector(U);

    cout << "Intersection: ";
    vector<int> I = intersectionArray(A,B);
    printVector(I);

    cout << "Difference (A-B): ";
    vector<int> D = differenceArray(A,B);
    printVector(D);

    cout << "Arrays Equal? ";
    cout << (areEqual(A,B) ? "Yes" : "No") << endl;
}