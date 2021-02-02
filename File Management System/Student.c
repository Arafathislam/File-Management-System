#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
struct {int id,age,phn,fee,session;char fname[10],lname[10],dept[12],batch[8],date[14];}Ad,Up,Rm,check,Tr; // collection
int i,j,main_exit; // global variable
COORD coord ={0,0};
void Loading(int j); // timing
void close(void);
void menu(void);
void add();
void view();
void del(void);
void find(void);
void up_info(void);
void trans(void);
void gotoxy(int x,int y);
                                                    /* Main function */
int main(){
    char pass[10],ch,password[10]="arafath"; // Password
    system("cls");
    system("color 6");
    gotoxy(50,1);
    printf("%s",__TIME__); // real time
    gotoxy(40,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(40,5);
    printf("Enter Password:");
        scanf("%s",&pass);
        /*while(ch!=13)
        {
        ch=getch();

        if(ch!=13 && ch!=8){
        putch('*');
        pass[i] = ch;
        i++;
        }
    }*/
    if(strcmp(pass,password)==0){
        gotoxy(40,7);
       printf("Password Match\n");
       for(i=0;i<30;i++){
        Loading(100000000);
        printf("\xdb");
       }
       system("cls");
       menu();
       }
       else{
        gotoxy(40,7);
        printf("Invalid Password!");
        loging_try:
            gotoxy(40,9);
            printf("Enter 1 to again and 0 to exit:");
            scanf("%d",&main_exit);
            if(main_exit==1){
                system("cls");
                main();
            }
            else if(main_exit==0){
                system("cls");
                close();
            }
            else{
                system("cls");
                Loading(10000);
                goto loging_try;
            }
       }

    return 0;
}
                                            /* Timing Function*/
void Loading(int j){
int i,k;
for(i=0;i<j;i++){
    k=i;
}
}
                                                    /* Closing Function*/
void close(void){
    char a[20]=" Thank You ";
    gotoxy(30,7);
    for(i=0;i<20;i++){
        Sleep(50);
        printf(":");
    }
    for(i=0;i<12;i++){
        Sleep(50);
        printf("%c",a[i]);
    }
    for(i=0;i<20;i++){
        Sleep(50);
        printf(":");
    }
    getch();
}
                                                            /*Menu Function*/
void menu(void){
    int choice ;
    system("cls");
    system("color 9");
    char d[30]=" STUDENT MANAGEMENT SYSTEM ";
    gotoxy(30,2);
    for(i=0;i<20;i++){
        Sleep(50);
        printf("\xB2");
    }
    for(i=0;i<28;i++){
        Sleep(50);
        printf("%c",d[i]);
    }
    for(i=0;i<20;i++){
        Sleep(50);
        printf("\xB2");
    }

    gotoxy(40,6);
    printf("[1].Add Information");
    gotoxy(40,8);
    printf("[2].Delete Information");
    gotoxy(40,10);
    printf("[3].Find Information");
    gotoxy(40,12);
    printf("[4].Update Information");
    gotoxy(40,14);
    printf("[5].View All Information");
    gotoxy(40,16);
    printf("[6].Transaction");
    gotoxy(40,18);
    printf("Enter:");
    scanf("%d",&choice);
    system("cls");
    switch(choice){
        case 1:add();
        break;
        case 2:del();
        break;
        case 3:find();
        break;
        case 4:up_info();
        break;
        case 5:view();
        break;
        case 6:trans();
        break;
        default:{
            gotoxy(40,4);
            printf("Invalid!");
            gotoxy(40,6);
            printf("Enter 1 to again or Any other key to Exit:\n");
            scanf("%d",&main_exit);
            if(main_exit==1){
                system("cls");
                menu();
            }
            else{
                system("cls");
                close();
            }
            break;
        }

    }


}
                                                            /*Adding Function*/
void add(){
    int choice;
    FILE *AR;
    AR=fopen("record.txt","a+");
    id_no:
        system("cls");
    gotoxy(40,2);
    printf("\xB2\xB2\xB2 ADD INFORMATION \xB2\xB2\xB2");
    gotoxy(20,7);
    printf("Enter ID:");
    scanf("%d",&check.id);
    while(fscanf(AR,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s",&Ad.id,Ad.fname,Ad.lname,Ad.batch,Ad.dept,&Ad.age,&Ad.phn,&Ad.session,&Ad.fee,Ad.date)!=EOF){
          if(check.id==Ad.id){
             gotoxy(40,5);
             printf("ID no is already use!");
             Loading(100000000000);
             goto id_no;
          }
    }
    Ad.id=check.id;
    gotoxy(20,9);
    printf("Enter First Name:");
    fflush(stdin);
    gets(Ad.fname);
    gotoxy(20,11);
    printf("Enter Last Name:");
    fflush(stdin);
    gets(Ad.lname);
    gotoxy(20,13);
    printf("Enter your Dept:");
    fflush(stdin);
    gets(Ad.dept);
    gotoxy(20,15);
    printf("Enter your Batch:");
    fflush(stdin);
    gets(Ad.batch);
    gotoxy(20,17);
    printf("Enter your age:");
    fflush(stdin);
    scanf("%d",&Ad.age);
    gotoxy(20,19);
    printf("Enter your number:+880 - ");
    fflush(stdin);
    scanf("%d",&Ad.phn);
    gotoxy(20,21);
    printf("Enter your session:");
    fflush(stdin);
    scanf("%d",&Ad.session);
    gotoxy(20,23);
    printf("Enter Date(dd-mm-yy):");
    fflush(stdin);
    gets(Ad.date);

    Ad.fee=0;
    fprintf(AR,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n",Ad.id,Ad.fname,Ad.lname,Ad.batch,Ad.dept,Ad.age,Ad.phn,Ad.session,Ad.fee,Ad.date);
    fclose(AR);
    gotoxy(20,27);
    printf("Account created successfully");
    gotoxy(20,29);
    printf("Enter 1 to the Main menu and any other key to Exit:");
    scanf("%d",&main_exit);
    system("cls");
    if(main_exit==1){
        menu();
    }
    else{
        close();
    }
}
                                /* Showing All Data */
void view(){
    FILE *show;
    show=fopen("record.txt","r");
    int test=0;
    system("cls");
    gotoxy(40,2);
    printf("\xB2\xB2\xB2 ALL LIST \xB2\xB2\xB2\n\n\n");
    while(fscanf(show,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s",&Ad.id,Ad.fname,Ad.lname,Ad.batch,Ad.dept,&Ad.age,&Ad.phn,&Ad.session,&Ad.fee,Ad.date)!=EOF){
    printf("Id:%d\t\Name:%s %s\t\tBatch:%s\t\tDepartment:%s\n",Ad.id,Ad.fname,Ad.lname,Ad.batch,Ad.dept);
    test++;
   }
    fclose(show);
     if(test==0){
        system("cls");
        gotoxy(40,5);
        printf("NO Records!\n");
    }
    printf("\n\nEnter 1 to mainmenu and any other key to exit");
    scanf("%d",&main_exit);
    system("cls");
    if(main_exit==1){
        menu();
    }
    else{
        close();
    }
}
                                            /*Deleting Function*/
void del(void){
    FILE *old,*newrec;
    int test=0;
    old = fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    gotoxy(40,3);
    printf("\xB2\xB2\xB2 DELETE RECORD \xB2\xB2\xB2");
    gotoxy(20,7);
    printf("Enter Your ID No:");
    scanf("%d",&Rm.id);
    while(fscanf(old,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s",&Ad.id,Ad.fname,Ad.lname,Ad.batch,Ad.dept,&Ad.age,&Ad.phn,&Ad.session,&Ad.fee,Ad.date)!=EOF){
        if(Ad.id!=Rm.id){
               fprintf(newrec,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n",Ad.id,Ad.fname,Ad.lname,Ad.batch,Ad.dept,Ad.age,Ad.phn,Ad.session,Ad.fee,Ad.date);

        }
        else{

            test++;
            gotoxy(20,7);
            printf("Record delete Successfully !");
        }
    }
        fclose(old);
        fclose(newrec);
        remove("record.txt");
        rename("new.txt","record.txt");
        if(test==0){
            system("cls");
            gotoxy(20,7);
            printf("Record not found!");
            gotoxy(20,9);
            printf("Enter 1 to try again ,0 to main menu And any other key to exit:");
            scanf("%d",&main_exit);
            if(main_exit==1)
                del();
            else if(main_exit==0)
                menu();
            else
                close();
        }
        else{
            gotoxy(20,9);
            printf("Enter 1 to menu And any other key to exit:");
            scanf("%d",&main_exit);
            if(main_exit==1)
                menu();
            else
                close();
        }
}
                                                /*Finding Fucntion*/
void find(void){
    FILE*AR;
    int test=0,choice;
    AR=fopen("record.txt","r");
    gotoxy(40,3);
    printf("\xB2\xB2\xB2 FIND INFORMATION \xB2\xB2\xB2");
    gotoxy(30,7);
    printf("Enter id No:");
    scanf("%d",&check.id);
        while(fscanf(AR,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s",&Ad.id,Ad.fname,Ad.lname,Ad.batch,Ad.dept,&Ad.age,&Ad.phn,&Ad.session,&Ad.fee,Ad.date)!=EOF){
            if(check.id==Ad.id){
                system("cls");
                test=1;
                gotoxy(40,2);
                printf("\xB2\xB2\xB2 INFORMATION \xB2\xB2\xB2");
                gotoxy(30,5);
                printf("ID: %d",Ad.id);
                gotoxy(30,7);
                printf("Name: %s %s",Ad.fname,Ad.lname);
                gotoxy(30,9);
                printf("Session:%d",Ad.session);
                gotoxy(30,11);
                printf("Batch: %s",Ad.batch);
                gotoxy(30,13);
                printf("Department: %s",Ad.dept);
                gotoxy(30,15);
                printf("Phone: +880 - %d",Ad.phn);
                gotoxy(30,17);
                printf("Age: %d",Ad.age);
                gotoxy(30,19);
                printf("Total paid: %d",Ad.fee);
                gotoxy(30,21);
                printf(" Cardite Completed:%d",Ad.fee/1500);
                gotoxy(30,23);
                printf("Admitted Date:%s",Ad.date);
            }
        }
        fclose(AR);
         if(test!=1)
        {   system("cls");
            gotoxy(30,4);
            printf("Record not found!!\a\a\a");
            see_invalid:
                gotoxy(30,6);
              printf("Enter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    find();
                else
                    {
                        system("cls");
                        gotoxy(30,8);
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {
           gotoxy(30,25);
            printf("Enter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
             close();
            }

}
                                            /*Updating Function*/
void up_info(void){
        int choice,test=0;
        FILE *old,*newrec;
        old=fopen("record.txt","r");
        newrec=fopen("new.txt","w");
        gotoxy(40,1);
        printf("\xB2\xB2\xB2 Update INFORMATION \xB2\xB2\xB2");
        gotoxy(30,5);
        printf("Enter id:");
        scanf("%d",&Up.id);
        while(fscanf(old,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s",&Ad.id,Ad.fname,Ad.lname,Ad.batch,Ad.dept,&Ad.age,&Ad.phn,&Ad.session,&Ad.fee,Ad.date)!=EOF){
            if(Ad.id==Up.id){
                test=1;
                system("cls");
                push_invalid:
                gotoxy(40,3);
                printf("\xB2\xB2\xB2 Update INFORMATION \xB2\xB2\xB2");
                gotoxy(30,5);
                printf("[1].Age");
                gotoxy(30,7);
                printf("[2].Phone");
                gotoxy(30,9);
                printf("[3].Batch");
                gotoxy(30,11);
                printf("[4].Department");
                gotoxy(30,13);
                printf("Enter:");
                scanf("%d",&choice);
                system("cls");
                if(choice==1){
                    printf("Enter New Age: ");
                    scanf("%d",&Up.age);
                    fprintf(newrec,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n",Ad.id,Ad.fname,Ad.lname,Ad.batch,Ad.dept,Up.age,Ad.phn,Ad.session,Ad.fee,Ad.date);
                    system("cls");
                    gotoxy(30,2);
                    printf("Change save!");
                }
                else if(choice==2){
                    printf("Enter New Phone No:+880 - ");
                    scanf("%d",&Up.phn);
                    fprintf(newrec,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n",Ad.id,Ad.fname,Ad.lname,Ad.batch,Ad.dept,Ad.age,Up.phn,Ad.session,Ad.fee,Ad.date);
                    system("cls");
                    gotoxy(30,2);
                    printf("Change save!");
                }
                  else if(choice==3){
                    printf("Enter New Batch: ");
                    fflush(stdin);
                    gets(Up.batch);
                    fprintf(newrec,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n",Ad.id,Ad.fname,Ad.lname,Up.batch,Ad.dept,Ad.age,Ad.phn,Ad.session,Ad.fee,Ad.date);
                    system("cls");
                    gotoxy(30,2);
                    printf("Change save!");
                }
                  else if(choice==4){
                    printf("Enter New Department: ");
                    fflush(stdin);
                    gets(Up.dept);
                    Ad.fee=0;
                    fprintf(newrec,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n",Ad.id,Ad.fname,Ad.lname,Ad.batch,Up.dept,Ad.age,Ad.phn,Ad.session,Ad.fee,Ad.date);
                    system("cls");
                    gotoxy(30,2);
                    printf("Change save!");
                }
                else{
                    gotoxy(40,1);
                    printf("Invalid Please try again!");
                    goto push_invalid;

                }
            }
                else
                    fprintf(newrec,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n",Ad.id,Ad.fname,Ad.lname,Ad.batch,Ad.dept,Ad.age,Ad.phn,Ad.session,Ad.fee,Ad.date);

        }
        fclose(old);
        fclose(newrec);
        remove("record.txt");
        rename("new.txt","record.txt");
        if(test!=1){
            gotoxy(30,8);
            printf("Enter 1 to try again or 0 to main menu and any other key to exit:");
            scanf("%d",&main_exit);
            system("cls");
            if(main_exit==1)
                up_info();
            else if(main_exit==0)
                menu();
            else
                close();
        }
        else{
            gotoxy(30,4);
            printf("Enter 1 to menu And any other key to exit:");
            scanf("%d",&main_exit);
            system("cls");
            if(main_exit==1)
                menu();
            else
                close();
        }
}
                                                /* Transaction Function*/
void trans(void){
        FILE *old,*newrec;
        int test=0;
        old=fopen("record.txt","r");
        newrec=fopen("new.txt","w");
        gotoxy(40,2);
        printf("\xB2\xB2\xB2 Transcation INFORMATION \xB2\xB2\xB2");
        gotoxy(30,4);
        printf("Enter your ID:");
        scanf("%d",&Tr.id);
        while(fscanf(old,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s",&Ad.id,Ad.fname,Ad.lname,Ad.batch,Ad.dept,&Ad.age,&Ad.phn,&Ad.session,&Ad.fee,Ad.date)!=EOF){
            if(Tr.id==Ad.id){
                test=1;
                try_again:
                gotoxy(30,6);
                printf("Enter your cardite:");
                scanf("%d",&Tr.fee);
                if(Tr.fee<=15){
                   Ad.fee+=Tr.fee*1500;
                }else{
                    system("cls");
                    gotoxy(30,2);
                    printf("You cannot carry more then 15 cardite!");
                    goto try_again;
                }


            fprintf(newrec,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n",Ad.id,Ad.fname,Ad.lname,Ad.batch,Ad.dept,Ad.age,Ad.phn,Ad.session,Ad.fee,Ad.date);
            gotoxy(30,8);
            printf("%d ID fee paid successfully",Ad.id);

            } else
                    fprintf(newrec,"%d\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n",Ad.id,Ad.fname,Ad.lname,Ad.batch,Ad.dept,Ad.age,Ad.phn,Ad.session,Ad.fee,Ad.date);

        }
        fclose(old);
        fclose(newrec);
        remove("record.txt");
        rename("new.txt","record.txt");
        if(test!=1){
            gotoxy(30,6);
            printf("ID not found!!!Enter 1 to try again or 0 to main menu and any other key to exit:");
            scanf("%d",&main_exit);
            system("cls");
            if(main_exit==1)
                up_info();
            else if(main_exit==0)
                menu();
            else
                close();
        }
        else{
            gotoxy(30,10);
            printf("Enter 1 to menu And any other key to exit:");
            scanf("%d",&main_exit);
            system("cls");
            if(main_exit==1)
                menu();
            else
                close();
        }
}
                                                    /*Cursor at a Desired location on screen Function*/
void gotoxy(int x,int y){
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


