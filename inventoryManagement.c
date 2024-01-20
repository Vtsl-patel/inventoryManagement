#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct Product
{
  char Name[50];
  int qty;
  int MRP;
  int ID;
};

struct Product pr[10];

struct cart
{
    char pname[50];
    int pquant;
    int pPrice;
};

struct cart p2[10];

int Custbill[100];

int days1[31], reserve1[31], tprofit[31],mprofit[31];

int monthday;

void add_product(int num, char *a,int *b,int *c,int *d){

  printf("Please enter details for the product\n");
  printf("Name:- ");
  scanf(" %[^\n]s", a);
  printf("Quantity: ");
  scanf("%d",c);
  printf("MRP: ");
  scanf("%d",d);
}

int edit_product(){
  int change;
  printf("Enter the change in quantity \"use negative sign for removing items from the stock\" \n");
  scanf("%d",&change);
  return change;
}

void StockTable(int num){ if(num==0){printf("Inventory is empty. Please add some products to continue.\n"); return;}
  char c = '|'; int n; int id; int q; int m;

    printf("\n\nProduct Name          | Product ID | Quantity  | MRP (Rs)  |\n\n");

    for(int i=0;i<num;i++){
      n= 23 - strlen(pr[i].Name);
      id=11;
      for(int j= pr[i].ID/10;j>0;j=j/10){id--;}
      q =10;
      for(int j= pr[i].qty/10;j>0;j=j/10){q--;}
      m =7;
      for(int j= pr[i].MRP/10;j>0;j=j/10){m--;}
      
      printf("%s%*c %d%*c %d%*c %d%*c\n",pr[i].Name,n,c, pr[i].ID,id,c, pr[i].qty,q,c, pr[i].MRP,m,c);
    }
}

