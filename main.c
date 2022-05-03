#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"car.h"
int main()
{
    int i,type,k,choice,result;
    User *usr;
     gotoxy(32,12);
     textcolor(YELLOW);
     printf("WELCOME TO CAR RENTAL SYSTEM");
     gotoxy(27,16);
     textcolor(GREEN);
     printf("* RENT A CAR AND GO WHEREVER YOU NEED *");
     getch();
     addAdmin();
     while(1)
     {
           clrscr();
           gotoxy(40,2);
           textcolor(RED);
           printf("CAR RENTAL SYSTEM");
           gotoxy(1,10);
           textcolor(YELLOW);
         for(i=0;i<96;i++)
         {
             printf("*");
         }
          gotoxy(1,20);
          for(i=0;i<96;i++)
         {
             printf("*");
         }
               gotoxy(40,12);
               printf("1.Admin");
               gotoxy(40,14);
               printf("2.Employe");
               gotoxy(40,16);
               printf("3.Exit");
               gotoxy(40,18);
               textcolor(WHITE);
               printf("Select an operation:");
            do
            {
               scanf("%d",&type);
               k=0;
               if(type==1)
               {
                   do
                   {
                       usr=getInput();
                       if(usr!=NULL)
                             k=checkUserExit(*usr,"admin");
                       else
                       {
                           k=-1;
                          break;
                       }
                   }while(k==0);
                                if(k==-1)
                                       break;
                                if(k==1)
                                 {
                                           gotoxy(1,25);
                                           textcolor(WHITE);
                                            printf("Press any key to continue");
                                            getch();
                              while(1)
                            {
                                        clrscr();
                                         choice=adminMenu();
                                             if(choice==7)
                                                      break;
                                             switch(choice)
                                             {
                                             case 1:
                                                clrscr();
                                                addEmployee();
                                                break;
                                            case 2:
                                                clrscr();
                                                addCarDetails();
                                               break;
                                            case 3:
                                                clrscr();
                                                 viewEmpolyee();
                                                 break;
                                            case 4:
                                                clrscr();
                                                showCarDetails();
                                                 break;
                                            case 5:
                                                clrscr();
                                                result=deleteEmp();
                                                gotoxy(32,16);
                                                if(result==0)
                                                {
                                                    textcolor(LIGHTRED);
                                                    printf("Sorry! NO Empolyee found for given Emp-ID");
                                                }
                                                else if(result==1)
                                                {
                                                    textcolor(LIGHTGREEN);
                                                    printf("Record Deleted Sucessfully");
                                                }
                                                  else if(result==2)
                                                {
                                                    textcolor(LIGHTRED);
                                                    printf("Sorry! Error in deletion.Try again !");
                                                }
                                                  textcolor(WHITE);
                                                  printf("\n\nPress any key to go back to the main screen!");
                                                  getch();
                                                  break;
                                            case 6:
                                                clrscr();
                                                 result=deleteCarModel();
                                                gotoxy(32,16);
                                                if(result==0)
                                                {
                                                    textcolor(LIGHTRED);
                                                    printf("Sorry! NO Car found for given CAR-ID");
                                                }
                                                else if(result==1)
                                                {
                                                    textcolor(LIGHTGREEN);
                                                    printf("Record Deleted Sucessfully");
                                                }
                                                  else if(result==2)
                                                {
                                                    textcolor(LIGHTRED);
                                                    printf("Sorry! Error in deletion.Try again !");
                                                }
                                                  textcolor(WHITE);
                                                  printf("\n\nPress any key to go back to the main screen!");
                                                  getch();
                                                 break;
                                            default:
                                                  gotoxy(40,23);
                                                 textcolor(RED);
                                                 printf("Incorrect Choice:");
                                                 getch();
                                                 gotoxy(40,23);
                                                printf("\t\t\t\t\t");
                                             }
                         }
                          if(choice==7)
                          {
                                                     clrscr();
                                                      break;
                          }
                   }
               }
               else if(type==2)
               {
                    do
                   {
                       usr=getInput();
                       if(usr!=NULL)
                             k=checkUserExit(*usr,"emp");
                       else
                       {
                           k=-1;
                          break;
                       }
                   }while(k==0);
                                if(k==-1)
                                       break;
                                if(k==1)
                                 {
                                           gotoxy(1,25);
                                           textcolor(WHITE);
                                            printf("Press any key to continue");
                                            getch();
                                while(1)
                            {
                                        clrscr();
                                         choice=empMenu();
                                             if(choice==6)
                                                      break;
                                             switch(choice)
                                             {
                                             case 1:
                                                clrscr();
                                                result=rentCar();
                                                if(result==-2)
                                                {
                                                    gotoxy(36,25);
                                                    textcolor(LIGHTRED);
                                                    printf("Sorry,All Car has Been Booked ,Try Again Later...");
                                                    getch();
                                                }
                                                else if(result==0)
                                                {
                                                    gotoxy(36,25);
                                                    textcolor(LIGHTRED);
                                                    printf("You Did Not Choose Any Car");
                                                    getch();
                                                }
                                                break;
                                             case 2:
                                                 result=returnCar();
                                                  if(result==1)
                                                {
                                                    gotoxy(32,25);
                                                    textcolor(LIGHTGREEN);
                                                    printf("Car Had Returned Sucessfully");
                                                    gotoxy(40,27);
                                                    printf("Thank You");
                                                    getch();
                                                }
                                                break;
                                            case 3:
                                                clrscr();
                                                bookedCarDetails();
                                               break;
                                            case 4:
                                                clrscr();
                                                 availCarDetails();
                                                 break;
                                            case 5:
                                                clrscr();
                                                showCarDetails();
                                                 break;
                                           default:
                                                  gotoxy(40,23);
                                                 textcolor(RED);
                                                 printf("Incorrect Choice:");
                                                 getch();
                                                 gotoxy(40,23);
                                                printf("\t\t\t\t\t");
                                 }
                            }
                            if(choice==6)
                          {
                                                     clrscr();
                                                      break;
                          }
                    }
               }
               else if(type==3)
               {
                   clrscr();
                   textcolor(BLUE);
                   gotoxy(32,14);
                   printf("THANK YOU FOR USING THE  CAR RENTAL APP");
                   exit(0);
               }
               else
               {
                   gotoxy(38,23);
                   textcolor(RED);
                   printf("Invalid choice");
                   getch();
                   gotoxy(25,23);
                   printf("\t\t\t\t");
                   gotoxy(60,18);
                   printf("\t\t");
                   gotoxy(60,18);
               }
         }while(1);
     }
     return 0;
}

