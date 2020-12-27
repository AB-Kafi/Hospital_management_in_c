#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define BUFFER_SIZE 1000

struct node
{
    char name[50];
    int id;
    int age;
    int cabin;
    char diseases[100];

    struct node *next;
    struct node *previous;
}*first,*last,*t;


void displaynode(struct node *p);

void create(int n)
{
    int i;


    first=(struct node*)malloc(sizeof(struct node));
    {


        printf("Enter name:");
        scanf("%s",&first->name);
        printf("Enter id:");
        scanf("%d",&first->id);
        printf("Enter age:");
        scanf("%d",&first->age);
        printf("Enter cabin no.:");
        scanf("%d",&first->cabin);
        printf("Enter disease:");
        scanf("%s",&first->diseases);
        printf("\n\n");
    }
    first->next=first->previous=NULL;
    last=first;
    for(i=1; i<n; i++)
    {
        t=(struct node*)malloc(sizeof(struct node));


        printf("Enter name:");
        scanf("%s",&t->name);
        printf("Enter id:");
        scanf("%d",&t->id);
        printf("Enter age:");
        scanf("%d",&t->age);
        printf("Enter cabin no.:");
        scanf("%d",&t->cabin);
        printf("Enter disease:");
        scanf("%s",&t->diseases);
        printf("\n\n");

        last->next=t;
        t->previous=last;
        t->next=NULL;
        last=t;

    }

}
int compare_name(char x[],char y[])
{
    int i=0,j=0;
    for(i=0,j=0; x[i]!='\0'|| y[i]!='\0'; i++,j++)
    {
        if(x[i]!=y[j])
            return 1;
    }
    if(x[i]=='\0' && y[j]=='\0')
        return 0;



}

void sarch_name(struct node *p)
{
    char name[100];
    printf("Enter a name to search:");

    scanf("%s",&name);
    //gets(name);

    while(p != NULL)
    {
        char x[50];
        strcpy(x,p->name);
        if(compare_name(name,x)==0);
        {
            printf("RESULT:\n\n");
            printf("Name:%s\n",p->name);
            printf("ID:%d\n",p->id);
            printf("Age:%d\n",p->age);
            printf("Cabin No:%d\n",p->cabin);
            printf("Diseases:%s\n\n\n",p->diseases);
            break;
        }
        p=p->next;
    }
    if(p==NULL)
        printf("No Patient Found\n\n");

}
void sarch_id(struct node *p)
{
    int id;
    printf("Enter a ID to search:");
    scanf("%d",&id);
    while(p != NULL)
    {
        if(id==p->id)
        {
            printf("Name:%s",p->name);
            printf("ID:%d",p->id);
            printf("Age:%d",p->age);
            printf("Cabin No:%d",p->cabin);
            printf("Diseases:%s",p->diseases);
            break;
        }
        p=p->next;
    }

}
void sarch_cabin(struct node *p)
{
    int cabin;
    printf("Enter a Cabin No to search:");
    scanf("%d",&cabin);
    while(p != NULL)
    {
        if(cabin==p->cabin)
        {
            printf("Name:%s",p->name);
            printf("ID:%d",p->id);
            printf("Age:%d",p->age);
            printf("Cabin No:%d",p->cabin);
            printf("Diseases:%s",p->diseases);
            break;
        }
        p=p->next;
    }

}

void bedcount( int x)
{

    printf("%d",(100-x));
}
void otbooking()
{
    int total=3;
    int arr[total];
    char x;
    int i;
    printf("Do you want to book? press Y for yes or N for no:" );
    scanf("%c",&x);
    if(x=='Y')
    {
        for(i=0; i<total; ++i)
        {
            if(arr[i]==0)
            {
                arr[i]=1;
                break;
            }
            printf("OT booking has been booked");
        }
        if(i!=total)
        {
            printf("Total OT %d \n%d OT  are vacant",total,total-(i+1));
        }
        else
        {
            printf("NO vacancy");
        }
    }

}

void display_single(struct node *p)
{
    printf("Name:%s\n",p->name);
    printf("ID:%d\n",p->id);
    printf("Age:%d\n",p->age);
    printf("Cabin No:%d\n",p->cabin);
    printf("Diseases:%s\n",p->diseases);

}