void xyz(int num)
{
    
    int ip1=1; 
    cart:
    printf("What You want to proceed with : \n");
    printf("1. New Cart \n");
    printf("2. Reserve order \n");
    printf("3. Exit \n");
    
    printf("---------------------------------------------------------------------- \n");
    printf("Enter your response : ");
    scanf(" %d",&ip1);

    int ip15=1;
    switch (ip1)
    {
        case 1:
        ;
        int b=0;
        while(ip15==1)
        {
            StockTable(num);
            printf("\n");
            char ip13 = 'y';
            int ip14=0;
            while(ip13=='Y' || ip13=='y')
            {
                int ip11,ip12;
                printf("Enter the Sr. number of Product you want to purchase : ");
                scanf(" %d",&ip11);
                ip11--;
                if(ip11<0 || ip11>6) {
                        printf("---------------------------------------------------------------------- \n");
                        printf("Enter valid Sr. number \n");
                        printf("---------------------------------------------------------------------- \n");
                }
                else {
                printf("Enter Product Quantity you want to Purchase : ");
                scanf(" %d",&ip12);
                    

                    
                    
                for (int j=0 ; j<=10 ; j++)
                {
                    if (j==ip11)
                    {
                        if(pr[j].qty >= ip12){
                            pr[j].qty = pr[j].qty-ip12;
                            strcpy(p2[ip14].pname,pr[ip11].Name);
                            p2[ip14].pquant=ip12;
                            p2[ip14].pPrice=pr[ip11].MRP;
                        }
                        else{
                            printf("---------------------------------------------------------------------- \n");
                            printf("Not enough stock for Product number %d \n",ip11+1);
                            printf("---------------------------------------------------------------------- \n");
                            break;
                        }
                        break;    
                    }
                    
                }
                }
                
        
                printf("Press 'Y' to continue shopping and 'N' to checkout : ");
                scanf(" %c", &ip13); 
                printf("---------------------------------------------------------------------- \n");
                ip14++;
            }

            //display final list of product choosen by customer
            printf("Your bought products are : \n");
            printf("---------------------------------------------------------------------- \n");

            char c = '|'; int n,q,m; 

            printf("\n\nProduct Name          | Quantity | MRP (Rs)  |\n\n");

            for(int i=0;i<ip14;i++){
                n= 23 - strlen(p2[i].pname);
                q =10;
                for(int j= p2[i].pquant;j>0;j=j/10){q--;}
                m =8;
                for(int j= p2[i].pPrice;j>0;j=j/10){m--;}
                    
                printf("%s%*c %d%*c %d%*c\n",p2[i].pname,n,c, p2[i].pquant,q,c, p2[i].pPrice,m,c);
            
            }

            int bill=0;
            for(int k=0 ; k<=ip14 ; k++)
            {
                bill = bill + (p2[k].pquant)*(p2[k].pPrice);   
            }
            printf("---------------------------------------------------------------------- \n");
            printf("Total Bill is : %d \n",bill);
            Custbill[b] = bill;
            printf("---------------------------------------------------------------------- \n");

            printf("Choose option from below : \n");
            printf("1. New Customer \n");
            printf("2. End day \n");
            printf("Enter your choice : ");
            scanf("%d", &ip15);
            b++;

            if(ip15==2){
                break;
            }
            printf("---------------------------------------------------------------------- \n");                    
        }

        paynow:
        if(days1[monthday]==0){
            int daybill=0;
            for(int c=0 ; c<=b ; c++)
            {
                daybill = daybill + Custbill[c];
            }
            days1[monthday]=daybill;
        }  
        else{
            int daybill=0;
            for(int c=0 ; c<=b ; c++)
            {
                daybill = daybill + Custbill[c];
            }
            days1[monthday]= days1[monthday]+daybill;
        }  

        printf("---------------------------------------------------------------------- \n");
        goto cart;

        case 2:
        ;
        int rpr;
        int z=0;
        while(ip15==1)
        {
            StockTable(num);
            printf("\n");
            char ip13 = 'y';
            int ip14=0;
            while(ip13=='Y' || ip13=='y')
            {
                int ip11,ip12;
                printf("Enter the Sr. number of Product you want to reserve : ");
                scanf(" %d",&ip11);
                ip11--;
                if(ip11<0 || ip11>6) {
                        printf("---------------------------------------------------------------------- \n");
                        printf("Enter valid Sr. number \n");
                        printf("---------------------------------------------------------------------- \n");
                }
                else {
                printf("Enter Product Quantity you want to Purchase : ");
                scanf(" %d",&ip12);      
                    
                for (int j=0 ; j<=10 ; j++)
                {
                    if (j==ip11)
                    {
                        if(pr[j].qty >= ip12){
                            pr[j].qty = pr[j].qty-ip12;
                            strcpy(p2[ip14].pname,pr[ip11].Name);
                            p2[ip14].pquant=ip12;
                            p2[ip14].pPrice=pr[ip11].MRP;
                        }
                        else{
                            printf("---------------------------------------------------------------------- \n");
                            printf("Not enough stock for Product number %d \n",ip11+1);
                            printf("---------------------------------------------------------------------- \n");
                            break;
                        }
                        break;    
                    }
                    
                }
                }
        
                printf("Press 'Y' to continue shopping and 'N' to checkout : ");
                scanf(" %c", &ip13); 
                printf("---------------------------------------------------------------------- \n");
                ip14++;
            }

            //display final list of product choosen by customer
            printf("Your reserved products are : \n");
            printf("---------------------------------------------------------------------- \n");

            char c = '|'; int n,q,m; 

            printf("\n\nProduct Name          | Quantity | MRP (Rs)  |\n\n");

            for(int i=0;i<ip14;i++){
                n= 23 - strlen(p2[i].pname);
                q =10;
                for(int j= p2[i].pquant;j>0;j=j/10){q--;}
                m =8;
                for(int j= p2[i].pPrice;j>0;j=j/10){m--;}
                    
                printf("%s%*c %d%*c %d%*c\n",p2[i].pname,n,c, p2[i].pquant,q,c, p2[i].pPrice,m,c);
            
            }

            int bill=0;
            for(int k=0 ; k<=ip14 ; k++)
            {
                bill = bill + (p2[k].pquant)*(p2[k].pPrice);   
            }
            printf("---------------------------------------------------------------------- \n");
            printf("Total Bill is : %d \n",bill);
            Custbill[z] = bill;
            printf("---------------------------------------------------------------------- \n");

            printf("---------------------------------------------------------------------- \n");
            printf("What you want to procced with : \n");
            printf("1. Pay Now \n");
            printf("2. Pay Later \n");
            printf("---------------------------------------------------------------------- \n");
            printf("Enter your response : ");
            scanf("%d",&rpr);
            printf("---------------------------------------------------------------------- \n");

            if(rpr==1){
                printf("You have to pay : %d \n",bill);
                goto paynow;
            }
            else if(rpr==2){
                printf("-----");
                printf("You have to pay : %d now and %d will be paid later. \n",(bill/2),(bill/2));
                goto paylater;
            }
            else{
                printf("Enter valid response !! \n");
                printf("---------------------------------------------------------------------- \n");
            }

            printf("Choose option from below : \n");
            printf("1. New Customer \n");
            printf("2. End day \n");
            printf("Enter your choice : ");
            scanf("%d", &ip15);
            z++;

            if(ip15==2){
                break;
            }
            printf("---------------------------------------------------------------------- \n");                    
        }

        paylater:
        if(rpr==2)
        {
            if(days1[monthday]==0){
                int daybillrs=0;
                for(int c=0 ; c<=z ; c++)
                {
                    daybillrs = daybillrs + Custbill[c];
                }
                days1[monthday]=daybillrs/2;
                reserve1[monthday]=daybillrs/2;
            } 
            else{
                int daybillrs=0;
                for(int c=0 ; c<=z ; c++)
                {
                    daybillrs = daybillrs + Custbill[c];
                }
                days1[monthday]=days1[monthday]+daybillrs/2;
                reserve1[monthday]=daybillrs/2;
            }   
        }    

        printf("---------------------------------------------------------------------- \n");
        goto cart;

        case 3: 
        printf("Exiting menu....\n");
        printf("---------------------------------------------------------------------- \n");
        break;

        default:
        printf("Enter valid argument !! \n");

    }
}

