#ifndef CREDIT_H
#define CREDIT_H
#include <string>
#include "Payment.h"
using namespace std;

class Credit : public Payment
{
    public:
        Credit();
        ~Credit();

        void pay();


    protected:

    private:
        string Number;
        string type;
        string Expire_Date;
};

#endif // CREDIT_H
