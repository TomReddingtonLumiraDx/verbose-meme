#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    const int a;
    const int b;
    const int c;
    const char ch[6];
} a_t;

a_t arr[100] = {0};

int getIndex(const a_t *pPointer) {
    size_t start = (size_t)&arr[0];
    size_t position = (size_t)pPointer;
    return (int)(((size_t)pPointer - (size_t)&arr[0]) / sizeof(a_t));
}


int main() {
    a_t *pPointer = &arr[34];

    printf("%d\n", getIndex(&arr[34]));
    printf("%d\n", getIndex(&arr[77]));
    printf("%d\n", getIndex(&arr[0]));
    printf("%d\n", getIndex(&arr[99]));
    printf("%d\n", getIndex(&arr[103]));
}