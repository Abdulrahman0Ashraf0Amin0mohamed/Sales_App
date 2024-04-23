#ifndef CAMPANY_H
#define CAMPANY_H
#include <string>
#include "Customer.h"
using namespace std;

class Campany : public Customer
{
    public:
        Campany();
        ~Campany();
       void Write_File_Campany();
       void Read_File_Campany();
       void Delete_Company();
       void Edit_Company();
        char Location[20];
        char Campany_name[20];

    protected:
virtual void print(ostream &out);
virtual void readstream(istream &in);
    private:

};

#endif // CAMPANY_H
