/*
* File:Sap xep.c
* Author: Nguyen Van Thanh
* Date: 24/04/2023
* Description: Sap xep
*/

#include<stdio.h>

/*
* Function: lay vi tri so nho nhat
* Description: lay vi tri so nho nhat
* Input:
*  iArray[] - mang kieu int
*  iLow  -  bien kieu int
*  iHigh  -  bien kieu int
* Output:
*   returns: vi tri so nho nhat
*/

int getSmallestLocation(int iArray[],int iLow, int iHigh)
{
    int iSmallest= iArray[iLow];
    int iSmallestLocation=iLow;
    for(int i=iLow+1; i<iHigh; i++)
    {
        if(iSmallest > iArray[i])
        {
            iSmallest= iArray[i];
            iSmallestLocation=i;
        }
    }
    return iSmallestLocation;
}

/*
* Function: hoan doi
* Description: hoan doi vi tri trong mang
* Input:
*  iArray[] - mang kieu int
*  iLocation1  -  bien kieu int
*  iLocation1  -  bien kieu int
* Output:
*   returns: none
*/

void swap (int iArray[], int iLocation1, int iLocation2)
{
    int iTemp= iArray[iLocation1];
    iArray[iLocation1]= iArray[iLocation2];
    iArray[iLocation2]= iTemp;
}

/*
* Function: sap xep tu be den lon
* Description: sap xep tu be den lon
* Input:
*  iArray[] - mang kieu int
*  iSize  -  bien kieu int
* Output:
*   returns: none
*/

void sortFromLowToHigh(int iArray[], int iSize)
{
    int iSmallLocation;
    for(int i=0;i<iSize-1;i++)
    {
        iSmallLocation=getSmallestLocation(iArray, i, iSize-1);
        swap(iArray, i, iSmallLocation);
    }
}

/*
* Function: hien thi so phan tu giong nhau
* Description: hien thi so phan tu giong nhau
* Input:
*  iArray[] - mang kieu int
*  iSize  -  bien kieu int
* Output:
*   returns: none
*/

void xuatSoPhanTuGiongNhau(int iArray[],int iSize)
{
    int iCount=1;
    for(int i=0; i<iSize; i++)
    {
        if(iArray[i]==iArray[i+1])
        {
            iCount++;
        }
        else
        {
            printf("So lan xuat hien %d la: %d\n",iArray[i],iCount);
            iCount=1;
        }
    }
}
int main()
{
    int array[]={7,3,5,3,2,8};
    sortFromLowToHigh(array,6);
    xuatSoPhanTuGiongNhau(array,6);
}