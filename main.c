// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct items{
    char item[20];
    float price;
    int qty;
};

struct orders{
    char customer[50];
    char date[50];
    int numberOfItems;
    struct items itm[50];
};

void generateBillHeader(char name[50], char date[30]) {
    printf("\n\n");
        printf("\t   ADV. Resturant");
        printf("\n\t  ---------------");
        printf("\nDate:%s",date);
        printf("\nInvoice To: %s",name);
        printf("\n");
        printf("-------------------");
        printf("Items\t\t");
        printf("Qty\t\t");
        printf("Total\t\t");
        printf("\n--------------------");
        printf("\n\n");
}

void generateBillBody(char item[30], int qty, float price) {
        printf("%s\t\t",item);
        printf("%d\t\t",qty);
        printf("%.2f\t\t",qty * price);
        printf("\n");
}


void generateBillFooter(float total) {
    printf("\n");
    float dis = 0.1*total;
    float netTotal=total-dis;
    float cgst=0.09*netTotal,grandTotal=netTotal + 2*cgst;
    printf("----------------\n");
    printf("Sub Total\t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t%.2f","%",dis);
    printf("\n\t\t\t\t\t-----");
    printf("\nNet Total\t\t\t%.2f",netTotal);
    printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
    printf("SGST @9%s\t\t\t%.2f","%",cgst);
    printf("\n--------------");
    printf("Grand Total\t\t\t%.2f",grandTotal);
    printf("\n---------------");
}

int main(){
    int opt,n;
    float total;
    
    struct orders ord;
    
    printf("\t=========ADV. Resturant==========");
    printf("\n\nPlease select your preferred operation:");
    printf("\n1.Generate Invoice");
    printf("\n2.Show all Invoice");
    printf("\n3.Search Invoice");
    printf("\n4.Exit");
    
    printf("\n\nYour choice:");
    scanf("%d",&opt);
    fgetc(stdin);
   
   switch(opt){
       case 1:
       printf("\nPlease enter the name of the customer: \t");
       fgets(ord.customer,50,stdin);
       ord.customer[strlen(ord.customer)-1] = 0;
       strcpy(ord.date,__DATE__);
       printf("\nPlease enter the amount of items:\t");
       scanf("%d",&n);
       ord.numberOfItems = n;
       
       for(int i=0;i<n;i++) {
           fgetc(stdin);
           printf("\n\n");
           printf("Please enter the item %d:\t",i+1);
           fgets(ord.itm[i].item,20,stdin);
           ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
           printf("\nPlease enter the quantity:\t");
           scanf("%d",&ord.itm[i].qty);
           printf("\nPlease enter the unit price:\t");
           scanf("%f",&ord.itm[i].price);
           total += ord.itm[i].qty * ord.itm[i].price;
       }
       
       generateBillHeader(ord.customer,ord.date);
       for(int i=0;i<ord.numberOfItems;i++){
       generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
       }
       
       generateBillFooter(total);
   }
    
    printf("\n\n");
    
    return 0;
}


