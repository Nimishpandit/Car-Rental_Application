#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"conio2.h"
#include"car.h"

void addAdmin()
{
    FILE*fp=fopen("admin.bin","rb");
   if(fp==NULL)
   {
       fp=fopen("admin.bin","wb");
       User u[2]={{"admin","abc","Nimish"},{"demo","def","Sunil"}};
       fwrite(u,sizeof(u),1,fp);
   }
   fclose(fp);
}
User* getInput()
{
    int i;
    static User U;
    char *pos;
    clrscr();
    gotoxy(40,2);
    textcolor(YELLOW);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,3);
        for(i=0;i<96;i++)
    {
        printf("%c",247);
    }
    gotoxy(41,6);
    printf("* LOGIN PANEL *");
     gotoxy(1,11);
     textcolor(LIGHTCYAN);
       for(i=0;i<96;i++)
    {
        printf("%c",247);
    }
    gotoxy(1,21);
       for(i=0;i<96;i++)
    {
        printf("%c",247);
    }
    textcolor(WHITE);
    gotoxy(80,12);
    printf("Press 0 to exit");
    gotoxy(34,15);
    textcolor(LIGHTCYAN);
    printf("Enter user id :");
    fflush(stdin);
    textcolor(WHITE);
    fgets(U.userid,20,stdin);
    pos=strchr(U.userid,'\n');
    if(pos!=NULL)
        *pos='\0';
    if(U.userid[0]=='0')
    {
        gotoxy(40,24);
        textcolor(RED);
        printf("Login Cancelled!");
        getch();
        return NULL;
    }
    gotoxy(34,16);
    textcolor(LIGHTCYAN);
    printf("Enter Password :");
    textcolor(WHITE);
    fflush(stdin);
    i=0;
    while(1)
    {
        U.pwd[i]=getch();
        if(U.pwd[i]==8)
        {
            printf("\b \b");
            i--;
            continue;
        }
        if(U.pwd[i]==13)
            break;
        printf("*");
        i++;
    }
    U.pwd[i]='\0';
     if(U.pwd[0]=='0')
    {
        gotoxy(40,24);
        textcolor(RED);
        printf("Login Cancelled!");
        getch();
        return NULL;
    }
    return &U;
}
int checkUserExit(User  U,char *p)
{
    User Usr;
    int found=0;
    FILE*fp;
    if(strcmp(U.userid,"")==0||strcmp(U.pwd,"")==0)
    {
         gotoxy(35,24);
        textcolor(RED);
        printf("Both Field Are Mandatory. Try again");
        getch();
        gotoxy(35,24);
        printf("\t\t\t\t\t");
        return 0;
    }
    if(strcmp(p,"admin")==0)
    {
        fp=fopen("admin.bin","rb");
    }
    else
    {
        fp=fopen("emp.bin","rb");
    }
    if(fp==NULL)
    {
         gotoxy(35,24);
        textcolor(RED);
        printf("Sorry! File Cannot be opended ");
        getch();
        gotoxy(35,24);
        printf("\t\t\t\t\t");
        return -1;
    }
    while(fread(&Usr,sizeof(User),1,fp)==1)
    {
          if(strcmp(U.userid,Usr.userid)==0&&strcmp(U.pwd,Usr.pwd)==0)
          {
              found=1;
              break;
          }
    }
    if(found==0)
    {
         gotoxy(35,24);
        textcolor(RED);
        printf("Invalid Userid or Password ");
        getch();
        gotoxy(35,24);
        printf("\t\t\t\t\t");
    }
    else
    {
        gotoxy(40,24);
        textcolor(GREEN);
        printf("Login Successful!");
        getch();
        gotoxy(40,24);
        printf("\t\t\t\t\t");
    }
    fclose(fp);
    return found;
}

