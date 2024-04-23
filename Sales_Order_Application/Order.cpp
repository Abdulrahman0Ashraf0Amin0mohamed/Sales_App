#include "Order.h"
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
enum Order_Statue {NEW, HOLD, PAID, CANCELED};
Order::Order()
{
    //ctor
}

Order::~Order()
{
    //dtor
}
void Order::Creat_Order()
{

    Product Pr;
    Stock St;
    Person pe;
    Campany ca;
    Customers cus;
    Order_Statue Statue;
    Statue = NEW;

    int a;
    cout<<"\n[1] person\n";
    cout<<"\n[2] Comapny\n";
    cout<<"Enter Your Choice -> ";
    cin>>a;
    if(a==1)
    {

        cout<<"\nEnter The ID OF Customer : ";
        cin>>iD_customer_ord;
        ifstream f91;
        f91.open("Customer.txt");
        while(!f91.eof())
        {


            f91>>pe.Billing_Address>>pe.Full_Name>>pe.id>>pe.phone;
            if(iD_customer_ord==pe.id)
            {
                ofstream f12;
                f12.open("order.txt",ios::app);
                f12<<iD_customer_ord<<" ";
                f12.close();
                Product pr;
                // To Loop For The The Sales User Will Buy ....
                char q;
                cin>>*this;

askUser:
                cout<<"\nEnter The ID OF Product : ";
                cin>>ID_Product_Search;

                ifstream f90;
                f90.open("Product.txt");

                while(!f90.eof())
                {

                    f90>>pr.id>>pr.name>>pr.number>>pr.Quantity>>pr.price>>pr.type;

                    if (ID_Product_Search==pr.id)
                    {
                        cout<<"Enter The Quantity_Order : ";
                        cin>>Quantity_Order;
                        y += pr.price*Quantity_Order;
                        ofstream f12;
                        f12.open("order.txt",ios::app);
                        f12<<ID_Product_Search<<" "<<Quantity_Order<<" ";
                        cout<<"\nIF You Want Another Product Press ( y ) "<<endl;
                        cout<<"\nIF You Don't Want Another Product Press ( n ) "<<endl;
                        cout<<"\nEnter Your Choice ";
                        cin>>q;
                        if(q=='y')
                        {

                            goto askUser;

                        }
                        f12<<y<<endl;
                          ofstream f0;
                        f0.open("payment.txt",ios::app);
                        f0<<iD_customer_ord<<" "<<y<<endl;
                        f0.close();

                        ///To Calling Operator


                        if(q!='y')
                        {

                            break;
                        }
                        f12.close();



                    }


                }


                f90.close();

            }
        }
    }
    if(a==2)
    {

        cout<<"\nEnter The ID OF Company : ";
        cin>>iD_customer_ord;
        ifstream f91;
        f91.open("Customer.txt");
        while(!f91.eof())
        {

            f91>>ca.Location>>ca.Campany_name>>ca.id>>ca.phone;

            if (iD_customer_ord==ca.id)
            {
                ofstream f112;
                f112.open("order.txt",ios::app);
                f112<<iD_customer_ord<<" ";

                f112.close();
                Product pr;
                // To Loop For The The Sales User Will Buy ....
                char q;
                //.......

                cin>>*this;

seif:
                cout<<"\nEnter The ID OF Product : ";
                cin>>ID_Product_Search;

                ifstream f90;
                f90.open("Product.txt");

                while(!f90.eof())
                {

                    f90>>pr.id>>pr.name>>pr.number>>pr.Quantity>>pr.price>>pr.type;
                   // if(ID_Product_Search!=pr.id)
                   // {
                   //     break;
                   // }

                    if (ID_Product_Search==pr.id)
                    {

                        cout<<"Enter The Quantity_Order : ";
                        cin>>Quantity_Order;
                        y += pr.price*Quantity_Order;
                        ofstream f12;
                        f12.open("order.txt",ios::app);
                        f12<<ID_Product_Search<<" "<<Quantity_Order<<" ";

                        cout<<"\nIF You Want Another Product Press ( y ) "<<endl;
                        cout<<"\nIF You Don't Want Another Product Press ( n ) "<<endl;
                        cout<<"\nEnter Your Choice -> ";
                        cin>>q;
                        if(q=='y')
                        {

                            goto seif;

                        }
                        f12<<y<<endl;
                        ofstream f0;
                        f0.open("payment.txt",ios::app);
                        f0<<iD_customer_ord<<" "<<y<<endl;
                        f0.close();

                        if(q!='y')
                        {
                            break;
                        }
                        f12.close();

                    }

                }

                f90.close();

            }
        }
    }

}
void Order::Edit_Order()
{
   int ID_Edit;
        int flag = 0;
        ofstream f19;
        ifstream f18;

        f18.open("order.txt");
        f19.open("temp.txt");

        cout<<"Enter ID to Edit : ";
        cin>>ID_Edit;

        while(f18>>iD_customer_ord>>ID>>Number_OF_Order>>date>>ID_Product_Search>>Quantity_Order>>y)
        {

                if(ID!=ID_Edit)
                {
                    f19<<iD_customer_ord<<" "<<ID<<" "<<Number_OF_Order<<" "<<date<<" "<<ID_Product_Search<<" "<<Quantity_Order<<" "<<y<<endl;
                }


                else
                    flag = 1;
            }


        f18.close();
        f19.close();
        remove("order.txt");
        rename("temp.txt", "order.txt");
        flag==1?
        cout<<"\ntEnter New Data...":
            cout<<"\ntEnter New Data..";
        Creat_Order();
}
void Order::delete_ord()
{
 int ID_Edit;
        int flag = 0;
        ofstream f19;
        ifstream f18;

        f18.open("order.txt");
        f19.open("temp.txt");

        cout<<"Enter ID to Delete : ";
        cin>>ID_Edit;

        while(f18>>iD_customer_ord>>ID>>Number_OF_Order>>date>>ID_Product_Search>>Quantity_Order>>y)
        {

                if(ID!=ID_Edit)
                {
                    f19<<iD_customer_ord<<" "<<ID<<" "<<Number_OF_Order<<" "<<date<<" "<<ID_Product_Search<<" "<<Quantity_Order<<" "<<y<<endl;
                }


                else
                    flag = 1;
            }


        f18.close();
        f19.close();
        remove("order.txt");
        rename("temp.txt", "order.txt");
        flag==1?
        cout<<"\n\tDeleted...":
            cout<<"\n\tDeleted..";
}

