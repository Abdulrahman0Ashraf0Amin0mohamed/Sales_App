#ifndef ORDER_H
#define ORDER_H
#include <string>
#include "Product.h"
#include "Stock.h"
#include "Customer.h"
#include "Person.h"
#include "Campany.h"
#include "Customers.h"
using namespace std;

class Order
{
public:
    Order();
    ~Order();
    void Creat_Order();
    void Update_Order();
    void Edit_Order();
     void delete_ord();
    int iD_customer_ord;
    friend std::ostream& operator<<(std::ostream& out, Order& o);
    friend std::istream& operator>>(std::istream& in, Order& o );
 int y = 0;
  int Number_OF_Order;
    int date;
    int Quantity_Order;
    int ID_Product_Search;
    int iD_company_ord;
    int ID;
protected:
    Customer*customerord;
private:


    // Save Price Total

};

#endif // ORDER_H
