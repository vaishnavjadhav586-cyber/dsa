#include<iostream> // list
#include<list>
using namespace std;

int main()
{
    list<int> l={10,20,30,40,50};  //create list

    cout<<"List elements: ";
    for(int x:l)
    {
        cout<<x<<" ";       //display elements
    }

    cout<<"\nFront element: "<<l.front();  //first element
    cout<<"\nBack element: "<<l.back();    //last element

    //Modify first element
    l.front()=15;

    cout<<"\nAfter modification: ";
    for(int x:l)
    {
        cout<<x<<" ";
    }

    //Insert element at beginning
    l.push_front(5);

    //Insert element at end
    l.push_back(60);

    cout<<"\nAfter insertion: ";
    for(int x:l)
    {
        cout<<x<<" ";
    }

    //Insert element at a specific position
    list<int>::iterator it=l.begin();
    advance(it,3);
    l.insert(it,25);

    cout<<"\nAfter inserting 25: ";
    for(int x:l)
    {
        cout<<x<<" ";
    }

    //Delete first element
    l.pop_front();

    //Delete last element
    l.pop_back();

    cout<<"\nAfter deleting first and last: ";
    for(int x:l)
    {
        cout<<x<<" ";
    }

    //Delete element at a specific position
    it=l.begin();
    advance(it,2);
    l.erase(it);

    cout<<"\nAfter deleting an element: ";
    for(int x:l)
    {
        cout<<x<<" ";
    }

    return 0;
}