int sorb(int num){
int tempID, input;
  
  StockTable(num);
stock:
  printf("\n---------------------------------------------------------------------- \n");
  printf("Stock Management System.\n");
  printf("1. Edit stock of existing products\n");
  printf("2. Add a new product to inventory\n");
  printf("3. Remove a product form inventory\n");
  printf("4. View inventory\n");
  printf("0. Exit\n");
  printf("Enter a choice:- ");
  scanf("%d", &input);
  printf("---------------------------------------------------------------------- \n");

  switch(input) {
    case 4:
    if(num==0){
      printf("Inventory is empty. Please add some products to continue.\n");
      printf("\n----------------------------------------------------------\n");
      goto add;
    }else{
      StockTable(num); 
      printf("\n----------------------------------------------------------\n");
      goto stock;
    }

    case 1:
      edit:
      printf("\nEnter product ID to proceed: ");
      scanf(" %d",&tempID);

      for(int i=0;i<num;i++){

        if(tempID==pr[i].ID){
          pr[i].qty= pr[i].qty + edit_product();
          printf("\nProduct edited succefully.");
          printf("\n----------------------------------------------------------\n");
          StockTable(num);  goto stock;
        }else if(tempID!=pr[i].ID && i==num-1){
          printf("No product with such ID found.\nPlease check the product ID again.\n");
          StockTable(num); goto edit;
        }
      }
    break;

    case 2: printf("\n");
      int *b, *c, *d; char *a;
      add: ;
      pr[num].ID= num+1;
      a = pr[num].Name, b = &pr[num].ID, c=&pr[num].qty, d = &pr[num].MRP ;
      add_product(num,a,b,c,d);
      num++;
      printf("\nProduct added succesfully.");
      printf("\n----------------------------------------------------------\n");
      goto stock;

    case 3:
      remove:
      printf("Enter ID of the product you want to remove: ");
      scanf("%d",&tempID);
      
        for(int i=0;i<num;i++){
          if( tempID==pr[i].ID){
            for(int j=i;j<num;j++){
              strcpy(pr[i].Name,pr[i+1].Name);
              pr[i].ID=pr[i+1].ID;
              pr[i].MRP=pr[i+1].MRP;
              pr[i].qty=pr[i+1].qty;
            }
            num--;
            printf("\nProduct removed succesfully.");
            printf("\n----------------------------------------------------------\n");
          }else if(tempID!=pr[i].ID && i==num-1){
          printf("No product with such ID found.\nPlease check the product ID again.\n");
          StockTable(num); goto remove;
        }
        }
    case 0:
    return num;       
  }
  return num;
}

int tEarnings(int p)
{
    int x;
    x=days1[p];
    return x;
}

int mEarnings(int p)
{
    int x,total;
    total=0;
    while(x<30)
    {
        total=total + days1[x];
        x++;
    }
    return total;
}

void tExpenses(int p,int q)
{
    mprofit[p]=days1[p] - q; 
}

int tProfit(int p)
{
    int x;
    x=mprofit[p];
    return x;
}

int mProfit(int p)
{
    int x,total;
    total=0;
    while(x<30)
    {
        total=total + mprofit[x];
        x++;
    }
    return total;
}

