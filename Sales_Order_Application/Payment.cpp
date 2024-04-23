#include "Payment.h"
#include <iostream>
#include <string>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<fstream>
#include<unistd.h>
#include "Credit.h"
#include "Cash.h"
#include "Check.h"


using namespace std;
Credit Cr;
Cash Ca;
Check Ch;
Payment::Payment()
{
    //ctor
}

Payment::~Payment()
{
    //dtor
}
void Payment::pay()
{


    Order o;
    cout<<"\nEnter Your ID Customer : ";
    cin>>ID_Customer_Pay;
    ifstream f8;
    f8.open("payment.txt",ios::app);
    while(f8>>o.iD_customer_ord>>o.y)
    {
        if(ID_Customer_Pay==o.iD_customer_ord)
        {
            //f8.seekg(o.y,ios_base::end);
            cout<<"\nThe price Your order : "<<o.y<<endl;
            int a;
            cout<<"\t\t\n Choice The Way "<<endl;
            cout<<"\n[1] credit"<<endl;
            cout<<"\n[2] cash"<<endl;
            cout<<"\n[3] check"<<endl;
            cin>>a;
            if(a==1)
            {
                p="paid";
                w="credit";
                ofstream fi("pay.txt",ios::app);
                Cr.pay();
                fi<< ID_Customer_Pay<<" "<<p<<" "<<w<<endl;
                fi.close();
            }
            if(a==2)
            {
                p="paid";
                w="cash";
                ofstream fi("pay.txt",ios::app);
                Ca.pay();
                fi<< ID_Customer_Pay<<" "<<p<<" "<< w<<endl;
                fi.close();
            }
            if(a==3)
            {
                p="paid";
                w="check";
                ofstream fi("pay.txt",ios::app);
                Ch.pay();
                fi<< ID_Customer_Pay<<" "<<p<<" "<<w<<endl;
                fi.close();
                break;
            }
        }
    }
}

