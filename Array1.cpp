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

 int main()
 {
  	struct Array arr={{2,3,4,5,6},10,5};
  	Display(arr);
  	return 0;

 }
