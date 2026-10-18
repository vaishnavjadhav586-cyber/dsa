#include<iostream>
#include<string>

using namespace std;

class Student{
    private:
    double salary;

    public: 

    string name;
    string department;


    void changedepart(string dr){

        department = dr;
    }

    void display(){

        cout<<department;
    }


};


    int main(){

        Student s1;

        s1.name = "Vaishnav";
        s1.department = "Electrical";

        //s1.changedepart("ENTC");
         s1.department = "ENTC";

        cout<<s1.name<<endl;
        s1.display();
    }

    



