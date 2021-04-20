#include<stdio.h>
struct Array
{
int A[10];
int size;
int length;
};
void Display(struct Array arr)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d",arr.A[i]);
}
int Get(struct Array arr, int index)
 {
 	if(index>=0 && index<arr.length)
 	return arr.A[index];
 	return -1;
 }

void Set(struct Array *arr, int index,int x)
{
	if(index>=0 && index <arr->length)
	arr->A[index]=x;
}
int Max(struct Array arr)
{
 int max=arr.A[0];
 int i;
 for(i=1;i<arr.length;i++)
 {
 if(arr.A[i]>max)
 max=arr.A[i];
 }
 return max;
}

int Sum(struct Array arr)
{
 int s=0;
 int i;
 for(i=0;i<arr.length;i++)
 s+=arr.A[i];
 return s;
}

float Avg(struct Array arr)
{
 return (float)Sum(arr)/arr.length;
}

struct Array()
{
	int A[10];
	int size;
	int length;
}

void Areverse(struct Array *arr)
{	
	int i,j;
	int n=sizeof(A);
	int *B;
	B=(int *)malloc(arr->length*sizeof(int));

	/*reverse copying in B*/
	for(i=0,j=arr->length-1;i>=0;i--,j++)
	{
		B[i]=arr->A[j];
	}

	/*copying back the reversed in A*/
	for(i=0,;i<arr->length-1;i++)
	{
		arr->A[i]=B[i];
	}
}

void Swreverse( struct Array *arr)
{
	int i,j;

	/*swapping*/
	for(i=0,j=arr->length-1;i<j;i--,j++)
	{
		temp=arr->A[j];
		arr->A[j]=arr->A[i];
		arr->A[i]=arr->A[j];
	}
}

void negleft(struct Array *arr)
{
	int i=0;
	int j=arr->length-1;
	while(i<j)
	{
		while(A[i]<0)
			i++;
		while(A[j]>=0)
			j++;
		if(i<j)
			{
				int temp=A[j];
				A[j]=A[i];
				A[i]=temp;
			}
	}
}

int isSorted(struct Array arr)
{
	int i;
	for(i=0;i<arr.length-1;i++)
	{
		if(arr.A[i+1]<arr.A[i])
			return -1;
	}
	return 1;
}

void Merge(struct Array arr1, struct Array arr2)
{
	int i=0,j=0,k=0;
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
	while(i<arr1.length && j<arr2.length)
	{
		if(arr1.A[i]<arr2.A[j])
			arr3->A[k++]=arr1.A[i++];
		else
			arr3->A[k++]=arr2.A[j++];
	}
	for(;i<arr1.length;i++)
	{
		arr3->A[k++]=arr1.A[i]
	}
	for(;j<arr2.length;j++)
	{
		arr3->A[k++]=arr2.A[j]
	}

	arr3->length=arr2.length+arr1.length;
	arr3->size=10;
}

 int main()
 {
  	struct Array arr={{2,3,4,5,6},10,5};
  	Display(arr);
  	return 0;

 }
