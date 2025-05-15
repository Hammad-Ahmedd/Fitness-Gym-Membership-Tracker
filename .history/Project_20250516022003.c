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
    FILE *fp=fopen("member.txt","r");
    if (fp=NULL)return 0;
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
    printf("\n Enter member ID to delte:");
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
        printf("Member not found.\n");
    }
    
void updateMemberInfo(){
    printf("NOt yet implementsss\n");
}
void addDietPlan(){
    printf("NOt yet implement\n");
}
void viewDietplan(){
    printf("NOt yet implement\n");
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