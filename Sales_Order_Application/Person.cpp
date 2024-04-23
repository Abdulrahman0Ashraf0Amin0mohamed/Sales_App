#include "Person.h"
#include <iostream>
#include <string>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<fstream>
#include<unistd.h>

using namespace std;
Person::Person()
{
    //ctor
}

Person::~Person()
{
    //dtor
}
void Person::readstream(istream &in)
{

    cout<<"\nEnter The Billing Address : ";
    in>>Billing_Address;
    cout<<"\nEnter The Full Name OF Customer : ";
    in>>Full_Name;
    cout<<"\t\t\t\"Enter The Information OF Customer\"\n"<<endl;
    cout<<"\nEnter The ID OF Customer is -> ";
    in>>id;
    cout<<"\nEnter The Phone OF Customer is -> ";
    in>>phone;



}
void Person::print(ostream &out)
{
cout<<"\n==================================\n";
    out<<"\nThe Billing Address is : "<<Billing_Address;
    out<<"\nThe Full Name OF Customer is : "<<Full_Name;
    out<<"\nThe ID OF Customer is : "<<id;
    out<<"\nThe Phone OF Customer is : "<<phone<<endl;



}
void Person::Write_File_Person()
{

    char o;
    ofstream f7;
    f7.open("Customer.txt",ios::app);
    do
    {
        cin>>*this;
        f7<<Billing_Address<<" "<<Full_Name<<" "<<id<<" "<<phone<<endl;
        cout<<"Do You Have Next Data ( y / n ) ";
        cout<<"\n Enter Your Choice -> ";
        cin>>o;

    }
    while(o=='y');
    cout<<"\n\t\t\t\"The operation was completed successfully\""<<endl;
    f7.flush();
    f7.close();
}
void Person::Read_File_Person()
{
    ifstream f12;
    f12.open("Customer.txt");
   while(!f12.eof())
    {
        if(f12>>Billing_Address>>Full_Name>>id>>phone)
        {
            cout<<*this;


        }
    }
    f12.close();


}
void Person::Delete_person()
{

    int id_delete;

    int flag = 0;
    ofstream f4;

    ifstream f5;
    char t;
    f5.open("Customer.txt");
    f4.open("temp.txt");

    cout<<"Enter ID Customer You Want Delete : ";
    cin>>id_delete;

    //>>Pe.Billing_Address>>Pe.Full_Name>>Cu.id>>Cu.phone;
    //cout<< Cu.id<<endl;;
    while(f5>>Billing_Address>>Full_Name>>id>>phone)
    {


        if(id!=id_delete)
        {
            f4<<Billing_Address<<" "<<Full_Name<<" "<<id<<" "<<phone<<endl;


        }
        else
        {
            flag = 1;
        }

    }

    f5.close();
    f4.close();
    remove("Customer.txt");
    rename("temp.txt","Customer.txt");
    flag==1?
    cout<<endl<<endl<<"\tContact Deleted...":
        cout<<endl<<endl<<"\tContact Deleted...";
}
void Person::Edit_person()
{

    int id_delete;
    int flag = 0;
    ofstream f4;
    ifstream f5;
    char t;
    f5.open("Customer.txt");
    f4.open("temp.txt");
    cout<<"Enter ID Customer You Want Edit : ";
    cin>>id_delete;
    //>>Pe.Billing_Address>>Pe.Full_Name>>Cu.id>>Cu.phone;
    //cout<< Cu.id<<endl;;
    while(f5>>Billing_Address>>Full_Name>>id>>phone)
    {


        if(id!=id_delete)
        {
            f4<<Billing_Address<<" "<<Full_Name<<" "<<id<<" "<<phone<<endl;


        }
        else
        {
            flag = 1;
        }

    }

    f5.close();
    f4.close();
    remove("Customer.txt");
    rename("temp.txt","Customer.txt");
     flag==1?
    cout<<endl<<endl<<"\tEnter New Data...":
        cout<<endl<<endl<<"\tEnter New Data..";

      Write_File_Person();



}

