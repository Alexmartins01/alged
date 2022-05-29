#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "products.h"
#include "product.h"

void print_menu(){
    printf("--------------------------------\n");
    printf("|Bem vindo ao sistema de stocks|\n");
    printf("|  -i insere um novo produto   |\n");
    printf("|       -r remove produto      |\n");
    printf("|      -g imprime produto      |\n");
    printf("| -p imprime todos os produtos |\n");
    printf("|           -h help            |\n");
    printf("|      -q sai do programa      |\n");
    printf("--------------------------------\n");
    
}


void print_product(PRODUCT p){

    if(!p) {
        printf("product not found\n");
    }

    else{
        int id,preco,stock;
        char *nome;

        id  = get_id(p);
        nome = get_nome(p);
        preco = get_preco(p);
        stock = get_stock(p);

        printf("|produto: %s, id: %i, preco: %i, quantidade em stock:%i|\n",nome,id,preco,stock);
    }
}

void print_all(products ps, int i){
    while(get_next(ps)!=NULL && i>0) {
        print_product(get_product(ps));
        ps=get_next(ps);
        i--;
    }
    print_product(get_product(ps));
}

int ui(){
    
    char buf[32];
    int i=0;

    products ps = create_products();

    print_menu();

    while(fgets(buf, 32, stdin) && strncmp(buf,"-q",2)!=0){

        if(strncmp(buf,"-i",2)==0){

            printf("inserting product...\n");

            build_products(buf,&ps,i);

            perror("product inserted");
            i++;
        }

        if(strncmp(buf,"-r",2)==0){

            printf("removing product...\n");

            char * token = strtok(buf, " ");
            token = strtok(NULL, " \n");


            int id = atoi(token);

            ps = remove_products(id, ps, i);
            i--;

            perror("product removed");
        }

        if(strncmp(buf,"-g",2)==0){
            printf("searching product...\n");

            char * token = strtok(buf, " ");
            token = strtok(NULL, " \n");


            int id = atoi(token);

            print_product(search_product(id,ps,i));
        }

        if(strncmp(buf,"-p",2)==0) {
            print_all(ps,i);
        }

        if(strncmp(buf,"-h",2)==0){
            print_menu();
        }

   }

   return 1;
}