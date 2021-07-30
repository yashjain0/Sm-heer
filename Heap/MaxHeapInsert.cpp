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

void create()
{
	int A[8]={12,30,57,21,34,54,3,52};
	int i=0,n=8;
	for(i=2;i<n;i++)
	{
		insert(A,i);
	}
}
void delete(int A[], int n)
{
	int x,i,j;
	x=A[n];
	A[1]=A[n];
	i=1; j=2*i;
	while(j<n-1)
	{
		if(A[j]<A[j+1])
		{
			j=j+1;
		}
		if(A[j]>A[i])
		{
			swap(A[i],A[j]);
			i=j;
			j=2*j;
		}
		else
			break;
	}

}
