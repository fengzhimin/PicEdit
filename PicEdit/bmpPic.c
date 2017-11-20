/******************************************************
* Author       : fengzhimin
* Email        : 374648064@qq.com
* Filename     : bmpPic.h
* Descripe     : bmp图片处理源文件
******************************************************/

#include "bmpPic.h"

BMPINFOHEADER bih;  
BYTE *Buffer = NULL;  
long LineByteWidth; 


int ReadBmp(const char* filePath)
{
    FILE *file;  
    WORD bfh[7];  
    long dpixeladd;  
    if(NULL == (file = fopen(filePath, "rb")))  
    {
        return 0;  
    }
    printf("%s\n", filePath);  
    fread(&bfh, sizeof(WORD), 7, file);  
    if (bfh[0] != (WORD)(((WORD)'B')|('M'<<8)))  
    {
        fclose(file);  
        return 0;  
    }
    fread(&bih, sizeof(BMPINFOHEADER), 1, file);  
    if (bih.biBitCount < 24)  
    {
        fclose(file);  
        return 0;  
    }
    dpixeladd = bih.biBitCount / 8;  
    LineByteWidth = bih.biWidth * (dpixeladd);  
    if ((LineByteWidth % 4) != 0)  
    LineByteWidth += 4 - (LineByteWidth % 4);  
    if ((Buffer = (BYTE*)malloc(sizeof(BYTE)* LineByteWidth * bih.biHeight)) != NULL)  
    {
        fread(Buffer, LineByteWidth * bih.biHeight, 1, file);  
        fclose(file);  
        return 1;  
    }
    fclose(file); 
 
    return 0;  
}

int GetDIBColor(int X, int Y, BYTE *r, BYTE *g, BYTE *b)
{
    int dpixeladd;  
    BYTE *ptr;  
    if(X < 0 || X >= bih.biWidth || Y < 0 || Y >= bih.biHeight)  
    {  
        return 0;  
    }  
    dpixeladd = bih.biBitCount / 8;  
    ptr = Buffer + X * dpixeladd + (bih.biHeight - 1 - Y) * LineByteWidth;  
    *b = *ptr;  
    *g = *(ptr + 1);  
    *r = *(ptr + 2);  
    return 1; 
}