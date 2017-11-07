//
//  main.cpp
//  exp2
//
//  Created by Parth Verma on 30/10/17.
//  Copyright © 2017 Parth Verma. All rights reserved.
//

#include <iostream>

using namespace std;

int* neg(int *a){
    *a *=-1;
    return a;
}
int neg(int &a){
    a*=-1;
    return a;
}

int main(int argc, const char * argv[]) {
    int *a,n;
    a = new int();
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Negative of "<<n<<" is "<<neg(n)<<'.'<<endl;
    cout<<"Enter a number: ";
    cin>>*a;
    cout<<"Negative of "<<*a<<" is "<<*neg(a)<<'.'<<endl;
}
