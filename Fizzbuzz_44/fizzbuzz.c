#include <stdio.h>
#include <string.h>

// The 'niche' version
int divisibleByThree(int number) {
    if(number % 3 == 0) {
        printf("Fizz");
        return 1;
    }
    return 0;
}

int divisibleByFive(int number) {
    if(number % 5 == 0) {
        printf("Buzz");
        return 1;
    }
    return 0;
}

// There is an argument start incase you wanna change it up
void fizzBuzz(int start, int end) {
    int counter;
    for(int i = start; i < end + 1; i++) {
        counter = 0;
        counter += divisibleByThree(i);
        counter += divisibleByFive(i);
        counter > 0 ? printf("\n") : printf("%d\n", i);
    }
}

// The normal version
void fizzBuzz1(int start, int end) {
    int counter;
    for(int i = start; i < end + 1; i++) {
        counter = 0;
        if(i % 3 == 0) {
            printf("Fizz");
            counter++;
        }
        if(i % 5 == 0) {
            printf("Buzz");
            counter++;
        }
        counter > 0 ? printf("\n") : printf("%d\n", i);
    }
}

int main(void) {
    int start, end;
    printf("Where would you like the FizzBuzz to start and end ?\n");
    printf("(type '1 10' if you want it to start on 1 and finish on 10): ");
    scanf("%d%d", &start, &end);
    while(end <= start || start < 1) {
        printf("Invalid numbers! Remember start smaller than end AND start greater than 0\n");
        scanf("%d%d", &start, &end);
    }
    printf("Would you like the 'niche' or the normal version ?\n");
    printf("(type niche or normal): ");
    char version[7];
    scanf("%s", version);
    while(strcmp(version, "niche") != 0 && strcmp(version, "normal") != 0) {
        printf("That's not an available option!\n");
        printf("(type niche or normal): ");
        scanf("%s", version);
    }
    if(strcmp(version, "niche") == 0) {
        fizzBuzz(start, end);
    }
    else {
        fizzBuzz1(start, end);
    }
    return 0;
}