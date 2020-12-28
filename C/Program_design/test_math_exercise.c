/*  program description: addition, subtraction, multiplication and division within 100
 *  author: software1921-Lucas Wang-2019005948
 *  date: 2020/09/30
 *  P.S :
 *       ATTENTION! encoding with UTF-8
 *       The source code can be compiled and run in the following environment after testing
 *       win compiler ver: gcc 9.2.0(MinGW) please use c99 OR c11 standard
 *       linux compiler ver: gcc 9.3.0(Ubuntu);
 *       please use c99 OR c11 standard，and add "-lm" at the end of the complie command // <math.h>
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

#define True 1
#define False 0
#define DIGIT 7 // digit of id  6 + 1('\0')
#define NUM_OF_QUESTIONS 10
//#define FILE_PATH "D:/record.txt"
#define FILE_PATH "/mnt/d/record.txt"

const char op_list[4] = {'+', '-', '*', '/'}; 
// Generate a random num from 0 to 3 as an index, whereby generating a operator randomly
char questions[NUM_OF_QUESTIONS][11] = {'\0'};
int usr_ans[NUM_OF_QUESTIONS]; // Store the answers entered by the user
int std_ans[NUM_OF_QUESTIONS]; // Store standard answers

typedef struct {
    char id[10];
    int score;
    int time;
} student;

int id_identify(student * stu);
/*  Ask user enter a string, store it in stu->id[10],
 *  then check if the ID user entered is legal
 *  PARAM: stu - a pointer to type "student"
 *  RETURN: True for legal, False for illegal
 */

int list_factor(int num, int factor[]); 
/*  Put all the factors of the dividend into an array
 *  PARAM: num - Number to be decomposed
 *         factor - a array to store all the factors of num
 *  RETURN: False when num is prime, otherwise True
 */

void op_generator(int arr[]);   
/*  Generate 10 adjacent operators that do not repeat and each appear at least once,
 *  and store them in an array
 *  PARAM: arr - to store 10 operators
 */

void formula_generator(int arr[]);
/*  Randomly generate formulas,
 *  then store them in array "questions"
 *  PARAM: arr - including 10 operators
 */

int scorer(int usr[], int std[]);
/*  Calculate user's score
 *  PARAM: usr - including user's answer of 10 questions
 *         std - including standard answer of 10 questions
 *  RETURN: user's score
 */

void print_ans(); // Print question, correct answer, user answer

int main(void) {
    int current_op_list[NUM_OF_QUESTIONS]; // Store the currently randomly generated op
    int begin, end; // Timing
    int option; // 3 options
    char str[81]; // Store each line of the file
    FILE * fp;
    student stu1;
    // If the input is illegal, prompt the user to re-enter
    while (!id_identify(&stu1))
        printf("This id is invalid, please re-enter\n");

    while (True) {
        printf("options:\n");
        printf("(1)start testing\n");
        printf("(2)check score\n");
        printf("(3)exit\n");
        
        char ch1;
        while (scanf("%d", &option) == 0 || (option < 1 || option > 3) || (ch1 = getchar()) != '\n') {
            printf("please enter an integer from 1 to 3!\n");
            fflush(stdin);
        }
  
        if (3 == option)
            break;

        switch (option) {
            // option1 -- start testing
            case 1:
                if ((fp = fopen(FILE_PATH, "a")) == NULL) {
                    printf("Error! opening file\n");
                    exit(1);
                }

                // question
                srand((unsigned int)time(NULL));
                op_generator(current_op_list);
                formula_generator(current_op_list);

                // answer
                char ch2;
                begin = time(NULL); // Timing begins
                for (int i = 0; i < NUM_OF_QUESTIONS; i++) {
                    printf("%s", questions[i]); // Print a question
                    
                    if (scanf("%d", &usr_ans[i]) == 0 || (ch2 = getchar()) != '\n') {
                        printf("Please enter an integer! Try again.\n");
                        i--; // Answer not finished yet, thus i--
                        fflush(stdin); // Clear the buffer
                    }
                }    
                end = time(NULL); // Timing ends

                stu1.score = scorer(usr_ans, std_ans);
                stu1.time = end - begin;
                // Write id, score, time to file
                fputs(stu1.id, fp);
                fprintf(fp, "\t%d\t%ds\n", stu1.score, stu1.time);
                fclose(fp);
                // Print question, correct answer, user answer
                print_ans();
                break;

            // option2 -- check score
            case 2 :
                if ((fp = fopen(FILE_PATH, "r")) == NULL) {
                    printf("Error! opening file\n");
                    exit(1);
                }
                // Read records from file
                while (!feof(fp)) {
                    fgets(str, 81, fp);
                    if (feof(fp)) // Prevent the last line of the file from being printed twice
                        break;
                    fputs(str, stdout);
                }
                fclose(fp);
                break;
        }   
    }
}