void Order::Update_Order()
{
    int q;
cout<<"\n[1] New";
cout<<"\n[2] cancelled";
cout<<"\n[3] pay";
cin>>q;
switch(q){
case 1:
     Creat_Order();
     break;
case 2:
    delete_ord();
    break;
case 3:
  cout<<" 56";
  break;
}

}



std::ostream& operator<<(std::ostream& out, Order& o)
{
    out<<"\t\t\"THE INFORMATION OF ORDER\""<<endl;
    out<<"\nThe ID OF Order : "<<o.ID<<endl;
    out<<"\n==================================\n";
    out<<"\nThe Number OF Order : "<<o.Number_OF_Order<<endl;
    out<<"\n==================================\n";
    out<<"\nThe Date Of The Order : "<<o.date<<endl;
    out<<"\n==================================\n";
    out<<"\nThe Quantity Order is : "<<o.Quantity_Order<<endl;
    return out;
};
std::istream& operator>>(std::istream& in, Order& o )
{
    ofstream f7;
    f7.open("order.txt",ios::app);
    cout<<"\t\t\"ENTER INFORMATION OF ORDER YOU WANT\""<<endl<<endl;

    cout<<"\nEnter ID OF Order -> ";
    in>>o.ID;
    cout<<"\n==================================\n";
    cout<<"\nEnter Number OF Order -> ";
    in>>o.Number_OF_Order;
    cout<<"\n==================================\n";
    cout<<"\nEnter The Date Of The Order -> ";
    in>>o.date;
    cout<<"\n==================================\n";

    f7<<o.ID<<" "<<o.Number_OF_Order<<" "<<o.date<<" ";
    f7.close();

    return in;
}

