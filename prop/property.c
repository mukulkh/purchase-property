#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
FILE *fp;
FILE *pf;
FILE *pf2;
void Delet(int,int,int);
void Del();
void delet_a();
void apply();
void Property();
void property_details();
void applicant_details();
void display_a();
void display_p();
void display_id();
void Applicant();
void report_a();
void report_p();
 COORD coord={0,0}; // this is global variable
                                    //center of axis is set to the top left cornor of the screen
            void gotoxy(int x,int y)
 {
 coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }//set the position of text in compile screen

    struct element
{
int d;
int m;
int y;
char name[50];
char fname[50];
char age[50];
char gender[50];
char address[50];
char pcard[50];
char bank[50];
char branch[50];
char coc[50];
char property[50];
char id[20];
}applicant;

    struct elements //propertyid //location code //location name// no. of flats // area //initial payment. //price
{
int d;
int y;
int m;
char pid[50];
char lcode[50];
char lname[50];
char nof[50];
char area[50];
char ipayment[50];
char price[50];
}property;

    void type()
{
int n;
do{
system("cls");
gotoxy(10,9);
printf("     ************************************************* ");
gotoxy(10,10);
printf("     *                     Welcome                   * ");
gotoxy(10,11);
printf("     *       Government Housing Management System    * ");
gotoxy(10,12);
printf("     *                  1. Applicant Details         * ");
gotoxy(10,13);
printf("     *                  2. Property Details          * ");
gotoxy(10,14);
printf("     *                  3. Exit                      * ");
gotoxy(10,15);
printf("     ************************************************* ");
gotoxy(20,17);
printf("Please Enter Your Option < 1 / 2 / 3 >:");
scanf("%d",&n);

switch(n)
{
case 1:Applicant();
break;
case 2:Property();
break;
case 3:exit(0);
break;
default:printf("\n Error wrong number is entered\n please try again");

}
}
while(n!=3);

}

	int main(void)
{
int ch,n;
system("cls");
system("COLOR 79");

system("cls");
gotoxy(20,8);
    printf("***************************************************");
gotoxy(20,9);  printf("*");    gotoxy(70,9);    printf("*");
gotoxy(20,10); printf("*");   gotoxy(70,10);  printf("*");
gotoxy(20,11); printf("*");   gotoxy(70,11);  printf("*");
gotoxy(20,12); printf("*");   gotoxy(70,12);  printf("*");
gotoxy(20,13); printf("*");
gotoxy(27,13);
    printf("Government Housing Management System ");
gotoxy(70,13);  printf("*");
gotoxy(20,14); printf("*");   gotoxy(70,14);  printf("*");
gotoxy(20,15); printf("*");   gotoxy(70,15);  printf("*");
gotoxy(20,16); printf("*");   gotoxy(70,16);  printf("*");
gotoxy(20,17); printf("*");   gotoxy(70,17);  printf("*");
gotoxy(20,18);
    printf("***************************************************\n");
printf("\n\t\t\t\t press any key for continue...");
getch();
type();

}

    void Applicant()
{

    int i;
    while(1)
{
    system("cls");
    gotoxy(22,9);
    printf("---------- Hello User ----------");
    gotoxy(24,11);
    printf("1:Add applicant details\n\t\t\t2:Delete\n\t\t\t3.Display by ID\n\t\t\t4:Display all the applicant\n\t\t\t5.Report\n\t\t\t6:Back");
    printf("\n\n\t\t\t");
    printf("   enter your choice=");
    fflush(stdin);
    scanf("%d",&i);
    switch(i)
    {
        case 1:applicant_details();
        break;
        case 2:delet_a();
        break;
        case 3:display_id();
        break;
        case 4:display_a();
        break;
        case 5:report_a();
        break;
        case 6:type();
        break;
        default:printf("wrong option=");
    }

}
}

    void Property()
{
    int i;
    while(1)
{
       system("cls");
       gotoxy(22,9);
    printf("----------- Property ----------");

    gotoxy(24,11);
    printf("1:Add property details\n\t\t\t2:Display the property\n\t\t\t3.Delete property\n\t\t\t4:Apply\n\t\t\t5.Report\n\t\t\t6:Back");

    gotoxy(28,18);
    fflush(stdin);
    printf("Enter you choice=");
    scanf("%d",&i);
    switch(i)
    {
        case 1:property_details();
        break;
        case 2:display_p();
        break;
        case 3:Del();
        break;
        case 4:apply();
        break;
        case 5:report_p();
        break;
        case 6:type();
        break;
        default:printf("wrong option=");
    }

}
}

    void applicant_details()
{
system("cls");

int i=0,som=0;
char cha=0;
fp=fopen("mukula.txt","ab+");

gotoxy(22,7);
printf(" ----------- Add new applicant details ----------");
printf("\n\n\t\t\t    Please enter the following applicant details.");
a:
    fflush(stdin);
printf("\n\n\t\t\t Applicant Name: ");
gets(applicant.name);
for(i=0; applicant.name[i]!='\0';i++)
    {
	if(isalpha(applicant.name[i]))
	{

	}
	else
    {
	printf("\n\t\t\tNot a valid name");
	goto a;
	}
	}

b:
printf("\n\t\t\t Fathers Name: ");
fflush(stdin);
gets(applicant.fname);
for(i=0; applicant.fname[i]!='\0';i++)
	{
	if(isalpha(applicant.fname[i]))
	{

	}
	else
    {
	printf("\n\t\t\tNot a valid father name");
	goto b;
	}
	}
e:
    fflush(stdin);
printf("\n\n\t\t\t Property ID : ");
gets(applicant.id);
for(i=0; applicant.id[i]!='\0';i++)
   {
	if(isalpha(applicant.id[i]))
    {
	printf("\n\t\t\tNot a valid id");
	goto e;
	}
	}
pf= fopen("mukulp.txt","rb+");
som=0;
    while(fread(&property,sizeof(property),1,pf)==1)
{
    if(strcmp(property.pid,applicant.id)==0)
    {
     som= 1;
    }
}
    if(som==0)
    {
        cha=0;
        printf("\n\t\t\t Not a valid id");
        fflush(stdin);
        printf("\n\t\t\t you want to continue <y or n> :");
        scanf("%c",&cha);
        if(cha=='y' || cha=='Y')
            goto e;
        else
            Applicant();
    }
fclose(pf);

c:
    fflush(stdin);
printf("\n\t\t\t Age: ");
gets(applicant.age);
for(i=0; applicant.age[i]!='\0';i++)
	{
	if(isalpha(applicant.age[i]))
    {
	printf("\n\t\t\tNot a valid age");
	goto c;
	}
	}
d:
fflush(stdin);
printf("\n \n\t\t\t Gender: ");
scanf("%s",applicant.gender);
for(i=0; applicant.gender[i]!='\0';i++)
	{
	if(isalpha(applicant.gender[i]))
	{

	}
	else
    {
	printf("\n\t\t\tNot a valid gender");
	goto d;
	}
	}

printf("\n\t\t\t Address: ");
fflush(stdin);
gets(applicant.address);

f:
printf("\n\t\t\t Pan Card Number: ");
gets(applicant.pcard);
for(i=0; applicant.pcard[i]!='\0';i++)
{
if(isalpha(applicant.pcard[i]))
    {
	printf("\n\t\t\tNot a valid pan no.");
	goto f;
	}
}

g:
printf("\n\t\t\t Bank: ");
fflush(stdin);
gets(applicant.bank);
for(i=0; applicant.bank[i]!='\0';i++)
	{
	if(isalpha(applicant.bank[i]))
	{

	}
	else
    {
	printf("\n\t\t\tNot a valid bank");
	goto g;
	}
	}
h:
printf("\n \n\t\t\t Branch: ");
fflush(stdin);
gets(applicant.branch);
for(i=0; applicant.branch[i]!='\0';i++)
	{if(isalpha(applicant.branch[i]))
	{

	}
	else
    {
	printf("\n\t\t\tNot a valid branch");
	goto h;
	}
	}
i:
printf("\n\t\t\t Enter the mode of payment\n\t\t\t Cash or Credit: ");
gets(applicant.coc);
for(i=0;applicant.coc[i]!='\0';i++)
	{
	if(isalpha(applicant.coc[i]))
	{

	}
	else
    {
	printf("\n\t\t\tNot a valid cash or credit");
	goto i;
	}
	}
j:
printf("\n \n\t\t\t\t Date: ");
scanf("%d",&applicant.d);
printf("\n \n\t\t\t\t Month: ");
scanf("%d",&applicant.m);
printf("\n \n\t\t\t\t Year: ");
scanf("%d",&applicant.y);
if((applicant.d>=1 && applicant.d<=31) &&
      (applicant.m==1 || applicant.m==3 || applicant.m==5 || applicant.m==7 ||
      applicant.m==8 || applicant.m==10 || applicant.m==12) &&
      (applicant.y>=2000))
      {

      }
      else
      if((applicant.d>=1 && applicant.d<=30) &&
      (applicant.m==4 || applicant.m==6 || applicant.m==9 || applicant.m==11) &&
      (applicant.y>=2000))
      {

      }
       else
      if((applicant.d>=1 && applicant.d<=29) && (applicant.m==2) &&
      (applicant.y>=1990) &&
      (applicant.y%100!=0 && applicant.y%4==0))
      {

      }
      else
      if((applicant.d>=1 && applicant.d<=28) && (applicant.m==2)&&(applicant.y>=1990))
      {

      }

      else
      {
       printf("\n\t\t\tInvalid date");
       printf("\n\t\t\tPlease re-enter the date in the correct format : \n ");
       goto j;
       }


fwrite(&applicant,sizeof(applicant),1,fp);
fclose(fp);
printf("\n\n\t\t\t\tThanks");
getch();
}

    void property_details()
{
    system("cls");
    int i=0;

pf= fopen("mukulp.txt","ab+");

gotoxy(22,11);
printf(" ---------- Add new applicant details ----------");
printf("\n \n\t\t\t    Please enter the following applicant details.");

a1:
    fflush(stdin);
printf("\n\t\t\t\t Enter Property Id: ");
gets(property.pid);
for(i=0; property.pid[i]!='\0';i++)
{
if(isalpha(property.pid[i]))
    {
	printf("\n\t\t\tNot a valid property id");
	goto a1;
	}
}

b1:
fflush(stdin);
printf("\n \n\t\t\t\t Enter Location Code: ");
gets(property.lcode);
for(i=0; property.lcode[i]!='\0';i++)
{
if(isalpha(property.lcode[i]))
    {
	printf("\n\t\t\tNot a valid location code");
	goto b1;
	}
}

c1:
printf("\n \n\t\t\t\t Location Name: ");
fflush(stdin);
gets(property.lname);
for(i=0;property.lname[i]!='\0';i++)
	{
	if(isalpha(property.lname[i]))
	{

	}
	else
    {
	printf("\n\t\t\tNot a valid location name");
	goto c1;
	}
	}
d1:
    fflush(stdin);
printf("\n \n\t\t\t\t Enter Number Of Property: ");
gets(property.nof);
for(i=0; property.nof[i]!='\0';i++)
{
if(isalpha(property.nof[i]))
    {
	printf("\n\t\t\tNot a valid property no.");
	goto d1;
	}
}
e1:
    fflush(stdin);
printf("\n \n\t\t\t\t Enter Property Area: ");
gets(property.area);
for(i=0;property.area[i]!='\0';i++)
	{
	if(isalpha(property.area[i]))
	{

	}
	else
    {
	printf("\n\t\t\tNot a valid father name");
	goto e1;
	}
	}

f1:
    fflush(stdin);
printf("\n \n\t\t\t\t Enter Initial Payment: ");
gets(property.ipayment);
for(i=0; property.ipayment[i]!='\0';i++)
{
if(isalpha(property.ipayment[i]))
    {
	printf("\n\t\t\tNot a valid Initial Payment");
	goto f1;
	}
}

g1:
    fflush(stdin);
printf("\n \n\t\t\t\t Enter Property Price: ");
gets(property.price);
for(i=0; property.price[i]!='\0';i++)
{
if(isalpha(property.price[i]))
    {
	printf("\n\t\t\tNot a valid Property Price");
	goto g1;
	}
}

h1:
    fflush(stdin);
printf("\n \n\t\t\t\t Date: ");
scanf("%d",&property.d);
    fflush(stdin);
printf("\n\t\t\t\t Month: ");
scanf("%d",&property.m);
    fflush(stdin);
printf("\n\t\t\t\t Year: ");
scanf("%d",&property.y);
if((property.d>=1 && property.d<=31) &&
      (property.m==1 || property.m==3 || property.m==5 || property.m==7 ||
      property.m==8 || property.m==10 || property.m==12) &&
      (property.y>=2000))
      {

      }
      else
      if((property.d>=1 && property.d<=30) &&
      (property.m==4 || property.m==6 || property.m==9 || property.m==11) &&
      (property.y>=2000))
      {

      }
       else
      if((property.d>=1 && property.d<=29) && (property.m==2) &&
      (property.y>=1990) &&
      (property.y%100!=0 && property.y%4==0))
      {

      }
      else
      if((property.d>=1 && property.d<=28) && (property.m==2)&&(property.y>=1990))
      {

      }

      else
      {
       printf("\n\t\t\tInvalid date");
       printf("\n\t\t\tPlease re-enter the date in the correct format : \n ");
       goto h1;
       }

fwrite(&property,sizeof(property),1,pf);
fclose(pf);
printf("\n\n\t\t\t\tthanks");
getch();


}

        void display_a()
{
	system("cls");
	gotoxy(25,10);
	printf("---------- Display ALL Applicant Details ----------");

	fp=fopen("mukula.txt","rb");
while(fread(&applicant,sizeof(applicant),1,fp)==1)

{
printf("\n\n  Date: %d",applicant.d);
printf("\n  Month: %d",applicant.m);
printf("\n  Year: %d",applicant.y);
printf("\n  Applicant Name:%s",applicant.name);
printf("\n  Fathers Name: %s",applicant.fname);
printf("\n  Property ID: %s",applicant.id);
printf("\n  Age: %s",applicant.age);
printf("\n  Gender: %s",applicant.gender);
printf("\n  Address: %s",applicant.address);
printf("\n  Pan Card Number: %s",applicant.pcard);
printf("\n  Bank: %s",applicant.bank);
printf("\n  Branch: %s",applicant.branch);
printf("\n  Enter the mode of payment\n\n Cash or Credit: %s",applicant.coc);
printf("\n\n");

}
	 fclose(fp);
	 printf("\n\n\t\tpress any key for back");
    getch();
    Applicant();
}

        void delet_a()
{
	system("cls");

    char c=0,d[20];
    int f=1,x=0;


	fp=fopen("mukula.txt","r+");
	 pf2=fopen("text.txt","wb+");

            gotoxy(16,10);
            printf("----- Display Applicant Details -----");
            fflush(stdin);

                printf("\n\n\t\t\t  Enter your pan card no.  :");
               gets(d);
while(fread(&applicant,sizeof(applicant),1,fp)==1)
{
    if(strcmp(d,applicant.pcard)==0)
{

printf("\n\n  Date: %d",applicant.d);
printf("\n  Month: %d",applicant.m);
printf("\n  Year: %d",applicant.y);
printf("\n  Applicant Name:%s",applicant.name);
printf("\n  Fathers Name: %s",applicant.fname);
printf("\n  Property ID: %s",applicant.id);
printf("\n  Age: %s",applicant.age);
printf("\n  Gender: %s",applicant.gender);
printf("\n  Address: %s",applicant.address);
printf("\n  Pan Card Number: %s",applicant.pcard);
printf("\n  Bank: %s",applicant.bank);
printf("\n  Branch: %s",applicant.branch);
printf("\n  Enter the mode of payment\n\n Cash or Credit: %s",applicant.coc);
printf("\n\n");
f=0;
}
    else
{
    fwrite(&applicant,sizeof(applicant),1,pf2);

}
}
	 fclose(fp);
	 fclose(pf2);
    remove("mukula.txt");
    rename("text.txt","mukula.txt");
    printf("\n\n\t\t\tpress any key for back...");
    getch();
}

        void display_p()
{
	system("cls");
	gotoxy(28,9);
	printf("---------- Property provides ----------");
	pf=fopen("mukulp.txt","rb+");
while(fread(&property,sizeof(property),1,pf)==1)
{

printf("\n\n  Date: %d",property.d);
printf("\n  Month: %d",property.m);
printf("\n  Year: %d",property.y);
printf("\n  ID: %s",property.pid);
printf("\n  Code: %s",property.lcode);
printf("\n  Name: %s",property.lname);
printf("\n  No. of property: %s",property.nof);
printf("\n  Area: %s",property.area);
printf("\n  Initial Payment: %s",property.ipayment);
printf("\n  Property Price: %s",property.price);

}
	 fclose(pf);
	 printf("\n\n\t\t\t\tpress any key for back...");
	 getch();
}

        void apply()
{
    	system("cls");
    	int y=0,d,m,l;
    	char c=0,ans=0;
	gotoxy(16,10);
    printf("---------- APPLY FOR PROPERTY ----------");

	pf=fopen("mukulp.txt","r+");
	 fflush(stdin);
                d=0;
                m=0;
                y=0;
                printf("\n\n\t\t\t  Date :");
                scanf("%d",&d);
                printf("\n\t\t\t  MONTH :");
                scanf("%d",&m);
                printf("\n\t\t\t  YEAR :");
                scanf("%d",&l);

        while(fread(&property,sizeof(property),1,pf)==1)
{
    system("cls");

    if((d==property.d) && (m==property.m))
{
        if(l==property.y)
{

gotoxy(18,6);
printf("++++++++++ Your Property Details ++++++++++");

printf("\n\n\t\t  Date: %d",property.d);
printf("\n\t\t\t  Month: %d",property.m);
printf("\n\t\t\t  Year: %d",property.y);
printf("\n\t\t\t  ID:%s",property.pid);
printf("\n\t\t\t  Code: %s",property.lcode);
printf("\n\t\t\t  Name: %s",property.lname);
printf("\n\t\t\t  No.of pro.: %s",property.nof);
printf("\n\t\t\t  Area: %s",property.area);
printf("\n\t\t\t  Payment %s",property.ipayment);
printf("\n\t\t\t  Price: %s",property.price);

gotoxy(14,17);
fflush(stdin);
printf("you want to buy this property <y or n> =");
scanf("%c",&c);
        if(c=='y' || c=='Y')
{
        Delet(d,m,l);

    printf("\n\n\t\tpress any key for back...");
    getch();
    Property();

}

                    else
    {
                system("cls");
                gotoxy(22,15);
                printf("********** Sorry wrong ID ***********");
                gotoxy(22,17);
                fflush(stdin);
                printf("You want to try again <y or n> =");
                scanf("%c",&ans);

                                    if(ans=='y' || ans =='Y')
                        {
                                            apply();
                        }

                                    else

                        {
                                            if(ans=='n' || ans=='N')
                                {
                                            Property();
                                }
                                            else
                                {
                                        printf("\n\t\t----- wrong input -----");
                                        printf("\npress any key for back...");
                                        Property();
                                }
                        }
            }

}
}
    else
    {
        y=1;
    }

}
        if(y==1)
        {
                system("cls");
                gotoxy(22,12);
                printf("********** Sorry wrong ID ***********");
                gotoxy(22,17);
                fflush(stdin);
                printf("You want to try again <y or n> =");
                scanf("%c",&ans);

                                    if(ans=='y' || ans =='Y')
                        {
                                            apply();
                        }

                                    else

                        {
                                            if(ans=='n' || ans=='N')
                                {
                                            Property();
                                }
                                            else
                                {
                                        printf("\n\t\t----- wrong input -----");
                                        printf("\npress any key for back...");
                                        Property();
                                }
                        }
        }

fclose(pf);
            getch();
}

        void Delet(int d ,int m, int l)
{

        pf=fopen("mukulp.txt","rb+");

        pf2=fopen("text.txt","ab+");

        while(fread(&property,sizeof(property),1,pf)==1)
    {

    if((d==applicant.d) && (m==applicant.m))
    {
        if(l==applicant.y)

        {
    system("cls");

    gotoxy(12,9);
    printf("----- This property is alloted to you -----");

            printf("\n\n\t\t  Date: %d",property.d);
            printf("\n\t\t  Month: %d",property.m);
            printf("\n\t\t  Year: %d",property.y);
            printf("\n\t\t  ID:%s",property.pid);
            printf("\n\t\t  Code: %s",property.lcode);
            printf("\n\t\t  Name: %s",property.lname);
            printf("\n\t\t  Gender: %s",property.nof);
            printf("\n\t\t  Area: %s",property.area);
            printf("\n\t\t  Payment: %s",property.ipayment);
            printf("\n\t\t  Price: %s",property.price);
        }
            else
            goto z;
        }

                else

        {
            z:
             fwrite(&property,sizeof(property),1,pf2);

        }
    }


      fclose(pf2);

   fclose(pf);

    remove("mukulp.txt");
    rename("text.txt","mukulp.txt");

}

        void Del()
{
   	system("cls");

		char d[50];


		pf=fopen("mukulp.txt","r+");
        pf2=fopen("text.txt","wb+");

        gotoxy(20,9);
		printf("********** DELETE THE PROPERTY RECORD *********");


        fflush(stdin);
        fflush(stdin);
            printf("Enter you Pan no :");
            gets(d);

        while(fread(&property,sizeof(property),1,pf)==1)
    {

    if(strcmp(d,property.pid)==0)
{
            printf("\n\n\t\t  Date: %d",property.d);
            printf("\n\t\t  Month: %d",property.m);
            printf("\n\t\t  Year: %d",property.y);
            printf("\n\t\t  ID:%s",property.pid);
            printf("\n\t\t  Code: %s",property.lcode);
            printf("\n\t\t  Age: %s",property.lname);
            printf("\n\t\t  Gender: %s",property.nof);
            printf("\n\t\t  Address: %s",property.area);
            printf("\n\t\t  Pan Card Number: %s",property.ipayment);
            printf("\n\t\t  Bank: %s",property.price);

}
        else

        {

                fwrite(&property,sizeof(property),1,pf2);

        }
}

    fclose(pf);
    fclose(pf2);

    remove("mukulp.txt");
    rename("text.txt","mukulp.txt");
    printf("\n\n\t\tpress any key for back...");
    getch();
}

        void report_p()
{
     system("cls");

    int a=0,d=0,m=0,y=0;
    gotoxy(20,11);
    printf("REPORT");
    gotoxy(24,13);
    printf("1.DATE");
    gotoxy(24,14);
    printf("2.MONTH");
    gotoxy(24,15);
    printf("3.YEAR");
    gotoxy(22,17);
    printf("Enter your choice :");
    scanf("%d",&a);
    switch(a)
    {
        case 1: system("cls");
                d=0;
                m=0;
                y=0;
                printf("\t\t\tEnter the details");
                printf("\n\n\t\t\t  Date :");
                scanf("%d",&d);
                printf("\n\t\t\t  MONTH :");
                scanf("%d",&m);
                printf("\n\t\t\t  YEAR :");
                scanf("%d",&y);
                pf=fopen("mukulp.txt","r+");
while(fread(&property,sizeof(property),1,pf)==1)
{
    if((d==applicant.d) && (m==applicant.m))
{
    if(y==applicant.y)
{
printf("\n\n Date: %d",property.d);
printf("\n  Month: %d",property.m);
printf("\n  Year: %d",property.y);
printf("\n  ID:%s",property.pid);
printf("\n  Code: %s",property.lcode);
printf("\n  Age: %s",property.lname);
printf("\n  Gender: %s",property.nof);
printf("\n  Address: %s",property.area);
printf("\n  Pan Card Number: %s",property.ipayment);
printf("\n  Bank: %s",property.price);
}
}
}
	 fclose(pf);
	 printf("\n\npress any key for back...");
	 getch();
    break;

        case 2:system("cls");
                m=0;
                y=0;
                printf("\n\n\t\t\tEnter the details");
                printf("\n\n\t\t\t MONTH :");
                scanf("%d",&m);
                printf("\n\t\t\t YEAR :");
                scanf("%d",&y);
                pf=fopen("mukulp.txt","r+");
while(fread(&property,sizeof(property),1,pf)==1)
{
    if(m==applicant.m && y==applicant.y)
{
printf("\n\n Date: %d",property.d);
printf("\n  Month: %d",property.m);
printf("\n  Year: %d",property.y);
printf("\n  ID:%s",property.pid);
printf("\n  Code: %s",property.lcode);
printf("\n  Age: %s",property.lname);
printf("\n  Gender: %s",property.nof);
printf("\n  Address: %s",property.area);
printf("\n  Pan Card Number: %s",property.ipayment);
printf("\n  Bank: %s",property.price);
}
}
	 fclose(pf);
	 printf("\n\npress any key for back...");
	 getch();
	 break;

	 case 3:system("cls");

                y=0;
                printf("\n\n\t\t\tEnter the details");
                printf("\n\n\t\t\t YEAR :");
                scanf("%d",&y);
                pf=fopen("mukulp.txt","r+");
while(fread(&property,sizeof(property),1,pf)==1)
{
    if(y==applicant.y)
{
printf("\n\n Date: %d",property.d);
printf("\n  Month: %d",property.m);
printf("\n  Year: %d",property.y);
printf("\n  ID: %s",property.pid);
printf("\n  Code: %s",property.lcode);
printf("\n  Age: %s",property.lname);
printf("\n  Gender: %s",property.nof);
printf("\n  Address: %s",property.area);
printf("\n  Pan Card Number: %s",property.ipayment);
printf("\n  Bank: %s",property.price);
}
}
	 fclose(pf);
	 printf("\n\npress any key for back...");
	 getch();
	 break;

	 default:printf("\n\n\t\t\tWrong option...");
            printf("press any key for back...");
            getch();
            Property();

}
}

        void report_a()
{
    system("cls");

    int a=0,d=0,m=0,y=0;
    gotoxy(20,11);
    printf("REPORT");
    gotoxy(24,13);
    printf("  1.Date ");
    gotoxy(24,14);
    printf("  2.MONTH ");
    gotoxy(24,15);
    printf("  3.YEAR ");
    gotoxy(22,17);
    printf("Enter your choice :");
    scanf("%d",&a);
    switch(a)
    {
        case 1: system("cls");
                d=0;
                m=0;
                y=0;
                printf("\n\n\t\t\tEnter the details");
                printf("\n\n\t\t\t  Date :");
                scanf("%d",&d);
                printf("\n\t\t\t  MONTH :");
                scanf("%d",&m);
                printf("\n\t\t\t  YEAR :");
                scanf("%d",&y);

                fp=fopen("mukula.txt","rb");
while(fread(&applicant,sizeof(applicant),1,fp)==1)
{
    if((d==applicant.d) && (m==applicant.m))
    {
        if(y==applicant.y)
{
printf("\n \n Date: %d",applicant.d);
printf("\n  Month: %d",applicant.m);
printf("\n  Year: %d",applicant.y);
printf("\n  Applicant Name:%s",applicant.name);
printf("\n  Fathers Name: %s",applicant.fname);
printf("\n  Property ID: %s",applicant.id);
printf("\n  Age: %s",applicant.age);
printf("\n  Gender: %s",applicant.gender);
printf("\n  Address: %s",applicant.address);
printf("\n  Pan Card Number: %s",applicant.pcard);
printf("\n  Bank: %s",applicant.bank);
printf("\n  Branch: %s",applicant.branch);
printf("\n  Enter the mode of payment\n\n Cash or Credit: %s",applicant.coc);
printf("\n\n");
}
}
}
	 fclose(fp);
    getch();
    break;

    case 2:system("cls");
                d=0;
                m=0;
                y=0;
                printf("\n\n\t\t\tEnter the details");
                printf("\n\n\t\t\t  MONTH :");
                scanf("%d",&m);
                printf("\n\t\t\t  YEAR :");
                scanf("%d",&y);


                fp=fopen("mukula.txt","rb");
while(fread(&applicant,sizeof(applicant),1,fp)==1)
{
    if(m==applicant.m && y==applicant.y)
{
printf("\n \n Date: %d",applicant.d);
printf("\n  Month: %d",applicant.m);
printf("\n  Year: %d",applicant.y);
printf("\n  Applicant Name:%s",applicant.name);
printf("\n  Fathers Name: %s",applicant.fname);
printf("\n  Property ID: %s",applicant.id);
printf("\n  Age: %s",applicant.age);
printf("\n  Gender: %s",applicant.gender);
printf("\n  Address: %s",applicant.address);
printf("\n  Pan Card Number: %s",applicant.pcard);
printf("\n  Bank: %s",applicant.bank);
printf("\n  Branch: %s",applicant.branch);
printf("\n  Enter the mode of payment\n\n Cash or Credit: %s",applicant.coc);
printf("\n\n");
}
}
	 fclose(fp);
    getch();
    break;

    case 3:system("cls");
                d=0;
                m=0;
                y=0;
                printf("\n\n\t\t\tEnter the details");
                printf("\n\n\t\t\t  YEAR :");
                scanf("%d",&y);

                fp=fopen("mukula.txt","rb");
while(fread(&applicant,sizeof(applicant),1,fp)==1)
{
    if(y==applicant.y)
{
printf("\n \n Date: %d",applicant.d);
printf("\n  Month: %d",applicant.m);
printf("\n  Year: %d",applicant.y);
printf("\n  Applicant Name:%s",applicant.name);
printf("\n  Fathers Name: %s",applicant.fname);
printf("\n  Property ID: %s",applicant.id);
printf("\n  Age: %d",applicant.age);
printf("\n  Gender: %s",applicant.gender);
printf("\n  Address: %s",applicant.address);
printf("\n  Pan Card Number: %s",applicant.pcard);
printf("\n  Bank: %s",applicant.bank);
printf("\n  Branch: %s",applicant.branch);
printf("\n  Enter the mode of payment\n\n Cash or Credit: %s",applicant.coc);
printf("\n\n");
}
}
	 fclose(fp);
    getch();
    break;

    default:printf("\n\t\t\twrong option...");
            printf("press any key for back");
            Applicant();
            getch();
}
}

        void display_id()
{

	system("cls");
	char a[20];
	gotoxy(28,9);
	printf("---------- Applicant details by ID ----------");
	fp=fopen("mukula.txt","rb+");
	fflush(stdin);
	printf("\n\n\t\t\tEnter the ID");
	gets(a);

while(fread(&applicant,sizeof(applicant),1,fp)==1)

{
    if(strcmp(a,applicant.id)==0)
    {
printf("\n\n Date: %d",applicant.d);
printf("\n  Month: %d",applicant.m);
printf("\n  Year: %d",applicant.y);
printf("\n  Applicant Name:%s",applicant.name);
printf("\n  Fathers Name: %s",applicant.fname);
printf("\n  Property ID: %s",applicant.id);
printf("\n  Age: %s",applicant.age);
printf("\n  Gender: %s",applicant.gender);
printf("\n  Address: %s",applicant.address);
printf("\n  Pan Card Number: %s",applicant.pcard);
printf("\n  Bank: %s",applicant.bank);
printf("\n  Branch: %s",applicant.branch);
printf("\n  Enter the mode of payment\n\n Cash or Credit: %s",applicant.coc);
printf("\n\n");
}
}
	 fclose(fp);
	 printf("\n\n\t\t\t\tpress any key for back...");
	 getch();
}

