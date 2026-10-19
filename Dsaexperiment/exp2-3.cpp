#include<iostream> //stack
#include<stack>
using namespace std;

int main()
{
    stack<int> s;       //create stack

    s.push(10);         //insert element
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<"Top element: "<<s.top()<<endl;  //access top element

    //Display stack elements
    cout<<"Stack elements (top to bottom): ";
    stack<int> temp=s;     //copy stack for displaying

    while(!temp.empty())
    {
        cout<<temp.top()<<" ";  //display top element
        temp.pop();             //remove top from temporary stack
    }

    //Modify top element
    s.pop();          //remove 50
    s.push(60);       //insert 60

    cout<<"\nAfter modification: "<<s.top();

    //Insert another element
    s.push(70);

    cout<<"\nAfter inserting 70: "<<s.top();

    //Delete top element
    s.pop();

    cout<<"\nAfter deleting top element: "<<s.top();

    //Display final stack
    cout<<"\nFinal stack (top to bottom): ";
    temp=s;

    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }

    return 0;
}
