                    #include <stdio.h>
                    #include <stdlib.h>
                    #include<string.h>
                    #include<windows.h>
                    #define s scanf
                    #define p printf

                    int index[100];
                    int troll[100];
                    struct student
                    {
                        int roll;
                        char fname[20];
                        char lname[20];
                        char grp[5];
                        double hgpa,sgpa;
                        int payed;

                    };
                    struct student data[100];
                    struct student temp;
                    struct student chh[100];///for using group file
                    void menu()
                    {

                             int time=19990,i;
                             fflush(stdout);
                            usleep(time);
                             printf("\n\t\t  %c%c%c%c STUDENT______INFO %c%c%c%c\n\n",206,206,206,177,177,206,206,206);
                                  for(i=1;i<=90;i++)
                      {
                          fflush(stdout);
                             usleep(10111);
                             p("%c",177);
                      }
                      p("\n\n");
                            fflush(stdout);
                            usleep(time);
                             printf("\t\t\t%c 1: Input data\n",220);
                            fflush(stdout);
                            usleep(time);
                             printf("\t\t\t%c 2: UPDATE\n",220);
                            fflush(stdout);
                            usleep(time);
                             printf("\t\t\t%c 3:delete\n",220);
                            fflush(stdout);
                            usleep(time);
                             printf("\t\t\t%c 4:Datalist(1/2)\n",220);
                            fflush(stdout);
                            usleep(time);
                             printf("\t\t\t%c 5:search\n",220);
                            fflush(stdout);
                            usleep(time);
                            printf("\t\t\t%c 6:Male/Female list\n",220);
                            fflush(stdout);
                            usleep(time);
                            printf("\t\t\t%c 7:Chage password\n",220);
                            fflush(stdout);
                            usleep(time);
                            printf("\t\t\t%c 8:View Groups\n",220);
                            fflush(stdout);
                            usleep(time);
                            printf("\t\t\t%c 9:INFO\n",220);
                            fflush(stdout);
                            usleep(time);
                             printf("\t\t\t%c 0:End\n\t\t\t",220);
                            fflush(stdout);
                            usleep(time);

                    }

                    void indata(x)
                    {
                        FILE *fulldata;
                        system("cls");
                        p("\t\t\t\t INPUT DATA\n\t\t________________________________________________\n");
                     printf("\n\t\t\t%c Enter data for student %d\n\n",254,x);
                      printf("\t\t\t%c Enter First name(e.g Mamun): ",175);
                      fflush(stdin);
                      s("%s",data[x].fname);
                       printf("\t\t\t%c Enter last name(e.g Mahmud): ",175);
                        fflush(stdin);
                      gets(data[x].lname);
                      printf("\t\t\t%c Admission Roll(C221046): C",175);
                        scanf("%d",&data[x].roll);
                      printf("\t\t\t%c SSC GPA: ",175);
                        scanf("%lf",&data[x].sgpa);
                          printf("\t\t\t%c HSC GPA: ",175);
                        scanf("%lf",&data[x].hgpa);
                     printf("\t\t\t%c Enter payed amount(integer):",175);
                        scanf("%d",&data[x].payed);

                        ///writing to fulldata
                        fulldata = fopen("fulldata.txt","a");
                        fprintf(fulldata,"%s\n%s\n%d\n%lf\n%lf\n%d\n",data[x].fname,data[x].lname,data[x].roll,data[x].sgpa,data[x].hgpa,data[x].payed);
                        fclose(fulldata);
                    x++;

                       ///new count for start file
                        FILE *start;
                        start = fopen("start.txt","w");
                        fprintf(start,"%d",x);
                        fclose(start);
                   group(x);

                    }

                    ///read and write code to full data in update file
                    void update(int c,int n)
                    {
                        int i,index,flag=0;
                        FILE *start,*fulldata;

                      c--;

                        ///reading and assigining from fulldata file
                        fulldata=fopen("fulldata.txt","r");
                        for(i=1;i<=c;i++)
                        fscanf(fulldata,"%s%s%d%lf%lf%d",data[i].fname,data[i].lname,&data[i].roll,&data[i].sgpa,&data[i].hgpa,&data[i].payed);
                        fclose(fulldata);


                     // p("\t\t\t%c Enter Roll to update:C",175);
                     // s("%d",&n);
                      for(i=1;i<=c;i++)
                      {
                          if(data[i].roll == n)
                          { flag =1;
                              printf("\n\t\t\t%c Update Following data \n",254);
                            printf("\t\t\t%c Name    : %s %s\n",201,data[i].fname,data[i].lname);
                            printf("\t\t\t%c Roll    :C-%d\n",186,data[i].roll);
                            printf("\t\t\t%c SSC GPA :%.2f\n",186,data[i].sgpa);
                            printf("\t\t\t%c HSC GPA :%.2f\n",186,data[i].hgpa);
                            printf("\t\t\t%c payed   :%d\n",186,data[i].payed);
                             if(data[i].sgpa == 5.00 && data[i].hgpa == 5.00)
                               {
                                 printf("\t\t\t%c Waiver  : YES!\n",186);
                                 printf("\t\t\t%c Due     :%d\n\n\n",200,60000 - data[i]. payed);
                               }
                             else
                               {
                                 printf("\t\t\t%c Waiver  : NO!\n",186);
                                 printf("\t\t\t%c Due     :%d\n\n\n",200,90000 - data[i]. payed);
                               }
                         p("\t\t\t%c Enter new first name(e.g Mamun):",175);
                      fflush(stdin);
                      gets(temp.fname);
                      p("\t\t\t%c Enter new last name(e.g Mahmud):",175);
                      fflush(stdin);
                      gets(temp.lname);
                      p("\t\t\t%c Enter new roll:C",175);
                      s("%d",&temp.roll);
                      p("\t\t\t%c Enter new SSC GPA:",175);
                      s("%lf",&temp.sgpa);
                      p("\t\t\t%c Enter new HSC GPA:",175);
                      s("%lf",&temp.hgpa);
                      p("\t\t\t%c Enter new payment:",175);
                      s("%d",&temp.payed);


                        for(i=1;i<=c;i++)
                        {
                         if(n == data[i].roll)
                          {
                           index = i;
                           break;
                          }
                        }
                            strcpy(data[index].fname,temp.fname);
                            strcpy(data[index].lname,temp.lname);
                            data[index].roll = temp.roll;
                            data[index].sgpa = temp.sgpa;
                            data[index].hgpa = temp.hgpa;
                            data[index].payed = temp.payed;

                      fulldata= fopen("fulldata.txt","w");
                      fclose(fulldata);
                       fulldata = fopen("fulldata.txt","a");
                        for(i=1;i<=c;i++)
                         {
                          fprintf(fulldata,"%s\n%s\n%d\n%lf\n%lf\n%d\n",data[i].fname,data[i].lname,data[i].roll,data[i].sgpa,data[i].hgpa,data[i].payed);
                         }
                       fclose(fulldata);
                    p("\n\t\t\t\ Successfully Updated!\n\n");

                     ///reading and assigining from fulldata file
                        fulldata=fopen("fulldata.txt","r");
                        for(i=1;i<=c;i++)
                        fscanf(fulldata,"%s%s%d%lf%lf%d",data[i].fname,data[i].lname,&data[i].roll,&data[i].sgpa,&data[i].hgpa,&data[i].payed);
                        fclose(fulldata);
                          for(i=1;i<=c;i++)
                      {
                          if(data[i].roll == temp.roll)
                          { printf("\t\t\t%c Updated Data \n\n",254);
                            printf("\t\t\t%c Name    : %s %s\n",201,data[i].fname,data[i].lname);
                            printf("\t\t\t%c Roll    :C-%d\n",186,data[i].roll);
                            printf("\t\t\t%c SSC GPA :%.2f\n",186,data[i].sgpa);
                            printf("\t\t\t%c HSC GPA :%.2f\n",186,data[i].hgpa);
                            printf("\t\t\t%c payed   :%d\n",186,data[i].payed);
                             if(data[i].sgpa == 5.00 && data[i].hgpa == 5.00)
                               {
                                 printf("\t\t\t%c Waiver  : YES!\n",186);
                                 printf("\t\t\t%c Due     :%d\n\n\n",200,60000 - data[i]. payed);
                               }
                             else
                               {
                                 printf("\t\t\t%c Waiver  : NO!\n",186);
                                 printf("\t\t\t%c Due     :%d\n\n\n",200,90000 - data[i]. payed);
                               }
                          }

                      }
                          }

                      }
                     if(flag == 0)
                        p("\t\t\t\ No data found!\n");
           c++;
                    group(c);
                    }

                    void deletee(c)
                    {     int i,n,j,index,flag =1;
                        FILE *start,*fulldata;
                      c--;
                        ///reading and assigining from fulldata file
                        fulldata=fopen("fulldata.txt","r");
                        for(i=1;i<=c;i++)
                        fscanf(fulldata,"%s%s%d%lf%lf%d",data[i].fname,data[i].lname,&data[i].roll,&data[i].sgpa,&data[i].hgpa,&data[i].payed);
                        fclose(fulldata);

                        p("\t\t\t%c Enter Roll to delete data:C",254);
                        s("%d",&n);

                           for(i=1;i<=c;i++)
                        {
                         if(n == data[i].roll)
                          {
                           index = i;
                           flag= 0;
                           break;
                          }
                        else
                        flag = 1;
                        }

                    if(flag==0)
                        {

                        for(i=index;i<=c-1;i++)
                         { j =i+1;
                         strcpy(data[i].fname,data[j].fname);
                        strcpy(data[i].lname,data[j].lname);
                        data[i].roll = data[j].roll;
                        data[i].sgpa = data[j].sgpa;
                        data[i].hgpa = data[j].hgpa;
                       data[i].payed = data[j].payed;
                         }
                         c--;
                          fulldata= fopen("fulldata.txt","w");
                      fclose(fulldata);
                       fulldata = fopen("fulldata.txt","a");
                        for(i=1;i<=c;i++)
                         {
                          fprintf(fulldata,"%s\n%s\n%d\n%lf\n%lf\n%d\n",data[i].fname,data[i].lname,data[i].roll,data[i].sgpa,data[i].hgpa,data[i].payed);
                         }
                       fclose(fulldata);
                    p("\t\t\t\t Successfully deleted!\n");
                    c++;

                     ///new count for start file

                        start = fopen("start.txt","w");
                        fprintf(start,"%d",c);
                        fclose(start);
                    }
                    if(flag == 1)
                        p("\t\t\t\ Data doesn't match!\n");


                    group(c);
                    }

                    void swap(int *x, int *y)
                    {
                        int t;
                        t = *x;
                        *x = *y;
                        *y = t;
                    }


                    void fulldataa(int c)
                    {

                         int i,j,ct=1,n,mainmenu,time=11999;

                        FILE *fulldata;
                        FILE *group;
                          system("Cls");
                          p("\t\t\t\t FULL DATA\n\t_____________________________________________________\n");
                        ///reading and assigining from fulldata file
                        fulldata=fopen("fulldata.txt","r");
                        for(i=1;i<=c;i++)
                        fscanf(fulldata,"%s%s%d%lf%lf%d",data[i].fname,data[i].lname,&data[i].roll,&data[i].sgpa,&data[i].hgpa,&data[i].payed);
                        fclose(fulldata);
                           ///reading from group file
                        group=fopen("group.txt","r");
                        for(i=1;i<=c;i++)
                        fscanf(group,"%d%s",&troll[i],chh[i].grp);
                        fclose(group);


                        for(i=1;i<=c;i++)
                        for(j=1;j<=c;j++)
                        {
                            if(data[i].roll == troll[j])
                                {
                                    strcpy(data[i].grp,chh[j].grp);

                                 break;
                                }
                        }


                       for(i=1;i<=c;i++)
                         {   p("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
                           p("\t\t\ %d%c\n",ct,245);
                           ct++;

                             fflush(stdout);
                            usleep(time);
                            printf("\t\t\t%c Name    :%s %s\n",201,data[i].fname,data[i].lname);
                            fflush(stdout);
                            usleep(time);
                            printf("\t\t\t%c Roll    :C-%d\n",186,data[i].roll);
                            fflush(stdout);
                            usleep(time);
                            printf("\t\t\t%c Group   :%s\n",186,data[i].grp);
                              fflush(stdout);
                            usleep(time);
                            printf("\t\t\t%c SSC GPA :%.2f\n",186,data[i].sgpa);
                             fflush(stdout);
                            usleep(time);
                            printf("\t\t\t%c HSC GPA :%.2f\n",186,data[i].hgpa);
                             fflush(stdout);
                            usleep(time);
                            printf("\t\t\t%c payed   :%d/-\n",186,data[i].payed);
                             fflush(stdout);
                            usleep(time);
                        if(data[i].sgpa == 5.00 && data[i].hgpa == 5.00)
                            {
                                printf("\t\t\t%c Waiver  : YES!\n",186);
                                 fflush(stdout);
                            usleep(time);
                                printf("\t\t\t%c Due     :%d/-\n\n",200,60000 - data[i]. payed);
                            }
                         else
                            {
                             printf("\t\t\t%c Waiver  : NO!\n",186);
                              fflush(stdout);
                            usleep(time);
                             printf("\t\t\t%c Due     :%d/-\n\n",200,90000 - data[i]. payed);
                            }
                        }
                        p("\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __\n\t\t\t%c Total students : %d\n\n",240,c);
                     p("\t\t\t%c Enter any number for main menu\n\t\t\t",175);
                    s("%d",&mainmenu);
                        system("cls");
                    }

                    void fullpayed(int c)
                    {
                          int i,j,n,mainmenu,ct=1,index,time=19999;
                        FILE *start,*fulldata,*group;
                        system("Cls");
                          p("\t\t\t\t FULL PAID\n\t_________________________________________________________\n");

                        ///reading and assigining from fulldata file
                        fulldata=fopen("fulldata.txt","r");
                        for(i=1;i<=c;i++)
                        fscanf(fulldata,"%s%s%d%lf%lf%d",data[i].fname,data[i].lname,&data[i].roll,&data[i].sgpa,&data[i].hgpa,&data[i].payed);
                        fclose(fulldata);
                           ///reading from group file
                        group=fopen("group.txt","r");
                        for(i=1;i<=c;i++)
                        fscanf(group,"%d%s",&troll[i],chh[i].grp);
                        fclose(group);

                        for(i=1;i<=c;i++)
                        for(j=1;j<=c;j++)
                        {
                            if(data[i].roll == troll[j])
                                {
                                    strcpy(data[i].grp,chh[j].grp);

                                 break;
                                }
                        }

                        for(i=1;i<=c;i++)
                        {
                            if(data[i].sgpa == 5.00 && data[i].hgpa == 5.00 && data[i].payed == 60000)
                             { p("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
                                p("\t\t\ %d%c\n",ct,245);
                                ct++;

                                  fflush(stdout);
                            usleep(time);
                               printf("\t\t\t%c Name    :%s %s\n",201,data[i].fname,data[i].lname);
                                fflush(stdout);
                            usleep(time);
                               printf("\t\t\t%c Roll    :C-%d\n",186,data[i].roll);
                                fflush(stdout);
                            usleep(time);
                               printf("\t\t\t%c Group    :%s\n",186,data[i].grp);
                                fflush(stdout);
                            usleep(time);
                               printf("\t\t\t%c SSC GPA :%.2f\n",186,data[i].sgpa);
                                fflush(stdout);
                            usleep(time);
                               printf("\t\t\t%c HSC GPA :%.2f\n",186,data[i].hgpa);
                                fflush(stdout);
                            usleep(time);
                               printf("\t\t\t%c payed   :%d/-\n",186,data[i].payed);
                                fflush(stdout);
                            usleep(time);
                               printf("\t\t\t%c Waiver  :YES!\n",186);
                                fflush(stdout);
                            usleep(time);
                               printf("\t\t\t%c Due     :00/-\n\n",200);
                             }
                         else if (data[i].payed == 90000)
                          { p("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
                             p("\t\t\ %d%c\n",ct,245);
                             ct++;

                            usleep(time);
                               printf("\t\t\t%c Name    :%s %s\n",201,data[i].fname,data[i].lname);
                                fflush(stdout);
                            usleep(time);
                            printf("\t\t\t%c Roll :C-%d\n",186,data[i].roll);
                             fflush(stdout);
                            usleep(time);
                               printf("\t\t\t%c Group    :%s\n",186,data[i].grp);
                                  fflush(stdout);
                             fflush(stdout);
                            usleep(time);
                            printf("\t\t\t%c SSC GPA :%.2f\n",186,data[i].sgpa);
                             fflush(stdout);
                            usleep(time);
                            printf("\t\t\t%c HSC GPA :%.2f\n",186,data[i].hgpa);
                             fflush(stdout);
                            usleep(time);
                            printf("\t\t\t%c payed   :%d/-\n",186,data[i].payed);
                             fflush(stdout);
                            usleep(time);
                            printf("\t\t\t%c Waiver  :NO!\n",186);
                             fflush(stdout);
                            usleep(time);
                            p("\t\t\t%c Due     :00/-\n\n",200);

                          }
                        }
                        ct--;
                                p("\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __\n\t\t\t%c Total students : %d\n\n",240,ct);
                     p("\t\t\t%c Enter any number for main menu\n\t\t\t",175);
                    s("%d",&mainmenu);
                        system("cls");
                    }
                    void sort(int c)
                    {  int choice,time=19990,mainmenu;
                       int i,ct=1,j,n;
                       system("cls");
                       p("\t\t\t\t\t DATA LIST\n\t\t____________________________________________________\n");
                        FILE *start,*fulldata,*group;

                    fflush(stdout);
                            usleep(time);
                        p("\t\t\t%c%c Enter 1 for full data list\n",175,175);
                     fflush(stdout);
                            usleep(time);
                        p("\t\t\t%c%c Enter 2 for lowest to highest paid data list\n",175,175);
                    fflush(stdout);
                            usleep(time);
                        p("\t\t\t%c%c Enter 3 for highest to lowest paid data list\n",175,175);
                     fflush(stdout);
                            usleep(time);
                        p("\t\t\t%c%c Enter 4 for fullpayed list\n",175,175);
                    fflush(stdout);
                            usleep(time);
                        p("\t\t\t%c%c Enter 5 for waiver list\n",175,175);
                    fflush(stdout);
                            usleep(time);
                        p("\t\t\t%c%c Enter 6 for fullpayed and waiver list\n",175,175);
                    fflush(stdout);
                            usleep(time);
                        p("\t\t\t%c%c (1/2/3/4/5/6)?\n\t\t\t",175,175);
                         s("%d",&choice);
                        c--;
                    if(choice ==1)
                           fulldataa(c);
                    else if(choice == 4)
                             fullpayed(c);

                    else if(choice == 2 || choice == 3)
                           {
                            ///reading and assigining from fulldata file
                             fulldata=fopen("fulldata.txt","r");
                             for(i=1;i<=c;i++)
                             fscanf(fulldata,"%s%s%d%lf%lf%d",data[i].fname,data[i].lname,&data[i].roll,&data[i].sgpa,&data[i].hgpa,&data[i].payed);
                             fclose(fulldata);
                                 ///reading from group file
                        group=fopen("group.txt","r");
                        for(i=1;i<=c;i++)
                        fscanf(group,"%d%s",&troll[i],chh[i].grp);
                        fclose(group);

                        for(i=1;i<=c;i++)
                        for(j=1;j<=c;j++)
                        {
                            if(data[i].roll == troll[j])
                                {
                                    strcpy(data[i].grp,chh[j].grp);

                                 break;
                                }
                        }

                             for (i = 1; i <=c; i++)
                              index[i] = i;

                              for (i =   1; i <= c-1; i++)
                                for (j = i+1; j <= c; j++)
                                 if (data[index[i]].payed > data[index[j]].payed)
                                    swap(&index[i], &index[j]);

                            if(choice == 2)
                             { system("Cls");
                          p("\t\t\t LOwEST TO HIGHEST PAID\n\t\t_______________________________________________\n");
                                 printf("\t\t%c Sorted by Lowest payed to highest payed\n\n\n",254);
                                for (i = 1; i <= c; i++)
                                 { fflush(stdout);
                            usleep(time);
                                  p("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
                                 p("\t\t\ %d%c\n",ct,245);
                                 ct++;

                                  printf("\t\t\t%c Name :%s %s\n",201,data[index[i]].fname,data[index[i]].lname);
                                  printf("\t\t\t%c Roll :C%d\n",186,data[index[i]].roll);
                                  printf("\t\t\t%c GROUP:%s\n",186,data[index[i]].grp);
                                  printf("\t\t\t%c SSC GPA :%.2f\n",186,data[index[i]].sgpa);
                                  printf("\t\t\t%c HSC GPA :%.2f\n",186,data[index[i]].hgpa);
                                  printf("\t\t\t%c payed :%d\n",186,data[index[i]].payed);
                                    if(data[index[i]].sgpa == 5.00 && data[index[i]].hgpa==5.00)
                                     {
                                         printf("\t\t\t%c Waiver  :YES!\n",186);
                                          p("\t\t\t%c Due     :%d/-\n\n",200,60000-data[index[i]].payed);
                                     }
                                     else
                                        {printf("\t\t\t%c Waiver  :NO!\n",186);
                                        p("\t\t\t%c Due     :%d/-\n\n",200,90000-data[index[i]].payed);
                                        }
                                  }
                        p("\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __\n\t\t\t%c Total students : %d\n\n",240,c);
                     p("\t\t\t%c Enter any number for main menu\n\t\t\t",175);
                    s("%d",&mainmenu);
                        system("cls");


                              }
                    else if (choice == 3)
                            {system("Cls");
                          p("\t\t\t HIGHEST TO LOWEST PAID\n\t\t_______________________________________________\n");
                              printf("\t\t%c Sorted by highest to lowest payed\n\n\n",254);
                             for (i = c; i >= 1; i--)
                              {  p("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
                                  p("\t\t\ %d%c\n",ct,245);
                                  ct++;
                                  fflush(stdout);
                            usleep(time);

                                  printf("\t\t\t%c Name :%s %s\n",201,data[index[i]].fname,data[index[i]].lname);
                               printf("\t\t\t%c Roll :C%d\n",186,data[index[i]].roll);
                                printf("\t\t\t%c GROUP:%s\n",186,data[index[i]].grp);
                               printf("\t\t\t%c SSC GPA :%.2f\n",186,data[index[i]].sgpa);
                               printf("\t\t\t%c HSC GPA :%.2f\n",186,data[index[i]].hgpa);
                               printf("\t\t\t%c payed :%d\n",186,data[index[i]].payed);
                              if(data[index[i]].sgpa == 5.00 && data[index[i]].hgpa==5.00)
                                     {
                                         printf("\t\t\t%c Waiver  :YES!\n",186);
                                          p("\t\t\t%c Due     :%d/-\n\n",200,60000-data[index[i]].payed);
                                     }
                                     else
                                        {printf("\t\t\t%c Waiver  :NO!\n",186);
                                        p("\t\t\t%c Due     :%d/-\n\n",200,90000-data[index[i]].payed);
                                        }
                              }
                            p("\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __\n\t\t\t%c Total students : %d\n\n",240,c);
                     p("\t\t\t%c Enter any number for main menu\n\t\t\t",175);
                    s("%d",&mainmenu);
                        system("cls");
                             }

                         }

                    else if(choice == 5)
                          { system("Cls");
                          p("\t\t\t\t WAIVER LIST\n\t\t_______________________________________________\n");
                        ///reading and assigining from fulldata file
                             fulldata=fopen("fulldata.txt","r");
                             for(i=1;i<=c;i++)
                             fscanf(fulldata,"%s%s%d%lf%lf%d",data[i].fname,data[i].lname,&data[i].roll,&data[i].sgpa,&data[i].hgpa,&data[i].payed);
                             fclose(fulldata);
                               ///reading from group file
                        group=fopen("group.txt","r");
                        for(i=1;i<=c;i++)
                        fscanf(group,"%d%s",&troll[i],chh[i].grp);
                        fclose(group);

                        for(i=1;i<=c;i++)
                        for(j=1;j<=c;j++)
                        {
                            if(data[i].roll == troll[j])
                                {
                                    strcpy(data[i].grp,chh[j].grp);

                                 break;
                                }
                        }
                              for(i=1;i<=c;i++)
                             {
                                 if(data[i].sgpa == 5.00 && data[i].hgpa== 5.00)
                                 {  p("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
                                   p("\t\t\ %d%c\n",ct,245);
                                   ct++;
                                     fflush(stdout);
                            usleep(time);

                                  printf("\t\t\t%c Name    :%s %s\n",201,data[i].fname,data[i].lname);
                                  printf("\t\t\t%c Roll    :C-%d\n",186,data[i].roll);
                                   printf("\t\t\t%c GROUP   :%s\n",186,data[i].grp);
                                  printf("\t\t\t%c SSC GPA :%.2f\n",186,data[i].sgpa);
                                  printf("\t\t\t%c HSC GPA :%.2f\n",186,data[i].hgpa);
                                  printf("\t\t\t%c payed   :%d/-\n",186,data[i].payed);
                                  printf("\t\t\t%c Waiver  :YES!\n",186);
                                  printf("\t\t\t%c Due     :%d/-\n\n",200,60000-data[i].payed);

                                 }

                             }
                                    p("\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __\n\t\t\t%c Total students : %d\n\n",240,ct-1);
                     p("\t\t\t%c Enter any number for main menu\n\t\t\t",175);
                    s("%d",&mainmenu);
                        system("cls");
                          }
                    else if(choice == 6)
                    {
                         ///reading and assigining from fulldata file
                             fulldata=fopen("fulldata.txt","r");
                             for(i=1;i<=c;i++)
                             fscanf(fulldata,"%s%s%d%lf%lf%d",data[i].fname,data[i].lname,&data[i].roll,&data[i].sgpa,&data[i].hgpa,&data[i].payed);
                             fclose(fulldata);
                                    ///reading from group file
                        group=fopen("group.txt","r");
                        for(i=1;i<=c;i++)
                        fscanf(group,"%d%s",&troll[i],chh[i].grp);
                        fclose(group);
                        for(i=1;i<=c;i++)
                        for(j=1;j<=c;j++)
                        {
                            if(data[i].roll == troll[j])
                                {
                                    strcpy(data[i].grp,chh[j].grp);

                                 break;
                                }
                        }
                               for(i=1;i<=c;i++)
                                {
                                 if(data[i].sgpa == 5.00 && data[i].hgpa== 5.00 && data[i].payed == 60000)
                                 {  p("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
                                   p("\t\t\ %d%c\n",ct,245);
                                   ct++;
                                     fflush(stdout);
                            usleep(time);

                                  printf("\t\t\t%c Name    :%s %s\n",201,data[i].fname,data[i].lname);
                                  printf("\t\t\t%c Roll    :C-%d\n",186,data[i].roll);
                                  printf("\t\t\t%c GROUP   :%s\n",186,data[i].grp);
                                  printf("\t\t\t%c SSC GPA :%.2f\n",186,data[i].sgpa);
                                  printf("\t\t\t%c HSC GPA :%.2f\n",186,data[i].hgpa);
                                  printf("\t\t\t%c payed   :%d/-\n",186,data[i].payed);
                                  printf("\t\t\t%c Waiver  :YES!\n",186);
                                  printf("\t\t\t%c Due     :%d/-\n\n",200,60000-data[i].payed);

                                 }

                             }
                             p("\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __\n\t\t\t%c Total students : %d\n\n",240,ct-1);
              p("\t\t\t%c Enter any number for main menu\n\t\t\t",175);
                    s("%d",&mainmenu);
                        system("cls");
                    }
                    }


                    void search(int c)
                    {
                         int i,n,j,choice,flag=0,go,cc=0;
                        FILE *start,*fulldata,*group;
                        c--;
                        p("\t\t\t%c%c Enter 1 for search by roll.\n\t\t\t%c%c Enter 2 for search by name.\n\n\t\t\t",175,175,175,175);
                       s("%d",&choice);
                        ///reading and assigining from fulldata file
                          fulldata=fopen("fulldata.txt","r");
                           for(i=1;i<=c;i++)
                            fscanf(fulldata,"%s%s%d%lf%lf%d",data[i].fname,data[i].lname,&data[i].roll,&data[i].sgpa,&data[i].hgpa,&data[i].payed);
                          fclose(fulldata);
                          ///reading from group file
                          group=fopen("group.txt","r");
                        for(i=1;i<=c;i++)
                        fscanf(group,"%d%s",&troll[i],chh[i].grp);
                        fclose(group);
                        for(i=1;i<=c;i++)
                        for(j=1;j<=c;j++)
                        {
                            if(data[i].roll == troll[j])
                                {
                                    strcpy(data[i].grp,chh[j].grp);

                                 break;
                                }
                        }
                       if(choice==1)
                       {
                           system("cls");
                       p("\t\t\t%c SEARCH BY ROLL\n\n",254);
                          p("\t\t\t%c Enter Roll for search.\n\t\t\t C",175);
                          s("%d",&n);

                            for(i=1;i<=c;i++)
                            {
                             if(n == data[i].roll)
                              {

                            printf("\n\n\n\t\t\t%c Name    :%s %s\n",201,data[i].fname,data[i].lname);
                            printf("\t\t\t%c Roll    :C%d\n",186,data[i].roll);
                            printf("\t\t\t%c GROUP    :%s\n",186,data[i].grp);
                            printf("\t\t\t%c SSC GPA :%.2f\n",186,data[i].sgpa);
                            printf("\t\t\t%c HSC GPA :%.2f\n",186,data[i].hgpa);
                            printf("\t\t\t%c payed :%d/-\n",186,data[i].payed);
                             if(data[i].sgpa == 5.00 && data[i].hgpa == 5.00)
                            {p("\t\t\t%c Waiver :Yes!\n",186);
                            p("\t\t\t%c Due = %d/-\n\n",200,(60000 - data[i].payed));
                            }
                            else
                            {p("\t\t\t%c Waiver :NO!\n",186);
                            p("\t\t\t%c Due = %d/-\n\n",200,(90000 - data[i].payed));
                            }
                              cc=cc+1;
                                p("\t\t\t%c Enter 1 to update this data.\n\t\t\t%c Enter 0 to go back to main main menu\n",175,175);
                    s("%d",&go);
                    if(go == 1){
                         system("cls");
                           p("\t\t\t\t UPDATE\n\t\t\______________________________________\n");
                        update(c+1,n);
                            p("\n\t\t\t *Successfull!\n\n\t\t\t  Please Wait.\n");
                                   usleep(7111111);
                        }
                        else if(go == 1)
                            break;
                              }
                            }
                       }
                       if(choice==2)
                       { system("cls");
                       p("\t\t\t%c SEARCH BY NAME\n\n",254);
                           p("\t\t\t%c Enter name for search.\n\t\t\t%c First name(e.g Ayesha):",254,175);
                         s("%s",temp.fname);
                         p("\t\t\t%c Last name(e.g Mahmud) :",175);
                         s("%s",temp.lname);

                         for(i=1;i<=c;i++)
                         {
                           if(strcmp(data[i].fname,temp.fname)==0 && strcmp(data[i].lname,temp.lname)==0)
                           {
                            p("\n\n\n\t\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);

                            printf("\n\n\n\t\t\t%c Name    :%s %s\n",201,data[i].fname,data[i].lname);
                            printf("\t\t\t%c Roll    :C%d\n",186,data[i].roll);
                              printf("\t\t\t%c GROUP    :%s\n",186,data[i].grp);
                            printf("\t\t\t%c SSC GPA :%.2f\n",186,data[i].sgpa);
                            printf("\t\t\t%c HSC GPA :%.2f\n",186,data[i].hgpa);
                            printf("\t\t\t%c payed   :%d/-\n",186,data[i].payed);
                            if(data[i].sgpa == 5.00 && data[i].hgpa == 5.00)
                           {p("\t\t\t%c Waiver  :Yes!\n",186);
                           p("\t\t\t%c Due     : %d/-\n\n\n\n",200,(60000 - data[i].payed));
                           }
                            else
                           {p("\t\t\t%c Waiver  :No!\n",186);
                           p("\t\t\t%c Due     : %d/-\n\n\n\n",200,(90000 - data[i].payed));
                           }
                           cc=cc+1;
                               p("\t\t\t%c Enter 1 to update this data.\n\t\t\t%c Enter 0 to go back to main main menu\n",175,175);
                    s("%d",&go);
                    if(go == 1)
                    {  system("cls");
                           p("\t\t\t\t UPDATE\n\t\t\______________________________________\n");

                        update(c+1,data[i].roll);
                         p("\n\t\t\t *Successfull!\n\n\t\t\t  Please Wait.\n");
                                   usleep(7111111);
                    }
                         }
                           else if( go == 1)
                            break;

                         }

                        }
                    if(cc == 0){
                    p("\t\t\t%c No data found\n\t\t\t%c Enter any number for mainmenu\n\t\t\t",175,175);
                    s("%d",&go);
                    }
                    }

                    void gotoxy(int x,int y)
                    {
                         COORD CRD;
                        CRD.X=x;
                        CRD.Y=y;
                        SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE),CRD );

                    }
                    void animation()
                    {int i,time=49999;
                        for(i=1;i<=2;i++)
                        {system("cls");

                           gotoxy(28,5);
                           printf("W"); fflush(stdout);
                            usleep(time);
                        gotoxy(34,5);
                          printf("E");fflush(stdout);
                           usleep(time);
                          gotoxy(29,5);
                          printf("E");fflush(stdout);
                           usleep(time);
                                gotoxy(33,5);
                           printf("M"); fflush(stdout);
                            usleep(time);
                           gotoxy(30,5);
                           printf("L"); fflush(stdout);
                            usleep(time);
                           usleep(time);
                          gotoxy(32,5);
                          printf("O");fflush(stdout);
                           usleep(time); gotoxy(31,5);
                           printf("C"); fflush(stdout);
                            usleep(time);
                          p("\n");
                      }
                      for(i=1;i<=4;i++)
                      {
                          system("cls");
                          fflush(stdout);
                          usleep(111111);
                          gotoxy(28,1);
                           printf(" WELCOME\n");
                            fflush(stdout);
                            usleep(111111);
                      }
                      p("\n");
                           for(i=1;i<=90;i++)
                      {
                          fflush(stdout);
                             usleep(10000);
                             p("%c",177);
                      }
                      p("\n");


                    }

                    void fm(int c,int n)
                    {  system("cls");
                         int i,j,choseagain,ct=1,count =0,mainmenu;
                    FILE *fulldata,*group;
                        struct student temp[40];
                        ///reading and assigining from fulldata file
                          fulldata=fopen("fulldata.txt","r");
                           for(i=1;i<c;i++)
                            fscanf(fulldata,"%s%s%d%lf%lf%d",data[i].fname,data[i].lname,&data[i].roll,&data[i].sgpa,&data[i].hgpa,&data[i].payed);
                          fclose(fulldata);
                                fclose(fulldata);
                          ///reading from group file
                          group=fopen("group.txt","r");
                        for(i=1;i<=c;i++)
                        fscanf(group,"%d%s",&troll[i],chh[i].grp);
                        fclose(group);
                        for(i=1;i<=c;i++)
                        for(j=1;j<=c;j++)
                        {
                            if(data[i].roll == troll[j])
                                {
                                    strcpy(data[i].grp,chh[j].grp);

                                 break;
                                }
                        }
                        for(i=1;i<c;i++)
                        {
                        itoa(data[i].roll,temp[i].fname,10);
                        }
                     if(n==1)
                     {   system("cls");

                         for(i=1;i<c;i++)
                         {
                             if(temp[i].fname[1]=='2')
                             {p("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
                              p("\t\t\ %d%c\n",ct,245);
                              ct++;

                                  printf("\t\t\t%c Name    :%s %s\n",201,data[i].fname,data[i].lname);
                                  printf("\t\t\t%c Roll    :C-%d\n",186,data[i].roll);
                                  printf("\t\t\t%c group   :%s\n",186,data[i].grp);
                                  printf("\t\t\t%c SSC GPA :%.2f\n",186,data[i].sgpa);
                                  printf("\t\t\t%c HSC GPA :%.2f\n",186,data[i].hgpa);
                                  printf("\t\t\t%c payed   :%d/-\n",186,data[i].payed);
                               if(data[i].sgpa==5.00 && data[i].hgpa == 5.00)
                                  { printf("\t\t\t%c Waiver  :YES!\n",186);
                                  printf("\t\t\t%c Due     :%d/-\n\n",200,60000-data[i].payed);
                                 }
                               else
                                { printf("\t\t\t%c Waiver  :NO!\n",186);
                                 printf("\t\t\t%c Due     :%d/-\n\n",200,90000-data[i].payed);
                               }
                                count++;
                             }
                         else
                            continue;
                         }
                              p("\t\t\t%c Total Male students : %d\n\n",240,count);
                             p("\t\t\t%c Enter 2 for Female students.\n",175);
                            p("\t\t\t%c Enter 0 for main menu\n\t\t\t",175);
                     }

                     else if (n == 2)
                    {
                       system("cls");
                        for(i=1;i<c;i++)
                         {
                             if(temp[i].fname[1]=='1')
                             {  p("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
                                 p("\t\t\ %d%c\n",ct,245);
                             ct++;

                                  printf("\t\t\t%c Name    :%s %s\n",201,data[i].fname,data[i].lname);
                                  printf("\t\t\t%c Roll    :C-%d\n",186,data[i].roll);
                                   printf("\t\t\t%c group   :%s\n",186,data[i].grp);
                                  printf("\t\t\t%c SSC GPA :%.2f\n",186,data[i].sgpa);
                                  printf("\t\t\t%c HSC GPA :%.2f\n",186,data[i].hgpa);
                                  printf("\t\t\t%c payed   :%d/-\n",186,data[i].payed);
                                    if(data[i].sgpa==5.00 && data[i].hgpa == 5.00)
                                  { printf("\t\t\t%c Waiver  :YES!\n",186);
                                  printf("\t\t\t%c Due     :%d/-\n\n",200,60000-data[i].payed);
                                 }
                               else{
                                 printf("\t\t\t%c Waiver  :NO!\n",186);
                                 printf("\t\t\t%c Due     :%d/-\n\n",200,90000-data[i].payed);
                                  }
                                  count++;
                             }
                         else
                            continue;
                         }
                    p("\t\t\t%c Total Female students : %d\n\n",240,count);
                         p("\t\t\t%c Enter 1 for male students.\n",175);
                        p("\t\t\t%c Enter 0 for main menu\n\t\t\t",175);
                    }
                    s("%d",&choseagain);
                    if(choseagain == 2)
                    fm(c,choseagain);
                    else if(choseagain == 1)
                    fm(c,choseagain);
                    else if(choseagain == 0)
                            return 0;

                    }

                    void passww(int pass)
                    {system("cls");
                    p("\t\t\t CHANGE PASSWORD\n");
                         FILE *passw;
                        int i,newpass,oldpass;
                        p("\t\t\t%c Enter Old password:",254);
                        for(i=1;i<=5;i++)
                        {
                            s("%d",&oldpass);
                            if(oldpass == pass)
                            {  system("cls");
                                passw=fopen("passw.txt","w");
                                p("\n\t\t\t%c Enter New password:",254);
                                s("%d",&newpass);
                           fprintf(passw,"%d",newpass);
                       fclose(passw);
                       p("\t\t\t Succesfull!\n");
                       p("\t\t\t  Please Wait...\n");
                                   usleep(1111191);
                       break;
                            }
                        else
                            p("\t\t\t%c Incorrect!Try again.");

                        }

                    }

            void info()
            { system("cls");
                p("Please Enter According to the instruction.\n Make sure that you're entering integers in the integer fields.\nDon't keep any field empty when you input data.\nThe program is sensitive for uppercase and lowercase letters.\n");
            }


        void group(int c)
        {
            int avr,i,j,ch=65,cnt=64,count=0,count2=0;
            char chh[10];
           double float1,float2,average[100];

          FILE *fulldata;
          FILE *group;
             ///reading and assigining from fulldata file
                        fulldata=fopen("fulldata.txt","r");
                        for(i=1;i<c;i++)
                        fscanf(fulldata,"%s%s%d%lf%lf%d",data[i].fname,data[i].lname,&data[i].roll,&data[i].sgpa,&data[i].hgpa,&data[i].payed);
                       fclose(fulldata);


              for (i = 1; i < c; i++)
                {
                    index[i] = i;
                 float1 = (data[i].sgpa * (0.25));
                 float2 = (data[i].hgpa * (0.75));
                 average[i] = (float1 + float2);
                }
                    for (i = 1; i < c-1; i++)
                                for (j = i+1; j <c ; j++)
                                 if (average[index[i]] < average[index[j]])
                                    swap(&index[i], &index[j]);
                  group= fopen("group.txt","w");
                  fclose(group);
                   group= fopen("group.txt","a");
                    for(i=1;i<c;i++)
                    {
                        itoa(data[index[i]].roll,chh,10);

                        if(chh[1] == '2')
                            {if(count == 0)
                               ch =65;
                               if(count == 5)
                                ch= 66;
                               if(count == 10)
                               ch =67;
                               if(count == 15)
                               ch =68;
                               if(count == 20)
                               ch =69;
                               if(count == 25)
                               ch =70;
                               if(count == 30)
                               ch =71;
                             fprintf(group,"%d\n%cM\n",data[index[i]].roll,ch);
                              count++;
                            }

                     //  if(count % 5 == 0 )
                       //  ch++;

                        }
                        fclose(group);


                    group= fopen("group.txt","a");

                    for(i=1;i<c;i++)
                    {
                        itoa(data[index[i]].roll,chh,10);

                        if(chh[1] == '1')
                            { if(count2 == 0)
                               cnt =65;
                               if (count2 == 5)
                                cnt = 66;
                               if (count2 == 10)
                                cnt = 67;
                                 if (count2 == 15)
                                cnt = 68;
                                 if (count2 == 20)
                                cnt = 69;
                                  if (count2 == 25)
                                cnt = 70;
                                  if (count2 == 30)
                                cnt = 71;
                             fprintf(group,"%d\n%cF\n",data[index[i]].roll,cnt);


                                 count2++; }




                        }
                        fclose(group);

             }


           void grpv(int c,int nn)
           {
               int i,j,count = 0,length,cnt = 65,cc;
               cc=c;
           char ch[10];
           FILE *fulldata,*group;

                                 ///reading and assigining from fulldata file
                        fulldata=fopen("fulldata.txt","r");
                        for(i=1;i<c;i++)
                        fscanf(fulldata,"%s%s%d%lf%lf%d",data[i].fname,data[i].lname,&data[i].roll,&data[i].sgpa,&data[i].hgpa,&data[i].payed);
                        fclose(fulldata);
                           ///reading from group file
                        group=fopen("group.txt","r");
                        for(i=1;i<c;i++)
                        fscanf(group,"%d%s",&troll[i],chh[i].grp);
                        fclose(group);



                        for(i=1;i<c;i++)
                        for(j=1;j<c;j++)
                        {
                            if(data[i].roll == troll[j])
                                {
                                    strcpy(data[i].grp,chh[j].grp);

                                 break;
                                }
                        }

                    length = (cc / 5);
                    if(cc % 5 != 0)
                        length++;

                    for(j=1;j<=length;j++)
                        {
    //p("\t\t\t GROOUP %c \n=================================================================\n",cnt);
                    for(i=1;i<c;i++)
                        {
                            itoa(data[i].roll,ch,10);
                           if(ch[1] == nn)
                           {

                            if(data[i].grp[0] == cnt)
                            {

                                  printf("\t\t\t%c Name    :%s %s\n",201,data[i].fname,data[i].lname);
                                  printf("\t\t\t%c Roll    :C-%d\n",186,data[i].roll);
                                printf("\t\t\t%c group   :%s\n",186,data[i].grp);
                                  printf("\t\t\t%c SSC GPA :%.2f\n",186,data[i].sgpa);
                                  printf("\t\t\t%c HSC GPA :%.2f\n",186,data[i].hgpa);
                                  printf("\t\t\t%c payed   :%d/-\n",186,data[i].payed);
                                    if(data[i].sgpa==5.00 && data[i].hgpa == 5.00)
                                  { printf("\t\t\t%c Waiver  :YES!\n",186);
                                  printf("\t\t\t%c Due     :%d/-\n\n",200,60000-data[i].payed);
                                 }
                               else{
                                 printf("\t\t\t%c Waiver  :NO!\n",186);
                                 printf("\t\t\t%c Due     :%d/-\n\n",200,90000-data[i].payed);


                            }
                             count++;
                           if(count == (c-1))
                            break;

                             }

                           }
                        }
                        cnt++;


                        }


           }

                    int main()
                    { ///count
                      int password,n,c,choice=1,pass,mainmenu,chs;
                      FILE *passw;
                      passw = fopen("passw.txt","r");
                      fscanf(passw,"%d",&pass);
                      fclose(passw);
                      //p("%d\n",pass);
                      p("\n\t\t  %c  Enter Admin Password.  %c\n\t\t\t",185,204);

                     for(;;)
                      {  s("%d",&password);
                          if(password == pass)
                          {system("cls");
                            break;}
                          else
                            p("Incorrect password.\nTry again.\n");
                      }

                    animation();
                       while(choice)
                       {
                          ///count from counting file(start)
                          FILE *start;
                          start = fopen("start.txt","r");
                          fscanf(start,"%d",&c);
                          fclose(start);

                            menu();
                            scanf("%d",&choice);
                            switch (choice)
                              {
                               case 1:
                                   {  system("cls");
                                   indata(c);
                                   p("\n\t\t\t *Successfull!\n\n\t\t\t  Please Wait.\n");
                                   usleep(999999);
                                    system("cls");
                                   break;
                                   }
                               case 2:
                                   {  system("cls");
                                       p("\t\t\t\t UPDATE\n\t\t\______________________________________\n");
                                    p("\t\t\t%c Enter Roll to update\n\t\t\t C",175);
                                  s("%d",&n);
                                  update(c,n);
                                  p("\t\t\t%c Enter any number for mainmenu.\n\t\t\t",175);
                                  s("%d",&mainmenu);
                                  system("cls");
                                   }
                                  break;
                               case 3:
                                   { system("cls");
                                    p("\t\t\t\t%c DELETE\n\t\t___________________________________________________\n",175);
                                   deletee(c);
                                             p("\t\t\t%c Enter any number for mainmenu.\n\t\t\t",175);
                                  s("%d",&mainmenu);
                                  system("cls");
                                   }
                                       break;
                               case 4:
                                   sort(c);
                                   break;
                               case 5:
                                   {     system("cls");
                                    p("\t\t\t\t%c SEARCH\n\t\t______________________________________________\n",175);
                                   search(c);
                                   system("cls");
                                    }
                                   break;
                               case 6:
                                   { system("cls");
                                        p("\t\t\t%c%c Enter 1 for total Male students.\n\t\t\t%c%c Enter 2 for total Female students\n\t\t\t",175,175,175,175);
                                     s("%d",&n);
                                   fm(c,n);
                                   system("cls");
                                   }
                                   break;
                                case 7:{
                                 passww(pass);
                                     system("cls");
                                     }
                                   break;
                                case 8:{
                                    system("cls");
                                    p("\t\t\t\t GROUPS \n------------------------------------------------------------------------------------------------\n",175);
                                    p("\t\t\t (Auto generated By average value)\n\t\t\t (Average = (SSC GPA * 0.25)+(HSC GPA * 0.75)\n ");
                                    p("\t\t\t%c Enter 1 for male groups.\n\t\t\t%c Enter 2 for female groups.\n\t\t\t",175,175);
                                   s("%d",&n);
                                   if(n==1)
                                   grpv(c,50);
                                   if (n==2)
                                    grpv(c,49);
                                   p("\n\t\t\t%c Enter any number for main menu\n\t\t\t ",175);
                                   s("%d",&mainmenu);
                                   system("cls");
                                   break;
                                }
                                case 9:
                                   info();
                                   break;
                               case 0:
                                   break;

                              }

                       }

                        return 0;
                    }