int id_identify(student * stu) {
    printf("Please enter your id:");

    // safer than gets()
    if (fgets(stu->id, 10, stdin) && stu->id[0] != '\n') {
        int j = 0;
        while (stu->id[j] != '\n' && stu->id[j] != '\0')
            j++;
        if (stu->id[j] == '\n')
            stu->id[j] = '\0';
        else
            while (getchar() != '\n')
                continue;        
    }

    int flag = True;
    if (strlen(stu->id) != 6)
        flag = False;

    for (int i = 0; i < DIGIT - 1; i++) {
        if (i < 2) {
            if (stu->id[i] < 65 || stu->id[i] > 90)
                flag = False;
        } 
        else {
            if (stu->id[i] < 48 || stu->id[i] > 57)
                flag = False;
        }
    }

    return flag;
}

int list_factor(int num, int factor[]) {
    int tmp = sqrt(num); // Round down
    int cnt = 0;

    for (int i = 1, j = 0; i <= tmp; i++) {
        if (num % i == 0) {
            factor[j] = i;
            cnt++;
            j++; // Index j will only increase if there is a deposit in the array
            if (i != num / i) {
                factor[j] = num / i;
                j++;
            }
        }
    }

    return 2 == cnt ? True : False;
}

void op_generator(int op[]) {
    int op_index; // Temporarily store the random number in [0, 3], compare with the last generated
    int flag[4] = {False};

    // Once each operator does not appear at least once, then regenerate
    while (!(flag[0] && flag[1] && flag[2] && flag[3])) {
        op[0] = rand() % 4;
        for (int i = 1; i < NUM_OF_QUESTIONS; i++) {
            // If the randomly generated operator is the same as the last time,
            // then regenerate until it is different
            do {
                op_index = rand() % 4;
            } while (op_index == op[i - 1]);

            // Once an operator appears randomly, its corresponding flag is changed to True
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

void formula_generator(int op[]) {
    int a, b;
    int factor[20] = {0}; // Store all factors of the dividend
    for(int i = 0; i < NUM_OF_QUESTIONS; i++) {
        a = rand() % 99 + 1; // a∈[1, 99]

        switch (op_list[op[i]]) {
            case '+':
                b = rand() % (99 - a) + 1; // b∈[1, 99 - a]
                std_ans[i] = a + b;
                break;

            case '-':
                b = rand() % (a - 1) + 1; // b∈[1, a - 1]
                std_ans[i] = a - b;
                break;

            case '*':
                a = rand() % 48 + 2; // a∈[2, 49]
                b = rand() % ((99 / a) - 1) + 2; // b∈[2, 99 / a]
                std_ans[i] = a * b;
                break;

            case '/':
                // Put all the factors of the dividend in factor[], and regenerate if a is prime
                while (!list_factor(a, factor)) {
                    // factor[] is cleared after each loop
                    for (int i = 0; i < 20; i++)
                        factor[i] = 0;
                    a = rand() % 96 + 4; // a∈[4, 99]
                }
            
                int length = 0;
                for (int j = 0; factor[j]; j++)
                    length++;
            
                b = factor[rand() % (length - 2) + 2]; // Randomly take from the non-1 and non-self factors of a
                std_ans[i] = a / b;
                break;
        }
        snprintf(questions[i], 11, "%2d %c %-2d = ", a, op_list[op[i]], b);
    }
}

int scorer(int usr_ans[], int std_ans[]) {
    int score = 0;

    for (int i = 0; i < NUM_OF_QUESTIONS; i++) {
        if (usr_ans[i] == std_ans[i])
            score += 10;
    }

    return score;
}

void print_ans() {
    printf("questions\tcorrect answer\tyour answer\n");
    for (int i = 0; i < NUM_OF_QUESTIONS; i++)
        printf("%s\t%d\t\t%d\t\n", questions[i], std_ans[i], usr_ans[i]);
}