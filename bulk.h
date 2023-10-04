#ifndef PRACTICAL_6_BULK_H
#define PRACTICAL_6_BULK_H

#include "product.h"

class bulk : public product {
private:
    float discountPercentage;
    int discountAmount;

public:
    bulk(std::string n, int bNn, int v, int a, float dP, int dA);
    ~bulk();
    virtual float price(std::string s);
    virtual void print()    ;
};
#endif //PRACTICAL_6_BULK_H
