#include<iostream>   //vector
#include<vector>
using namespace std;

int main()
{
    vector<int> v={10,20,30,40,50};  //create vector

    cout<<"Vector elements: ";
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";    //display elements
    }

    cout<<"\nFront element: "<<v.front();  //first element
    cout<<"\nBack element: "<<v.back();    //last element
    cout<<"\nElement at index 2: "<<v.at(2); //access element

    v[1]=25;    //modify element at index 1

    cout<<"\nAfter modification: ";
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    v.push_back(60);    //insert element at end

    cout<<"\nAfter inserting 60: ";
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    v.insert(v.begin()+2,35);  //insert 35 at index 2

    cout<<"\nAfter inserting 35: ";
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    v.pop_back();    //delete last element

    cout<<"\nAfter deleting last element: ";
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    v.erase(v.begin()+1);    //delete element at index 1

    cout<<"\nAfter deleting index 1: ";
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}
