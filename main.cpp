#include <iostream>
#include <sstream>
#include "item.h"
#include "product.h"
#include "service.h"
#include "bulk.h"
#include "discountedProduct.h"
#include "subscription.h"
#include "labor.h"
#include "shop.h"

void productTest() {
    product product1("item1", 13, 10, 30);
    product product2("item2", 432, 15, 5);
    product product3("item3", 2495, 1, 2300);
    product product4("item4", 36, 100, 1);

    std::cout << product1.getName() << ": " << product1.getBarcode() << '\n'
              << product1.getName() << ": " << product2.getBarcode() << '\n'
              << product1.getName() << ": " << product3.getBarcode() << '\n'
              << product1.getName() << ": " << product4.getBarcode() << std::endl;

    product1.print();
    product2.print();
    product3.print();
    product4.print();

    product1.buy("15");
    product2.buy("10");
    product3.buy("-1");
    product4.buy("0");

    product1.buy("20");

    item* product5 = new product("item5", 36, 100, 1);

    item** arr = new item*[1];
    arr[0] = product5;
    delete arr[0];
    delete [] arr;

}

void serviceTest() {
    service service1("service1", 13, 10, 'h');
    service service2("service1", 13, 14, 'd');
    service service3("service2", 432, 15, 'w');
    service service4("service3", 2495, 100, 'm');
    service service5("service4", 36, 100, 'y');

    service1.print();
    service2.print();
    service3.print();
    service4.print();
    service5.print();

    service1.buy("5 h");
    service2.buy("10 w");
    service3.buy("-1 d");
    service4.buy("0 m");
    service5.buy("10 y");
}

void bulkTest() {
    bulk bulk1("bulk1", 13, 10, 30, 0.1, 5);
    bulk bulk2("bulk2", 432, 15, 5, 0.2, 2);
    bulk bulk3("bulk3", 2495, 1, 2300, 0.3, 1);
    bulk bulk4("bulk4", 36, 100, 1, 0.4, 10);

    bulk1.print();
    bulk2.print();
    bulk3.print();
    bulk4.print();

    bulk1.buy("5");
    bulk2.buy("10");
    bulk3.buy("-1");
    bulk4.buy("0");
}

void discountedProductTest() {
    discountedProduct disc1("disc1", 13, 10, 30, 0.1);
    discountedProduct disc2("disc2", 432, 15, 5, 0.2);
    discountedProduct disc3("disc3", 2495, 1, 2300, 0.3);
    discountedProduct disc4("disc4", 36, 100, 1, 0.4);

    disc1.print();
    disc2.print();
    disc3.print();
    disc4.print();

    disc1.buy("5");
    disc2.buy("10");
    disc3.buy("-1");
    disc4.buy("0");
}

void laborTest() {
    int** workers = new int*[5];
    for (int i = 0; i < 5; i++) {
        workers[i] = new int[4];
        for (int j = 0; j < 4; j++) {
            workers[i][j] = i*j;
        }
    }
    labor labor1("labor1", 13, 10, 'y', workers[0], 4);
    labor labor2("labor2", 432, 15, 'm', workers[1], 4);
    labor labor3("labor3", 2495, 1, 'd', workers[2], 4);
    labor labor4("labor4", 36, 100, 'w', workers[3], 4);
    labor labor5("labor5", 1, 20, 'h', workers[4], 4);

    for (int i = 0; i < 5; i++) {
        delete [] workers[i];
    }
    delete [] workers;

    labor1.print();
    labor2.print();
    labor3.print();
    labor4.print();

    labor1.buy("5 h");
    labor2.buy("10 w");
    labor3.buy("-1 d");
    labor4.buy("0 m");
    labor5.buy("10 y");
}

void subscriptionTest() {
    subscription sub1("sub1", 13, 10, 'y', 0.1);
    subscription sub2("sub2", 432, 15, 'm', 0.5);
    subscription sub3("sub3", 2495, 1, 'd', 0.2);
    subscription sub4("sub4", 36, 100, 'w', 0.3);
    subscription sub5("sub5", 1, 20, 'h', 0.4);

    sub1.print();
    sub2.print();
    sub3.print();
    sub4.print();

    sub1.buy("5 h");
    sub2.buy("10 w");
    sub3.buy("-1 d");
    sub4.buy("0 m");
    sub5.buy("10 y");
}

void shopTest() {
    item* i1 = new product("prod1", 3, 10, 20);

    item** is = new item*[10];

    char cs[5] = {'h','d','w','m','y'};

    for (int i = 0; i < 10; i++) {
        std::stringstream ss;
        ss << "service" << i;
        is[i] = new service(ss.str(), (i+1)*13, (i+1)*22, cs[i%5]);
    }

    shop shop1;

    shop1.addItem(i1);
    shop1.addItem(i1);
    shop1.addItems(is, 10);

    shop1.buyItems("service1:10 h|prod1:5|service4:4 y|test:5|");

    shop1.printItems();

    shop1.removeItem("service1");
    shop1.removeItem("service10");

    delete [] is;
    is = new item*[10];

    for (int i = 0; i < 10; i++) {
        std::stringstream ss;
        ss << "service" << i;
        is[i] = new service(ss.str(), (i+1)*13, (i+1)*22, cs[i%5]);
    }
    shop1.addItems(is, 10);


    for (int i = 0; i < 10; i++) {
        if (i != 1)
            delete is[i];
    }

    delete [] is;
}

int main() {
    productTest();
//    serviceTest();
//    bulkTest();
//    discountedProductTest();
//    laborTest();
//    subscriptionTest();
//    shopTest();
    return 0;
}
