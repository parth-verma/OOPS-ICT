//
//  main.cpp
//  expt-5
//
//  Created by Parth Verma on 31/10/17.
//  Copyright © 2017 Parth Verma. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

class circle{
    float *radius,*area;
public:
    circle(){
        this->radius = new float;
        this->area = NULL;
        float a = 0;
        this->set_radius(&a);
    }
    circle(float *radius){
        this->radius = new float;
        this->area = NULL;
        this->set_radius(radius);
    }
    void set_radius(float *radius){
        *(this->radius) = *radius;
    }
    float get_radius(){
        return *(this->radius);
    }
    void set_area(float *area){
        if (this->area == NULL)
            this->area = new float;
        *(this->area)=*area;
    }
    float* get_area(){
        return this->area;
    }
    ~circle(){
        if (area != NULL)
            delete this->area;
        delete this->radius;
    }
    friend ostream & operator << (ostream &out,  circle &c);
    friend istream & operator >> (istream &in,  circle &c);
};

class square{
    float *side,*area;
public:
    square(){
        this->area = NULL;
        this->side = new float;
        float a =0;
        this->set_side(&a);
    }
    square(float *side){
        this->area = NULL;
        this->set_side(side);
    }
    void set_side(float *side){
        *(this->side)=*(side);
    }
    float get_side(){
        return *(this->side);
    }
    void set_area(float *area){
        if (this->area == NULL)
            this->area = new float;
        *(this->area)=*area;
    }
    float* get_area(){
        return this->area;
    }
    ~square(){
        if(this->area!=NULL)
            delete this->area;
        delete this->side;
    }
    friend ostream & operator << (ostream &out,  square &c);
    friend istream & operator >> (istream &in,  square &c);
};

class rectangle{
    float *l,*b,*area;
public:
    rectangle(){
        float a = 0;
        this->l = new float;
        this->b = new float;
        this->set_sides(&a, &a);
    }
    rectangle(float *l,float *b){
        this->set_sides(l, b);
    }
    void set_sides(float *length,float *breadth){
        *(this->l) = *length;
        *(this->b) = *breadth;
    }
    void set_area(float *area){
        if (this->area == NULL)
            this->area = new float;
        *(this->area)=*area;
    }
    float* get_area(){
        return this->area;
    }
    float get_length(){
        return *(this->l);
    }
    float get_breadth(){
        return *(this->b);
    }
    ~rectangle(){
        if (this->area != NULL)
            delete this->area;
        delete this->l;
        delete this->b;
    }
    
    friend ostream & operator << (ostream &out,  rectangle &c);
    friend istream & operator >> (istream &in,  rectangle &c);
};

class triangle {
    float *a,*b,*c,*area;
    
public:
    triangle(){
        this->a = new float;
        this->b = new float;
        this->c = new float;
        this->area = NULL;
        float a = 0;
        set_sides(&a, &a, &a);
    }
    triangle(float *a,float *b,float *c){
        this->a = new float;
        this->b = new float;
        this->c = new float;
        this->area = NULL;
        set_sides(a, b, c);
    }
    void set_sides(float *a,float *b,float *c){
        *this->a = *a;
        *this->b = *b;
        *this->c = *c;
    }
    void set_area(float *area){
        if (this->area == NULL)
            this->area = new float;
        *(this->area)=*area;
    }
    float* get_area(){
        return this->area;
    }
    float get_a(){
        return *this->a;
    }
    float get_b(){
        return *this->b;
    }
    float get_c(){
        return *this->c;
    }
    ~triangle(){
        if (this->area!=NULL)
            delete this->area;
        delete this->a;
        delete this->b;
        delete this->c;
    }
    
    friend ostream & operator << (ostream &out,  triangle &c);
    friend istream & operator >> (istream &in,  triangle &c);
};
float area(circle *a){
    if (a->get_area() == NULL){
        float arr = M_PI*pow(a->get_radius(), 2);
        a->set_area(&arr);}
    return *a->get_area();
}

float area(square *a){
    if (a->get_area() == NULL){
        float arr =pow(a->get_side(),2);
        a->set_area(&arr);}
    return *a->get_area();
}

float area(rectangle *a){
    if (a->get_area() == NULL){
        float ar = a->get_length()*a->get_breadth();
        a->set_area(&ar);}
    return *a->get_area();
}

float area(triangle *a){
    if (a->get_area() == NULL){
        float s = (a->get_a()+a->get_b()+a->get_c())/2;
        float ar = sqrt(s*(s-a->get_a())*(s-a->get_b())*(s-a->get_c()));
        a->set_area(&ar);}
    return *a->get_area();
}


ostream & operator << (ostream &out,  circle &c)
{
    out << "Radius: "<<*c.radius<<endl;
    out << "Area: "<< area(&c) << endl;
    return out;
}

istream & operator >> (istream &in,  circle &c)
{
    cout << "Enter Radius: ";
    in >> *c.radius;
    return in;
}

ostream & operator << (ostream &out,  square &c)
{
    out << "Side: "<<*c.side<<endl;
    out << "Area: "<< area(&c) << endl;
    return out;
}

istream & operator >> (istream &in,  square &c)
{
    cout << "Enter Side: ";
    in >> *c.side;
    return in;
}
ostream & operator << (ostream &out,  rectangle &c)
{
    out << "Length: "<<*c.l<<endl;
    out << "Breadth: "<<*c.b<<endl;
    out << "Area: "<< area(&c) << endl;
    return out;
}

istream & operator >> (istream &in,  rectangle &c)
{
    cout << "Enter Length: ";
    in >> *c.l;
    cout<<"Enter Breadth: ";
    in>>*c.b;
    return in;
}
ostream & operator << (ostream &out,  triangle &c)
{
    out << "Side A: "<<*c.a<<endl;
    out << "Side B: "<<*c.b<<endl;
    out << "Side C: "<<*c.c<<endl;
    out << "Area: "<< area(&c) << endl;
    return out;
}

istream & operator >> (istream &in,  triangle &c)
{
    cout << "Enter Side A: ";
    in >> *c.a;
    cout<<"Enter Side B: ";
    in>>*c.b;
    cout<<"Enter Side C: ";
    in>>*c.c;
    return in;
}

int main(int argc, const char * argv[]) {
    rectangle *r;
    circle *c;
    triangle *t;
    square *s;
    r = new rectangle;
    c = new circle;
    t = new triangle;
    s = new square;
    cout<<"Enter data for the circle:\n";
    cin>>*c;
    cout<<"\n\nEnter data for the square:\n";
    cin>>*s;
    cout<<"\n\nEnter data for the rectangle:\n";
    cin>>*r;
    cout<<"\n\nEnter data for the triangle:\n";
    cin>>*t;
    cout<<"\n\n\nCircle:\n"<<*c;
    cout<<"\n\nSquare:\n"<<*s;
    cout<<"\n\nRectangle:\n"<<*r;
    cout<<"\n\nTriangle:\n"<<*t;
    delete r;
    delete c;
    delete t;
    delete s;
    return 0;
}
