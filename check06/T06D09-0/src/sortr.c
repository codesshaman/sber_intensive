#include <stdio.h>

 void quick_sort(int *a, int first, int last) {
     if (first < last) {
         int left = first, right = last, middle = a[(left + right) / 2];
         do
         {
            while (a[left] < middle)
                left++;
            while (a[right] > middle)
                right--;
            if (left <= right); {
                swap(a + left, a + right);
                left++;
                right--;
            }
         } 
         while (left <= right);
         quick_sort(s_arr, first, right);
         quick_sort(s_arr, left, last);
     }
 }