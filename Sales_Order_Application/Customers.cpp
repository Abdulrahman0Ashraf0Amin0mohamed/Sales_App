#include "Customers.h"
#include <string>
#include <iostream>
#include "Customer.h"
#include "Person.h"
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
#include "Order.h"
using namespace std;
Customers::Customers()
{
    //ctor
}

Customers::~Customers()
{
    //dtor
}
void Customers::Add_Customer()
{   Campany ca;
    Person pe;

    int o;
    cout<<"[1] person\n";
    cout<<"[2] company\n";
    cin>>o;
    if(o==1){
    //customercu = new Person;
    //customercu->Write_File_Person();
        pe.Write_File_Person();

    }
    if(o==2)
    {
     ca.Write_File_Campany();
    }

}

void Customers::Delete_Customer()
{
     Campany ca;
    Person pe;
  int q;
  cout<<"\n[1] person";
  cout<<"\n[2] Company";
  cin>>q;
  if(q==1){
       pe.Delete_person();
  }


  if(q==2){
ca.Delete_Company();

  }
}
void Customers::Edit_Customer()
{

     Campany ca;
    Person pe;
  int q;
  cout<<"\n[1] person";
  cout<<"\n[2] Company";
  cin>>q;
  if(q==1){
        pe.Edit_person();
  }
  if(q==2){
    ca.Edit_Company();
  }
}


void Customers::print()
{
     Campany ca;
    Person pe;

    pe.Read_File_Person();
    ca.Read_File_Campany();

}
