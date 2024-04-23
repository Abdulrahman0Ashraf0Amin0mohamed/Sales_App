#include "iostream"
#include "cstring"
#include "Stock.h"
#include <fstream>



using namespace std ;

Stock::Stock()
{

}
Stock::Stock(int id,int quantity)
{
    counter = 0;
    this->product_id=id;
    this->product_quantity=quantity;
}

Stock::~Stock()
{
    //delete [] ProductList;
}
void Stock ::Delete_stock()
{
    int id_delete;
    Product pr;
    int flag = 0;
    ofstream f4;

    ifstream f5;
    char t;
    f5.open("stock.txt");
    f4.open("temp.txt");

    cout<<"Enter ID Stock You Want Delete : ";
    cin>>id_delete;

    while(f5>>ID_Stock>>product_ID>>pr.Quantity)
    {


        if(ID_Stock!=id_delete)
        {
            f4<<ID_Stock<<" "<<product_ID<<" "<<pr.Quantity<<" "<<endl;


        }
        else
        {
            flag = 1;
        }

    }

    f5.close();
    f4.close();
    remove("stock.txt");
    rename("temp.txt","stock.txt");
    flag==1?
    cout<<endl<<endl<<"\tContact Deleted...":
        cout<<endl<<endl<<"\tContact Deleted...";


}
void Stock :: UpdataProduct()
{
    int id_delete;
    Product pr;
    int flag = 0;
    ofstream f4;

    ifstream f5;
    char t;
    f5.open("stock.txt");
    f4.open("temp.txt");

    cout<<"Enter ID Stock You Want Delete : ";
    cin>>id_delete;


    while(f5>>ID_Stock>>product_ID>>pr.Quantity)
    {

        if(ID_Stock!=id_delete)
        {

            f4<<ID_Stock<<" "<<product_ID<<" "<<pr.Quantity<<" "<<endl;


        }
        else
        {
            flag = 1;
        }

    }

    f5.close();
    f4.close();
    remove("stock.txt");
    rename("temp.txt","stock.txt");
    flag==1?
    cout<<endl<<endl<<"\tEnter New Data..":
        cout<<endl<<endl<<"\tEnter New Data..";
    cin>>*this;


}
int Stock :: GetQuantity()
{
    return product_quantity;
}
ostream&operator <<(ostream &output, Stock &s)
{ Product pr;
ifstream f33;
f33.open("stock.txt");
while(f33>>s.ID_Stock>>s.product_ID>>pr.Quantity){
    output << "Stock id : " << s.ID_Stock<<endl<<"Product Id : "<< s.product_ID<<endl<<"Quantity Product : "<< pr.Quantity<<endl;
output<<"\n***********************\n";
}


    return output;
}
istream&operator >>(istream &input,Stock &s)
{
    Product pr;
    cout<<"\nEnter Stock id : ";
    input >> s.ID_Stock;
    cout<<"\nEnter Product ID : ";
    input >>s.product_ID;
    ifstream f90;
    f90.open("Product.txt");
    ofstream f12;
            f12.open("stock.txt",ios::app);
    while(f90>>pr.id>>pr.name>>pr.number>>pr.Quantity>>pr.price>>pr.type)
    {
        //f90>>pr.id>>pr.name>>pr.number>>pr.Quantity>>pr.price>>pr.type;
        if(s.product_ID==pr.id)
        {

            f12<<s.ID_Stock<<" "<<s.product_ID<<" "<<pr.Quantity<<" "<<endl;
            //f12.close();
            f90.close();
        }
        else
        {
            cout<<" No Product";
            cout<<"\n Go To Add pruduct";
        }
    }
    f12.close();
}
