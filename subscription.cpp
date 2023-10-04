//
// Created by vanaa on 2023/10/03.
//

#include <iostream>
#include <iomanip>
#include "subscription.h"

subscription::subscription(std::string n, int bNn, int r, char p, float d) : service(n, bNn, r, p) {
    yearDiscount = d;
}

subscription::~subscription() {

}

float subscription::price(std::string s) {
    char p = s[s.find(' ') + 1];

    float scale = 1;
    switch (p) {
        case 'h':
        case 'd':
        case 'w':
        case 'm':
            break;
        default:
            scale = 1 - yearDiscount;
            break;
    }
    return service::price(s) * scale;
}

void subscription::print() {
    std::string sPeriod;
    switch (period) {
        case 'h':
            sPeriod = "hour";
            break;
        case 'd':
            sPeriod = "day";
            break;
        case 'w':
            sPeriod = "week";
            break;
        case 'm':
            sPeriod = "month";
            break;
        default:
            sPeriod = "year";
            break;
    }

    std::cout << "subscription{" << getBarcode() << "}{"
            << name << "}{R" << rate << "/" << sPeriod
            << "}{" << std::setprecision(2) << std::fixed
            << yearDiscount * 100 << "%}" << std::endl;
}
