// Recursive.c -- EE 312 Project 7

/* Student information for project: This program creates functions that incorporate recursion to perform various tasks
 *
 * On my honor, Daniel Canterino, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Daniel Canterino
 * email address: dnc1231@verizon.net
 * UTEID: djc3323
 * Section 5 digit ID: 16115
 * Number of slip days used on this assignment: 0
 */

#include "Recursive.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h> //can only use strlen() from this

void isPaliHelper(int left, int right, char *s, bool *flag);
int doubleHelper(int data[], int N, int i);
void flowHelper(int M, int N, int map[M][N], int row, int col, bool *flag);

//getBinary takes an integer and returns the binary representation of that integer in a new integer
int getBinary(int n){
    if (n == 0) {//base case
        return 0;
    }
    else{
        return ((n % 2) + (10 * getBinary(n/2)));//builds from right to left (least significant bit to most)
    }
}

//isPalindrome returns true if the string passed to it is a palindrome and false otherwise
bool isPalindrome(char *s){
    int left = 0;//initializes the left index to the 0th term
    int right = strlen(s) - 1;//initializes the right index to the last index (-1 to convert length to index)
    bool flag = false;//initializes a flag to false (isPalindrome is false until proven otherwise)
    isPaliHelper(left, right, s, &flag);
    return flag;
}

//helper function for isPalindrome, same inputs as isPalindrome but also takes a pointer to the initialized false flag setup in isPalindrome
void isPaliHelper(int left, int right, char *s, bool *flag){
    if (left >= right){//base case, sets flag to true once it has reached the end of the recursive check (the bounds are equal to one another or the left bound is now past the right one)
        *flag = true;
        return;
    }
    if (s[left] == s[right]){//continues recursion if the values at both the indexes are the same
        isPaliHelper(left + 1, right - 1, s, flag);//recursively calls itself while moving the bounds towards one another
    }
}

//nextIsDouble takes an array of integers and that arrays length and returns how many of the integers are directly followed by twice that integers value
int nextIsDouble(int data[], int N){
    return doubleHelper(data, N, 0);//begins recursion with initial index set to 0
}

//helper for nextIsDouble, takes same inputs as nextIsDouble but also takes a pointer value
int doubleHelper(int data[], int N, int i){
    if (i >= (N - 1)){//base case, once the index points to the final element of the array (since this cannot be followed by a double value)
        return 0;
    }
    if (data[i + 1] == 2 * data[i]){//if the indexed element is followed by double its value, adds one to the total + the recursive call
        return 1 + doubleHelper(data, N, i + 1);
    }
    doubleHelper(data, N, i + 1);//continues recursion but does not add any to the total
}

//canFlowOff takes an array (map) of ints size M rows by N cols, and an initial 'coordinate' on the map for where a drop
// of water is placed. It then returns true if the water can in any way flow off the map based off its initial position
// by comparing the heights of each coordinate on the map (the int values) and seeing if its current height is more than
// the next height (meaning the water can flow in that direction)
bool canFlowOff(int M, int N, int map[M][N], int row, int col){
    bool flag = false;//initializes a flag to false that will only be changed to true after it finds a way for the water off the board
    flowHelper(M, N, map, row, col, &flag);//begins recursion
    return flag;
}

//flowHelper takes the same inputs as canFlowOff in addition to a pointer to a boolean flag that is initialized to false
void flowHelper(int M, int N, int map[M][N], int row, int col, bool *flag){
    if ((row == (M - 1)) || (col == (N - 1)) || (row == 0)
        || (col == 0) || (*flag == true)){//base case, if the case is located anywhere along the edge of the map, it
        *flag = true;//sets the flag to true and returns (also begins ending recursions since it only needs one path off the board)
        return;
    }
    if (map[row][col] > map[row + 1][col]){//checks South of current position
        flowHelper(M, N, map, row + 1, col, flag);
    }
    if (map[row][col] > map[row - 1][col]){//checks North of current position
        flowHelper(M, N, map, row - 1, col, flag);
    }
    if (map[row][col] > map[row][col - 1]){//checks West of current position
        flowHelper(M, N, map, row, col - 1, flag);
    }
    if (map[row][col] > map[row][col + 1]){//checks East of current position
        flowHelper(M, N, map, row, col + 1, flag);
    }
}