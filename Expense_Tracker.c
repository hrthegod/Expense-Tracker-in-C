#include <stdio.h>
#include <string.h>
#define MAX 100
int amount[MAX];
char category[MAX][50];
int count = 0;
int choice=0;
void showall(){
    if(count == 0){
        printf("No expenses added\n");
    }
    else{
        for(int i=0;i<count;i++){
            printf("\n\n%s\t",category[i]);
            printf("%d\n",amount[i]);
        }
    }
}
void total(){
    int sum=0;
    if(count == 0){
        printf("No expenses added\n");
    }
    else{
    for(int i=0;i<count;i++){
        sum+=amount[i];
    }
    printf("You spent total %d rupees",sum);
    }
}
void highest(){
    if(count == 0){
        printf("No expense added");
    }
    else{
        int maxamount=amount[0];
    int maxindex=0;
        for(int i=1;i<count;i++){
            if(amount[i]>maxamount){
                maxamount=amount[i];
                maxindex=i;
            }
        }
        printf("The max amount was %d in %s category\n",maxamount,category[maxindex]);
    }
}
void filter(){
    if(count == 0){
        printf("No expenses added\n");
    }
    else{
        char target[50];
        int found=0;
        printf("Enter the category you wanna check: ");
        scanf("%s",target);
        for(int i=0;i<count;i++){
            if(strcmp(category[i],target)==0){
                printf("%s\t%d\n",category[i],amount[i]);
                found=1;
            }
        }
        if(found==0){
            printf("No category was found");
        }
    }
}


void expense(){
    if(count >= MAX){
        printf("Storage Full!\n");
        return;
    }
    printf("Enter the category: ");
    scanf("%s", category[count]);
    printf("Enter the amount: ");
    scanf("%d",&amount[count]);
    printf("Alright Expenses added.\n");
    count++;
}
int main(){
    while(1){
        printf("\n\n\n  ====EXPENSE TRACKER====  \n");
        printf("Choose bro:\n");
        printf("1. to add any expense. \n");
        printf("2. to show all expenses. \n");
        printf("3. Your total spendings. \n");
        printf("4. to see your highest expense. \n");
        printf("5. to filter by category. \n");
        printf("6. to exit\n");
        printf("Your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
        expense();
        break;
        case 2:
        showall();
        break;
        case 3:
        total();
        break;
        case 4:
        highest();
        break;
        case 5:
        filter();
        break;
        case 6:
        printf("Exiting...");
        return 0;
        break;
        default:
        printf("Please enter a valid choice from above\n");
        }
    }
}