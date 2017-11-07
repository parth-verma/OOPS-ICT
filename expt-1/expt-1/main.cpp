//
//  main.cpp
//  expt-1
//
//  Created by Parth Verma on 09/10/17.
//  Copyright © 2017 Parth Verma. All rights reserved.
//

#include <iostream>

using namespace std;
class Student{
    string name,address;
    int age;
public:
    void getdata(){
        cout<<"Enter name: ";
        getline(cin,name,'\n');
        cout<<"Enter age: ";
        cin>>age;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Enter address: ";
        getline(cin, address,'\n');
    }
    void putdata(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Address: "<<address<<endl<<endl;
    }
    
};

int main(int argc, const char * argv[]) {
    int n;
    cout<<"Enter the number of students: ";
    cin>>n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    Student students[n];
    Student* pointer = students;
    void (Student::*getdataptr)() = &Student::getdata;
    void (Student::*putdataptr)() = &Student::putdata;
    for (int i=0; i<n; i++) {
        (students[i].*getdataptr)();
    }
    cout<<"\nThe students are:\n";
    for(int i=0;i<n;i++){
        ((pointer+i)->*putdataptr)();
    }
}
