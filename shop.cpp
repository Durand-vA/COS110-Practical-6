#include <iostream>
#include <sstream>
#include <iomanip>
#include "shop.h"

shop::shop() {
    numItems = 0;
    items = new item*[0];
}

shop::~shop() {
    if (items != NULL) {
        for (int i = 0; i < numItems; i++) {
            delete items[i];
        }
        delete[] items;
    }
}

int shop::itemIndex(std::string n) {
    for (int i = 0; i < numItems; i++) {
        if (items[i]->getName() == n)
            return i;
    }
    return -1;
}

void shop::addItem(item* i) {
    if (i == NULL) {
        std::cout << "Item is NULL" << std::endl;
        return;
    }
    if (itemIndex(i->getName()) != -1) {
        std::cout << "Item already in shop" << std::endl;
        return;
    }

    item** temp = new item*[numItems + 1];
    for (int j = 0; j < numItems; j++) {
        temp[j] = items[j];
    }

    temp[numItems] = i;

    delete[] items;

    items = temp;
    numItems++;
}

void shop::addItems(item** i, int n) {
    if (i == NULL) {
        return;
    }
    for (int j = 0; j < n; j++) {
        addItem(i[j]);
    }
}

void shop::buyItems(std::string s) {
    std::stringstream ss;
    ss << s;

    std::string name;
    std::string inp;

    float price = 0;

    while (std::getline(ss, name, ':')) {
        int index = itemIndex(name);
        if (index == -1) {
            std::cout << "Couldn't find " << name << std::endl;
            std::getline(ss, inp, '|');
        } else {
            std::getline(ss, inp, '|');
            price += items[index]->price(inp);
            items[index]->buy(inp);
        }
    }

    std::cout << "Total: R " << std::setprecision(2) << std::fixed << price << std::endl;
}

void shop::printItems() {
    for (int i = 0; i < numItems; i++) {
        items[i]->print();
    }
}

void shop::removeItem(std::string s) {
    int index = itemIndex(s);
    if (index == -1) {
        std::cout << "Item not found" << std::endl;
    } else {
        item** temp = new item*[numItems - 1];
        int count = 0;
        for (int i = 0; i < numItems; i++) {
            if (i != index) {
                temp[count] = items[i];
                count++;
            }
        }

        delete items[index];
        delete[] items;

        items = temp;
        numItems--;
    }
}
