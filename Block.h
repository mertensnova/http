#include <iostream>

#include "Transactions.h"

#if !defined(BLOCK_H)

#define BLOCK_H

class Block
{
    private:
    public:
        std::string prev_hash;
        Transactions transaction;
        std::string date;

        void hash();
};

Block::hash();

#endif

