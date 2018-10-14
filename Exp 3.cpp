/*
A program to accept N integers from the user and store them in an array. Sort the array in ascending order using Bubble sort.
Then accept another number from the user, search whether that number exists in the array using Binary Search.
If it does, display its index and if it doesn’t, then print that the number is not found in the array.
*/
#include <iostream>
using namespace std;
void sort_bubble(int a[],int n)
{

    int i,j;
    for(i=0;i<n;i++)
    {

        for(j=i+1;j<n;j++)
        {

            if(a[i]>a[j])
            {

                int temp;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
int search_binary(int a[], int l, int r, int x)
{
    int m=0;
     if (r >= l)
   {
        int mid = l + (r - l)/2;


        if (a[mid] == x)
            return mid;
        if (a[mid] > x)
            return search_binary(a, l, mid-1, x);
        return search_binary(a, mid+1, r, x);
   }
 return -1;
}
int main()
{
    int a[100],n,x;
    cout<<"enter the array length";
    cin>>n;
    cout<<"enter elements"<<endl;
    for(int i=0;i<n;i++)
    {

        cin>>a[i];
    }
    sort_bubble(a,n);
    for(int i=0;i<n;i++)
    {

        cout<<a[i]<<endl;
    }
    cout<<"enter the number to search"<<endl;
    cin>>x;
int result;
result=search_binary(a,0,n-1,x);
if(result==-1)
{
    cout<<"Number not found";
}
else
{

    cout<<"Number found with index"<<result;
}

    return 0;
}
