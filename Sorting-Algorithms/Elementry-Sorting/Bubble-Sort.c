#include<stdio.h>
int bubble_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int flag=0;
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
    printf("The sorted array is ----\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}
void main()
{
    int n;
    printf("Enter the size of the array:- ");
    scanf("%d",&n);
    int array[n];
    printf("Enter the elements of the array in the following index :-\n");
    for(int i=0;i<n;i++)
    {
        printf("Array[%d] = ",i);
        scanf("%d",&array[i]);
    }
    bubble_sort(array,n);
}