#ifndef PRACTICAL_6_PRODUCT_H
#define PRACTICAL_6_PRODUCT_H

#include "item.h"

class product : public item {
protected:
    int value, amount;

public:
    product(std::string n, int bNn, int v, int a);
    ~product();
    virtual void buy(std::string s);
    virtual float price(std::string s);
    virtual void print();
};

#endif //PRACTICAL_6_PRODUCT_H
