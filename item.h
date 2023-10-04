#ifndef PRACTICAL_6_ITEM_H
#define PRACTICAL_6_ITEM_H

#include <string>

class item {
protected:
    std::string name;
    int barcodeLength;
    bool* barcode;

public:
    item(std::string n, int bN);
    ~item();
    std::string getName();
    std::string getBarcode();
    virtual void buy(std::string s) = 0;
    virtual float price(std::string s) = 0;
    virtual void print() = 0;

};

#endif //PRACTICAL_6_ITEM_H