int adminMenu()
{
    int choice;
     gotoxy(40,2);
     textcolor(RED);
      printf("CAR RENTAL SYSTEM");
      gotoxy(44,8);
       textcolor(GREEN);
      printf("ADMIN MENU\n");
       for(int i=0;i<96;i++)
         {
             printf("*");
         }
         textcolor(YELLOW);
         gotoxy(40,10);
         printf("1. Add Employee");
         gotoxy(40,11);
         printf("2. Add Car Details");
         gotoxy(40,12);
         printf("3. Show Employee");
         gotoxy(40,13);
         printf("4. Show Car Details");
         gotoxy(40,14);
         printf("5. Delete Employee");
         gotoxy(40,15);
         printf("6. Delete Car Details");
         gotoxy(40,16);
         printf("7. Exit");
         gotoxy(40,18);
         printf("Enter Choice:");
         textcolor(WHITE);
         scanf("%d",&choice);
         return choice;
}

void  addEmployee()
{
    User u;
    char choice;
    char*pos;
    char temp[20];
    FILE *fp=fopen("emp.bin","ab+");
    fseek(fp,0,SEEK_END);
    long total_rec=ftell(fp)/sizeof(User);
    if(total_rec!=0)
    {
        fseek(fp,-60,SEEK_END);
        fread(temp,sizeof(temp),1,fp);
        pos=strchr(temp,'-');
        total_rec=atoi(pos+1);
    }
    total_rec++;
    sprintf(u.userid,"EMP-%ld",total_rec);
    fseek(fp,0,SEEK_END);
    do
    {
       clrscr();
       gotoxy(40,2);
       textcolor(RED);
       printf("CAR RENTAL SYSTEM\n");
       textcolor(LIGHTGREEN);
       for(int i=0;i<96;i++)
             printf("~");
       gotoxy(33,5);
       textcolor(WHITE);
       printf("***** ADD EMPLOYEE DETAILS *****\n\n");
       textcolor(YELLOW);
       printf("Enter Empolyee Name :");
       fflush(stdin);
       textcolor(WHITE);
       fgets(u.name,20,stdin);
       pos=strchr(u.name,'\n');
       if(pos!=NULL)
               *pos='\0';
        textcolor(YELLOW);
       printf("Enter Empolyee Password :");
       fflush(stdin);
       textcolor(WHITE);
       fgets(u.pwd,20,stdin);
       pos=strchr(u.pwd,'\n');
       if(pos!=NULL)
               *pos='\0';
        fwrite(&u,sizeof(u),1,fp);
        gotoxy(35,18);
        textcolor(GREEN);
        printf("EMPOLYEE ADDED SUCCESFULLY!\n");
        printf("EMPOLYEE ID IS : %s",u.userid);
        getch();
        do
        {
        gotoxy(1,24);
        textcolor(LIGHTRED);
        printf("DO YOU WANT TO ADD MORE EMPOLYEE(Y/N) :");
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='N'||choice=='Y'||choice=='n'||choice=='y')
            break;
        gotoxy(40,26);
        printf("INVAILD CHOICE");
        gotoxy(39,27);
        printf("PLEASE TRY AGAIN");
         getch();
        gotoxy(39,27);
        printf("\t\t\t\t");
        gotoxy(40,26);
        printf("\t\t\t\t");
        gotoxy(37,24);
        printf("\t\t");
        gotoxy(37,24);
        }while(1);
    total_rec++;
    sprintf(u.userid,"EMP-%ld",total_rec);
    }while(choice=='Y'||choice=='y');
   fclose(fp);
}

