#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
You can type the students' names and grades for each subject
This code enables the user to find the average score and list the students in order of the grade
*/

typedef struct STUDENT {
    char name[10];
    int english;
    int math;
    int science;
    int programming;
    int average;
}STUDENT;

void addUser(STUDENT *ptr, int *count) {
    int index = *count;

    if (*count > 9) {
        printf("Already 10 students in the list.\n");
        (*count)-- ;
        return;
    }

    printf("Type your name: ");
    gets(ptr[index].name), sizeof(ptr[index].name);

    
for (int i = 0; i <= index - 1; i++) {
        if (strcmp(ptr[index].name, ptr[i].name) == 0) {
            printf("Already on the list. Please input different name.\n");
            (*count)--;
            return;
        }
    }
    

    printf("English grade: ");
    scanf("%d", &ptr[index].english), sizeof(ptr[index].english);

    printf("Math grade: ");
    scanf("%d", &ptr[index].math), sizeof(ptr[index].math);

    printf("Science grade: ");
    scanf("%d", &ptr[index].science), sizeof(ptr[index].science);

    printf("Programming grade: ");
    scanf("%d", &ptr[index].programming), sizeof(ptr[index].programming);
}


void showList(STUDENT *ptr, int *count){

    for (int i = 0; i <= *count; i++) {
        ptr[i].average = (ptr[i].english + ptr[i].math + ptr[i].science + ptr[i].programming) / 4;
    }

    printf("*********************************************************************\n");
    for (int i = 0, j = 0; i <= *count; i++) {
            printf("%d.\t name: %10s\t, english: %3d\t, math: %3d\t, science: %3d\t, programming: %3d\t, average: %3d\n", ++j, ptr[i].name, ptr[i].english, ptr[i].math, ptr[i].science, ptr[i].programming, ptr[i].average);
    }
    printf("*********************************************************************\n");
}

void averageAlph(STUDENT *ptr, int *count) {
    int index = *count;
    char alphabet;
    char find[10];

    printf("Which student's average would you like to see: ");
    scanf_s("%s", &find, sizeof(find));

    for (int i = 0; i <= count; i++){
        if (strcmp(find, ptr[i].name) == 0) {

            if (ptr[i].average >= 90) {
                printf("A\n");
            }
            else if (ptr[i].average >= 80) {
                printf("B\n");
            }
            else if (ptr[i].average >= 70) {
                printf("C\n");
            }
            else if (ptr[i].average >= 60) {
                printf("D\n");
            }
            else {
                printf("F\n");
            }
            break;
        }
    }
}

void topFive(STUDENT *ptr, STUDENT *temporary, int count) {

    /*
    char tempName [10];


    for (int i = 0; i <= *count; i++) {
        strcpy (temp[i], ptr[i]);
    }


    for (int i = 0; i <= *count; i++) {
        for (int j = 0; j <= (*count) - 1; j++) {
            if (ptr[j].average < ptr[j+1].average) {
                strcpy(tempName , temp[j]);
                strcpy(temp[j], temp[j+1]);
                strcpy(temp[j+1], tempName);

                strcpy(tempAvg, tAvg[j]);
                strcpy(tAvg[j], tAvg[j+1]);
                strcpy(tAvg[j+1], tempAvg);


            }
        }
    }
    */

    /*
    int max = 0;
    char first[10];
    for (int i = 0; i <= (*count); i++) {
        if (max < ptr[i].average) {
            max = ptr[i].average;
            strcpy(first, ptr[i].name);
        }
    }


    int maxTwo = 0;
    char second[10];
    for (int i = 0; i <= (*count); i++) {
        if (maxTwo < ptr[i].average < max) {
            maxTwo = ptr[i].average;
            strcpy(second, ptr[i].name);
        }
    }

    int maxThree = 0;
    char third[10];
    for (int i = 0; i <= (*count); i++) {
        if (maxThree < ptr[i].average && ptr[i].average < maxTwo) {
            maxThree = ptr[i].average;
            strcpy(third, ptr[i].name);
        }
    }

    int maxFour = 0;
    char fourth[10];
    for (int i = 0; i <= (*count); i++) {
        if (maxFour < ptr[i].average && ptr[i].average < maxThree) {
            maxFour = ptr[i].average;
            strcpy(fourth, ptr[i].name);
        }
    }

    int maxFive = 0;
    char fifth[10];
    for (int i = 0; i <= (*count); i++) {
        if (maxFive < ptr[i].average && ptr[i].average < maxFour) {
            maxFive = ptr[i].average;
            strcpy(fifth, ptr[i].name);
        }
    }

    printf("%s, %s, %s, %s, %s\n", &first, &second, &third, &fourth, &fifth);
}
*/
/*
for (int i = 0; i <= count; i++) {
    temp[i] = ptr[i];
}
*/

    for (int i = 0; i < count ; i++) {
        for (int j = 0; j < count; j++) {
            if (ptr[j].average < ptr[j + 1].average) {
                temporary[j] = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temporary[j];
            }
        }
    }

    printf("Top five students: \n");
    for (int i = 0; i < 5; i++) {
        printf("%s \n", ptr[i].name);
    }
}


#define MAX 10

int main() {
    STUDENT student[MAX];
    STUDENT temporary[MAX];
    //struct STUDENT tempTwo[MAX];
    int cmd = 0;
    int count = -1;
    int average[MAX];
    //char temp[MAX][10];

    while (1) {
        printf("1: 추가, 2: 리스트 보여주기, 3: 평균점수 알파벳, 4: 평균 상위 5등 학생들 찾기, 5: 끝내기\n");
        scanf_s("%d%*c", &cmd);

        switch (cmd)
        {
        case 1:
            count++;
            addUser(&student, &count);
            showList(&student, &count);
            break;
        case 2:
            showList(&student, &count);
            break;
        case 3:
            averageAlph(&student, &count);
            break;
        case 4:
            topFive(&student, &temporary, count);
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("Wrong number. Plz input 1~5");
            break;
        }
    }
}


