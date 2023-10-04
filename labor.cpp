#include <iostream>
#include <iomanip>
#include "labor.h"

labor::labor(std::string n, int bNn, int r, char p, int* wR, int num) : service(n, bNn, r, p) {
    numWorkers = num;
    workerRates = new int[numWorkers];
    for (int i = 0; i < numWorkers; i++) {
        workerRates[i] = wR[i];
    }
}

labor::~labor() {
    if (workerRates != NULL) {
        delete [] workerRates;
    }
}

float labor::price(std::string s) {
    float base = service::price(s);
    float total = 0;
    for (int i = 0; i < numWorkers; i++) {
        total += base * workerRates[i];
    }
    return total;
}

void labor::print() {
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

    std::cout << "labor{" << getBarcode() << "}{"
            << name << "}{R" << rate << "/" << sPeriod
            << "}{[";
    for (int i = 0; i < numWorkers; i++) {
        std::cout << workerRates[i];
        if (i != numWorkers - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]}" << std::endl;
}

