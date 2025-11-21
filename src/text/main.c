#include <stdio.h>
#include <windows.h>

int main()
{
    char* myStr = "fonts\\arial.ttf";
    unsigned int currentInt = 0;
    char* charPtr = myStr;
    while (*charPtr != '\0')
    {
        if (myStr[currentInt] == '\\')
        {
            printf("separator \\ found at index %d\n", currentInt);
            break;
        }
        charPtr++;
        currentInt++;
    }
    return 0;
}