#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>


using namespace std;
class Product
{

public:

    Product();
    Product(int id,int type,string number,string name,double price,int Quantity);
    void update();
    int getID();
    void Add_product();
    void Delete_Product();
    ~Product();
     int Quantity;
    int id,type;
    string number,name;
    double price;
     //int i=0;
private:
 friend istream&operator>>(istream &input,Product &p);
    friend ostream & operator <<(ostream &output, Product &p);

};


#endif
