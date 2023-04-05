#if !defined(TRANSACTIONS_H)
#define TRANSACTIONS_H



#include <iostream>
#include <openssl/crypto.h>


class Transactions 
{
    private:
    public:
        int amount;
        std::string payer;
        std::string payee;
        Transactions();    
};


Transactions::Transactions(){}


#endif

