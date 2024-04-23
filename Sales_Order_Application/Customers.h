#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include <string>
#include "Customer.h"
#include "Order.h"
using namespace std;

class Customers
{
    public:
        Customers();
        ~Customers();
        void Add_Customer();
        void Delete_Customer();
        void Edit_Customer();
        void print();

    protected:

Customer* customercu;
    private:

};

#endif // CUSTOMERS_H

/*

#include "Person.h"

Person::Person():billingaddress("unknown"), fullname("unknown") {}

Person::~Person() {}

void Person::print() const
{
    cout<<"Billing Address: "<<billingaddress<<endl<<"Full name: "<<fullname<<"\n\n";
    Customer::print();
}

Customer cus;

istream &operator >> (istream & input, Person & per)
{
    cout<<"Billing Address: ";
    put.ignore();
    getline(put,per.billingaddress);

    cout<<"Full name: ";
    getline(put,per.fullname);

    cin>>cus;
    return put;
}

ostream &operator << (ostream & out, Person & per)
{
    out<<"Billing Address: "<<per.billingaddress<<endl<<"Full name: "<<per.fullname<<"\n\n";
    cout<<cus;
    return out;
}
*/
