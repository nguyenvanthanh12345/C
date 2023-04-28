/*
* File:Bai3.c
* Author: Nguyen Van Thanh
* Date: 24/04/2023
* Description: liet ke từ co so lan xuat hien trong mang ki tu
*/
//vd: mang[]="hai mot ba hai ba"
//liet ke từ co so lan xuat hien trong mang ki tu vd: hai xuat hien 2 lan
//                                                    mot xuat hien 1 lan
//                                                    ba xuat hien 2 lan
#include<stdio.h>
#define MAX_COT 10
#define MAX_HANG 10
/*
* Function: lay vi tri ki tu nho nhat 
* Description: lay vi tri ki tu nho nhat o đầu mỗi từ theo ma Ascii trong mang 2 chieu
* Input:
*   cArray[][MAX_COT] - mang 2 chieu kieu int
*   iViTriBatDau - bien kieu int
*   iSize - bien kieu int
* Output:
*   Tra vi tri nho nhat trong mang 2 chieu
*/
int layViTriKiTuThapNhat(char cArray[][MAX_COT],int iViTriBatDau, int iSize)
{
    char cNhoNhat= cArray[iViTriBatDau][0];
    int iViTriNhoNhat = iViTriBatDau;
    for(int i= iViTriNhoNhat + 1; i < iSize; i++)
    {
        if(cNhoNhat > cArray[i][0])
        {
            cNhoNhat= cArray[i][0];
            iViTriNhoNhat = i;
        }
    }
    return iViTriNhoNhat ;
}
/*
* Function: sao chep mang
* Description: Sao chep mang ki tu
* Input:
*   *ptrArray1 - con tro mang kieu char
*   *ptrArray2 - con tro mang kieu char
* Output:
*   returns None
*/
void copyMangKiTu(char *ptrArray1, char *ptrArray2)
{
    int i=0;
    while(ptrArray2[i] !='\0')
    {
        ptrArray1[i]= ptrArray2[i];
        i++;
    }
    ptrArray1[i] ='\0';
}
/*
* Function: Hoan doi vi tri
* Description: Hoan doi vi tri trong mang 2 chieu
* Input:
*   cArray[][MAX_COT] - mang 2 chieu kieu char
*   iViTri1 - bien kieu int
*   iViTri2 - bien kieu int
* Output:
*   returns None
*/
void hoanDoi (char cArray[][MAX_COT], int iViTri1, int iViTri2)
{
    char temp[MAX_COT];
    copyMangKiTu(temp,&(cArray[iViTri1][0]));
    copyMangKiTu(&(cArray[iViTri1][0]), &(cArray[iViTri2][0]));
    copyMangKiTu(&(cArray[iViTri2][0]),temp);
}
/*
* Function: sap xep mang ki tu
* Description: sap xep mang ki tu trong mang 2 chieu
* Input:
*   cArray[][MAX_COT] - mang 2 chieu kieu char
*   iViTri1 - bien kieu int
*   iViTri2 - bien kieu int
* Output:
*   returns None
*/
void sapXepMangKiTu(char cArray[][MAX_COT], int iSize)
{
    int iViTriKiTuThapNhat;
    for(int i=0;i<iSize-1;i++)
    {
        iViTriKiTuThapNhat = layKiTuThapNhat(cArray,i,iSize);
        hoanDoi(cArray,i,iViTriKiTuThapNhat);
    }
}
void hienThiMangHaiChieu(char cArray[][MAX_COT],int iSize)
{
    for(int i=0; i< iSize; i++)
    {
        printf("%s\n",cArray[i]);
    }
}

/*
* Function: copy mang ki tu 1 chieu sang mang 2 chieu
* Description: copy mang ki tu 1 chieu sang mang 2 chieu
* Input:
*   cArray[][MAX_COT] - mang 2 chieu kieu char
*   cArray2 - mang 1 chieu kieu char
*   length - size mang kieu co tro kieu int
* Output:
*   returns None
*/

void copyMangKiTu1ChieuSang2Chieu(char cArray1[][MAX_COT],char cArray2[],int *length)
{
    int i=0;
    int j=0;
    int k=0;
    while(cArray2[i] != '\0' )
    {
        cArray1[j][k]= cArray2[i];
        i++;
        k++;
        if(cArray2[i] == ' ')
        {
            cArray1[j][k]= '\0';
            i++;
            j++;
            k=0;
        }
    }
    cArray1[j][k]='\0';
    *length=j+1;
}

/*
* Function: so sanh mang 
* Description: so sanh mang
* Input:
*   *ptrArray1 - con tro mang kieu char
*   *ptrArray2 - con tro mang kieu char
* Output:
*   returns 1: hai mang bang nhau
*   returns 0: hai mang khac  bang nhau
*/

int soSanhMangKiTu(char *ptrArray1, char *ptrArray2)
{
    int i=0;
    while( ptrArray1[i] == ptrArray2[i])
    {
        if(ptrArray1[i] == '\0') return 1;
        i++;
    }
    return 0;
}

/*
* Function: hien thi so lan xuat từ hien trong mang ki tu
* Description: hien thi so lan xuat từ hien trong mang ki tu
* Input:
*   Array1 - mang kieu char
* Output:
*  none
*/

void LanXuatHienTrongMangKiTu(char cArray1[])
{
    int iCount=1, length;
    char cArray2[MAX_HANG][MAX_COT]={0};
    copyMangKiTu1ChieuSang2Chieu(cArray2,cArray1,&length);
    sapXepMangKiTu(cArray2,length);
    for(int i=0;i<length;i++)
    {
        if(soSanhMangKiTu( &(cArray2[i][0]), &(cArray2[i+1][0])))
        { 
            iCount++;
        }
        else 
        {
            printf("%s: xuat hien %d lan\n",cArray2[i],iCount);
            iCount=1;
        }
    }
}
int main()
{
   char m[]="hai hai mot sau bay hai mot ba";
   LanXuatHienTrongMangKiTu(m);
}