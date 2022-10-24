#include <stdio.h>
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
    int a[10], count = 0;
    for(int i=0;i<10;i++)
    {
        if (scanf("%d",&a[i]) != 1) {
            count++;
        }
    }
    if (count == 0) {
    selectionSort(a,10);
    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    
        return 0;
    } else {
            printf("n/a");
            return 1;
        }
}

