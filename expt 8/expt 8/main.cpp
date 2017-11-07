//
//  main.cpp
//  expt 8
//
//  Created by Parth Verma on 01/11/17.
//  Copyright © 2017 Parth Verma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class departments  {
protected:
    string name,head_name;
    int num_employees;
public:
    virtual void get_data()=0;
    virtual void put_data()=0;
};

class examination:public departments{
    
public:
    examination(){
        name = "Examination";
        num_employees = 0;
        head_name = "";
    }
    examination(int no_employee,string head_name){
        name = "Examination";
        num_employees = no_employee;
        head_name = head_name;
    }
    void get_data(){
        cout<<"Enter the name of head: ";
        cin>>head_name;
        cout<<"Enter no. of employees: ";
        cin>>num_employees;
    }
    void put_data(){
        ;
        
    }
};

class library:public departments{

public:
    library(){
        name = "Library";
        num_employees = 0;
        head_name = "";
    }
    library(int no_employee,string head_name){
        name = "Library";
        num_employees = no_employee;
        head_name = head_name;
    }
    void get_data(){
        cout<<"Enter the name of head: ";
        cin>>head_name;
        cout<<"Enter no. of employees: ";
        cin>>num_employees;
    }
    void put_data(){
        ;
    }
};

class accounts:public departments{
public:
    accounts(){
        name = "Accounts";
        num_employees = 0;
        head_name = "";
    }
    accounts(int no_employee,string head_name){
        name = "Accounts";
        num_employees = no_employee;
        head_name = head_name;
    }
    void get_data(){
        cout<<"Enter the name of head: ";
        cin>>head_name;
        cout<<"Enter no. of employees: ";
        cin>>num_employees;
    }
    void put_data(){
        cout<<"Department: "<<name<<endl;
        cout<<"Head Name: "<<head_name<<endl;
        cout<<"No. of Employees: "<<num_employees<<endl;
    }
};

class university{
    vector<departments*> a;
    string name;
public:
    university(string name){
        this->name=name;
    }
    university(string name,departments *list,int size){
        this->name=name;
        for(int i=0;i<size;i++){
            a.push_back((list+i));
        }
    }
    void put_data(){
        cout<<"Name: "<<name<<endl;
        cout<<"Number of departments: "<<a.size()<<endl;
        cout<<"Departments:\n";
        for (int i=0;i<a.size();i++){
            a[i]->put_data();
            cout<<endl;
        }
    }
    void add_department(){
        cout<<"Choose department type:\n1)Accounts\n2)Library\n3)Examination\nEnter your choice: ";
        int ch;
        cin>>ch;
        departments * n;
        if (ch==1){
            accounts *t = new accounts();
            n=t;
        }
        else if (ch==2){
            library *t =  new library();
            n=t;
            
        }
        else{
            examination *t = new examination();
            n=t;
            
        }
        n->get_data();
        a.push_back(n);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<"Enter name of university: ";
    string * name = new string;
    getline(cin, *name);
    university uni(*name);
    delete name;
    int ch = 0;
    while(ch !=3){
        cout<<"\nChoose Operation:\n1) Add department\n2) Display information\n3) Exit\nEnter your choice:";
        cin>>ch;
        cout<<"\n\n";
        switch (ch) {
            case 1:
                uni.add_department();
                break;
            case 2:
                uni.put_data();
                break;
            case 3:
                break;
            default:
                cout<<"\nInvalid option. Retry"<<endl;
        }
    }
    return 0;
          
}
