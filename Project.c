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

struct Member {
    int id;
    char name[50];
    int age;
    float weight;
    float fee;
};

void addMember() {
    struct Member m;
    FILE *fp = fopen("members.txt", "a");

    if (fp == NULL) {
        printf("Error: Cannot open members.txt for writing\n");
        return;
    }

    printf("Enter Member ID: ");
    scanf("%d", &m.id);

    if (m.id <=0) {
        printf ("Error: Invalid ID.Must be positive\n");
        fclose(fp);
        return;
    }

    if(memberExists(m.id)) {
        printf("Error: Member ID already exists\n");
        fclose(fp);
        return;
    }

    printf("Enter Name; ");
    safeInput(m.name,50);
    printd("Enter Age: ");
    scanf("%d", &m.age);
    if (m.age <=0) {
        printf("Error: Invalid age. Must be positive\n");
        fclose(fp);
        return;
    }

    printf("Enter Weight (kg): ");
    scanf("%f", &m.weight);
    if (m.weight <=0) {
        printf("Error: Invalid weight . Must be positive\n");
        fclose(fp);
        return;
    }

    printf("Enter Fee Paid: ");
    scanf("%f", &m.fee);
    if (m.fee <0) {
        printf("Error: Invalid fee. Must be positive\n");
        fclose(fp);
        return;
    }

    fprintf(fp, "%d is %d %.2f\n" , m.id, m.name, m.age, m.weight, m.fee);
    fflush(fp);// Ensurewrite is flushed
    fclose(fp);
    printf("Succes: Member added\n");
}