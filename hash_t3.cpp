#include <stdio.h>
#include <iostream>
#include "malloc.h"

using namespace std;

#define MAX_TABLE 10
#define MAX_N 10
#define MAX_LEN 15

typedef struct dat_t{
    char key[15];
    int val;
}dat_t;

int N;

unsigned long myhash(const char *str)
{
    unsigned long hash = 5381;
    int c;
    while(c = *str++)
    {
        hash = (((hash << 5) + hash) + c) % MAX_TABLE;
    }
    return hash % MAX_TABLE;
}

int main(void)
{
    int ret = 0;
    int i;
    freopen("hash_t3.txt", "r", stdin);
    scanf("%d", &N);
    printf("%d\n", N);
    
    dat_t **ptr = NULL;
    ptr = (dat_t **)malloc(sizeof(dat_t *) * N);
    for (i = 0; i < N; i++) {

        *(ptr + i) = (dat_t *)malloc(sizeof(dat_t) * MAX_LEN);
        scanf( "%s", &(*(ptr + i))->key[0] );
        scanf( "%d", &(*(ptr + i))->val );
        printf("input %s, val(%d)\n", (*(ptr + i))->key, (*(ptr + i))->val );
    }

    for (i = 0; i < N; i++) {
        free(*(ptr+i));
    }
    free(ptr);

    return ret;
}
