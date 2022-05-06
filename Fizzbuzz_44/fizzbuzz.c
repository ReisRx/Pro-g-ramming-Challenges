#include <stdio.h>
#include <string.h>
#include <assert.h>

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
        counter > 0 ? printf(" ") : printf("%d ", i);
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
        counter > 0 ? printf(" ") : printf("%d ", i);
    }
}

int main(void) {
    int start, end;
    printf("1st input is start, 2nd input is the end\n");
    scanf("%d%d", &start, &end);
    assert(start < end && start > 0);
    // fizzBuzz(start, end);
    fizzBuzz1(start, end);
    return 0;
}