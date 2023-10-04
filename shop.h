#ifndef PRACTICAL_6_SHOP_H
#define PRACTICAL_6_SHOP_H

class item;
#include "item.h"

class shop {
private:
    item **items;
    int numItems;

public:
    shop();
    ~shop();
    int itemIndex(std::string n);
    void addItem(item* i);
    void addItems(item** i, int n);
    void buyItems(std::string s);
    void printItems();
    void removeItem(std::string s);
};

#endif //PRACTICAL_6_SHOP_H
