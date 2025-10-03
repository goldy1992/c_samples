#include <stdio.h>


#define TYPE(t) #t

struct MyStruct {
    int x;
    int y;
    char name [100];
};
typedef struct MyStruct MyStruct;


int main()
{
    MyStruct myStruct;
    myStruct.x = 10;
    myStruct.y = 20;

    printf("hello macros, %s\n", TYPE(MyStruct));
}