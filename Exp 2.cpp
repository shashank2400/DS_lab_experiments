/*A program to accept N numbers from the user and store them in an array.
 Then, accept another number from the user and search that using Linear Search.
*/
#include <iostream>
using namespace std;
class sear
{
    int a[100];
    int n;
public:
    void insert_arr();
    void find_ele();
};
void sear::insert_arr()
{

    int i;
    cout<<"enter the array length";
    cin>>n;
    cout<<"enter elements";
    for(i=0;i<n;i++)
    {

        cin>>a[i];
    }
}
void sear::find_ele()
{
    int coun=0;
    int val;
    cout<<"enter the number to search";
    cin>>val;
     for(int i=0;i<n;i++)
            {
                if(a[i]==val)
                {
                    coun++;
                    break;

                }
            }
       if(coun==1)
            cout<<"Number found";
        else if(coun==0)
            cout<<"Number not found";

}
int main()
{
    sear p;
    p.insert_arr();
    p.find_ele();
    return 0;
}