int adi()
{
    int end;
    int menu,tE,mE,tDay,tEx,tP,mP,P;
    char choice;
    end=0;
    while(end==0)
    {
        printf("Welcome to the Revenue Management menu!\n");
        printf("Menu:-\n");
        printf("1. View a specific day's earnings.\n");
        printf("2. View this month's entire earnings.\n");
        printf("3. Input specific day's expenses.\n");
        printf("4. View specific day's profit.\n");
        printf("5. View monthly profit.\n");
        printf("6. Exit.\n");
        printf("Enter your response:- ");
        scanf("%d",&menu);
        printf("--------------------------------------------- \n");
        if(menu==1)
        {
            printf("Enter day of the month:- ");
            scanf("%d",&tDay);
            tE=tEarnings(tDay);
            printf("(%d) day's earnings are %d.\n",tDay,tE);
            printf("--------------------------------------------- \n");
        }
        if(menu==2)
        {
            P=1;
            mE=mEarnings(P);
            printf("This month's entire earnings are %d.\n",mE);
            printf("--------------------------------------------- \n");
        }
        if(menu==3)
        {
            printf("Which day of the month is it today? : ");
            scanf("%d",&tDay);
            printf("Input (%d) day's expenses:- ",tDay);
            scanf("%d",&tEx);
            tExpenses(tDay,tEx);
            printf("--------------------------------------------- \n");
        }
        if(menu==4)
        {
            printf("Which day of the month is it today? : ");
            scanf("%d",&tDay);
            tP=tProfit(tDay);
            printf("(%d) day's profit is %d.\n",tDay,tP);
            printf("--------------------------------------------- \n");
        }
        if(menu==5)
        {
            P=1;
            mP=mProfit(P);
            printf("This month's profit is %d.\n",mP);
            printf("--------------------------------------------- \n");
        }
        if(menu==6)
        {
            printf("Exiting the menu...\n");
            printf("--------------------------------------------- \n");
            end=1;
        }
        if(menu!=6)
        {
            printf("Do you wish to continue(Y/N)? : ");
            scanf(" %c",&choice);
            if((choice!='Y' && choice!='N') && (choice!='y' && choice!='n'))
            {
                printf("Invalid Input.\n");
                printf("Taking you back to the menu options...\n");
                end=0;
            }
            if(choice=='N' || choice=='n')
            {
                printf("Exiting the menu....\n");
                end=1;
            }
            printf("--------------------------------------------- \n");
        }
        
    }    
    return 0;
}

int main() {
    printf("Enter day of the month : ");
    scanf("%d",&monthday);
    printf("---------------------------------------------------------------------- \n");


    strcpy(pr[0].Name,"Maggie Noodles");
    strcpy(pr[1].Name,"Tomato Ketchup");
    strcpy(pr[2].Name,"Peanut Butter Cookies");
    strcpy(pr[3].Name,"Hair Shampoo");
    strcpy(pr[4].Name,"Shaving Cream");
    strcpy(pr[5].Name,"Hand Sanitizer");
    strcpy(pr[6].Name,"KitKat Chocolate");


    pr[0].qty = 250;    pr[0].ID = 1;    pr[0].MRP = 12;
    pr[1].qty = 190;    pr[1].ID = 2;    pr[1].MRP = 30;
    pr[2].qty = 150;    pr[2].ID = 3;    pr[2].MRP = 40;
    pr[3].qty = 200;    pr[3].ID = 4;    pr[3].MRP = 120;
    pr[4].qty = 100;    pr[4].ID = 5;    pr[4].MRP = 70;
    pr[5].qty = 100;    pr[5].ID = 6;    pr[5].MRP = 50;
    pr[6].qty = 120;    pr[6].ID = 7;    pr[6].MRP = 40;
    int num=7;

    int choice;
    project:
    printf("---------------------------------------------------------------------- \n");
    printf("WELCOME TO THE INVENTORY MANAGEMENT SYSTEM\n");
    printf("1. Start shopping\n");
    printf("2. Review product and stock details\n");
    printf("3. Manage revenue and expenses\n");
    printf("0. Exit\n");
    printf("Enter a choice:- ");
    scanf("%d", &choice);
    printf("---------------------------------------------------------------------- \n");

    switch(choice) {
        
        case 1: 
        xyz(num);
        break;

        case 2:
        num = sorb(num);
        break;

        case 3: 
        adi();
        break; 

        case 0:
        printf("Exiting the system...\n");
        printf("---------------------------------------------------------------------- \n");
        return 0;

        default: 
        printf("Invalid Input! Please enter the correct input.");
        goto project;
    }
    goto project;
}