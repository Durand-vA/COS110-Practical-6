#include <iostream>
#include <iomanip>
#include <sstream>
#include "service.h"
/**
 * @brief Default constructor
 * @param n The name of the service
 * @param bNn The barcode number of the service
 * @param r The rate of the service
 * @param p The period of the service
 */
service::service(std::string n, int bNn, int r, char p) : item(n, bNn) {
    rate = r;
    period = p;
}

service::~service() {

}
/**
 * @brief Buys a service
 * @param s The amount to buy. Format: "<amount> <period>"
 */
void service::buy(std::string s) {
    std::stringstream ss;
    ss << s.substr(0, s.find(' '));
    int n;
    ss >> n;
    char p = s[s.find(' ') + 1];

    std::string sPeriod;

    switch (p) {
        case 'h':
            sPeriod = "hours";
            break;
        case 'd':
            sPeriod = "days";
            break;
        case 'w':
            sPeriod = "weeks";
            break;
        case 'm':
            sPeriod = "months";
            break;
        default:
            p = 'y';
            sPeriod = "years";
            break;
    }

    if (n < 0) {
        n = 0;
    }

    std::cout << "Bought{" << n << sPeriod
            << "}{" << name << "}{R" << std::setprecision(2)
            << std::fixed << price(s) << "}" << std::endl;
}
/**
 * @brief Calculates the price of a service
 * @param s The amount to buy. Format: "<amount> <period>"
 * @return The price of the service
 */
float service::price(std::string s) {
    std::stringstream ss;
    ss << s.substr(0, s.find(' '));
    int n;
    ss >> n;
    char p = s[s.find(' ') + 1];

    if (n < 0) {
        n = 0;
    }

    int rateScale, nScale;

    //// Set period scale factor
    switch (period) {
        case 'h':
            rateScale = 1;
            break;
        case 'd':
            rateScale = 24;
            break;
        case 'w':
            rateScale = 24 * 7;
            break;
        case 'm':
            rateScale = 24 * 7 * 4;
            break;
        default:
            rateScale = 24 * 7 * 4 * 12;
            break;
    }

    switch (p) {
        case 'h':
            nScale = 1;
            break;
        case 'd':
            nScale = 24;
            break;
        case 'w':
            nScale = 24 * 7;
            break;
        case 'm':
            nScale = 24 * 7 * 4;
            break;
        default:
            nScale = 24 * 7 * 4 * 12;
            break;
    }

    return ((static_cast<float>(rate) / rateScale) * (n * nScale));
}
/**
 * @brief Prints the service
 */
void service::print() {
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

    std::cout << "service{" << getBarcode() << "}{"
            << name << "}{R" << rate << "/" << sPeriod
            << "}" << std::endl;
}

