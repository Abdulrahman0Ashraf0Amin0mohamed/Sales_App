#ifndef CASH_H
#define CASH_H
#include "Payment.h"
#include <string>
using namespace std;

class Cash : public Payment
{
    public:
        Cash();
        ~Cash();

        void pay();

    protected:

    private:
        double Cash_Value;
};

#endif // CASH_H
