#include <stdio.h>

#define LEN 100
void selectionSort(int *num, int size)
{
    int min, temp;
    for(int i=0; i<size-1;i++)
    {
        min = i;
        for(int j=i+1; j<size;j++)
        {
            if(num[j]<num[min])
                min=j;
        }
        temp=num[i];
        num[i]=num[min];
        num[min]=temp;
    }
}
int main()
{
    int a[21], count = 0;
    for(int i=0;i<21;i++)
    {
        if (scanf("%d",&a[i]) != 1) {
            count++;
        }
    }
    if (count == 0) {
    selectionSort(a,21);
    for(int i=0;i<21;i++)
        printf("%d ",a[i]);
    
        return 0;
    } else {
            printf("n/a");
            return 1;
        }
}
