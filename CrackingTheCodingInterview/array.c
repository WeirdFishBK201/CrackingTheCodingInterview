//
//  array.c
//  Array
//
//  Created by WeirdFish on 20/12/2016.
//  Copyright © 2016 WeirdFish. All rights reserved.
//
#include <stdio.h>

#include "array.h"

void reverse_array(int* arr, int len)
{
    int begin = 0, end = len - 1, temp;
    while (begin < end) {
        temp = arr[begin];
        arr[begin++] = arr[end];
        arr[end--] = temp;
    }
}

void display(int* arr, int len)
{
    int i = 0;
    while (i < len)
        printf("%d ", arr[i++]);
    printf("\n");
}

void rotate(int** matrix, int row, int col)
{
    
}
