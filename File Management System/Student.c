#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
struct date{int month,day,year;};
struct {int id,age,batch; char name[10]; char dept[12]; double phone; struct date dob; struct date aob;}Ad,Up,Rm,check;
int i,j,main_exit;
COORD coord ={0,0};
void Loading(int j);
void close(void);
void menu(void);
void add();
void view();
void del(void);
void find(void);
void up_info(void);
void gotoxy(int x,int y);
int main(){
    char pass[10],ch,password[10]="arafath";
    system("cls");
    system("color 6");
    gotoxy(40,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(40,5);
    printf("Enter Password:");
   // scanf("%s",&pass);
        while(ch!=13)
        {
        ch=getch();

        if(ch!=13 && ch!=8){
        putch('*');
        pass[i] = ch;
        i++;
        }
    }
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
void Loading(int j){
int i,k;
for(i=0;i<j;i++){
    k=i;
}
}
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
void add(){
    int choice;
    FILE *AR;
    AR=fopen("record.dat","a+");
    id_no:
        system("cls");
    gotoxy(40,2);
    printf("\xB2\xB2\xB2 ADD INFORMATION \xB2\xB2\xB2");
    gotoxy(20,5);
    printf("Enter Todays date(mm/dd/yy):");
    scanf("%d/%d/%d",&Ad.aob.month,&Ad.aob.day,&Ad.aob.year);
    gotoxy(20,7);
    printf("Enter ID:");
    scanf("%d",&check.id);
    while(fscanf(AR,"%d %s %d/%d/%d %d %s %lf %d %d/%d/%d\n",&Ad.id,Ad.name,&Ad.aob.month,&Ad.aob.day,&Ad.aob.year,&Ad.batch,Ad.dept,&Ad.phone,&Ad.age,&Ad.dob.month,&Ad.dob.day,&Ad.dob.year)!=EOF){
          if(check.id==Ad.id){
             printf("ID no is already use!");
             Loading(100000);
             goto id_no;
          }
    }
    Ad.id=check.id;
    gotoxy(20,9);
    printf("Enter First Name:");
    scanf("%s",Ad.name);
    gotoxy(20,11);
    printf("Enter Batch:");
    scanf("%d",&Ad.batch);
    gotoxy(20,13);
    printf("Enter Department:");
    scanf("%s",Ad.dept);
    gotoxy(20,15);
    printf("Enter Phone number:+880-");
    scanf("%lf",&Ad.phone);
    gotoxy(20,17);
    printf("Enter date of birth(mm/dd/yy):");
    scanf("%d/%d/%d",&Ad.dob.month,&Ad.dob.day,&Ad.dob.year);
    gotoxy(20,19);
    printf("Enter Age:");
    scanf("%d",&Ad.age);
    fprintf(AR,"%d %s %d/%d/%d %d %s %lf %d  %d/%d/%d\n",Ad.id,Ad.name,Ad.aob.month,Ad.aob.day,Ad.aob.year,Ad.batch,Ad.dept,Ad.phone,Ad.age,Ad.dob.month,Ad.dob.day,Ad.dob.year);
    fclose(AR);
    gotoxy(20,21);
    printf("Account created successfully");
    gotoxy(20,23);
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

void view(){
    FILE *show;
    show=fopen("record.dat","r");
    int test=0;
    system("cls");
    gotoxy(40,2);
    printf("\xB2\xB2\xB2 ALL LIST \xB2\xB2\xB2\n\n\n");
    while(fscanf(show,"%d %s %d/%d/%d %d %s %lf %d %d/%d/%d\n",&Ad.id,Ad.name,&Ad.aob.month,&Ad.aob.day,&Ad.aob.year,&Ad.batch,Ad.dept,&Ad.phone,&Ad.age,&Ad.dob.month,&Ad.dob.day,&Ad.dob.year)!=EOF){
    printf("Id:%d\t\tName:%s\t\tBatch:%d\t\tDepartment:%s\n",Ad.id,Ad.name,Ad.batch,Ad.dept);
    test++;
   }
    fclose(show);
     if(test==0){
        system("cls");
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
void del(void){
    FILE *old,*newrec;
    int test=0;
    old = fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    gotoxy(40,3);
    printf("\xB2\xB2\xB2 DELETE RECORD \xB2\xB2\xB2");
    gotoxy(20,7);
    printf("Enter Your Account No:");
    scanf("%d",&Rm.id);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %lf %d %d/%d/%d\n",&Ad.id,Ad.name,&Ad.aob.month,&Ad.aob.day,&Ad.aob.year,&Ad.batch,Ad.dept,&Ad.phone,&Ad.age,&Ad.dob.month,&Ad.dob.day,&Ad.dob.year)!=EOF){
        if(Ad.id!=Rm.id){
               fprintf(newrec,"%d %s %d/%d/%d  %d %s %lf  %d %d/%d/%d\n",Ad.id,Ad.name,Ad.aob.month,Ad.aob.day,Ad.aob.year,Ad.batch,Ad.dept,Ad.phone,Ad.age,Ad.dob.month,Ad.dob.day,Ad.dob.year);

        }
        else{

            test++;
            gotoxy(20,7);
            printf("Record delete Successfully !");
        }
    }
        fclose(old);
        fclose(newrec);
        remove("record.dat");
        rename("new.dat","record.dat");
        if(test==0){
            gotoxy(20,7);
            printf("Record not found!");
            gotoxy(20,9);
            printf("Enter 1 to try agian ,0 to main menu And any other key to exit:");
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
void find(void){
    FILE*AR;
    int test=0,choice;
    AR=fopen("record.dat","r");
    gotoxy(40,3);
    printf("\xB2\xB2\xB2 FIND INFORMATION \xB2\xB2\xB2");
    gotoxy(30,7);
    printf("Do you want to chek by");
    gotoxy(30,9);
    printf("[1].ID");
    gotoxy(30,11);
    printf("[2].NAME");
    gotoxy(30,13);
    printf("Enter:");
    scanf("%d",&choice);
    if(choice==1){
        gotoxy(30,15);
        printf("Enter id No:");
        scanf("%d",&check.id);
        while(fscanf(AR,"%d %s %d/%d/%d %d %s %lf %d %d/%d/%d\n",&Ad.id,Ad.name,&Ad.aob.month,&Ad.aob.day,&Ad.aob.year,&Ad.batch,Ad.dept,&Ad.phone,&Ad.age,&Ad.dob.month,&Ad.dob.day,&Ad.dob.year)!=EOF){
            if(check.id==Ad.id){
                system("cls");
                test=1;
                gotoxy(40,2);
                printf("\xB2\xB2\xB2 INFORMATION \xB2\xB2\xB2");
                gotoxy(30,5);
                printf("ID: %d",Ad.id);
                gotoxy(30,7);
                printf("Name: %s",Ad.name);
                gotoxy(30,9);
                printf("Admitted Date: %d/%d/%d",Ad.aob.month,Ad.aob.day,Ad.aob.year);
                gotoxy(30,11);
                printf("Batch: %d",Ad.batch);
                gotoxy(30,13);
                printf("Department: %s",Ad.dept);
                gotoxy(30,15);
                printf("Phone: +880-%.0lf",Ad.phone);
                gotoxy(30,17);
                printf("Age: %d",Ad.age);
                gotoxy(30,19);
                printf("Birth Date: %d/%d/%d",Ad.dob.month,Ad.dob.day,Ad.dob.year);
            }
        }
    }
    else if(choice==2){
        gotoxy(30,15);
        printf("Enter Name:");
        scanf("%s",&check.name);
         while(fscanf(AR,"%d %s %d/%d/%d %d %s %lf %d %d/%d/%d\n",&Ad.id,Ad.name,&Ad.aob.month,&Ad.aob.day,&Ad.aob.year,&Ad.batch,Ad.dept,&Ad.phone,&Ad.age,&Ad.dob.month,&Ad.dob.day,&Ad.dob.year)!=EOF){
            if(strcmpi(Ad.name,check.name)==0){
                system("cls");
                test=1;
                gotoxy(40,2);
                printf("\xB2\xB2\xB2 INFORMATION \xB2\xB2\xB2");
                gotoxy(30,5);
                printf("ID: %d",Ad.id);
                gotoxy(30,7);
                printf("Name: %s",Ad.name);
                gotoxy(30,9);
                printf("Admitted Date: %d/%d/%d",Ad.aob.month,Ad.aob.day,Ad.aob.year);
                gotoxy(30,11);
                printf("Batch: %d",Ad.batch);
                gotoxy(30,13);
                printf("Department: %s",Ad.dept);
                gotoxy(30,15);
                printf("Phone: +880-%.0lf",Ad.phone);
                gotoxy(30,17);
                printf("Age: %d",Ad.age);
                gotoxy(30,19);
                printf("Birth Date: %d/%d/%d",Ad.dob.month,Ad.dob.day,Ad.dob.year);
            }
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
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {
           gotoxy(30,21);
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
void up_info(void){
        int choice,test=0;
        FILE *old,*newrec;
        old=fopen("record.dat","r");
        newrec=fopen("new.dat","w");
        printf("Enter id:");
        scanf("%d",&Up.id);
        while(fscanf(old,"%d %s %d/%d/%d %d %s %lf %d %d/%d/%d\n",&Ad.id,Ad.name,&Ad.aob.month,&Ad.aob.day,&Ad.aob.year,&Ad.batch,Ad.dept,&Ad.phone,&Ad.age,&Ad.dob.month,&Ad.dob.day,&Ad.dob.year)!=EOF){
            if(Ad.id==Up.id){
                test=1;
                printf("Which information do you want to change:\n[1]Age\n[2].Phone\nEnter:");
                scanf("%d",&choice);
                system("cls");
                if(choice==1){
                    printf("Enter New Age:\n");
                    scanf("%d",&Up.age);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %lf %d %d/%d/%d\n",Ad.id,Ad.name,Ad.aob.month,Ad.aob.day,Ad.aob.year,Ad.batch,Ad.dept,Ad.phone,Up.age,Ad.dob.month,Ad.dob.day,Ad.dob.year);
                    system("cls");
                    printf("Change save!");
                }
                else if(choice==2){
                    printf("Enter New Phone No:\n");
                    scanf("%lf",&Up.phone);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %lf %d %d/%d/%d\n",Ad.id,Ad.name,Ad.aob.month,Ad.aob.day,Ad.aob.year,Ad.batch,Ad.dept,Up.phone,Ad.age,Ad.dob.month,Ad.dob.day,Ad.dob.year);
                    system("cls");
                    printf("Change save!");
                }
            }
                else
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %lf %d %d/%d/%d\n",Ad.id,Ad.name,Ad.aob.month,Ad.aob.day,Ad.aob.year,Ad.batch,Ad.dept,Ad.phone,Ad.age,Ad.dob.month,Ad.dob.day,Ad.dob.year);

        }
        fclose(old);
        fclose(newrec);
        remove("record.dat");
        rename("new.dat","record.dat");
        if(test!=1){
            printf("Enter 1 to try again or 0 to mainmenu and any other key to exit:");
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
            printf("\n\nEnter 1 to menu And any other key to exit:");
            scanf("%d",&main_exit);
            system("cls");
            if(main_exit==1)
                menu();
            else
                close();
        }
}
void gotoxy(int x,int y){
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

