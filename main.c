#include <stdio.h>
#include <string.h>

int option,account_nb_to_enter,amount_plus_minus,indexid ;
int account_counter=0;
char bank_account_name[100][30];
char bank_account_last_name[100][30];
char bank_account_id[100][30];
double  bank_account_amount[100];
char tmp[30];
int flag=0;
float percentage_to_add;
//functions
void space(){
    for(int i = 0 ; i <50 ; i++){
        printf("\n");
    }
}
void miniSpace(){
    printf("\n\n\n\n\n");
}
void normal_print(int start,int condition){
    printf("_________________________________________________________________________________________\n");
    for(int i=start;i<condition;i++){
        printf("|\t%10s|\t%10s\t|\t%10s\t|\t%11.2f\t|\n", bank_account_last_name[i],bank_account_name[i], bank_account_id[i], bank_account_amount[i]);
    }
    printf("|________________________________________________________________________________________|\n\n");
}
void Ascending_Order(){
    int copy_of_account_counter = 0;
    copy_of_account_counter = account_counter;

    while (copy_of_account_counter > 0) {
        char save_name[30];
        char save_last_name[30];
        char save_id[30];
        int max = bank_account_amount[0];
        int max_index = 0;
      
        // this loop for finding max value and storing max value 
        for (int i = 0; i < copy_of_account_counter; i++) {
            if (bank_account_amount[i] > max) {
                max = bank_account_amount[i];
                max_index = i;
            }
            // this loop for storing the information having the same index of max  
            for (int j = 0; j < 30; j++) {
                save_name[j] = bank_account_name[max_index][j];
                save_id[j] = bank_account_id[max_index][j];
                save_last_name[j]= bank_account_last_name[max_index][j];
            }

        }
        //storing the value in the previous cases
        for (int i = max_index; i < copy_of_account_counter; i++) {
            bank_account_amount[i] = bank_account_amount[i + 1];
            for (int j = 0; j < 30; j++) {
                bank_account_id[i][j] = bank_account_id[i + 1][j];
                bank_account_name[i][j] = bank_account_name[i + 1][j];
                bank_account_last_name[i][j] = bank_account_last_name[i + 1][j];
            }
        }
        //storing the max value in the last case of the array
        bank_account_amount[copy_of_account_counter - 1] = max;
        for (int j = 0; j < 30; j++) {
            bank_account_id[copy_of_account_counter - 1][j] = save_id[j];
            bank_account_name[copy_of_account_counter - 1][j] = save_name[j];
            bank_account_last_name[copy_of_account_counter - 1][j] = save_last_name[j];
        }
        copy_of_account_counter--;
        printf("\n");
    }

}
void Descending_Order(){
    int copy_of_account_counter = account_counter;

    while (copy_of_account_counter > 0) {
        char save_name[30];
        char save_last_name[30];
        int min = bank_account_amount[0];
        int min_index = 0;
        char save_id[30];
        // this loop for finding max value and storing max value 
        for (int i = 0; i < copy_of_account_counter; i++) {
            if (bank_account_amount[i] < min) {
                min = bank_account_amount[i];
                min_index = i;
            }
            for (int j = 0; j < 30; j++) {
                save_name[j] = bank_account_name[min_index][j];
                save_last_name[j] = bank_account_last_name[min_index][j];
                save_id[j] = bank_account_id[min_index][j];
            }

        }
        // this loop for storing the information having the same index of max  
        for (int i = min_index; i < copy_of_account_counter; i++) {

            bank_account_amount[i] = bank_account_amount[i + 1];
            for (int j = 0; j < 30; j++) {
                bank_account_id[i][j] = bank_account_id[i + 1][j];
                bank_account_name[i][j] = bank_account_name[i + 1][j];
                bank_account_last_name[i][j] = bank_account_last_name[i + 1][j];
            }
        }
        //storing the max value in the last case of the array
        bank_account_amount[copy_of_account_counter - 1] = min;

        for (int j = 0; j < 30; j++) {
            bank_account_id[copy_of_account_counter - 1][j] = save_id[j];
            bank_account_name[copy_of_account_counter - 1][j] = save_name[j];
            bank_account_last_name[copy_of_account_counter - 1][j] = save_last_name[j];
        }
        copy_of_account_counter--;
        printf("\n");
    }

}
int searchById(){
    char search_id[30];
    int index_id;
    do {
        printf("please enter the id of the client :");
        scanf("%s", &search_id);

        for (int i = 0; i < account_counter; i++) {

            for (int j = 0; j < 30; j++) {
                tmp[j] = bank_account_id[i][j];
            }
            if (strcmp(tmp, search_id) == 0) {
                printf("your id exist\n");
                flag = 1;
                index_id = i;
                break;
            }
        }
        if (flag == 0) {
            printf("This id doesn't exist\n");
        }
    }while(flag==0);


    return index_id;
}
void account_entry(){


    printf("please enter the id of the client.\n");
    scanf("%s",&bank_account_id[account_counter]);
    printf("please enter the name of the client.\n");
    scanf("%s",&bank_account_name[account_counter]);
    printf("please enter the last name of the client.\n");
    scanf("%s",&bank_account_last_name[account_counter]);
    printf("please enter the balance of the client.\n");
    scanf("%lf",&bank_account_amount[account_counter]);
    account_counter++;
}
void print_main_menu(){
    miniSpace();
    printf("\n\n---------------------------------MAIN MENU-----------------------------\n");
    printf("\t1.Create a bank account (CIN, Name and Surname, Amount).\n");
    printf("\t2.Create several bank accounts (CIN, Name and Surname, Amount).\n");
    printf("\t3.Operations.\n");
    printf("\t4.Display.\n");
    printf("\t5.Customer Loyalty.\n");
    printf("\t0.Quit.\n");
    printf("----------------------------------------------------------------------\n");
}
void display_menu(){
    miniSpace();
    printf(" 1-In Ascending Order\n");
    printf(" 2-By Descending Order\n");
    printf(" 3-By Ascending Order from an entered amount\n");
    printf(" 4-By Descending Order from an entered amount\n");
    printf(" 5-Search by ID \n");
}
//main function
int main() {
    do{
        print_main_menu();
        printf("\n Choose your option : ");
        scanf("%d",&option);
        switch(option){
            case 1 :{

                space();
                printf("\t===============================");
                printf("\n\t\tCreate an account ");
                printf("\n\t===============================\n");
                account_entry();
                break;
            }
            case 2 :{
                space();
                printf("\t===============================");
                printf("\n\t\tCreate an account ");
                printf("\n\t===============================\n");
                printf("Enter how many accounts you want to enter: ");
                scanf("%d",&account_nb_to_enter);
                for(int i=0; i < account_nb_to_enter; i++){
                    miniSpace();
                    printf("Enter details of account number %d :\n",i+1);
                    account_entry();
                }
                break;
            }
            case 3:{
                printf("1-withdrawal.\n");
                printf("2-deposit.\n");
                printf("please enter your option :");
                scanf("%d", &option);

                switch (option) {
                    case 1 :{
                        indexid = searchById();
                        if (flag==1){
                            printf("the client is |%10s|\t%10s\t|\t%10s\t|\t%8.2lf\t|\n",bank_account_name[indexid],bank_account_last_name[indexid], bank_account_id[indexid], bank_account_amount[indexid]);
                            printf("please enter the amount you want to withdraw :");
                            scanf("%d", &amount_plus_minus);
                            bank_account_amount[indexid] -= amount_plus_minus;
                            printf("the new amount is %.2lf\n", bank_account_amount[indexid]);
                            flag=0;
                        }
                        break;
                    }
                    case 2 :{
                        indexid=searchById();
                        if (flag==1) {
                            printf("please enter the amount you want to add :");
                            scanf("%d", &amount_plus_minus);
                            bank_account_amount[indexid] += amount_plus_minus;
                            printf("the new amount is %.2lf", bank_account_amount[indexid]);
                            flag=0;
                        }
                        break;
                    }
                }
                break;}
            case 4 :

            {
                display_menu();
                printf("\n Choose your option : ");
                scanf("%d",&option);
                switch (option) {
                    case 1 : { // In Ascending Order
                        Ascending_Order();
                        normal_print(0,account_counter);
                        break;
                    }
                    case 2 :{
                        // Descending Order{
                        Descending_Order();
                        normal_print(0,account_counter);
                        break;
                    }
                    case 3 : {
                        int amount_search;
                        int amount_search_index;
                        Ascending_Order();
                        do {
                            printf("please enter the amount you want to search from :");
                            scanf("%d", &amount_search);

                            for (int k = 0; k < account_counter; k++) {
                                if (bank_account_amount[k] == amount_search) {
                                    amount_search_index = k;
                                    flag=1;
                                    break;
                                }
                            }
                            if(flag==0)
                            {printf("the amount does not exist\n");}
                            else
                            {
                                normal_print(amount_search_index, account_counter);
                            }

                        }while(flag==0);
                        flag=0;
                        break;
                    }
                    case 4 : {
                        Descending_Order();
                        int amount_search;
                        int amount_search_index;

                        do {
                            printf("please enter the amount you want to search from :");
                            scanf("%d", &amount_search);

                            for (int k = 0; k < account_counter; k++) {
                                if (bank_account_amount[k] == amount_search) {
                                    amount_search_index = k;
                                    flag=1;
                                    break;
                                }
                            }
                            if(flag==0)
                            {printf("the amount does not exist\n");}
                            else {
                                normal_print(0, amount_search_index);
                            }

                        }while(flag==0);
                        flag=0;
                        break;
                    }
                    case 5 : {
                        searchById();
                        normal_print(indexid,indexid+1);
                        flag=0;
                        break;
                    }
                }
                break;
            }
            case 5 : {
                Descending_Order();
                for (int i = 0; i < 3 ; i++) {
                    percentage_to_add = 0;
                    percentage_to_add = (bank_account_amount[i] * 1.3) / 100;
                    bank_account_amount[i] += percentage_to_add;
                }
                printf(" ____________________________________________________________________________\n");
                for(int i=0;i<3;i++){printf("|\t%10s|\t%10s\t|\t%10s\t|\t%11.2f\t|\n", bank_account_last_name[i],bank_account_name[i], bank_account_id[i], bank_account_amount[i]);
                }
                printf("|____________________________________________________________________________|\n\n");
                break;
            }
        }
    }while (option!=0);

    return 0 ;
}
