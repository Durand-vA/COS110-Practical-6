#include <sstream>
#include <iostream>
#include <iomanip>
#include "product.h"
/**
 * @brief Creates a product
 * @param n The name of the product
 * @param bNn The barcode number of the product
 * @param v The value of the product
 * @param a The amount of the product
 */
product::product(std::string n, int bNn, int v, int a) : item(n, bNn) {
    value = v;
    amount = a;
}

product::~product() {

}
/**
 * @brief Buys a product
 * @param s The amount to buy, will be a positive integer
 */
void product::buy(std::string s) {
    std::stringstream ss;
    ss << s;
    int n;
    ss >> n;

    if (n > amount) {
        n = amount;
    }
    if (n < 0) {
        n = 0;
    }

    amount -= n;

    std::cout << "Bought{" << std::setprecision(2) << std::fixed
            << n << "}{" << name << "}{R" << price(s) << "}" << std::endl;
}
/**
 * @brief Calculates the price of a product
 * @param s The amount to buy, will be a positive integer
 * @return The price of the product
 */
float product::price(std::string s) {
    std::stringstream ss;
    ss << s;
    int n;
    ss >> n;

    if (n < 0) {
        n = 0;
    }

    return n * value;
}
/**
 * @brief Prints the product
 */
void product::print() {
    std::cout << "product{" << getBarcode() << "}{"
            << name << "}{R" << value << "}{"
            << amount << "}" << std::endl;
}
