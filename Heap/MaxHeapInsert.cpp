void insert(int A[], int n)
{
	int temp,i=n;
	temp=A[n];
	while(i>1 && temp>A[i/2])
	{

		A[i]=A[i/2];
		i=i/2;
	}
	A[i]=temp;
}
