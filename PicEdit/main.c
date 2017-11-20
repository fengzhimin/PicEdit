#include "bmpPic.h"

int main(void)  
{  
    int x, y;  
    BYTE r, g, b;  
    char szfilename[255] = "test.bmp";  
    if (ReadBmp(szfilename) == 0)  
    {  
        printf("failure to read file %s", szfilename);  
        return 1;  
    }  
    printf("Width: %d\n", bih.biWidth);  
    printf("Height: %d\n", bih.biHeight);  
    printf("BitCount: %d\n\n", (int)bih.biBitCount);  
    while(1)  
    {  
        printf("input the X:");  
        scanf("%d", &x);  
        if (x < 0)  
                break;  
        printf("input the Y:");  
        scanf("%d", &y);  
        if(GetDIBColor(x, y, &r, &g, &b) == 1)  
            printf("(%d, %d): r:%d, g:%d, b:%d\n", x, y, (int)r, (int)g, (int)b);  
        else
            printf("input error.\n");  
    }  
    free(Buffer);  
    return 0;  
}  