#include "Customer.h"
#include <iostream>
#include <string>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<fstream>
#include<unistd.h>
#include "Person.h"
#include "Campany.h"
using namespace std;
Customer::Customer()
{
    //ctor
}

Customer::~Customer()
{
    //dtor
}
void Customer::print(ostream &out)
{
   out<<"\nThe ID OF Customer is : "<<id<<endl;
    out<<"\n==================================\n";
    out<<"\nThe Phone OF Customer is : "<<phone<<endl;
    out<<"\n==================================\n";
}

std::ostream& operator<<(std::ostream& out,  Customer& c)
{
    c.print(out);
    return out;
   /* out<<"\nThe ID OF Customer is : "<<c.id<<endl;
    out<<"\n==================================\n";
    out<<"\nThe Phone OF Customer is : "<<c.phone<<endl;
    out<<"\n==================================\n";
*/
}
std::istream& operator>>(std::istream& in,  Customer& c)
{
c.readstream(in);
 return in;

}
