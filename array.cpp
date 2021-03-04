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

}


int main()
{
	Array arr(10);
	arr.create();
	arr.display();

	return 0;
}