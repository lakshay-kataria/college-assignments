//WAP to increase every student mark by 5 & then print the updated array
#include<stdio.h>
int main()
{
    int max;
    printf("enter no. of students : ");
    scanf("%d",&max);

    int marks[max];
    int i;
    for(i=0;i<max;i++)
    {
        if(i==0)
        {
            printf("enter 1st student marks : ");
        }
        else if(i==1)
        {
            printf("enter 2nd student marks : ");
        }
        else if(i==2)
        {
            printf("enter 3rd student marks : ");
        }
        else if(i>2)
        {
            printf("enter %dth student marks : ",i+1);
        }
        
        scanf("%d",&marks[i]);
    }
    int j;
    for(j=0;j<max;j++)
    {
        marks[j]=(marks[j]+5);
    }

    for(int k=0;k<max;k++)
    {
        if(k==0)
        {
            printf("1st student updated marks is : %d\n",marks[k]);
        }
        else if(k==1)
        {
            printf("2nd student updated marks is : %d\n",marks[k]);
        }
        else if(k==2)
        {
            printf("3rd student updated marks is : %d\n",marks[k]);
        }
        else if(k>2)
        {
            printf("%dth student updated marks is : %d\n",k+1,marks[k]);
        }
    }
    

    return 0;
}