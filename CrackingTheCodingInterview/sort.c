//
//  sort.c
//  CrackingTheCodingInterview
//
//  Created by WeirdFish on 30/01/2017.
//  Copyright © 2017 WeirdFish. All rights reserved.
//

#include "sort.h"
#include "string.h"

void merge_sort(int* arr, int from , int to) {
    if (to - from <= 0)
        return;
    
    int i = from, mid = (from + to) / 2, j = mid + 1;
    
    merge_sort(arr, i, mid);
    merge_sort(arr, j, to);
    
    //归并
    int reg[to - from + 1], index = 0;
    while (i <= mid && j <= to) {
        if (arr[i] < arr[j])
            reg[index++] = arr[i++];
        else
            reg[index++] = arr[j++];
    }
    while (i <= mid)
        reg[index++] = arr[i++];
    while (j <= to)
        reg[index++] = arr[j++];
    
    j = 0;
    for (i = from; i <= to; i++)
        arr[i] = reg[j++];
}

void quick_sort(int* arr, int left, int right) {
    if (left >= right)
        return;
    
    int i = 0, stored_index = 0, tmp;
    for (; i < right; i++) {
        if (arr[i] < arr[right]) {
            tmp = arr[i];
            arr[i] = arr[stored_index];
            arr[stored_index++] = tmp;
        }
    }
    tmp = arr[right];
    arr[right] = arr[stored_index];
    arr[stored_index] = tmp;
    
    quick_sort(arr, left, stored_index -1);
    quick_sort(arr, stored_index + 1, right);
}

/**
 ** merge b into a(a has enough buffer at the end to hold b) in sorted order.
 **/
void merge(int* a, int* b, int len1, int len2) {
    int last = len1 + len2 - 1;
    int i = len1 - 1, j = len2 - 1;
    while (i >= 0 && j >= 0) {
        if (a[i] > b[j])
            a[last--] = a[i--];
        else
            a[last--] = b[j--];
    }
    while (j >= 0)
        a[last--] = b[j--];
}

void sort_anagrams(char** arr, int len) {
    
}
