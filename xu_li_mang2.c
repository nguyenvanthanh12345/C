/*
* File:Dao chieu doan van.c
* Author: Nguyen Van Thanh
* Date: 24/04/2023
* Description: Tim kiem nhi phan
*/

#include<stdio.h>

/*
* Function: copy mang 
* Description: copy mang ki tu
* Input:
*   ptr1 - con tro kieu char
*   ptr1 - con tro kieu char
*   length -  chieu dai mang can copy
* Output:
*   returns None
*/

void copyMangKiTu(char *ptr1,char *ptr2, int length)
{
    for(int i=0; i<length; i++)
    {
        ptr1[i]=ptr2[i];
    }
}

/*
* Function: dao chieu doan van 
* Description: dao chieu doan van
* Input:
*   cArray1[]  -  mang ki tu
*   cArray1[] -  mang ki tu copy
*   size -  size mang ki tu copy
* Output:
*   returns None
*/

void daoChieu(char cArray1[], char cArray2[],int iSize)
{
    int length=0;
    int j=0;
    for(int i = iSize-2 ; i>= -1; i--)
    {
        if(cArray2[i] == ' ' || i==-1)
        {
            copyMangKiTu(&(cArray1[j]), &(cArray2[i+1]), length);
            j = j + length;
            cArray1[j] = ' ';
            j++;
            length=0;
        }
        else
        {
            length++;
        }
    }
    cArray1[j]='\0';
}
int main()
{
    int size;
    char m2[]="thanh dep trai thanh dep trai";
    char m1[100];
    size=sizeof(m2);
    daoChieu(m1,m2,size);
    printf("%s",m1);
    
}