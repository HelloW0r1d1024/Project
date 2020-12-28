/*  
 *  程序描述：100以内的加减乘除练习
 *  作者：软件1921-王鸣辉-5948
 *  日期：2020/09/30
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<sys/types.h>
#include<sys/timeb.h>

#define BOOL int
#define True 1
#define False 0
#define DIGIT 7 // id位数 6 + 1('\0')
#define NUM_OF_QUESTIONS 10  // 题目数量
#define FILE_PATH "D:/record.txt"   // 文件的存放位置

const char op_list[4] = {'+', '-', '*', '/'}; // 通过生成[0, 3]的随机数作为下标来实现运算符的随机产生
int op_10[10]; //存放随机生成的运算符下标
char questions[NUM_OF_QUESTIONS][10] = {'\0'}; //存放随机生成的算式
int usr_ans[NUM_OF_QUESTIONS];  // 用户输入的答案
int std_ans[NUM_OF_QUESTIONS];   //存放随机生成的算式答案

typedef struct  {
    char id[10];
    int score;
    int time;
} student;

BOOL id_identify(student * stu);  // id合法性检测，合法返回True,不合法返回False 
BOOL list_factor(int num, int factor[]);    // 将被除数的所有因子置入一个数组中，且当num为质数时返回False
unsigned int seed_generator();  // 重新生成种子，且返回该种子，日后可用于重做本次题目
void op_generator(int[]);   // 生成10个相邻不重复且每个至少出现一次的运算符，并存到数组中
void formula_generator(char, int);  // 生成算式 
int scorer(int[], int[]);   // 计算用户得分
void print_ans(int usr_ans[]); // 打印题目 正确答案 用户答案

int main(void) {
    int current_op_list[NUM_OF_QUESTIONS]; // 存放当前随机生成的运算符的数组
    int begin, end; // 计时始终点
    int option; // 三个选项
    char str[81];   // 存放文件的每一行
    FILE * fp;
    student stu1;
    // 若输入不合法，提示用户重新输入
    while (!id_identify(&stu1))
        printf("This id is invalid, please re-enter\n");

    while (True) {
        printf("options:\n");
        printf("(1)start testing\n");
        printf("(2)check score\n");
        printf("(3)exit\n");
        //若用户输入的是非数字，或者是小于1大于3的正数，提示其输入正确的数据
        while (scanf("%d", &option) == 0  || (option < 1 || option > 3)) {
            printf("please enter an integer from 1 to 3!\n");
            fflush(stdin);
        }
        
        if (3 == option)
            break;

        switch (option) {
            //选项1 -- 开始测试
            case 1:
                if ((fp = fopen(FILE_PATH, "a")) == NULL) {
                    printf("Error! opening file\n");
                    exit(1);
                }

                seed_generator();   //重新播种
                op_generator(current_op_list);  // 生成10个符合要求的运算符，存到current_op_list数组中
                for (int i = 0; i < NUM_OF_QUESTIONS; i++) {
                    formula_generator(op_list[current_op_list[i]], i); //生成随机算式，存到question数组中
                }

                begin = time(NULL); // 计时开始
                // 一道题答完后再出下一道
                for (int i = 0; i < NUM_OF_QUESTIONS; i++) {
                    printf("%s", questions[i]);   //打印该算式
                    if (scanf("%d", &usr_ans[i]) == 0) {
                        printf("Please enter an integer! Try again.\n");
                        i--;
                        fflush(stdin);
                    }     
                }    
                end = time(NULL);   // 计时结束

                stu1.score = scorer(usr_ans, std_ans);
                stu1.time = end - begin;
                //将id 分数 用时写入到文件中
                fputs(stu1.id, fp);
                fprintf(fp, "\t%d\t%ds\n", stu1.score, stu1.time);
                fclose(fp);
                //打印题目 正确答案 用户答案
                print_ans(usr_ans);
                continue;

            // 选项二 -- 检查分数
            case 2 :
                if ((fp = fopen(FILE_PATH, "r")) == NULL) {
                    printf("Error! opening file\n");
                    exit(1);
                }   //从文件中读取记录
                while (!feof(fp)) {
                    fgets(str, 81, fp);
                    if (feof(fp))   // 防止文件最后一行打印两次
                        break;
                    fputs(str, stdout);
                }
                fclose(fp);
                continue;
        }   
    }
    getchar();    
}

// id合法性检测，合法返回True,不合法返回False //DONE
BOOL id_identify(student * stu) {
    printf("Please enter your id:");
    gets(stu->id);

    BOOL flag = True;    // 标签初始为True, 一旦有一位不符合要求就将其设置为False
    if (stu->id[6] != '\0')
        flag = False;

    for (int i = 0; i < DIGIT; i++) {
        if (i < 2) {
            if (stu->id[i] < 65 || stu->id[i] > 90)
                flag = False;
        } 
        else {
            if (stu->id[i] == '\0')
                break;
            if (stu->id[i] < 48 || stu->id[i] > 57)
                flag = False;
        }
    }
    return flag;
}

// 将被除数的所有因子置入一个数组中，且当num为质数时返回False
BOOL list_factor(int num, int factor[]) {
    int tmp = sqrt(num);    // tmp存放num的平方根，若不是正数则向下取整
    int cnt = 0;
    // i为假想的因数
    for (int i = 1, j = 0; i <= tmp; i++) {
        if (num % i == 0) {
            factor[j] = i;
            cnt++;
            j++;    //数组中有存入,下标才增加
            if (i != num / i) {
                factor[j] = num / i;
                j++;    //数组中有存入,下标才增加
            }
        }
    }

    return cnt == 2? True : False;
}

// 重新生成种子并播种
unsigned int seed_generator() {
    unsigned int seed_val;
    struct _timeb timeBuf;
    // 检索当前时间，存入timeBuf.time中。// 当前时间的值从1970年1月1日开始以秒计算
    _ftime(&timeBuf);   //timeBuf.millitm中还存入了当前那一秒所度过的毫秒数

    // 毫秒数与秒数相加，再与毫秒数做一次异或运算 &0xFFFF取低16位
    seed_val = ((((unsigned int)timeBuf.time & 0xFFFF) +
                (unsigned int)timeBuf.millitm) ^
                (unsigned int)timeBuf.millitm);
    srand(seed_val);

    return seed_val;
}

// 生成10个相邻不重复且每个至少出现一次的运算符，并存到数组中
void op_generator(int op[]) {
    int op_index;   //临时存放[0, 3]内的随机数，与上次生成的比较，实现相邻运算不重复
    BOOL flag[4] = {False}; //存放四个标签，初始值全为False

    //  一旦没有满足每个运算符至少出现一次，则循环到满足为止
    while (!(flag[0] && flag[1] && flag[2] && flag[3])) {
        op[0] = rand() % 4;
        for (int i = 1; i < NUM_OF_QUESTIONS; i++) {
            //若本次随机生成的运算符与上次一样，则重新生成直到不一样为止
            do {
                op_index = rand() % 4;
            } while (op_index == op[i - 1]);

            //  一旦某个运算符随机出现了，则其对应的标签修改为True
            if (0 == op_index)
                flag[0] = True;
            else if (1 == op_index)
                flag[1] = True;
            else if (2 == op_index)
                flag[2] = True;
            else if (3 == op_index)
                flag[3] = True;
                
            op[i] = op_index;
        }
    }
}

// 生成算式 // DONE
void formula_generator(char op, int i) {
    int a, b;
    a = rand() % 99 + 1;    //a∈[1, 99]
    int factor[20] = {0}; //存放被除数的所有因子

    switch (op) {
        case '+':
            b = rand() % (99 - a) + 1; // b∈[1, 99 - a]
            std_ans[i] = a + b;        //std_ans[]是用来存放结果的，用于之后评分
            break;

        case '-':
            b = rand() % (a - 1) + 1;   // b∈[1, a - 1]
            std_ans[i] = a - b;
            break;

        case '*':
            a = rand() % 48 + 2;    // a∈[2, 49]
            b = rand() % ((99 / a) - 1) + 2;   // b∈[2, 99 / a]
            std_ans[i] = a * b;
            break;

        case '/':
            //将被除数的所有因数放在 int factor[]中，如果a为质数则重新生成
            while (!list_factor(a, factor)) {
                // 每次循环后factor[]清零
                for (int i = 0; i < 20; i++)
                    factor[i] = 0;
                a = rand() % 96 + 4; // a∈[4, 99]
            }
            
            int length = 0;
            for (int j = 0; factor[j]; j++)  //计算因数个数，遇0停止
                length++;
            
            b = factor[rand() % (length - 2) + 2];  // 从a的非1和非本身的因数中随机取
            std_ans[i] = a / b;
            break;
    }
    snprintf(questions[i], 10, "%d %c %d = ", a, op, b);    // 将本次生成的算式放入字符串数组里
}

// 计算用户得分
int scorer(int usr_ans[], int std_ans[]) {
    int score = 0;

    for (int i = 0; i < NUM_OF_QUESTIONS; i++) {
        if (usr_ans[i] == std_ans[i])
            score += 10;
    }

    return score;
}

// 打印题目 正确答案 用户答案
void print_ans(int usr_ans[]) {
    printf("questions\tcorrect answer\tyour answer\n");
    for (int i = 0; i < NUM_OF_QUESTIONS; i++)
        printf("%s\t%d\t\t%d\t\n", questions[i], std_ans[i], usr_ans[i]);
}