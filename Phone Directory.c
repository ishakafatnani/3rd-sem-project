/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char phone[50];
    char name[50];
    char email[50];
    char add[50];
    struct node *link;
};
struct node* head=NULL;
struct node *create()
{
    struct node *temp=malloc(sizeof(struct node));
    printf("\nPhone:");
    fflush(stdin);
    scanf("%s",temp->phone);
    printf("\nName:");
    scanf("%s",temp->name);
    printf("\nE-mail:");
    scanf("%s",temp->email);
    printf("\nAddress:");
    scanf("%s",temp->add);
    temp->link=NULL;
    return temp;
}
void insert()
{
    printf("\nEnter the details of the new contact to be created\n");
    printf("---------------------------------------------------------\n");
    struct node *sll=create();
    if(head!=NULL)
        sll->link=head;
    head=sll;
}
void display()
{
    struct node *temp=head;
    if(head==NULL)
        printf("\nNO CONTACTS TO DISPLAY\n");
    else
    {
        while(temp!=NULL)
        {
            fflush(stdout);
            printf("\nPhone:%s",temp->phone);
            printf("\nName:%s",temp->name);
            printf("\nE-mail:%s",temp->email);
            printf("\nAddress:%s",temp->add);
            temp=temp->link;
            printf("\n--------------------------------------------------");
        }
    }
}
void search(char *p)
{
    struct node *temp=head;int flag=0;
    while(temp!=NULL)
    {
        int r=strcmp(temp->phone,p);
        
        if(r==0)
        {
            flag=1;
            printf("Contact found\n");
            printf("\nName:%s",temp->name);
            printf("\nPhone number:%s",temp->phone);
            printf("\nEmail:%s",temp->email);
            printf("\nAddress:%s",temp->add);
            return;
        }
        temp=temp->link;
    }
    if(flag!=1)
        printf("\nNo match found\n");
}
void edit(char * p)
{
    struct node *temp=head;int flag=0;
    while(temp!=NULL)
    {
        int r=strcmp(temp->phone,p);
        if(r==0)
        {
            flag=1;
            printf("\nEnter the details to be edited\n");
            printf("\nName:");
            scanf("%s",temp->name);
            printf("\nPhone number:");
            scanf("%s",temp->phone);
            printf("\nE-mail:");
            scanf("%s",temp->email);
            printf("\nAddress:");
            scanf("%s",temp->add);
            printf("\nContact edited successfully\n");
            return;
        }
        temp=temp->link;
    }
    if(flag!=1)
        printf("\nNo contact match found to edit\n");
}
void del(char * p)
{
    
    struct node *temp=head;int flag=0;struct node *prev;struct node *next;
    prev=head;
    while(temp!=NULL)
    {
        next=temp->link;
        int r=strcmp(temp->phone,p);
        if(r==0)
        {
            if(temp==head)
            {
                flag=1;
                printf("1st case");
                printf("\nName:%s",temp->name);
                printf("\nPhone:%s",temp->phone);
                printf("\nE-mail:%s",temp->email);
                printf("\nAddress:%s",temp->add);
                printf("\nThe following contact is deleted");
                head=temp->link;
                free(temp);
                return;
            }
            else if(temp->link==NULL)
            {
                flag=1;
                printf("\nName:%s",temp->name);
                printf("\nPhone:%s",temp->phone);
                printf("\nE-mail:%s",temp->email);
                printf("\nAddress:%s",temp->add);
                printf("\nThe following contact is deleted");
                prev->link=NULL;
                free(temp);
                return;
            }
            else
            {
                flag=1;
                printf("1st case");
                printf("\nName:%s",temp->name);
                printf("\nPhone:%s",temp->phone);
                printf("\nE-mail:%s",temp->email);
                printf("\nAddress:%s",temp->add);
                printf("\nThe following contact is deleted");
                prev->link=next;
                free(temp);
                return;
            }
        }
        prev=temp;
        temp=temp->link;
    }
     printf("\nNO MATCH FOUND\n");
}
int main()
{
    int c;struct node *re;char p[50];
    while(1)
    {
        printf("\n1.Add a contact\n2.Display contacts\n3.Search a contact\n4.Edit a contact\n5.Delete a contact\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("\nEnter the phone number to be searched\n");
                scanf("%s",p);
                
                search(p);
                break;
            case 4:
                printf("\nEnter the phone number of the contact to be edited:");
                scanf("%s",p);
                edit(p);
                break;
            case 5:
                printf("\nEnter the phone number of the contact to be deleted:");
                scanf("%s",p);
                del(p);
                break;
            
            default:
                exit(0);
        }
    }
    return 0;
}








