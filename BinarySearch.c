#include<stdio.h>
int binarysearch(int a[],int n,int x)
{	
	int low,high,mid;
	low=0;
	high=n-1;
	mid=(low+high)/2;
	
	while(low<=high)
	{
		mid=(low+high)/2;

		if(x == a[mid])
			return 1;
		if(x < a[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	return 0;
}

void bubblesort(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}

int main()
{
	int a[20],n,i,x;
	printf("Enter nos of elements in array\n");
	scanf("%d",&n);
	
	printf("Enter elements in array\n");
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	
	printf("Enter element to search\n");
	scanf("%d",&x);
	bubblesort(a,n);
	
	printf("Elements in array\n");
	for(i  =0; i < n; i++)
		printf("%d ",a[i]);
	printf("\n");
	
	if(binarysearch(a,n,x))
		printf("%d is present in array\n",x);
	else
		printf("%d is not present in array\n",x);
		
	return 0;
}
