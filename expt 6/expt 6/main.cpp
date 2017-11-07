//
//  main.cpp
//  expt 6
//
//  Created by Parth Verma on 31/10/17.
//  Copyright © 2017 Parth Verma. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class complex {
    float r_num,i_num;
public:
    complex(){
        r_num=i_num=0;
    }
    complex(float real,float imaginary){
        r_num = real;
        i_num = imaginary;
    }
    complex(const complex &c){
        r_num = c.r_num;
        i_num = c.i_num;
    }
    bool operator==(const complex &c){
        return r_num==c.r_num && i_num==c.i_num;
    }
    bool operator!=(const complex &c){
        return r_num!=c.r_num || i_num!=c.i_num;
    }
    float operator! (){
        return sqrt(r_num*r_num + i_num*i_num);
    }
    complex operator+(const complex &c){
        complex ans(r_num+c.r_num,i_num+c.i_num);
        return ans;
    }
    complex operator-(const complex &c){
        complex ans(r_num-c.r_num,i_num-c.i_num);
        return ans;
    }
    complex operator=(const complex &c){
        r_num = c.r_num;
        i_num = c.i_num;
        return *this;
    }
    complex operator*(const complex &c){
        complex ans;
        ans.r_num = r_num*c.r_num-i_num*c.i_num;
        ans.i_num = r_num*c.i_num + i_num*c.r_num;
        return ans;
    }
    complex operator/(const complex &c){
        float norm =sqrt(c.r_num*c.r_num + c.i_num*c.i_num);
        complex temp(c.r_num/norm,-1*c.i_num/norm);
        return (*this)*temp;
    }
    void * operator new(size_t size){
        void *p = ::new complex();
        return p;
    }
    void operator delete(void *p){
        free(p);
    }
    friend ostream &operator << (ostream &out,const complex &c);
    friend istream &operator >> (istream &in, complex &c);
};


ostream & operator << (ostream &out,const complex &c){
    out<<c.r_num<<' '<<(c.i_num<0?'-':'+')<<" i"<<fabs(c.i_num);
    return out;
}
istream & operator >>(istream &in, complex &c){
    cout<<"Real Part: ";
    in >> c.r_num;
    cout<<"Imaginary Part: ";
    in>>c.i_num;
    return in;
}

int main(int argc, const char * argv[]) {
    complex  *c1,*c2;
    c1 = new complex;
    c2 = new complex;
    cout<<"Input c1:\n";
    cin>>*c1;
    cout<<"\nInput c2:\n";
    cin>>*c2;
    cout<<"\nc1 = "<<*c1<<endl;
    cout<<"\nc2 = "<<*c2<<endl;
    cout<<"\nc1 + c2 = "<<*c1+*c2<<endl;
    cout<<"\nc1 - c2 = "<<*c1-*c2<<endl;
    cout<<"\nc1 * c2 = "<<(*c1)*(*c2)<<endl;
    complex c3 = *c1/(*c2);
    cout<<"\nc1 / c2 = "<<c3<<endl;
    cout<<"\nNormal of c1 and c2: "<<!*c1<<' '<<!*c2<<endl;
    cout<<"\nc1 == c2: "<<((*c1)==(*c2))<<endl;
    cout<<"\nc1 != c2: "<<((*c1)!=(*c2))<<endl;
    delete c1;
    delete c2;
    return 0;
}
