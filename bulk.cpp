#include <sstream>
#include <iostream>
#include <iomanip>
#include "bulk.h"
/**
 * @brief Creates a bulk product
 * @param n The name of the product
 * @param bNn The barcode number of the product
 * @param v The value of the product
 * @param a The amount of the product
 * @param dP The discount percentage of the product
 * @param dA The discount amount of the product
 */
bulk::bulk(std::string n, int bNn, int v, int a, float dP, int dA) : product(n, bNn, v, a) {
    discountPercentage = dP;
    discountAmount = dA;
}

bulk::~bulk() {

}
/**
 * @brief Calculates the price of a bulk product
 * @param s The amount to buy, will be a positive integer
 * @return The price of the bulk product
 */
float bulk::price(std::string s) {
    std::stringstream ss;
    ss << s;
    int n;
    ss >> n;

    if (n < 0) {
        n = 0;
    }

    int numGroups = n / discountAmount;
    float groupDiscountPrice = value * (1 - discountPercentage) * discountAmount;

    return numGroups * groupDiscountPrice + (n % discountAmount) * value;
}
/**
 * @brief Prints the bulk product
 */
void bulk::print() {
    std::cout << "bulk{" << getBarcode() << "}{" << name
            << "}{R" << value << "}{" << amount << "}{"
            << std::setprecision(2) << std::fixed
            << discountPercentage * 100 << "%}{"
            << discountAmount << "}" << std::endl;
}

