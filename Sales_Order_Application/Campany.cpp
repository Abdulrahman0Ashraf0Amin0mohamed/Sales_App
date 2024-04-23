#include "Campany.h"
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
Campany::Campany()
{
    //ctor
}

Campany::~Campany()
{
    //dtor
}
void Campany::readstream(istream&in){
      cout<<"\nEnter The Location OF Company : ";
    in>>Location;
    cout<<"\nEnter The Company Name : ";
    in>>Campany_name;
    cout<<"\t\t\t\"Enter The Information OF Customer\"\n"<<endl;
    cout<<"\nEnter The ID OF Customer is -> ";
    in>>id;
    cout<<"\nEnter The Phone OF Customer is -> ";
    in>>phone;

}

void Campany::print(ostream &out)
{   out<<"\n*********************************************";
    out<<"\nThe Location OF Company is : "<<Location;
    out<<"\nThe Company Name is : "<<Campany_name;
    out<<"\nThe ID OF Customer is : "<<id;
    out<<"\nThe Phone OF Customer is : "<<phone<<endl;




}

void Campany::Write_File_Campany()
{
    char ch;
    ofstream f6;
    f6.open("Customer.txt",ios::app);
    do
    {
       cin>>*this;
        f6<<Location<<" "<<Campany_name<<" "<<id<<" "<<phone<<endl;
        cout<<"Do You Have Next Data ( y / n ) ";
        cout<<"\n Enter Your Choice -> ";
        cin>>ch;

    }
    while(ch=='y');
    cout<<"\n\t\t\t\"The operation was completed successfully\""<<endl;
    f6.flush();
    f6.close();
}
void Campany::Read_File_Campany()
{
    ifstream f11;
    f11.open("Customer.txt");

    while(!f11.eof())
    {
        if(f11>>Location>>Campany_name>>id>>phone)
        {
           cout<<*this;

        }
    }
    f11.close();


}
void Campany::Delete_Company(){


    int id_delete;
    int flag = 0;
    ofstream f4;

    ifstream f5;
    char t;
    f5.open("Customer.txt");
    f4.open("temp.txt");

    cout<<"Enter ID Customer You Want Delete : ";
    cin>>id_delete;
    while(f5>>Location>>Campany_name>>id>>phone)
    {

            if(id!=id_delete)
            {
                f4<<Location<<" "<<Campany_name<<" "<<id<<" "<<phone<<endl;


            }
            else{
                flag = 1;}

    }

    f5.close();
    f4.close();
    remove("Customer.txt");
    rename("temp.txt","Customer.txt");
    flag==1?
    cout<<endl<<endl<<"\tContact Deleted...":
        cout<<endl<<endl<<"\tContact Deleted...";

}
void Campany::Edit_Company(){


    int id_delete;
    int flag = 0;
    ofstream f4;

    ifstream f5;
    char t;
    f5.open("Customer.txt");
    f4.open("temp.txt");

    cout<<"Enter ID Customer You Want Delete : ";
    cin>>id_delete;
    while(f5>>Location>>Campany_name>>id>>phone)
    {

            if(id!=id_delete)
            {
                f4<<Location<<" "<<Campany_name<<" "<<id<<" "<<phone<<endl;

            }
            else{
                flag = 1;}

    }

    f5.close();
    f4.close();
    remove("Customer.txt");
    rename("temp.txt","Customer.txt");
    flag==1?
    cout<<endl<<endl<<"\tEnter New Data...":
        cout<<endl<<endl<<"\tEnter New Data...";

Write_File_Campany();
}
