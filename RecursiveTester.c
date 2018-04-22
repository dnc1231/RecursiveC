#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Recursive.h"


void doBinaryTests();
void doPalindromeTests();
void doNextIsDoubleTests();
void doCanFlowOffTests();
void doOneFlowOffTest(int M, int N, int arr[M][N], int, int, bool, int);

int main() {
    doBinaryTests();
    doPalindromeTests();
    doNextIsDoubleTests();
    doCanFlowOffTests();
}

void doCanFlowOffTests() {
    int testNum = 1;
    int world[][6] = {{5, 5, 5, 5, 5, 5},
                      {5, 5, 5, 5, 5, 5},
                      {5, 5, 5, 5, 5, 5},
                      {5, 5, 4, 4, 5, 5},
                      {5, 5, 3, 3, 5, 5},
                      {5, 5, 2, 2, 5, 5},
                      {5, 5, 5, 1, 5, 5},
                      {5, 5, -2, 5, 5, 5}};

    doOneFlowOffTest(8, 6, world, 3, 3, false, testNum++);
    doOneFlowOffTest(8, 6, world, 7, 5, true, testNum++);
    printf("\n");
}

void doOneFlowOffTest(int M, int N, int world[M][N], int r, int c, bool expected, int testNum) {
    printf("Can Flow Off Map Test Number %d\n", testNum);
    bool actual = canFlowOff(M, N, world, r, c);
    printf("Start location = %d, %d\n", r, c);
    printf("Expected result = %d, actual result = %d\n", expected, actual);
    if(expected == actual)
        printf("Passed Test %d can flow off map\n", testNum);
    else
        printf("FAILED test %d can flow off map\n", testNum);
    printf("\n");
}

void doNextIsDoubleTests(){
    int numsForDouble[] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
    int actual = nextIsDouble(numsForDouble, 9);
    int expected = 8;
    if(actual == expected)
        printf("Test 1 passed, next is double\n");
    else
        printf("Test 1 failed, next is double. expected: %d, actual: %d\n", expected, actual);

    int nums[] = {1, 3, 4, 2, 32, 8, 128, -5, 6};
    actual = nextIsDouble(nums, 9);
    expected = 0;
    if(actual == expected)
        printf("Test 2 passed, next is double\n");
    else
        printf("Test 2 failed, next is double. expected: %d, actual: %d\n", expected, actual);

    int nums2[] = {1, 0, 0, -5, -10, 32, 64, 128, 2, 9, 18};
    actual = nextIsDouble(nums2, 11);
    expected = 5;
    if(actual == expected)
        printf("Test 3 passed, next is double\n");
    else
        printf("Test 3 failed, next is double. expected: %d, actual: %d\n", expected, actual);

    int nums3[] = {};
    actual = nextIsDouble(nums3, 0);
    expected = 0;
    if (actual == expected)
        printf("Test 4 passed, next is double\n");
    else
        printf("Test 4 failed, next is double. expeded: %d, actual: %d\n", expected, actual);

}

void doBinaryTests(){
    int actual = getBinary(13);
    int expected = 1101;
    if(actual == expected)
        printf("Test 1 passed, get binary\n");
    else
        printf("Test 1 failed, get binary. expected = %d, actual = %d\n", expected, actual);

    actual = getBinary(0);
    expected = 0;
    if(actual == expected)
        printf("Test 2 passed, get binary\n");
    else
        printf("Test 2 failed, get binary. expected = %d, actual = %d\n", expected, actual);

    actual = getBinary(35);
    expected = 100011;
    if(actual == expected)
        printf("Test 3 passed, get binary\n");
    else
        printf("Test 3 failed, get binary. expected = %d, actual = %d\n", expected, actual);

    actual = getBinary(1);
    expected = 1;
    if (actual == expected)
        printf("Test 4 pased, get binary\n");
    else
        printf("Test 4 failed, get binary. expected = %d, actual = %d\n", expected, actual);
}

void doPalindromeTests() {
    char s[] = "hello olleh";
    bool expected = true;
    bool actual = isPalindrome(s);
    if(actual == expected)
        printf("Test 1 passed, is palindrome\n");
    else
        printf("Test 1 failed, is palindrome. expected = %d, actual = %d\n", expected, actual);

    char t[] = " ";
    expected = true;
    actual = isPalindrome(t);
    if(actual == expected)
        printf("Test 2 passed, is palindrome\n");
    else
        printf("Test 2 failed, is palindrome. expected = %d, actual = %d\n", expected, actual);

    char r[] = "oro";
    expected = true;
    actual = isPalindrome(r);
    if(actual == expected)
        printf("Test 3 passed, is palindrome\n");
    else
        printf("Test 3 failed, is palindrome. expected = %d, actual = %d\n", expected, actual);
}
    
   

    