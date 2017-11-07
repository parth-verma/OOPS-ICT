//
//  main.cpp
//  expt 12
//
//  Created by Parth Verma on 31/10/17.
//  Copyright © 2017 Parth Verma. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
int base = 10;
ostream & set_base(ostream & out, int base){
    if (base == 2 || base == 8 || base == 10 || base == 16){
        ::base = base;
    }
    return out;
}
class bit_stream{
    int base;
    long long n;
    string to_bin(){
        string a="";
        string base[2] = {"0","1"};
        long q=n;
        while(q!=0){
            a= base[q%2] +a;
            q/=2;
        }
        return a;
    }
    string to_oct(){
        string a="";
        string base[8] = {"0","1","2","3","4","5","6","7"};
        long long q=n;
        while(q!=0){
            a= base[q%8] +a;
            q/=8;
        }
        return a;
    }
    string to_hex(){
        string a="";
        string base[16] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
        long long q=n;
        while(q!=0){
            a= base[q%16] +a;
            q/=16;
        }
        return a;
    }
public:
    explicit bit_stream(long long &number,int b){
        n=number;
        base=b;
    }
    ostream& convert(ostream&out) {
        if (base==2){
            
            out<< to_bin();
        }
        else if (base==8)
            out<< to_oct();
        else if (base==16)
            out<< to_hex();
        else
            out<< to_string(n);
        return out;
    }
    std::ostream &operator()(std::ostream& out);
};


ostream & operator<<(ostream & out,bit_stream a){
    return a.convert(out);
}




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout<<"Enter a decimal number: ";
    long long n;
    cin>>n;
    
    cout<<"\nBinary: "<<bit_stream(n,2)<<endl;
    cout<<"\nOctal: "<<bit_stream(n,8)<<endl;
    cout<<"\nHexadecimal: "<<bit_stream(n,16)<<endl;
    return 0;
}
