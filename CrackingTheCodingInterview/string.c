//
//  string.c
//  Arrays_and_Strings
//
//  Created by WeirdFish on 14/01/2017.
//  Copyright © 2017 WeirdFish. All rights reserved.
//

#include <stdio.h>

#include "string.h"

int unique(char* s, int len)
{
    int i;
    int arr[129] = {0};
    for (i = 0; i < len; ++i) {
        if (arr[s[i]])
            return 0;
        arr[s[i]] = 1;
    }
    return 1;
}

void reverse(char* s, int len)
{
    int i = 0, j = len - 1;
    char temp;
    while (i < j) {
        temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
}

void remove_duplicates(char* s, int len)
{
    int i;
    int count[129] = {0};
    for (i = 0; i < len; ++i)
        count[s[i]]++;
    for (i = 0; i < 129; ++i)
        if(count[i] == 1) printf("%c", i);
    printf("\n");
}

int anagrams(char* s1, char* s2, int len)
{
    int i;
    int count1[129] = {0}, count2[129] = {0};
    for (i = 0; i < len; ++i)
    {
        count1[s1[i]]++;
        count2[s2[i]]++;
    }
    for (i = 0; i < 129; ++i)
        if (count1[i] != count2[i])
            return 0;
    return 1;
}

size_t strlen(const char* s)
{
    size_t len = 0;
    while (s[len]) len++;
    return len;
}

void url_encode_space(char* s, int len)
{
    char tmp[len+1];
    int i = 0, j = 0;
    for (; i < len; i++)
        tmp[i] = s[i];
    tmp[i] = '\0';
        
    for (i=0; i<len; i++) {
        if (tmp[i] == 32) {
            s[j++] = '%';
            s[j++] = '2';
            s[j++] = '0';
            continue;
        }
        s[j++] = tmp[i];
    }
    s[j] = '\0';
}



