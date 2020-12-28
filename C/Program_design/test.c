#include<stdio.h>
#include<math.h>

/*int main(void) {
    int num;
    scanf("%d", &num);

    int tmp = sqrt(num);

    for(int i = 1; i <= tmp; i++) {
        if(num % i == 0) {
            printf("You've fount a divisor of %d , and it is %d\n", num, i);
            if(i != num / i)
                printf("You also found a mate for it: %d\n", num / i);
        }
    }
}*/

int main(void) {
    // 计时开始
    begin = time(NULL);
    srand((unsigned)time(NULL));
    current_op_list[0] = rand() % 4;
    for(int i = 0; i < number_of_questions; i++) {
        if(i != 0) {
            do {
                op_index = rand() % 4;
            } while(op_index == current_op_list[i - 1]);
            current_op_list[i] = op_index;
        }
        formula_generator(op_list[current_op_list[i]], i); //生成随机算式
        scanf("%d", &user[i]);  //用户输入答案      
    }
    // 计时结束
    end = time(NULL);
    stu1.score = scorer(user, ans);
    stu1.time = end - begin;
}