//
//  main.cpp
//  expt4
//
//  Created by Parth Verma on 30/10/17.
//  Copyright © 2017 Parth Verma. All rights reserved.
//

#include <iostream>

using namespace std;
class Student {
    string name, dept_name;
    int rollnum,year,total_subjects;
    float percentage;
    
public:
    static int num_of_students;
    void getdata(){
        cout<<"Enter Name: ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, this->name);
        cout<<"Enter Roll No.: ";
        cin>>this->rollnum;
        cout<<"Enter Year: ";
        cin>>this->year;
        cout<<"Enter Department Name: ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, this->dept_name);
        cout<<"Enter Total No. of Subjects: ";
        cin>>this->total_subjects;
        cout<<"Enter Percentage: ";
        cin>>this->percentage;
        num_of_students++;
    }
    void putdata(){
        cout<<"Name: "<<this->name<<endl;
        cout<<"Roll No.: "<<this->rollnum<<endl;
        cout<<"Year: "<<this->year<<endl;
        cout<<"Department Name: "<<this->dept_name<<endl;
        cout<<"Total No. of Subjects: "<<this->total_subjects<<endl;
        cout<<"Percentage: "<<this->percentage<<endl;
    }
    static int getTotalStudents(){
        return num_of_students;
    }
    static void update(Student s){
        s.getdata();
    }
    friend void display_year_info(Student s);
    friend class University_record;
};

class University_record {
    int year;

    string dept_name;
    
public:
    static int count_dept;
    void getdata(){
        cout<<"Enter Dept. Name: ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, this->dept_name);
        cout<<"Enter Year: ";
        cin>>this->year;
        count_dept++;
    }
    void putdata(){
        cout<<"Dept. Name: "<<this->dept_name<<endl;
        cout<<"Year: "<<this->year<<endl;
    }
    void displayinfo(Student s){
        cout<<"Name: "<<s.name<<endl;
        cout<<"Roll No.: "<<s.rollnum<<endl;
        cout<<"Year: "<<s.year<<endl;
        cout<<"Department Name: "<<s.dept_name<<endl;
        cout<<"Total No. of Subjects: "<<s.total_subjects<<endl;
        cout<<"Percentage: "<<s.percentage<<endl;
    }
    void updateinfo(Student s){
        s.getdata();
    }
};

int University_record::count_dept=0;

int Student::num_of_students = 0;

void display_year_info(Student s){
    cout<<"Name: "<<s.name<<endl;
    cout<<"Year: "<<s.year<<endl;
}


int main(int argc, const char * argv[]) {
    University_record record;
    Student students[10];
    int n,m;
    cout<<"Enter the number of students: ";
    cin>>n;
    for (int i = 0; i<n; i++) {
        students[i].getdata();
    }
    cout<<"\nEnter the data for the department:\n";
    record.getdata();
    cout<<"Number of students: "<<Student().num_of_students<<endl;
    cout<<"Number of departments: "<<record.count_dept<<endl;
    cout<<"\nEnter the index of the student that you wish to alter: ";
    cin>>m;
    if (m>=n){
        cout<<"Invalid Index. Exiting\n";
        return 1;
    }
    record.updateinfo(students[m]);
    cout<<"\n\nStudent Records:\n";
    for (int i=0; i<n; i++) {
        if (i%2==0)
            record.displayinfo(students[i]);
        else
            students[i].putdata();
        cout<<endl;
    }
    cout<<"\nUniversity Record:\n";
    record.putdata();
    return 0;
}
