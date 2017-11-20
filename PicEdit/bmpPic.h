/******************************************************
* Author       : fengzhimin
* Email        : 374648064@qq.com
* Filename     : bmpPic.h
* Descripe     : bmp图片处理头文件
******************************************************/

#ifndef __BMPPIC_H__
#define __BMPPIC_H__

#include "config.h"

/********************************************
 * func: bmp图片格式头信息
 * @para bfType: 图片标识(2 Bytes)
 * @para bfSize: 文件的大小(4 Bytes)
 * @para bfReserved1: 保留(2 Bytes)
 * @para bfReserved2: 保留(2 Bytes)
 * @para bfOffBits: 文件起始位置到图像像素数据的字节偏移量(4 Bytes)
*********************************************/
typedef struct tagBITMAPFILEHEADER
{
    UINT16 bfType;
    DWORD bfSize;
    UINT16 bfReserved1;
    UINT16 bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER;

/********************************************
 * func: bmp图片信息头
 * @para biSize: INFOHEADER结构体大小，存在其他版本I NFOHEADER，用作区分(4 Bytes)
 * @para biWidth: 图像宽度（以像素为单位）(4 Bytes)
 * @para biHeight: 图像高度(4 Bytes)
 * @para biPlanes: 图像数据平面，BMP存储RGB数据，因此总为1(2 Bytes)
 * @para biBitCount: 图像像素位数(2 Bytes)(2 Bytes)
 * @para biCompression: 0：不压缩，1：RLE8，2：RLE4(4 Bytes)
 * @para biSizeImage: 4字节对齐的图像数据大小(4 Bytes)
 * @para biXPelsPerMeter: 用像素/米表示的水平分辨率(4 Bytes)
 * @para biYPelsPerMeter: 用像素/米表示的垂直分辨率(4 Bytes)
 * @para biClrUsed: 实际使用的调色板索引数，0：使用所有的调色板索引(4 Bytes)
 * @para biClrImportant: 重要的调色板索引数，0：所有的调色板索引都重要(4 Bytes)
*********************************************/
typedef struct tagBMPINFOHEADER
{
    DWORD biSize;
    DWORD biWidth;
    DWORD biHeight;
    WORD  biPlanes;
    WORD  biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    DWORD biXPelsPerMeter;
    DWORD biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BMPINFOHEADER;

BMPINFOHEADER bih;  
BYTE *Buffer;  
long LineByteWidth; 

/*****************************************
 * func: 读取bmp图片文件
 * return:
 * @para filePath: 图片路径
*****************************************/
int ReadBmp(const char* filePath);

/*****************************************
 * func: 获取指定位置的像素
 * return:
 * @para X: 水平坐标
 * @para Y: 垂直坐标
 * @para r: 红色
 * @para g: 绿色
 * @para b: 蓝色
*****************************************/
int GetDIBColor(int X, int Y, BYTE *r, BYTE *g, BYTE *b);

#endif