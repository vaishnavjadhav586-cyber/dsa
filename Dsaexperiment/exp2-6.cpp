#include<iostream> //map
#include<map>
using namespace std;

int main()
{
    map<int,int> m={{101,90},{102,85},{103,95}};
    //create map (Roll No. -> Marks)

    //Display map elements
    cout<<"Map elements:"<<endl;
    for(auto x:m)
    {
        cout<<x.first<<" -> "<<x.second<<endl;
        //first = key, second = value
    }

    //Access value using key
    cout<<"Marks of Roll No. 101: "<<m[101]<<endl;

    //Modify value
    m[102]=88;       //change marks of Roll No. 102

    cout<<"\nAfter modification:"<<endl;
    for(auto x:m)
    {
        cout<<x.first<<" -> "<<x.second<<endl;
    }

    //Insert new element
    m[104]=80;       //insert Roll No. 104 with marks 80

    cout<<"\nAfter insertion:"<<endl;
    for(auto x:m)
    {
        cout<<x.first<<" -> "<<x.second<<endl;
    }

    //Delete element
    m.erase(103);    //delete key 103

    cout<<"\nAfter deleting Roll No. 103:"<<endl;
    for(auto x:m)
    {
        cout<<x.first<<" -> "<<x.second<<endl;
    }

    //Search a key
    if(m.find(101)!=m.end())
    {
        cout<<"\nRoll No. 101 is present";
    }
    else
    {
        cout<<"\nRoll No. 101 is not present";
    }

    return 0;
}

