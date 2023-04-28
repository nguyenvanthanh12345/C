/*
* File:tim kiem nhi phan.c
* Author: Nguyen Van Thanh
* Date: 24/04/2023
* Description: Tim kiem nhi phan
*/

#include<stdio.h>

/*
* Function: tim kiem nhi phan
* Description: tim kiem so trong mang
* Input:
*   arr - mang kieu int
*   size - gia tri mang
*   key -  so can tim kiem
* Output:
*   returns None
*/

void binarySearch(const int arr[],const int key,const int size)
{
    int low = 0;
    int high = size-1;
    int middle ;
    while( (high-low)>1 )
    {
        middle=(high + low)/2;
        if(arr[middle] == key)
        {
            printf("tim thay %d vi tri %d",key,middle);
            break;
        }
        else if (key > arr[middle])
        {
            low = middle;
        }
        else
        {
            high = middle;
        }
    }
}
int main()
{
    int arr[6]={2,3,4,6,7,9};
    binarySearch(arr,3,6);
}