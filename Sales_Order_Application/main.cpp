/*******************************************
 ** COPYRIGHT BY QURSAAN *******************
 ** github@qursaan.com   *******************
 *******************************************/
#include <iostream>         // cin, cout
#include <cstdlib>          // cls
#include <windows.h>        // Sleep
#include <cstring>          // string, to_string
#include <bits/stdc++.h>    // stringstream
#include <windows.h>
#include"Customers.h"
#include "Product.h"
#include "Stock.h"
#include "Transaction.h"
#include "Customer.h"
#include "Person.h"
#include "Campany.h"
#include "Payment.h"
using namespace std;
Customers s;
Product Pr;
Stock St;
Transaction Tr;
Order Or;
Payment Pa;

HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);

/** ASSISTANT INLINE FUNCTIONS **/
inline void wait_or_clear(unsigned int sec, bool clear_screen = false)
{
    Sleep(sec*1000);
    if (clear_screen) system("cls");
}

inline void printline(string msg, bool end_line = true, int color_code=15)
{
    SetConsoleTextAttribute(cout_handle, color_code);
    cout <<  msg << (end_line?"\n":"\t");
}

inline void print_try_again()
{
    printline("\n\n\n\aInvalid Choice Try Again!!!!!!!!",1,4);
    wait_or_clear(3, 1);
}

/** MAIN PRINT MENU FUNCTION **/
int get_menu_choise(string menu, int level = 0)
{
    stringstream X(menu);
    string line, padding;
    int i = 1;
    for(int p=0; p<level+1; ++p)
        padding +="\t";

    while (getline(X, line, ','))
        printline(padding + to_string(i++) + ". " + line,1,level+11);

    printline(level?padding+"0. RETURN BACK":padding+"0. EXIT APP",1,5);
    int c;
    printline("ENTER YOUR CHOICE :",false,2);
    cin >> c;
    return c;
}

/** DATA ENTRY AND SUB MENU **/
void sub_sub_menu_1_product()
{

    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> DATA ENTRY -> PRODCUTS ....");
        c = get_menu_choise("ADD,EDIT,DELELE",2);
        switch(c)
        {
        case 1:
            cin>>Pr;
            system("pause");
            break;
        case 2:
            Pr.update();
            system("pause");
            break;
        case 3:
            Pr.Delete_Product();
            system("pause");
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_sub_menu_1_customer()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> DATA ENTRY -> CUSTOMERS ....");
        c = get_menu_choise("ADD,EDIT,DELELE",2);
        switch(c)
        {
        case 1:
        {
            s.Add_Customer();
            system("pause");
            break;
        }
        case 2:
            s.Edit_Customer();
            system("pause");
            break;
        case 3:
            s.Delete_Customer();
            system("pause");
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_sub_menu_1_stock()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> DATA ENTRY -> STOCK ....");
        c = get_menu_choise("ADD PRODUCT,UPDATE QUANTITY BY ID,CLEAR STOCK",2);
        switch(c)
        {
        case 1:

            cin>>St;
            system("pause");
            break;
        case 2:
            St.UpdataProduct();
            system("pause");
            break;
        case 3:
            St.Delete_stock();
            system("pause");
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_menu_1_data_entry()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> DATA ENTRY ....");
        c = get_menu_choise("PRODUCT,CUSTOMER,STOCK",1);
        switch(c)
        {
        case 1:
            sub_sub_menu_1_product();
            break;
        case 2:
            sub_sub_menu_1_customer();
            break;
        case 3:
            sub_sub_menu_1_stock();
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

/** SALSES AND SUB MENU **/

void sub_sub_menu_2_order()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> SALES PROCESS -> ORDERS....");
        c = get_menu_choise("ADD NEW,UPDATE,DELETE",2);
        switch(c)
        {
        case 1:
            Or.Creat_Order();
            system("pause");
            break;
        case 2:
            Or.Edit_Order();
            system("pause");
            break;
        case 3:
          Or.delete_ord();
            system("pause");
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}
void sub_sub_menu_2_payment(){
    Pa.pay();
}
void sub_sub_menu_2_transaction()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> SALES PROCESS -> TRANSACTIONS ....");
        c = get_menu_choise("ADD NEW,DELETE",2);
        switch(c)
        {
        case 1:
            printline("Do it here 1 ADD NEW TRANSACTION");
            Tr.Get_Order();
            system("pause");
            break;
        case 2:
           Tr.delete_tran();
            system("pause");
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_menu_2_sales_process()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> SALES PROCESS ....");
        c = get_menu_choise("ORDER,pay,TRANSCATION",1);
        switch(c)
        {
        case 1:
            sub_sub_menu_2_order();
            break;
        case 2 :
            sub_sub_menu_2_payment();
            break;
        case 3:
            sub_sub_menu_2_transaction();
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}


/** PRINTS AND SUB MENU **/

void sub_menu_3_prints()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> PRINTS ....");
        c = get_menu_choise("PRODUCT,STOCK,CUSTOMER,TRANSACTIONS",1);
        switch(c)
        {
        case 1:
            cout<<Pr;

            system("pause");
            break;
        case 2:
cout <<St;
            system("pause");
            break;
        case 3:
        {
            s. print();
            system("pause");

            break;
        }
        case 4:
            Tr.print();
            system("pause");
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

/** MAIN FUNCTION **/
int main()
{
    printline("START APPLICATION ....",1,6);
    wait_or_clear(1,1);
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0,1);
        printline("\n\nMAIN MENU ....",1,10);
        c = get_menu_choise("DATA ENTRY,SALES PROCESS,PRINTS",0);
        switch(c)
        {
        case 1:
        {
            sub_menu_1_data_entry();

            break;
        }
        case 2:
            sub_menu_2_sales_process();
            break;
        case 3:
            sub_menu_3_prints();
            break;
        case 0:
            printline("\n\n\a\t\t\tGoodbye :)......\n\n\n\n\n\n",1,112);
            break;
        default:
            print_try_again();
            wait_or_clear(3, true);
        }
    }
    return 0;
}
