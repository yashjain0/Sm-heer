#include<iostream>
using namespace std;

class Array{
private:
	int *A;
	int size;
	int length;	
public:
	Array(int size){
		this->size=size;
		A=new int[size];
	}

	void create(){
		cout<<"Enter total number"<<flush;
		cin >> length;
		for(int i=0;i<length;i++){
			cout<<i<<"="<<flush;
			cin>>A[i];
		}
	}
	void display(){
		for(int i=0;i<length;i++){
			cout<<A[i]<<" ";
		}
	}
	void Append(struct Array *arr,int x)
 {
 if(arr->length<arr->size)
 arr->A[arr->length++]=x;
 }
 void Insert(struct Array *arr,int index,int x)
 {
 int i;

 if(index>=0 && index <=arr->length)
 {
 for(i=arr->length;i>index;i--)
 arr->A[i]=arr->A[i-1];
 arr->A[index]=x;
 arr->length++;
 }
	 
int Delete(struct Array *arr,int index)
{
 int x=0;
 int i;
 if(index>=0 && index<arr->length)
 {
 x=arr->A[index];
 for(i=index;i<arr->length-1;i++)
 arr->A[i]=arr->A[i+1];
 arr->length--;
 return x;
 }
 return 0;
}

}


int main()
{
	Array arr(10);
	arr.create();
	arr.display();

	return 0;
}