void addCarDetails()
{
    Car C;
    int x;
    char choice;
    FILE *fp=fopen("car.bin","ab+");
    fseek(fp,0,SEEK_END);
    C.car_id=ftell(fp)/sizeof(Car);
    if(C.car_id!=0)
    {
        fseek(fp,-68,SEEK_END);
        fread(&x,sizeof(x),1,fp);
        C.car_id=x;
    }
    C.car_id++;
    fseek(fp,0,SEEK_END);
    do
    {
       clrscr();
       gotoxy(40,2);
       textcolor(RED);
       printf("CAR RENTAL SYSTEM\n");
       textcolor(LIGHTGREEN);
       for(int i=0;i<96;i++)
             printf("~");
       gotoxy(33,5);
       textcolor(WHITE);
       printf("***** ADD CAR DETAILS *****\n\n");
       textcolor(YELLOW);
       printf("Enter Car Model :");
       fflush(stdin);
       textcolor(WHITE);
       fgets(C.car_name,50,stdin);
       char*pos;
       pos=strchr(C.car_name,'\n');
       if(pos!=NULL)
               *pos='\0';
        textcolor(YELLOW);
       printf("Enter Car Capacity :");
        textcolor(WHITE);
        scanf("%d",&C.capacity);
       textcolor(YELLOW);
       printf("Enter Car Count :");
        textcolor(WHITE);
        scanf("%d",&C.car_count);
       textcolor(YELLOW);
       printf("Enter Car Price For Per Day :");
        textcolor(WHITE);
        scanf("%d",&C.price);
        fwrite(&C,sizeof(C),1,fp);
        gotoxy(35,18);
        textcolor(GREEN);
        printf("CAR ADDED SUCCESFULLY!\n");
        printf("CAR ID IS : %d",C.car_id);
        getch();
        do
        {
        gotoxy(1,24);
        textcolor(LIGHTRED);
        printf("DO YOU WANT TO ADD MORE CAR(Y/N) :");
        fflush(stdin);
        scanf("%c",&choice);
           if(choice=='N'||choice=='Y'||choice=='n'||choice=='y')
            break;
        gotoxy(40,26);
        printf("INVAILD CHOICE");
        gotoxy(39,27);
        printf("PLEASE TRY AGAIN");
         getch();
        gotoxy(39,27);
        printf("\t\t\t\t");
        gotoxy(40,26);
        printf("\t\t\t\t");
        gotoxy(35,24);
        printf("\t\t");
        gotoxy(35,24);
        }while(1);
        C.car_id++;
    }while(choice=='Y'||choice=='y');
    fclose(fp);
}

void viewEmpolyee()
{
    FILE*fp=fopen("emp.bin","rb");
    User ur;
    int i,x=10;
    textcolor(YELLOW);
    gotoxy(40,2);
    printf("Car Rental System\n");
    for(i=0;i<96;i++)
        printf("%c",247);
    gotoxy(38,5);
    printf("* EMPOLYEE DETAILS *\n\n");
    textcolor(LIGHTGREEN);
    for(i=0;i<96;i++)
    printf("%c",247);
    if(fp==NULL)
    {
        gotoxy(36,9);
        textcolor(LIGHTRED);
        printf("Sorry! Cannot open the file");
        getch();
        return;
    }
    gotoxy(1,9);
    for(i=0;i<96;i++)
        printf("%c",247);
    gotoxy(1,8);
     printf(" Employee ID\t\t\t\tName\t\t\t\tPassword");
     textcolor(YELLOW);
     while(fread(&ur,sizeof(ur),1,fp)==1)
     {
         gotoxy(2,x);
         printf("%s",ur.userid);
        gotoxy(41,x);
        printf("%s",ur.name);
        gotoxy(73,x);
        printf("%s",ur.pwd);
        x++;
     }
    fclose(fp);
    gotoxy(72,6);
    textcolor(WHITE);
    printf("Press any key to go back");
    getch();
    }

void  showCarDetails()
{
    FILE*fp=fopen("car.bin","rb");
    Car cr;
    int i,x=10;
    textcolor(YELLOW);
    gotoxy(40,2);
    printf("Car Rental System\n");
    for(i=0;i<96;i++)
        printf("%c",247);
    gotoxy(38,5);
    printf("* ALL CAR  DETAILS *\n\n");
    textcolor(LIGHTGREEN);
    for(i=0;i<96;i++)
    printf("%c",247);
    if(fp==NULL)
    {
        gotoxy(36,9);
        textcolor(LIGHTRED);
        printf("Sorry! Cannot open the file");
        getch();
        return;
    }
    gotoxy(1,9);
    for(i=0;i<96;i++)
        printf("%c",247);
    gotoxy(1,8);
     printf(" Car ID\t\tModel\t\tCapacity\t\tAvailable\t\tPrice/Day");
     textcolor(YELLOW);
     while(fread(&cr,sizeof(cr),1,fp)==1)
     {
         gotoxy(4,x);
         printf("%d",cr.car_id);
        gotoxy(17,x);
        printf("%s",cr.car_name);
        gotoxy(37,x);
        printf("%d",cr.capacity);
        gotoxy(61,x);
        printf("%d",cr.car_count);
        gotoxy(81,x);
        printf("%d",cr.price);
        x++;
     }
    fclose(fp);
    gotoxy(72,6);
    textcolor(WHITE);
    printf("Press any key to go back");
    getch();
}

