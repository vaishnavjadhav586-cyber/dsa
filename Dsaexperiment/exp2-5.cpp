#include<iostream> //set
#include<set>
using namespace std;

int main()
{
    set<int> s={30,10,20,40,20};  //create set (duplicates removed)

    //Display set elements
    cout<<"Set elements: ";
    for(int x:s)
    {
        cout<<x<<" ";       //display sorted, unique elements
    }

    //Access first and last elements
    cout<<"\nFirst element: "<<*s.begin();
    cout<<"\nLast element: "<<*s.rbegin();

    //Insert element
    s.insert(50);

    cout<<"\nAfter inserting 50: ";
    for(int x:s)
    {
        cout<<x<<" ";
    }

    //Try inserting duplicate element
    s.insert(20);

    cout<<"\nAfter inserting duplicate 20: ";
    for(int x:s)
    {
        cout<<x<<" ";
    }

    //Delete element
    s.erase(30);

    cout<<"\nAfter deleting 30: ";
    for(int x:s)
    {
        cout<<x<<" ";
    }

    //Search an element
    if(s.find(40)!=s.end())
    {
        cout<<"\n40 is present in set";
    }
    else
    {
        cout<<"\n40 is not present in set";
    }

    return 0;
}
