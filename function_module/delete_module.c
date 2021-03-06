#include "../heads/for_function_module.h"
#include "../heads/secondary_menu.h"
#include "stdlib.h"
#include "stdio.h"
#include "windows.h"

void delete_module(){
    char stu_num[20];
    char name[20];
    char gender[10];
    int age;
    float chinese,math,english;
    continue_query:
    //二级菜单界面
    system("cls");
    fflush(stdin);
    printf("------------------------------学生信息管理系统------------------------------\n");
    printf("->当前位置：学生信息删除\n\n");
    printf("->1、按学号查询并删除\n");
    printf("->2、按姓名查询并删除\n");
    printf("->3、按性别查询并删除\n");
    printf("->4、返回上级菜单\n");

    //把学生信息读入内存
    FILE *fp=fopen("../stu_info/stu_info.txt","r");
    struct stu *head,*p,*q,*t;
    head=(struct stu *) malloc(sizeof(struct stu));
    head->prev=NULL;
    q=head;
    int count=0;
    while (!feof(fp)){
        p=(struct stu *) malloc(sizeof(struct stu));
        fscanf(fp,"%s %s %s %d %f %f %f",&p->stu_num,&p->name,&p->gender,&p->age,&p->chinese,&p->math,&p->english);
        p->prev=q;
        q->next=p;
        q=p;
        count++;
    }
    fclose(fp);
    //数据表的最后一行为空行，导致链表的最后一个节点为空
    p->next=NULL;

    t=head->next;

    int whether_find=0;
    //读取用户输入，判断执行方向
    char query_menu_input;
    printf("\n->请输入选项（1/2/3/4）");
    fflush(stdin);
    scanf("%c",&query_menu_input);
    switch (query_menu_input) {
        //按学号查询
        case '1':{
            system("cls");
            fflush(stdin);
            printf("------------------------------学生信息管理系统------------------------------\n");
            printf("->当前位置：学生信息删除\n\n");
            printf("->请输入学生学号：");
            scanf("%s",&stu_num);
            t=head->next;
            while (t!=NULL){
                if(strcmp(stu_num,t->stu_num)==0){
                    system("cls");
                    fflush(stdin);
                    printf("------------------------------学生信息管理系统------------------------------\n");
                    printf("->当前位置：学生信息删除\n\n");
                    p=t;
                    t->prev->next=t->next;
                    t->next->prev=t->prev;
                    whether_find+=1;
                }
                t=t->next;

            }
            printf("共删除%d项记录\n\n",whether_find);
            //把修改后的信息写入文件
            t=head->next;
            fp= fopen("../stu_info/stu_info.txt","w");

            for (int i = 1; i < count-1; i++) {
                fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                t=t->next;
            }

//            while (t!=NULL){
//                fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
//                t=t->next;
//            }
            fclose(fp);
            count=0;

            if(whether_find==0){
                printf("->系统中没有该学生的信息！\n");
                Sleep(2000);
                whether_find=0;
                goto continue_query;
            }
            break;
        }
            //按姓名查询
        case '2':{
            system("cls");
            fflush(stdin);
            printf("------------------------------学生信息管理系统------------------------------\n");
            printf("->当前位置：学生信息删除\n\n");
            printf("->请输入学生姓名：");
            scanf("%s",&name);
            t=head->next;
            while (t!=NULL){
                if(strcmp(name,t->name)==0){
                    system("cls");
                    fflush(stdin);
                    printf("------------------------------学生信息管理系统------------------------------\n");
                    printf("->当前位置：学生信息删除\n\n");
                    p=t;
                    t->prev->next=t->next;
                    t->next->prev=t->prev;
                    whether_find+=1;
                }
                t=t->next;

            }
            printf("共删除%d项记录\n\n",whether_find);
            //把修改后的信息写入文件
            t=head->next;
            fp= fopen("../stu_info/stu_info.txt","w");

            for (int i = 1; i < count-1; i++) {
                fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                t=t->next;
            }
//            while (t!=NULL){
//                fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
//                t=t->next;
//            }
            fclose(fp);
            count=0;

            if(whether_find==0){
                printf("->系统中没有该学生的信息！\n");
                Sleep(2000);
                whether_find=0;
                goto continue_query;
            }
            break;
        }
        //按性别查询
        case '3':{
            system("cls");
            fflush(stdin);
            printf("------------------------------学生信息管理系统------------------------------\n");
            printf("->当前位置：学生信息删除\n\n");
            printf("->请输入学生性别：");
            scanf("%s",&gender);
            t=head->next;
            while (t!=NULL){
                if(strcmp(gender,t->gender)==0){
                    system("cls");
                    fflush(stdin);
                    printf("------------------------------学生信息管理系统------------------------------\n");
                    printf("->当前位置：学生信息删除\n\n");
                    p=t;
                    t->prev->next=t->next;
                    t->next->prev=t->prev;
                    whether_find+=1;
                    count--;
                }
                t=t->next;

            }
            printf("共删除%d项记录\n\n",whether_find);

            //把修改后的信息写入文件
            t=head->next;
            fp=fopen("../stu_info/stu_info.txt","w");

            for (int i = 1; i < count; i++) {
                fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                t=t->next;
            }
//            while (t!=NULL){
//                fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
//                t=t->next;
//            }
            fclose(fp);
            count=0;

            if(whether_find==0){
                printf("->系统中没有该学生的信息！\n");
                Sleep(2000);
                whether_find=0;
                goto continue_query;
            }
            break;
        }
            //返回上级菜单
        case '4':{
            secondary_menu();
        }
            //输入不合法
        default:{
            printf("输入不合法，请重新输入！\n\n");
            fflush(stdin);
            Sleep(2000);
            goto continue_query;
        }
    }
    //读取用户输入，判断执行方向
    char whether_continue_query;
    printf("是否继续删除？（y/n）");
    scanf("%c",&whether_continue_query);
    switch (whether_continue_query) {
        //继续删除
        case 'y':{
            goto continue_query;
            break;
        }
            //不继续删除
        case 'n':{
            secondary_menu();
            break;
        }
            //输入不合法
        default:{
            printf("->输入不合法，请重新输入！\n\n");
            fflush(stdin);
            Sleep(2000);
            goto continue_query;
            break;
        }
    }
}