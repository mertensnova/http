#if !defined(CHAIN_H)
#define CHAIN_H


#include <iostream>

class Chain
{
    private:
    public:
        std::string prev_hash;
        Transactions transaction;
        std::string date;

        void hash();
};

//Block::hash();

#endif
