cmake_minimum_required(VERSION 3.24)
project(Practical_6)

set(CMAKE_CXX_STANDARD 98)

add_executable(Practical_6 main.cpp
        item.cpp
        item.h
        product.cpp
        product.h
        service.cpp
        service.h
        bulk.cpp
        bulk.h
        discountedProduct.cpp
        discountedProduct.h
        labor.cpp
        labor.h
        subscription.cpp
        subscription.h
        shop.cpp
        shop.h)
