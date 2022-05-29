#ifndef PRODUCTS_H
#define PRODUCTS_H

#include "product.h"

typedef struct products{
    PRODUCT product;
    struct products *next;
}*products;


PRODUCT get_product(products ps);

products get_next(products ps);

void set_product(products ps,PRODUCT p);

void set_next(products ps,products next);

products create_products();

products remove_products(int id, products ps, int i);

PRODUCT search_product(int id, products ps,int i);

void build_products(char *line, products* ps, int i);

#endif