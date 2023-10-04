#ifndef PRACTICAL_6_SERVICE_H
#define PRACTICAL_6_SERVICE_H

#include "item.h"

class service : public item {
protected:
    int rate;
    char period;

public:
    service(std::string n, int bNn, int r, char p);
    ~service();
    virtual void buy(std::string s);
    virtual float price(std::string s);
    virtual void print();
};

#endif //PRACTICAL_6_SERVICE_H
