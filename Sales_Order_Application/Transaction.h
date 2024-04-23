#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
using namespace std;

class Transaction
{
public:
    Transaction();
    ~Transaction();
    void Get_Order();
   friend std::ostream& operator<<(std::ostream&, Transaction& t);
   int Transaction_Date;
   int ID_OF_Transction;
   void print();
   void delete_tran();
protected:

private:
char Adds[20];
char Ntr[20];
int pho;
int f;
};

#endif // TRANSACTION_H
