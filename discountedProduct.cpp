#include <iostream>
#include <iomanip>
#include "discountedProduct.h"
/**
 * @brief discountedProduct::discountedProduct
 * @param n The name of the product
 * @param bNn The barcode number of the product
 * @param v The value of the product
 * @param a The amount of the product
 * @param d The discount percentage of the product
 */
discountedProduct::discountedProduct(std::string n, int bNn, int v, int a, float d) : product(n, bNn, v, a) {
    discount = d;
}
/**
 * @brief Destructor
 */
discountedProduct::~discountedProduct() {

}
/**
 * @brief Applies the discount to the price of the product
 */
float discountedProduct::price(std::string s) {
    return product::price(s) * (1 - discount);
}

void discountedProduct::print() {
    std::cout << "discountedProduct{" << getBarcode()
            << "}{" << name << "}{R" << value
            << "}{" << amount << "}{" << std::setprecision(2)
            << std::fixed << discount*100 << "%}" << std::endl;
}
