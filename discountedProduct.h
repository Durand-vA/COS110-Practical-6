#ifndef PRACTICAL_6_DISCOUNTEDPRODUCT_H
#define PRACTICAL_6_DISCOUNTEDPRODUCT_H

#include "product.h"

class discountedProduct : public product {
private:
    float discount;

public:
    discountedProduct(std::string n, int bNn, int v, int a, float d);
    ~discountedProduct();
    float price(std::string s);
    void print();
};

#endif //PRACTICAL_6_DISCOUNTEDPRODUCT_H
