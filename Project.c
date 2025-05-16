#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/// functions
void addMember();
void viewAllMember();
void updateMemberInfo();
void addDietPlan();
void viewDietplan();
int memberExists(int id);
void deleteMember();

struct Member
{
    int id;
    char name[100];
};
struct Diet
{
    int memberId;
    char date[20];
    char Breakfast[100];
    char Lunch[100];
    char Dinner[100];
    char calories[100];
};

int memberExists(int id){
    FILE *fp=fopen("members.txt","r");
    if (fp==NULL)return 0;
    struct Member m;
    while(fread (&m,sizeof(struct  Member),1 ,fp)){
        if(m.id==id){
         fclose(fp);
         return 1;
        }
    }
fclose(fp);
return 0;

}
void addMember(){
    FILE *fp=fopen("members.txt","a");
    if(fp==NULL){
        printf("Error Opening File.\n");
        return;
    }
    struct Member m;
    printf("\n====Add Member====\n");
    printf("Enter member Id: ");
    scanf("%d",&m.id);
    if(memberExists(m.id)){
        printf("Member with Id %d already exists!\n",m.id);
        fclose(fp);
        return;
    }
    printf("ENter member Name: ");
    scanf("%s",m.name);
    fwrite(&m, sizeof(struct Member),1,fp);
        fclose(fp);
        printf("Member add successfully!\n");
}
void viewAllMember(){
    FILE *fp =fopen("members.txt","r");
    if(fp == NULL){
        printf("NO member founded .\n");
        return;
    }
    struct Member m;
    printf("\n---Member List---\n");
     while(fread(&m,sizeof(struct Member),1,fp)){
        printf("ID:%d , Name %s\n",m.id,m.name);
     }
      fclose(fp);
}
void deleteMember(){
    int id;
    printf("\n Enter member ID to deleted:");
    scanf("%d",&id);

    FILE* fp = fopen("members.txt","r");

    FILE*temp = fopen("temp.txt","w");

    struct Member m;
    int found = 0;

    while (fread(&m,sizeof(struct Member),1,fp)){
        if(m.id !=id){
            fwrite(&m,sizeof(struct Member),1,temp);}
            else{
                found = 1;
            }

        }
        fclose(fp);
        fclose(temp);

        remove("members.txt");
        rename("temp.txt","members.txt");
        if (found)
        printf("Member deleted.\n");
        else
        printf("Member not founded.\n");
    }
    

void addDietPlan(){
    FILE *fp=fopen("diet.txt","a");
    if (fp==NULL){
        printf("Error opeining in file\n");
        return;
    }
    struct Diet d;
    printf("=====Add diet Plan=====\n");
    printf("Enter member Id: ");
    scanf("%d",&d.memberId);
    if(!memberExists(d.memberId)){
        printf("Member with Id %d does not exists!\n",d.memberId);
        fclose(fp);
        return;
    }
    printf("Enter Date (YYY-MM-DD)\n");
    scanf("%s",d.date);
    getchar();
    printf("Enter Breakfast details: ");
    scanf("%[^\n]",d.Breakfast);
    getchar();
    printf("Enter Lunch details: ");
    scanf("%[^\n]",d.Lunch);
    getchar();
    printf("Enter dinner details: ");
    scanf("%[^\n]",d.Dinner);
    getchar();
    printf("Enter total Calories: ");
    scanf("%[^\n]",d.calories);
    getchar();
    fwrite(&d, sizeof(struct Diet),1,fp);
    fclose(fp);
    printf("Diet plan added successfully!\n");
}
void viewDietplan(){
    FILE*fp = fopen("diet.txt","r");
    if(fp == NULL){
        printf("No diets plans found.\n");
        return;
    }
    struct Diet d;
    printf("\n--- Diet Plans ---\n");
    while (freed(&d,sizeof(struct Diet), 1, fp)){
        printf("Member ID: %d\n", d.memberId);
        printf("Date: %s\n", d.date);
        printf("Breakfast: %s\n", d.Breakfast);
        printf("Lunch: %s\n", d.Lunch);
        printf("Dinner: %s\n", d.Dinner);
        printf("Calories: %s\n", d.calories);
        printf("---------------------------")
    }
    fclose(fp);
}
void updateMemberInfo(){
    printf("NOt yet implementsss\n");
}


int main(){
int choice;
while(1){
    printf("====================== Fitness Gym Membership Tracker & Diet Logger Menu ===============\n");
    printf("01) Add New Member\n");
    printf("02) View All Members\n");
    printf("03) Update Member Information\n");
    printf("04) Add Diet Plan\n");
    printf("05) View Diet Plan\n");
    printf("06) Delete Member\n");
    printf("07) Exit\n");
    printf("Enter Choice Between (1to7): ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:addMember();break;
    case 2:viewAllMember();break;
    case 3:updateMemberInfo();break;
    case 4:addDietPlan();break;
    case 5:viewDietplan();break;
    case 6:deleteMember();break;
    case 7:return 0;break;
    default: printf("Choice not found please select between (1to7)") ;break;
    }
}
    return 0;
}