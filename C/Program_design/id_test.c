#include<stdio.h>
#define True 1
#define False 0
#define DIGIT 6

int id_identify(char list[]) {

    //gets(list);
    //stu.id[6] = {'A', 'B', '1', '2', '3', '4'};
    int flag = True;
    for(int i = 0; i <= DIGIT; i++) {
        if(i < 2) {
            if(list[i] < 65 || list[i] > 90)
                flag = False;
        } 
        else {
            if(list[i] == '\0')
                break;
            if(list[i] < 49 || list[i] > 57)
                flag = False;
        }
    }

    return flag;
}

int main(void) {
    char list[7] = "AB1234";
    //gets(list);
    //puts(list);
    if(id_identify(list))
        printf("Yes");
    else
        printf("No");
    
}