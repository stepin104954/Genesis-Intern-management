#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<process.h>

#include<stdlib.h>

#include<dos.h>

struct Intern

{

    long ph;
    long PSid;

    char name[20],loc[20],add[20],email[30];

} list;

char query[20],name[20];

FILE *fp, *ft;

int i,n,ch,l,found;

int main()

{

main:

    system("cls");

    printf("\n\t  LTTS GENESIS INTERNSHIP PROGRAM ");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t||||||||||||||||||||\n\t\t[1] Add Intern Name \n\t\t[2] Intern List\n\t\t[3] Search Intern \n\t\t[4] Edit \n\t\t[5] Delete \n\t\t[0] Exit\n\t\t||||||||||||||||||||\n\t\t");

    printf("Enter the choice:");

    scanf("%d",&ch);

    switch(ch)

    {

    case 0:

        printf("\n\n\t\tDo you want to exit?");

        break;


    case 1:

        system("cls");

        fp=fopen("Intern.dll","a");

        for (;;)

        {
            fflush(stdin);

            printf("To exit press enter in the name input\nName :");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)

                break;

            fflush(stdin);

            printf("Phone:");

            scanf("%ld",&list.ph);

            fflush(stdin);

            printf("PSid:");

            scanf("%ld",&list.PSid);

            fflush(stdin);

            printf("Location:");

            scanf("%[^\n]",&list.loc);

            fflush(stdin);

            printf("Address:");

            scanf("%[^\n]",&list.add);

            fflush(stdin);

            printf("email address:");

            gets(list.email);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);

        break;



    case 2:

        system("cls");

        printf("\n\t\t\n\t\t\tLIST OF INTERNS\n\t\t\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("Intern.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name,

                           list.ph,list.add,list.email);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }

        break;



    case 3:

        system("cls");

        do

        {

            found=0;

            printf("\n\n\t..::Intern SEARCH\n\t===========================\n\t..::Name of Intern to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("Intern.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\n",list.name,list.ph,list.add,list.email);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        break;

    case 4:

        system("cls");

        fp=fopen("Intern.dll","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Editing '%s'\n\n",name);

        printf("..::Name:");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("..::Phone:");

        scanf("%ld",&list.ph);

        fflush(stdin);

        printf("..::address:");

        scanf("%[^\n]",&list.add);

        fflush(stdin);

        printf("..::email address:");

        gets(list.email);

        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("Intern.dll");

        rename("temp.dat","Intern.dll");

        break;



    case 5:

        system("cls");

        fflush(stdin);

        printf("\n\n\t..::DELETE A Intern\n\t==========================\n\t..::Enter the name of Intern to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("Intern.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("Intern.dll");

        rename("temp.dat","Intern.dll");

        break;

    default:

        printf("Invalid choice");

        break;

    }

    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

    scanf("%d",&ch);

    switch (ch)

    {
        case 1:

        goto main;

    case 0:

        break;

    default:

        printf("Invalid choice");

        break;

    }
    return 0;

}