int deleteEmp()
{
    FILE *fp1=fopen("emp.bin","rb");
    int i,result,found=0;
    char empid[20];
    textcolor(YELLOW);
    gotoxy(40,2);
    printf("Car Rental System\n");
    for(i=0;i<96;i++)
        printf("%c",247);
    gotoxy(35,5);
    printf("* DELETE EMPLOYEE RECORD  *\n\n");
    textcolor(LIGHTGREEN);
    for(i=0;i<96;i++)
    printf("%c",247);
    gotoxy(1,12);
    for(i=0;i<96;i++)
        printf("%c",247);
     if(fp1==NULL)
    {
        gotoxy(36,9);
        textcolor(LIGHTRED);
        printf("No Employee Added Yet !");
        getch();
        return -1;
    }
    FILE *fp2=fopen("temp.bin","wb+");
    gotoxy(28,9);
    textcolor(YELLOW);
    printf("Enter Empolyee ID to delete the record :-");
    textcolor(WHITE);
    scanf("%s",empid);
    User U;
    while(fread(&U,sizeof(U),1,fp1)==1)
    {
        if(strcmp(U.userid,empid)==0)
            found=1;
        else
            fwrite(&U,sizeof(U),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
    remove("temp.bin");
    }
    else
      {
         result=remove("emp.bin");
        if(result!=0)
            return 2;
        result=rename("temp.bin","emp.bin");
        if(result!=0)
            return 2;
      }
      return found;
}
int deleteCarModel()
{
    FILE *fp1=fopen("car.bin","rb");
    int i,result,found=0;
    int carid;
    textcolor(YELLOW);
    gotoxy(40,2);
    printf("Car Rental System\n");
    for(i=0;i<96;i++)
        printf("%c",247);
    gotoxy(37,5);
    printf("* DELETE CAR RECORD  *\n\n");
    textcolor(LIGHTGREEN);
    for(i=0;i<96;i++)
    printf("%c",247);
    gotoxy(1,12);
    for(i=0;i<96;i++)
        printf("%c",247);
     if(fp1==NULL)
    {
        gotoxy(36,9);
        textcolor(LIGHTRED);
        printf("No Car Added Yet !");
        getch();
        return -1;
    }
    FILE *fp2=fopen("temp.bin","wb+");
    gotoxy(28,9);
    textcolor(YELLOW);
    printf("Enter Car Model ID to delete the record :-");
    textcolor(WHITE);
    scanf("%d",&carid);
    Car C;
    while(fread(&C,sizeof(C),1,fp1)==1)
    {
        if(C.car_id==carid)
            found=1;
        else
            fwrite(&C,sizeof(C),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
    remove("temp.bin");
    }
    else
      {
         result=remove("car.bin");
        if(result!=0)
            return 2;
        result=rename("temp.bin","car.bin");
        if(result!=0)
            return 2;
      }
      return found;
}

int empMenu()
{
    int choice;
     gotoxy(40,2);
     textcolor(RED);
      printf("CAR RENTAL SYSTEM");
      gotoxy(44,8);
       textcolor(GREEN);
      printf("EMPLOYEE MENU\n");
       for(int i=0;i<96;i++)
         {
             printf("*");
         }
         textcolor(YELLOW);
         gotoxy(40,10);
         printf("1. Rent A Car");
         gotoxy(40,11);
         printf("2. Return A Car");
         gotoxy(40,12);
         printf("3. Booking Details");
         gotoxy(40,13);
         printf("4. Available Car Details");
         gotoxy(40,14);
         printf("5. Show All Car Details");
         gotoxy(40,15);
         printf("6. Exit");
         gotoxy(40,18);
         printf("Enter Choice:");
         textcolor(WHITE);
         scanf("%d",&choice);
         return choice;
}
int selectCarModel()
{
    Car C;
    int choice,flag,row=11;
    FILE *fp=fopen("car.bin","rb");
    if(fp==NULL)
    {
        gotoxy(36,12);
        textcolor(RED);
       printf("Sorry,Cannot open the file");
       getch();
       return -1;
    }
    textcolor(YELLOW);
    gotoxy(40,row);
    flag=0;
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_count>0)
            {
               printf("%d .  %s",C.car_id,C.car_name);
               gotoxy(40,++row);
               ++flag;
            }
    }
    if(flag==0)
    {
       fclose(fp);
       return -2;
    }
    gotoxy(40,row+2);
    printf("Enter your choice :");
    textcolor(WHITE);
    while(1)
    {
         flag=0;
        scanf("%d",&choice);
        if(choice==0)
        {
            fclose(fp);
            return 0;
        }
        rewind(fp);
        while(fread(&C,sizeof(C),1,fp)==1)
     {
        if(choice==C.car_id&&C.car_count>0)
            {
                flag=1;
                break;
            }
     }
     if(flag==1)
     {
         fclose(fp);
         return choice;
     }
     else
     {
         gotoxy(40,row+4);
         textcolor(LIGHTRED);
         printf("Worng Input");
         getch();
        gotoxy(40,row+4);
        printf("\t\t\t");
        gotoxy(59,row+2);
        printf("\t\t");
        gotoxy(59,row+2);
        textcolor(WHITE);
     }
    }
}
int isValidDate(struct tm dt)
{
    if(dt.tm_year>=2021&&dt.tm_year<=2022)
    {
        if(dt.tm_mon>=1&&dt.tm_mon<=12)
        {
            if((dt.tm_mday>=1&&dt.tm_mday<=31)&&(dt.tm_mon==1||dt.tm_mon==3||dt.tm_mon==5||dt.tm_mon==7||dt.tm_mon==8||dt.tm_mon==10||dt.tm_mon==12))
                return 1;
            else if((dt.tm_mday>=1&&dt.tm_mday<=30)&&(dt.tm_mon==4||dt.tm_mon==6||dt.tm_mon==9||dt.tm_mon==11))
                return 1;
            else if((dt.tm_mday>=1&&dt.tm_mday<=28)&&(dt.tm_mon==2))
                return 1;
            else if((dt.tm_mday==29)&&(dt.tm_mon==2)&&((dt.tm_year%400==0)||(dt.tm_year%4==0&&dt.tm_year%100!=0)))
                return 1;
        }
    }
    return 0;
}
int checkCurrentDate (struct tm sd)
{
    time_t obj=time(0);
    struct tm*p=localtime(&obj);
    p->tm_year=p->tm_year+1900;
    p->tm_mon=p->tm_mon+1;
    if(p->tm_year<=sd.tm_year)
    {
           if((p->tm_mon<=sd.tm_mon)||(p->tm_mon==12&&sd.tm_mon==1))
               {
                   if(p->tm_mday<=sd.tm_mday)
                             return 1;
                 else if((p->tm_mon<sd.tm_mon)&&(1<=sd.tm_mday))
                            return 1;
                else if((p->tm_mon==12&&sd.tm_mon==1)&&(1<=sd.tm_mday))
                           return 1;
               }
    }
    return 0;
}
int checkEndDate(struct tm sd,struct tm ed)
{
     if(sd.tm_year<=ed.tm_year)
    {
           if((sd.tm_mon<=ed.tm_mon)||(sd.tm_mon==12&&ed.tm_mon==1))
               {
                   if(sd.tm_mday<=ed.tm_mday)
                             return 1;
                 else if((sd.tm_mon<ed.tm_mon)&&(1<=ed.tm_mday))
                            return 1;
                 else if((sd.tm_mon==12&&ed.tm_mon==1)&&(1<=ed.tm_mday))
                           return 1;
               }
    }
    return 0;
}
void updateCarCount(int c_id,int x)
{
    Car C;
    int y;
    FILE*fp=fopen("car.bin","rb+");
     if(fp==NULL)
    {
       gotoxy(36,12);
       textcolor(RED);
       printf("Sorry,Cannot open the file");
       getch();
       return ;
    }
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(x==0)
        {
        if(C.car_id==c_id)
        {
            y=C.car_count;
            y--;
            fseek(fp,-8,SEEK_CUR);
            fwrite(&y,sizeof(y),1,fp);
            break;
        }
        }
        if(x==1)
        {
              if(C.car_id==c_id)
        {
            y=C.car_count;
            y++;
            fseek(fp,-8,SEEK_CUR);
            fwrite(&y,sizeof(y),1,fp);
            break;
        }
        }
    }
    fclose(fp);
}
void bookedCarDetails()
{
    clrscr();
    FILE*fp=fopen("cust.bin","rb");
    Customer_Car_Details CC;
    int i,x=10;
    textcolor(YELLOW);
    gotoxy(40,2);
    printf("Car Rental System\n");
    for(i=0;i<96;i++)
        printf("%c",247);
    gotoxy(36,5);
    printf("* BOOKED CAR  DETAILS *\n\n");
    textcolor(LIGHTGREEN);
    for(i=0;i<96;i++)
    printf("%c",247);
    if(fp==NULL)
    {
        gotoxy(36,9);
        textcolor(LIGHTRED);
        printf("Sorry! Cannot open the file");
        getch();
        return;
    }
    gotoxy(1,9);
    for(i=0;i<96;i++)
        printf("%c",247);
    gotoxy(1,8);
     printf(" Model");
     gotoxy(15,8);
     printf("Customer Name");
     gotoxy(35,8);
     printf("Pick Point");
     gotoxy(52,8);
     printf("Drop Point");
     gotoxy(70,8);
     printf("Start Date");
     gotoxy(86,8);
     printf("End Date");
     textcolor(YELLOW);
     while(fread(&CC,sizeof(CC),1,fp)==1)
     {
         gotoxy(2,x);
         printf("%s",getCarName(CC.car_id));
        gotoxy(15,x);
        printf("%s",CC.cust_name);
        gotoxy(35,x);
        printf("%s",CC.pick);
        gotoxy(52,x);
        printf("%s",CC.drop);
        gotoxy(70,x);
        printf("%d-%d-%d",CC.sd.tm_mday,CC.sd.tm_mon,CC.sd.tm_year);
        gotoxy(86,x);
        printf("%d-%d-%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);
        x++;
     }
    fclose(fp);
    gotoxy(72,6);
    textcolor(WHITE);
    printf("Press any key to go back");
    getch();
}
char *getCarName(int c_id)
{
    FILE*fp=fopen("car.bin","rb");
     if(fp==NULL)
    {
        gotoxy(36,9);
        textcolor(LIGHTRED);
        printf("Sorry! Cannot open the file");
        getch();
        return NULL;
    }
    static Car C;
    while(fread(&C,sizeof(C),1,fp)==1)
    {
        if(C.car_id==c_id)
               break;
    }
    fclose(fp);
    return C.car_name;
}
int rentCar()
{
      Customer_Car_Details CC;
      int c,i;
      char *pos;
      gotoxy(40,2);
      textcolor(RED);
      printf("CAR RENTAL SYSTEM");
      gotoxy(44,8);
       textcolor(GREEN);
      printf("EMPLOYEE MENU\n");
       for( i=0;i<96;i++)
             printf("*");
    textcolor(WHITE);
    gotoxy(80,8);
    printf("Press 0 to exit");
     c=selectCarModel();
     if(c<1)
        return c;
     CC.car_id=c;
     clrscr();
     gotoxy(40,2);
      textcolor(RED);
      printf("CAR RENTAL SYSTEM");
      gotoxy(44,8);
       textcolor(GREEN);
      printf("EMPLOYEE MENU\n");
       for(i=0;i<96;i++)
             printf("*");
     gotoxy(1,20);
     for(i=0;i<96;i++)
             printf("*");
    gotoxy(36,11);
    textcolor(YELLOW);
    printf("Enter Customer Name :");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.cust_name,30,stdin);
    pos=strchr(CC.cust_name,13);
    if(pos!=NULL)
        *pos='\0';
    gotoxy(36,12);
    textcolor(YELLOW);
    printf("Enter Pickup Point :");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.pick,30,stdin);
    pos=strchr(CC.pick,13);
    if(pos!=NULL)
        *pos='\0';
    gotoxy(36,13);
    textcolor(YELLOW);
    printf("Enter Drop Point :");
    fflush(stdin);
    textcolor(WHITE);
    fgets(CC.drop,30,stdin);
    pos=strchr(CC.drop,13);
    if(pos!=NULL)
        *pos='\0';
    gotoxy(36,14);
    textcolor(YELLOW);
    printf("Enter Start Date (dd/mm/yy) :");
    textcolor(WHITE);
     do
    {
    scanf("%d/%d/%d",&CC.sd.tm_mday,&CC.sd.tm_mon,&CC.sd.tm_year);
    i=isValidDate(CC.sd);
    if(i==1)
        i=checkCurrentDate(CC.sd);
    if(i==0)
    {
        gotoxy(28,22);
        textcolor(LIGHTRED);
        printf("You Have Entered The Wrong Date, Please Try Again");
        getch();
        gotoxy(28,22);
        printf("\t\t\t\t\t\t\t");
        gotoxy(65,14);
        printf("\t\t\t");
        gotoxy(65,14);
        textcolor(WHITE);
    }
    else
        break;
    }while(1);
    gotoxy(36,15);
    textcolor(YELLOW);
    printf("Enter End Date (dd/mm/yy) :");
    textcolor(WHITE);
      do
    {
    scanf("%d/%d/%d",&CC.ed.tm_mday,&CC.ed.tm_mon,&CC.ed.tm_year);
    i=isValidDate(CC.ed);
    if(i==1)
        i=checkEndDate(CC.sd,CC.ed);
    if(i==0)
    {
        gotoxy(28,22);
        textcolor(LIGHTRED);
        printf("You Have Entered The Wrong Date, Please Try Again");
        getch();
        gotoxy(28,22);
        printf("\t\t\t\t\t\t\t");
        gotoxy(63,15);
        printf("\t\t\t");
        gotoxy(63,15);
        textcolor(WHITE);
    }
    else
        break;
    }while(1);
    FILE*fp=fopen("cust.bin","ab");
    if(fp==NULL)
    {
        gotoxy(36,21);
        textcolor(LIGHTRED);
        printf("Sorry! Cannot open the file");
        getch();
        gotoxy(36,21);
        printf("\t\t\t");
        return -1;
    }
    fwrite(&CC,sizeof(CC),1,fp);
    textcolor(LIGHTCYAN);
    printf("\nBooking Done For Car ID:%d",CC.car_id);
    printf("\nPress any key to continue...");
    getch();
    fclose(fp);
    updateCarCount(c,0);
    bookedCarDetails();
    return 1;
}
void availCarDetails()
{
    FILE *fp=fopen("car.bin","rb");
    Car C;
    int i,x=10;
    textcolor(YELLOW);
    gotoxy(40,2);
    printf("Car Rental System\n");
    textcolor(LIGHTGREEN);
    for(i=0;i<96;i++)
        printf("%c",247);
    gotoxy(36,5);
    textcolor(YELLOW);
    printf("* AVAILABLE CAR  DETAILS *\n\n");
    textcolor(LIGHTGREEN);
    for(i=0;i<96;i++)
    printf("%c",247);
    if(fp==NULL)
    {
        gotoxy(36,9);
        textcolor(LIGHTRED);
        printf("Sorry! Cannot open the file");
        getch();
        return;
    }
    gotoxy(1,9);
    for(i=0;i<96;i++)
        printf("%c",247);
     gotoxy(1,8);
     printf(" Car ID\t\tModel\t\tCapacity\t\tAvailable\t\tPrice/Day");
     textcolor(YELLOW);
     while(fread(&C,sizeof(C),1,fp)==1)
     {
         if(C.car_count>0)
         {
         gotoxy(4,x);
         printf("%d",C.car_id);
        gotoxy(17,x);
        printf("%s",C.car_name);
        gotoxy(37,x);
        printf("%d",C.capacity);
        gotoxy(61,x);
        printf("%d",C.car_count);
        gotoxy(81,x);
        printf("%d",C.price);
        x++;
         }
     }
    fclose(fp);
    gotoxy(72,6);
    textcolor(WHITE);
    printf("Press any key to go back");
    getch();
}
int  deleteRecord(char *name,int c_id)
{
    FILE *fp1=fopen("cust.bin","rb");
    int result;
     if(fp1==NULL)
    {
        clrscr();
        gotoxy(36,9);
        textcolor(LIGHTRED);
        printf("Sorry ! Cannot Open File");
        getch();
        return 0;
    }
    FILE *fp2=fopen("temp.bin","wb+");
    if(fp2==NULL)
    {
        clrscr();
        gotoxy(36,9);
        textcolor(LIGHTRED);
        printf("Sorry ! Cannot Open File");
        getch();
        return 0;
    }
    Customer_Car_Details CC;
    while(fread(&CC,sizeof(CC),1,fp1)==1)
    {
        if((strcmp(CC.cust_name,name)!=0)&&(CC.car_id!=c_id))
            fwrite(&CC,sizeof(CC),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    result=remove("cust.bin");
        if(result!=0)
        {
               gotoxy(30,22);
                textcolor(LIGHTRED);
                printf("Sorry! Error in deletion.Try again ! 1");
                return -1;
        }
 result=rename("temp.bin","cust.bin");
        if(result!=0)
    {
            gotoxy(30,22);
             textcolor(LIGHTRED);
             printf("Sorry! Error in deletion.Try again !");
             return -1;
    }
    return 1;
}
int returnCar ()
{
      clrscr();
      int i,id,flag=0;
      Customer_Car_Details CC;
      char name[30];
      char *pos;
      gotoxy(40,2);
      textcolor(RED);
      printf("CAR RENTAL SYSTEM");
      gotoxy(44,8);
       textcolor(GREEN);
      printf("EMPLOYEE MENU\n");
       for( i=0;i<96;i++)
             printf("*");
     gotoxy(1,20);
     for(i=0;i<96;i++)
             printf("*");
    textcolor(WHITE);
    gotoxy(80,8);
    printf("Press 0 to exit");
    FILE*fp=fopen("cust.bin","rb");
    if(fp==NULL)
    {
        gotoxy(36,21);
        textcolor(LIGHTRED);
        printf("Sorry! Cannot open the file");
        getch();
        gotoxy(36,21);
        printf("\t\t\t");
        return -1;
    }
    do
    {
       gotoxy(36,14);
       textcolor(YELLOW);
        printf("Enter Customer Name :");
        fflush(stdin);
        textcolor(WHITE);
        fgets(name,30,stdin);
        if(name[0]=='0')
        {
            fclose(fp);
            return 0;
        }
        pos=strchr(name,13);
        if(pos!=NULL)
           *pos='\0';
    gotoxy(36,15);
    textcolor(YELLOW);
    printf("Enter Car ID :");
    textcolor(WHITE);
    scanf("%d",&id);
        if(id==0)
        {
            fclose(fp);
            return 0;
        }
    while(fread(&CC,sizeof(CC),1,fp)==1)
    {
        if((strcmp(CC.cust_name,name)==0)&&(CC.car_id==id))
        {
            flag++;
            break;
        }
     }
     if(flag==0)
     {
        gotoxy(40,22);
        textcolor(LIGHTRED);
        printf("%s",name);
        gotoxy(18,23);
        printf("Has Not Booked Any Car, Please Try Again or Press 0 To Exit");
        getch();
        gotoxy(40,22);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(18,23);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(50,15);
        printf("\t\t\t");
        gotoxy(57,14);
        printf("\t\t\t");
        gotoxy(57,14);
        textcolor(WHITE);
    }
    else
        break;
    }while(1);
    i=checkCurrentDate(CC.ed);
    if(i==0)
        {
             gotoxy(30,22);
             textcolor(LIGHTRED);
             printf("You Have to Return Car on %d/%d/%d",CC.ed.tm_mday,CC.ed.tm_mon,CC.ed.tm_year);
             gotoxy(26,23);
             printf("For Late Returing You Have To Deposit Fine of 500 rs");
             getch();
            gotoxy(30,22);
            printf("\t\t\t\t\t\t\t");
            gotoxy(26,23);
            printf("\t\t\t\t\t\t\t");
        }
        fclose(fp);
        i=deleteRecord(name,CC.car_id);
        if(i==1)
        {
        updateCarCount(CC.car_id,1);
        }
        return 1;
}
