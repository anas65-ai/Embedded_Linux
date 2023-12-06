#include<stdio.h>
typedef unsigned char u8;
u8 arr[7]={0,1,2,3,4,5};
u8 BinSearch(u8 *arr,u8 size,u8 target);
int main(void)
{
  u8 ReturnVal=BinSearch(arr,6,3);
  printf("%i\n",ReturnVal);
return 0;
}

u8 BinSearch(u8 *arr,u8 size,u8 target)
{
 
   u8 low = 0, high = size - 1;

    while (low <= high) {
        u8 mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;  // Element found at mid index
        } else if (arr[mid] < target) {
            low = mid + 1;  // If the target is greater, ignore the left half
        } else {
            high = mid - 1;  // If the target is smaller, ignore the right half
        }
    }

    return -1;  // Element not found in the array
}

