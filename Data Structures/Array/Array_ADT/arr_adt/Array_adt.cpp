//Represntation of Data type and structure 
//Entire Operations of Data type and DS Array.

#include <iostream>
using namespace std;    
class Array
{
    private:
        int *A;
        int size;
        int length;
    public:
        Array()
        {
            size=10;
            length=0;
            A=new int[size];
        }
        Array(int sz)
        {
            size=sz;
            length=0;
            A=new int[size];
        }
        ~Array()
        {
            delete []A;
        }
        void Display();
        void Append(int x);
        void Insert(int index,int x);
        int Delete(int index);
        int LinearSearch(int key);
        int BinarySearch(int key);
        int Get(int index);
        void Set(int index,int x);
        int Max();
        int Min();
        float Average();
};
void Array::Display()
{
    cout<<"Elements are: ";
    for(int i=0;i<length;i++)    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
void Array::Append(int x)
{
    if(length<size)
    {
        A[length++]=x;
    }
}
void Array::Insert(int index,int x)
{
    if(index>=0 && index<=length)
    {
        for(int i=length;i>index;i--)     {
            A[i]=A[i-1];        
        }
        A[index]=x;
        length++;
    }
}
int Array::Delete(int index)
{
    int x=0;
    if(index>=0 && index<length)
    {
        x=A[index];
        for(int i=index;i<length-1;i++)
        {
            A[i]=A[i+1];
        }
        length--;
    }
    return x;
}
int Array::LinearSearch(int key)
{
    for(int i=0;i<length;i++)    {
        if(key==A[i])    {
            return i;
        }
    }
    return -1;
}       
int Array::BinarySearch(int key)
{
    int l=0;
    int h=length-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(key==A[mid])
        {
            return mid;
        }
        else if(key<A[mid])
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return -1;
}
int Array::Get(int index)
{
    if(index>=0 && index<length)    {
        return A[index];
    }
    return -1;
}
void Array::Set(int index,int x)
{
    if(index>=0 && index<length)    {
        A[index]=x;
    }
}
int Array::Max()
{       
    int max=A[0];
    for(int i=1;i<length;i++)    {
        if(A[i]>max)        {
            max=A[i];
        }
    }
    return max;
}
int Array::Min()
{
    int min=A[0];
    for(int i=1;i<length;i++)    {
        if(A[i]<min)        {
            min=A[i];
        }
    }
    return min;
}
float Array::Average()
{
    int sum=0;
    for(int i=0;i<length;i++)    {
        sum+=A[i];
    }
    return (float)sum/length;
}
int main()
{
    Array arr(10);
    arr.Append(10);
    arr.Append(20);
    arr.Append(30);         
    arr.Append(40);
    arr.Append(50);
    arr.Display();

    arr.Insert(2,25);
    arr.Display();

    cout<<"Deleted element: "<<arr.Delete(4)<<endl;
    arr.Display();

    cout<<"Element found at index: "<<arr.LinearSearch(30)<<endl;

    cout<<"Element found at index: "<<arr.BinarySearch(25)<<endl;

    cout<<"Element at index 3: "<<arr.Get(3)<<endl;
    arr.Set(3,35);
    cout<<"Element at index 3 after setting: "<<arr.Get(3)<<endl;

    cout<<"Minimum element: "<<arr.Min()<<endl;
    cout<<"Maximum element: "<<arr.Max()<<endl;
    cout<<"Average: "<<arr.Average()<<endl;
    
    return 0;
}   