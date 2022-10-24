#include <stdio.h>
#define LEN 100
void selectionSort(int *num, int size)
{
    int cds, temp;
    for(int i=0; i<size-1;i++)
    {
        cds = i;
        for(int j=i+1; j<size;j++)
        {
            if(num[j]<num[cds])
                cds=j;
        }
        temp=num[i];
        num[i]=num[cds];
        num[cds]=temp;
    }
}
int main()
{
    int a[21], count = 0;
    for(int i=0;i<11;i++)
    {
        if (scanf("%d",&a[i]) != 1) {
            count++;
        }
    }
    if (count == 0) {
    selectionSort(a,11);
    for(int i=0;i<11;i++)
        printf("%d ",a[i]);
    
        return 0;
    } else {
            printf("n/a");
            return 1;
        }
}
