#include<stdio.h>

/// functions
void addMember();
void viewAllMember();
void updateMemberInfo();
void addDietPlan();
void viewDietplan();
void searchMember();

int main(){
int choice;
while(1){
    printf("====================== Fitness Gym Membership Tracker & Diet Logger Menu ===============\n");
    printf("01) Add New Member\n");
    printf("02) View All Members\n");
    printf("03) Update Member Information\n");
    printf("04) Add Diet Plan\n");
    printf("05) View Diet Plan\n");
    printf("06) Search Member by ID\n");
    printf("07) Exit\n");
    printf("Enter Choice Between (1to7)\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:addMember();break;
    case 2:viewAllMember();break;
    case 3:updateMemberInfo();break;
    case 4:addDietPlan();break;
    case 5:viewDietplan();break;
    case 6:searchMember();break;
    case 7:return 0;break;
    default: printf("Choice not found please select between (1to7)") ;break;
    }
}
    return 0;
}