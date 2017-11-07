//
//  main.cpp
//  expt 9
//
//  Created by Parth Verma on 06/11/17.
//  Copyright © 2017 Parth Verma. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
class point{
protected:
public:
    virtual int area(){
        return 0;
    }
    virtual int perimeter(){
        return 0;
    }
    virtual int volume(){
        return 0;
    }
    void get_data(){
        cout<<"Perimeter: "<<perimeter()<<endl;
        cout<<"Area: "<<area()<<endl;
        cout<<"Volume: "<<volume()<<endl;
    }
    
};

class line:public point{
protected:
    int length;
public:
    line():point(){
        length = 0;
    }
    line(int length){
        this->length = length;
    }
    int perimeter() {
        return length;
    }
    
};

class circle:public point{
protected:
    int radius;
public:
    circle():point(){
        radius =0;
    }
    circle(int r){
        radius=r;
    }
    int perimeter(){
        return 2*M_PI*radius;
    }
    int area(){
        return M_PI*radius*radius;
    }
};

class cylinder:public circle{
protected:
    int height;
public:
    cylinder():circle(){
        height = 0;
    }
    cylinder(int height, int radius):circle(radius){
        this->height=height;
    }
    int area(){
        return 2*circle::area() + 2*M_PI*radius*height;
    }
    int volume(){
        return circle::area()*height;
    }
};

class square:public line{
public:
    square():line(){
        ;
    }
    square(int side):line(side){
        ;
    }
    int perimeter(){
        return 4*line::perimeter();
    }
    int area(){
        return length*length;
    }
};

class rectangle:public line{
protected:
    int breadth;
public:
    rectangle():line(){
        ;
    }
    rectangle(int length,int breadth):line(length){
        this->breadth=breadth;
    }
    int perimeter(){
        return 2*(line::perimeter()+breadth);
    }
    int area(){
        return line::perimeter()*breadth;
    }
};

class cube:public square{
public:
    cube():square(){
        ;
    }
    cube(int side):square(side){
        ;
    }
    int area(){
        return 6*square::area();
    }
    int volume(){
        return square::area()*length;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