void  records_delete (struct node *p)
{

    int x,next_pre;

    while(p)
    {
        printf("\n\n");
        display_single(p);

         printf("Press 2 for Next Or 3 for Previous or 4 to RETURN:");
            scanf("%d",&next_pre);
        if(next_pre==2)
            p=p->next;
        else
            p=p->previous;


        printf("\n\nDo you want to delete?\n");
        printf("press 1 for YES or 0 No\n\n");


        scanf("%d",&x);
        if(x==1)
        {
            if(p==first)
            {
                if(first->next!=NULL)
                {
                    first=first->next;
                    free(p);
                    first->previous=NULL;
                }
                else
                {
                    printf("\nNo node remains\n");
                    free(p);
                }
            }
            else
            {

                p->previous->next=p->next;
                if(p->next!=NULL)
                p->next->previous=p->previous;
                free(p);

            }
        }
        else if(x==0)
        {
            p=p->next;
            display_single(p);
        }

    }
}

void displaynode(struct node *p)
{
    int x;
    while (p)
    {
        printf("Name:%s\n",p->name);
        printf("ID:%d\n",p->id);
        printf("Age:%d\n",p->age);
        printf("Cabin No:%d\n",p->cabin);
        printf("Diseases:%s\n",p->diseases);

        printf("Press 1 for Next Or 2 for Previous or 3 to RETURN:");
        scanf("%d",&x);
        printf("\n\n");
        if(x==1)
        {
            if(p->next!=NULL)
            {
                p=p->next;

            }
            else
            {
                printf("***No records Ahead***\n\n\n");
                printf("***Current Record is***\n\n");
            }
        }
        if(x==2)
        {
            if(p->previous!=NULL)
            {
                p=p->previous;
            }
            else
            {
                printf("***No records Ahead***\n\n\n");
                printf("***Current Record is***\n\n");
            }
        }
        if(x==3)
            return;

    }

}

void save_data()
{
    struct node *p=first;
    char name[6],id[4],age[5],cabin[10],diseases[12];

    strcpy(name,"Name:");
    strcpy(id,"ID:");
    strcpy(age,"Age:");
    strcpy(cabin,"Cabin No:");
    strcpy(diseases,"Diseases:");

    FILE *fp;
    fp=fopen("patient_list.txt","a+");
    while(p)
    {

        fprintf(fp,"%s %s\n",name,p->name);
        fprintf(fp,"%s %d\n",id,p->id);
        fprintf(fp,"%s %d\n",age,p->age);
        fprintf(fp,"%s %d\n",cabin,p->cabin);
        fprintf(fp,"%s %s\n",diseases,p->diseases);
        fprintf(fp,"\n\n\n");
        p=p->next;
    }
    fclose(fp);
    printf("\n\nData Saved\n\n");

}

void history(int n)
{

    FILE    *fp;
    fp=fopen("patient_list.txt","r");
    char buffer[BUFFER_SIZE];

    int totalRead = 0;

    while( fgets(buffer, BUFFER_SIZE, fp) != NULL)
    {

        totalRead = strlen(buffer);


        buffer[totalRead - 1] = buffer[totalRead - 1] == '\n'  ? '\0' : buffer[totalRead - 1];


        printf("%s\n", buffer);

    }

    fclose(fp);


    return;
}

int main()
{
    int choice,n;

    printf("\t\t\t\t***Hospital Management System***\n\n\n");
    do
    {
        printf("\n\t**Select one option below**\n\n");
        printf("\n\t1.Enter Patient Records");
        printf("\n\t2.search patient by name");
        printf("\n\t3.Search patient by id");
        printf("\n\t4.search patient by Cabin No");
        printf("\n\t5.Delete Patient Record");
        printf("\n\t6.Bed count");
        printf("\n\t7.OT booking");
        printf("\n\t8.See patient Record");
        printf("\n\t9.Save Data");
        printf("\n\t10.Show History");
        printf("\n\t11.Exit");
        printf("\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter number of Patient:");
            scanf("%d",&n);
            printf("\n\n");
            create(n);
            break;
        case 2:
            sarch_name(first);
            break;
        case 3:
            sarch_id(first);
            break;
        case 4:
            sarch_cabin(first);
            break;
        case 5:
            records_delete(first);
            break;
        case 6:
            bedcount(n);
            break;
        case 7:
            otbooking();
            break;
        case 8:
            displaynode(first);
            break;
        case 9:
            save_data();
            break;
        case 10:
            history(n);
            break;
        case 11:
            break;
        default:
            printf("\nEnter correct Choice");


        }
    }
    while(choice!=11);

    return 0;
}
