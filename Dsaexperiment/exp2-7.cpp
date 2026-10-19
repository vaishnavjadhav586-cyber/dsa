#include<iostream> //deque
#include<deque>
using namespace std;

int main()
{
    deque<int> d={10,20,30,40,50};  //create deque

    //Display deque elements
    cout<<"Deque elements: ";
    for(int i=0; i<d.size(); i++)
    {
        cout<<d[i]<<" ";       //display elements
    }

    //Access first and last elements
    cout<<"\nFront element: "<<d.front();
    cout<<"\nBack element: "<<d.back();
    cout<<"\nElement at index 2: "<<d.at(2);

    //Modify element
    d[1]=25;       //change element at index 1

    cout<<"\nAfter modification: ";
    for(int i=0; i<d.size(); i++)
    {
        cout<<d[i]<<" ";
    }

    //Insert at front
    d.push_front(5);

    //Insert at back
    d.push_back(60);

    cout<<"\nAfter insertion: ";
    for(int i=0; i<d.size(); i++)
    {
        cout<<d[i]<<" ";
    }

    //Delete from front
    d.pop_front();

    //Delete from back
    d.pop_back();

    cout<<"\nAfter deleting front and back: ";
    for(int i=0; i<d.size(); i++)
    {
        cout<<d[i]<<" ";
    }

    //Insert at a specific position
    d.insert(d.begin()+2,35);

    cout<<"\nAfter inserting 35: ";
    for(int i=0; i<d.size(); i++)
    {
        cout<<d[i]<<" ";
    }

    //Delete from a specific position
    d.erase(d.begin()+1);

    cout<<"\nAfter deleting index 1: ";
    for(int i=0; i<d.size(); i++)
    {
        cout<<d[i]<<" ";
    }

    return 0;
}
