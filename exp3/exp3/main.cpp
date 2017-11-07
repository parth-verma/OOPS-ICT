//
//  main.cpp
//  exp3
//
//  Created by Parth Verma on 30/10/17.
//  Copyright © 2017 Parth Verma. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
class Time{
private:
    int hours,minutes,seconds;
    const string meridian[2] =  {"AM","PM"};
    void add_hours(int hours){
        this->hours=(this->hours+hours)%24;
    }
    void add_minutes(int minutes){
        this->add_hours((this->minutes+minutes)/60);
        this->minutes=(this->minutes+minutes)%60;
    }
    void add_seconds(int seconds){
        this->add_minutes((this->seconds+seconds)/60);
        this->seconds=(this->seconds+seconds)%60;
    }
public:
    bool is12hour;
    Time(){
        hours=0;
        minutes=0;
        seconds=0;
        is12hour = false;
    }
    void gettime(){
        cout<<"Choose Time-Format:\n1)12-Hour\n2)24-Hour\nEnter your choice: ";
        int ch;
        cin>>ch;
        cout<<"Enter hours: ";
        cin>>hours;
        cout<<"Enter minutes: ";
        cin>>minutes;
        cout<<"Enter seconds: ";
        cin>>seconds;
        if (ch == 1) {
            cout<<"AM/PM?";
            string choice;
            cin>>choice;
            if (choice=="PM"){
                hours=(12+hours)%24;
            }
        }
    }
    void display(){
        cout<<"Time-> ";
        if (is12hour == true)
            cout<<setfill('0')<<setw(2)<<(hours-1)%12+1;
        else
            cout<<setfill('0')<<setw(2)<<hours;
        cout<<':'<<setfill('0')<<setw(2)<<minutes<<':'<<setfill('0')<<setw(2)<<seconds<<' ';
        if (is12hour == true)
            cout<<meridian[hours/12];
        cout<<endl;
    }
    Time& addtime_byvalue(Time time){
        add_hours(time.hours);
        add_minutes(time.minutes);
        add_seconds(time.seconds);
        return *this;
    }
    Time& addtime_byreference(Time &time){
        add_hours(time.hours);
        add_minutes(time.minutes);
        add_seconds(time.seconds);
        return *this;
    }
    Time& addtime_bypointer(Time *time){
        add_hours(time->hours);
        add_minutes(time->minutes);
        add_seconds(time->seconds);
        return *this;
    }
};

int main(int argc, const char * argv[]) {
    Time t1,*t2,t3;
    t2 = new Time();
    t1.gettime();
    t2->gettime();
    t3.gettime();
    t1.is12hour = true;
    t1.addtime_byvalue(t3).display();
    t1.addtime_bypointer(t2).display();
    t2->addtime_byreference(t3).display();
    delete t2;
    return 0;
}
