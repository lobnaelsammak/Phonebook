#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct address
{
    char street[50];
    int flat;
    char city[20];

} address;
typedef struct contact
{
    char first_name[20];
    char last_name[20];
    address a;
    long number;
    char email[20];
} contact;
contact c[100];
int v=0;
int Load();
void search(int n);
int ADD(int n);
void Modify(int n);
int Delete(int n);
void sort(int n);
void save(int n);
void quit(int n);
int main()
{
    char z;
    int n,H;
    n=Load();
    printf("\t\t\t\t\t\t Phone Book\n\t\t\t\t\t\t************\n");

    while(1)
    {
        printf("To Search for a contact'F':\nTo ADD a contact'A':\nTo Modify a contact'M':\nTo Delete a contact'D':\nFor sorting'S':\nTo save'v':\nTo Exit from phone Book'Q':\n");
        scanf("%c",&z);
        switch(z)
        {
        case'F':
            search(n);
            break;
        case'A':
            n=ADD(n);
            break;
        case'M':
            Modify(n);
            break;
        case'D':
            n=Delete(n);
            break;
        case'S':
            sort(n);
            break;
        case'v':
            save(n);
            break;
        case'Q':
            quit(n);
            break;
        default:
            break;
        }


        printf("\t\t\t\t************************************************\t\n");
    }


    return 0;
}
int Load()
{
    FILE *f;
    int x=0;
    f=fopen("source.txt","r");
    if(f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%[^,],%[^,],%[^,],%d,%[^,],%ld,%s\n",c[x].first_name,c[x].last_name,c[x].a.street,&c[x].a.flat,c[x].a.city,&c[x].number,c[x].email);
            x++;
        }
        fclose(f);
        return x;
    }
    else
        printf("Error in reading\n");
}
void search(int n)
{
    char name[20];
    int i,o=0;
    printf("Search for:\n");
    scanf("%s",name);
    printf("%-30s%-30s%-30s%-30s%-30s%-30s%-30s\n","FIRST NAME","LAST NAME","STREET","FLAT","CITY","NUMBER","EMAIL");
    for(i=0; i<n; i++)
    {
        if(!strcmp(name,c[i].first_name))
        {
            printf("%-30s%-30s%-30s%-30d%-30s%-30d%-30s\n",c[i].first_name,c[i].last_name,c[i].a.street,c[i].a.flat,c[i].a.city,c[i].number,c[i].email);
            o=1;
        }
    }
    if(o==0)
        printf("Contact Not found.\n");
}
int ADD(int n)
{
    contact Add;
    printf("First name:\n");
    scanf("%s",Add.first_name);
    printf("Last name:\n");
    scanf("%s",Add.last_name);
    printf("Street:\n");
    scanf("%s",Add.a.street);
    printf("Flat number:\n");
    scanf("%d",&Add.a.flat);
    printf("City:\n");
    scanf("%s",Add.a.city);
    printf("Phone number:\n");
    scanf("%ld",&Add.number);
    printf("E-mail:\n");
    getchar();
    scanf("%s",Add.email);
    c[n]=Add;
    n++;
    v=1;
    return n;
}

void Modify(int n)
{
    int k,i;
    char w;
    char F[20];
    char L[20];
    printf("Enter first name:\n");
    scanf("%s",F);
    printf("Enter Last name:\n");
    scanf("%s",L);

    for(i=0; i<n; i++)
    {
        if(!strcmp(F,c[i].first_name) && !strcmp(L,c[i].last_name))
            k=i;
    }
    contact modify;
    printf("Do you want to edit First name'Y'or'N':\n");
    getchar();
    scanf("%c",&w);
    if(w=='Y')
    {
        printf("First name:\n");
        getchar();
        scanf("%s",modify.first_name);
    }

    printf("Do you want to edit Last name'Y'or'N':\n");
    getchar();
    scanf("%c",&w);
    if(w=='Y')
    {
        printf("Last name:\n");
        scanf("%s",modify.last_name);
    }

    printf("Do you want to edit Street'Y'or'N':\n");
    getchar();
    scanf("%c",&w);
    if(w=='Y')
    {
        printf("street:\n");
        scanf("%s",modify.a.street);
    }

    printf("Do you want to edit Flat number'Y'or'N':\n");
    getchar();
    scanf("%c",&w);
    if(w=='Y')
    {
        printf("Flat number:\n");
        scanf("%d",&modify.a.flat);
    }

    printf("Do you want to edit City'Y'or'N':\n");
    getchar();
    scanf("%c",&w);
    if(w=='Y')
    {
        printf("City:\n");
        scanf("%s",modify.a.city);
    }

    printf("Do you want to edit Phone number'Y'or'N':\n");
    getchar();
    scanf("%c",&w);
    if(w=='Y')
    {
        printf("Phone number:\n");
        scanf("%ld",&modify.number);
    }

    printf("Do you want to edit E-mail'Y'or'N':\n");
    getchar();
    scanf("%c",&w);
    if(w=='Y')
    {
        printf("E-mail:\n");
        scanf("%s",modify.email);
    }

    c[k]=modify;
    v=1;



}
int Delete(int n)
{
    int i,k,u=0;
    char f[20];
    char l[20];
    printf("First name of the contact to delete:\n");
    scanf("%s",f);
    printf("Last name of the contact to delete:\n");
    scanf("%s",l);
    for(i=0; i<n; i++)
    {
        if(!strcmp(f,c[i].first_name) && !strcmp(l,c[i].last_name))
        {
            k=i;
            u=1;
        }
    }
    if(u==1)
    {
        for(i=k; i<n; i++)
        {
            c[i]=c[i+1];
        }
        n--;
        v=1;
        return n;
    }
    else
        printf("Contact not found");
}
void sort(int n)
{

    int i,j,x,z,k,p,r;
    contact t,y;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i; j++)
        {
            x=strcmp(c[j].first_name,c[j+1].first_name);
            if(x>0)
            {
                t=c[j];
                c[j]=c[j+1];
                c[j+1]=t;
                v=1;
            }
            else if(x==0)
            {
                x=strcmp(c[j].last_name,c[j+1].last_name);
                if(x>0)
                {
                    t=c[j];
                    c[j]=c[j+1];
                    c[j+1]=t;
                    v=1;
                }
            }
        }
    }

    printf("%-30s%-30s%-30s%-30s%-30s%-30s%-30s\n","FIRST NAME","LAST NAME","STREET","FLAT","CITY","NUMBER","EMAIL");
    for(i=0; i<n; i++)
        printf("%-30s%-30s%-30s%-30d%-30s%-30d%-30s\n",c[i].first_name,c[i].last_name,c[i].a.street,c[i].a.flat,c[i].a.city,c[i].number,c[i].email);

}
void save(int n)
{
    int B;
    FILE *f1;
    f1=fopen("source.txt","w");
    if(f1!=NULL)
    {
        for(B=0; B<n; B++)
        {
            fprintf(f1,"%s,%s,%s,%d,%s,%ld,%s\n",c[B].first_name,c[B].last_name,c[B].a.street,c[B].a.flat,c[B].a.city,c[B].number,c[B].email);
        }
        fclose(f1);
    }
    else
        printf("Error in saving\n");


}
void quit(int n)
{int f;
    if(v==1)
        {printf("WARNING! the changes will be discarded.\n");
        printf("To save'1'To quit'0'\n");
        scanf("%d",&f);
        if(f==1)
            save(n);
        else
            exit(0);}

    else
        exit(0);

}
