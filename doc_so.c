/*
* File:Doc so.c
* Author: Nguyen Van Thanh
* Date: 24/04/2023
* Description: Doc so
*/
// VD: 7250890 
// doc so : bay trieu hai tram nam muoi nghin tam tram chin muoi

#include<stdio.h>
#include<stdint.h>
#define MAX_THAP_PHAN 7

char readNumber[10][6]= {"khong","mot","hai","ba","bon","nam","sau","bay","tam","chin"};
/*
* Function: tach so thap phan
* Description: tach so thap phan
* Input:
*   num - so thap phan can tach
*   arr - mang chua so thap phan da tach
*   size - gia tri mang
* Output:
*   returns None
*/
void tachSo(uint32_t num, uint8_t arr[],uint8_t *size)
{
    uint8_t i=0;
    while(num > 0)
    {
        arr[i]=num % 10;
        num = num /10;
        i++;
    }
    *size = i;
}

/*
* Function: doc so thap phan
* Description: doc so thap phan
* Input:
*   num - so thap phan can tach
* Output:
*   returns None
*/

void docSo(uint32_t num)
{
    uint8_t arr[MAX_THAP_PHAN];
    uint8_t size;
    tachSo(num,arr,&size);
    for(int i=size-1; i>=0 ;i--)
    {
        switch(i)
        {
            case 6:
                printf("%s trieu ",readNumber[arr[i]]);
                break;
            case 5:
                printf("%s tram ",readNumber[arr[i]]);
                break;
            case 4:
                if (arr[i]==1) printf("muoi ");
                else if (arr[i]== 0) printf("linh ");
                else printf("%s muoi ",readNumber[arr[i]]);
                break;
            case 3:
                if(arr[i] > 0) printf("%s ",readNumber[arr[i]]);
                printf("nghin ");
                break;
            case 2:
                printf("%s tram ",readNumber[arr[i]]);
                break;
            case 1:
                if (arr[i]==1) printf("muoi ");
                else if (arr[i]== 0) printf("linh ");
                else printf("%s muoi ",readNumber[arr[i]]);
                break;
            case 0:
                if(arr[i] > 0) printf("%s ",readNumber[arr[i]]);
                break;
        }
    }
}
int main()
{
    docSo(7005806);
}