#include <iostream>
#include "Product.h"
#include <fstream>
using namespace std;

Product::Product()
{
}
Product::Product(int id,int type,string number,string name,double price,int Quantity)
{

    this->id = id;
    this->name = name;
    this->number = number;
    this->price = price;
    this->type = type;
    this->Quantity=Quantity;
}

Product::~Product()
{

}
void Product::Delete_Product()
{
     int id_delete;
    Product pr;
    int flag = 0;
    ofstream f4;

    ifstream f5;
    char t;
    f5.open("Product.txt");
    f4.open("temp.txt");

    cout<<"Enter ID Stock You Want Delete : ";
    cin>>id_delete;

    //>>Pe.Billing_Address>>Pe.Full_Name>>Cu.id>>Cu.phone;
    //cout<< Cu.id<<endl;;

    while(f5>> id>>name>>number>>Quantity>>price>>type)
    {

        if(id!=id_delete)
        {
            f4<<id<<" "<<name<<" "<<number<<" "<<Quantity<<" "<<price<<" "<<type<<endl;

        }
        else
        {
            flag = 1;
        }

    }

    f5.close();
    f4.close();
    remove("Product.txt");
    rename("temp.txt","Product.txt");
    flag==1?
    cout<<endl<<endl<<"\tDelete..":
        cout<<endl<<endl<<"\tDelete..";
}

void Product::Add_product()
{
    cin>>*this;
}

istream&operator >>(istream &input,Product &p)
{

    ofstream f2;


        f2.open("Product.txt",ios::app);

        cout<<"Enter product id : ";
        input >> p.id;
        cout<<endl;
        cout<<"Enter product name : ";
        input >> p.name;
        cout<<endl;
        cout<<"Enter product number : ";
        input >> p.number;
        cout<<endl;
        cout<<"Enter Quantity : ";
        input>>p.Quantity;
        cout<<endl;
        cout<<"Enter product price : ";
        input >> p.price;
        cout<<endl;
        cout<<"Enter product type : ";
        input >> p.type;
        cout<<endl;

        f2<<p.id<<" "<<p.name<<" "<<p.number<<" "<<p.Quantity<<" "<<p.price<<" "<<p.type<<endl;



    f2.close();
    return input;
}

void Product::update()
{
    int id_delete;
    Product pr;
    int flag = 0;
    ofstream f4;

    ifstream f5;
    char t;
    f5.open("Product.txt");
    f4.open("temp.txt");

    cout<<"Enter ID Stock You Want Edit : ";
    cin>>id_delete;

    //>>Pe.Billing_Address>>Pe.Full_Name>>Cu.id>>Cu.phone;
    //cout<< Cu.id<<endl;;

    while(f5>> id>>name>>number>>Quantity>>price>>type)
    {


        if(id!=id_delete)
        {
            f4<<id<<" "<<name<<" "<<number<<" "<<Quantity<<" "<<price<<" "<<type<<endl;

        }
        else
        {
            flag = 1;
        }

    }

    f5.close();
    f4.close();
    remove("Product.txt");
    rename("temp.txt","Product.txt");
    flag==1?
    cout<<endl<<endl<<"\tEnter New Data..":
        cout<<endl<<endl<<"\tEnter New Data..";
    cin>>*this;

}
ostream&operator <<(ostream &output, Product &p)

{
    ifstream f16;
    f16.open("Product.txt");

while(f16>>p.id>>p.name>>p.number>>p.Quantity>>p.price>>p.type){
    output << "Product id : " << p.id << endl << "Product Name : " << p.name << endl << "Product Number : " << p.number<<endl<<"Quantity :" <<p.Quantity<<endl << "Product Price : " << p.price << endl << "Product Type : " << p.type << endl;
    output<<"\n*************************\n";
}
    return output;
f16.close();

}
