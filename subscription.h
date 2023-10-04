#ifndef PRACTICAL_6_SUBSCRIPTION_H
#define PRACTICAL_6_SUBSCRIPTION_H

#include "service.h"

class subscription : public service {
private:
    float yearDiscount;

public:
    subscription(std::string n, int bNn, int r, char p, float d);
    ~subscription();
    float price(std::string s);
    void print();
};

#endif //PRACTICAL_6_SUBSCRIPTION_H
