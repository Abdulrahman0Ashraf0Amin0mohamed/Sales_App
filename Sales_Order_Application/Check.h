#ifndef CHECK_H
#define CHECK_H
#include <string>
#include "Payment.h"
using namespace std;

class Check : public Payment
{
    public:
        Check();
        ~Check();

        void pay();

    protected:

    private:
         string Name;
        string Bank_ID;
};

#endif // CHECK_H
