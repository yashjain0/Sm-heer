#include <iostream>

#include <iomanip>

class DiagonalMatrix{

private:

int n; //Dimension of Diagonal Matrix

int *pointerToArray; //For dynamically creating array

public:

DiagonalMatrix();

DiagonalMatrix( int n );

void setMatrixElement( int rowNumber, int columnNumber, int elementToSet );

int getMatrixElement( int rowNumber, int columnNumber );

void displayDiagonalMatrix();


//included this new code

friend std::ostream & operator<<(std::ostream &os,DiagonalMatrix &d);


~DiagonalMatrix();

};



//included this new code

std::ostream & operator<<(std::ostream &os,DiagonalMatrix &d)

{

for( int i = 1; i <= d.n; i++ ){

for( int j = 1; j <= d.n; j++ ){

if( i == j ){

std::cout << d.pointerToArray[i-1] << std::setw(2);

}

else{

std::cout << "0" << std::setw(2);

}

}

std::cout << std::endl;

}

return os;

}
//ob1 + ob2 ,To make this statement compile, we must overload ‘+’ in class of ‘ob1’ or make ‘+’ a global function.
//1) cout is an object of ostream class and cin is an object istream class
//2) These operators must be overloaded as a global function. And if we want to allow them to access private data members of class, we must make them friend.
