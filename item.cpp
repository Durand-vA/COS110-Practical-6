#include <iostream>
#include "item.h"
#include <sstream>

item::item(std::string n, int bN) {
    name = n;

    int count = 0, temp = bN;

    while (temp != 0) {
        count++;
        temp = temp >> 1;
    }

    barcodeLength = count;
    barcode = new bool[barcodeLength];

    for (int i = barcodeLength-1; i >= 0; i--) {
        barcode[barcodeLength-(i+1)] = (bN >> i) % 2;
    }
}

item::~item() {
    if (barcode != NULL)
        delete [] barcode;
}

std::string item::getName() {
    return name;
}

std::string item::getBarcode() {
    std::stringstream ss;

    int n = 0;

    ss << '[';
    for (int i = 0; i < barcodeLength; i++) {
        bool bar = barcode[i];
        n += bar;
        if (i != barcodeLength - 1)
            n = n << 1;
        ss << (bar ? '|' : ' ');
    }
    ss << "](" << n << ')';

    return ss.str();
}