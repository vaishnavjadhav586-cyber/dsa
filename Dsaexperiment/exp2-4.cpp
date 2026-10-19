
#include<iostream> //queue
#include<queue>
using namespace std;

int main()
{
    queue<int> q;       //create queue

    q.push(10);         //insert element
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout<<"Front element: "<<q.front()<<endl;  //first element
    cout<<"Back element: "<<q.back()<<endl;    //last element

    //Display queue elements
    cout<<"Queue elements: ";
    queue<int> temp=q;     //copy queue for displaying

    while(!temp.empty())
    {
        cout<<temp.front()<<" ";  //display front element
        temp.pop();               //remove front from temporary queue
    }

    //Modify front element
    q.pop();           //delete 10
    q.push(60);        //insert 60

    cout<<"\nAfter modification: ";
    temp=q;

    while(!temp.empty())
    {
        cout<<temp.front()<<" ";
        temp.pop();
    }

    //Insert another element
    q.push(70);

    cout<<"\nAfter inserting 70: ";
    temp=q;

    while(!temp.empty())
    {
        cout<<temp.front()<<" ";
        temp.pop();
    }

    //Delete front element
    q.pop();

    cout<<"\nAfter deleting front element: ";
    temp=q;

    while(!temp.empty())
    {
        cout<<temp.front()<<" ";
        temp.pop();
    }

    return 0;
}

