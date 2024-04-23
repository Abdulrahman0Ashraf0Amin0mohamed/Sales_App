#include "Transaction.h"
#include "Order.h"
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
#include "Order.h"
#include "Person.h"
#include <ctime>
using namespace std;
Transaction::Transaction()
{
    //ctor
}

Transaction::~Transaction()
{
    //dtor
}
Order o;
Payment pa;
void Transaction::Get_Order()
{
    ofstream f99;
    f99.open("Transaction.txt",ios::app);


    cout<<"\n[1] person";
    cout<<"\n[2] company\n";
    cin>>f;
    if(f==1)
    {
        Person p;

        cout<<"\nEnter Id Of customer : ";
        cin>>ID_OF_Transction;
        ifstream f91;
        f91.open("order.txt");
        while(f91>>o.iD_customer_ord>>o.ID>>o.Number_OF_Order>>o.date>>o.ID_Product_Search>>o.Quantity_Order>>o.y)
        {
            if(ID_OF_Transction==o.iD_customer_ord)
            {

                f99<<ID_OF_Transction<<" ";
                ifstream f92;
                f92.open("Customer.txt",ios::app);
                while(f92>>p.Billing_Address>>p.Full_Name>>p.id>>p.phone)
                {
                    if(ID_OF_Transction==p.id)
                    {
                        strcpy(Adds,p.Billing_Address);
                        strcpy(Ntr,p.Full_Name);
                        pho=  p.phone;
                        f99<<Adds<<" "<<Ntr<<" "<<pho<<" ";
                    }
                }

                f99<<o.ID<<" ";
                ifstream f93;
                f93.open("payment.txt");
                while(f93>>o.iD_customer_ord>>o.y)
                {
                    if(ID_OF_Transction==o.iD_customer_ord)
                    {

                        f99<<o.y<<" ";
                    }
                }
                ifstream f94;
                f94.open("pay.txt");
                while(f94>>pa.ID_Customer_Pay>>pa.p>>pa.w)
                {
                    if(ID_OF_Transction==pa.ID_Customer_Pay)
                    {

                        f99<<pa.w<<" ";
                    }


                }
                f99<<endl;
                f99.close();
                cout<<"\n\t\t\tSave Transction Successfuly"<<endl;
            }
            else if(ID_OF_Transction!=o.iD_customer_ord)
            {
                cout<<"\nNo Order"<<endl;
            }
        }
    }
    if(f==2)
    {
        Campany c;;

        cout<<"\nEnter Id Of customer : ";
        cin>>ID_OF_Transction;
        ifstream f91;
        f91.open("order.txt");
        while(f91>>o.iD_customer_ord>>o.ID>>o.Number_OF_Order>>o.date>>o.ID_Product_Search>>o.Quantity_Order>>o.y)
        {
            if(ID_OF_Transction==o.iD_customer_ord)
            {
                f99<<ID_OF_Transction<<" ";
                ifstream f92;
                f92.open("Customer.txt",ios::app);
                while(f92>>c.Location>>c.Campany_name>>c.id>>c.phone)
                {
                    if(ID_OF_Transction==c.id)
                    {
                        strcpy(Adds,c.Location);
                        strcpy(Ntr,c.Campany_name);
                        pho= c.phone;
                        f99<<Adds<<" "<<Ntr<<" "<<pho<<" ";
                    }
                }

                f99<<o.ID<<" ";
                ifstream f93;
                f93.open("payment.txt");
                while(f93>>o.iD_customer_ord>>o.y)
                {
                    if(ID_OF_Transction==o.iD_customer_ord)
                    {
                        f99<<o.y<<" ";
                    }
                }
                ifstream f94;
                f94.open("pay.txt");
                while(f94>>pa.ID_Customer_Pay>>pa.p>>pa.w)
                {
                    if(ID_OF_Transction==pa.ID_Customer_Pay)
                    {
                        f99<<pa.w<<" ";
                    }


                }
                f99<<endl;
                f99.close();
                cout<<"\n\t\t\tSave Transction Successfuly"<<endl;

            }
            else if(ID_OF_Transction!=o.iD_customer_ord)
            {
                cout<<"\nNo Order"<<endl;
            }
        }
    }
}
void Transaction::print()
{
    ifstream f1;
    f1.open("Transaction.txt");
    while(f1>>ID_OF_Transction>>Adds>>Ntr>>pho>>o.ID>>o.y>>pa.w)
    {
        cout<<"\t\t\"THE CHECK\" \n";
        std::time_t t = std::time(0);   // get time now
        std::tm* now = std::localtime(&t);
        cout<<"\nThe Date OF Check : ";
        std::cout << (now->tm_year + 1900) << '-'
                  << (now->tm_mon + 1) << '-'
                  <<  now->tm_mday
                  << "\n";
        cout<<"Address : "<<Adds;
        cout<<"\nName : "<<Ntr;
        cout<<"\nphone : "<<pho;
        cout<<"\nID of order : "<<o.ID;
        cout<<"\nPaid py : "<<pa.w<<endl;
    }
}
void Transaction::delete_tran()
{
    int ID_Edit;
    int flag = 0;
    ofstream f19;
    ifstream f18;

    f18.open("Transaction.txt");
    f19.open("temp.txt");

    cout<<"Enter ID Customer to Delete : ";
    cin>>ID_Edit;

    while(f18>>ID_OF_Transction>>Adds>>Ntr>>pho>>o.ID>>o.y>>pa.w)
    {

        if(ID_OF_Transction!=ID_Edit)
        {

            f19<<ID_OF_Transction<<" "<<Adds<<" "<<Ntr<<" "<<pho<<" "<<o.ID<<" "<<o.y<<" "<<pa.w<<endl;
        }


        else
            flag = 1;
    }


    f18.close();
    f19.close();
    remove("Transaction.txt");
    rename("temp.txt", "Transaction.txt");
    flag==1?
    cout<<"\n\tDeleted...\n":
        cout<<"\n\tDeleted..\n";
}
std::ostream& operator<<(std::ostream& out, Transaction& t)
{
    out<<"\t\t\"THE CHECK\" \n";
    out<<"\nThe Date OF Check : "<<t.Transaction_Date;//.....
    out<<"\n===============";
}
Transaction& operator+=(Order& o, Payment& p);
