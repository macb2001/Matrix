//Mackenzie Broughton
//Matrix Class
//March 6, 2020
//Purpose: create a Matrix class that can manipulate matrices with various functions, which are implemented through overloaded operators.

#include <iostream>
#include <cassert>
#include <iomanip>
#include "matrixPro2.h"
using namespace std;

//this is the constructor. The default parameter of the constructor is 2 in the header file. Creates the matrix of the inputted dimension and fills the spots with 0s.
CMatrixPro2::CMatrixPro2(int d){
   dim = d;
   arr2D = allocateMatrixMemory(d);
}

//this returns the dimension of the current matrix.
int CMatrixPro2::getDimension(){
   return dim;
}

//this returns the value at the inputted position.
int CMatrixPro2::getElementAt(int i, int j){
   return arr2D[i-1][j-1];
}

//this allows the user to input values for all of the positions of the matrix by overloading the insert operator >>
istream& operator>>(istream& is, CMatrixPro2 &M){

   for (int i = 0; i < M.dim; i++){
	   for (int j = 0; j < M.dim; j++){
	      cout << "Enter the value for (" << (i+1) << "," << (j+1) << "): ";
	      is >> M.arr2D[i][j];
	   }
	}
  return is;
}

//this prints the current matrix by overloading the output operator <<
ostream& operator<<(ostream& os, CMatrixPro2 &M){

   for (int i = 0; i < M.dim; i++){

      for (int j = 0; j < M.dim; j++){
	      os << left << setw(10) <<  M.getElementAt(i+1, j+1);
      }

      os << endl;

   }

   os << endl;
   return os;
}

//this resizes the matrix. If the matrix enlarges, the new positions are filled with 0s while the previous values remain in their previous positions. If the matrix shrinks, the values in the positions still valid in the new matrix remain in their positions while the others are deleted.
void CMatrixPro2::resizeMatrix(int newSize){
   assert(newSize >= 1);

   int oldSize = dim;

   int **temp = arr2D;
   arr2D = new int *[newSize];

   allocateMatrixMemory(newSize);

   if (newSize > oldSize){
      for (int i = 0; i < oldSize; i++){
         for (int j = 0; j < oldSize; j++){
            arr2D[i][j] = temp[i][j];
		   }
	   }
   }

   else {
      for (int i = 0; i < newSize; i++){
         for (int j = 0; j < newSize; j++){
            arr2D[i][j] = temp[i][j];
	      }
      }
   }

   deallocateMatrixMemory(temp, oldSize);

   dim = newSize;
}

//this deallocates memory (specifically for the resize function, as it properly deallocates the memory of the temp array).
void CMatrixPro2::deallocateMatrixMemory(int** A, int n){
   for (int i = 0; i < n; i++){
      delete [] A[i];
   }

   delete[] A;

   A = nullptr;
}

//this replaces an element at a desired position with an inputted value while returning the value of that position before its replacement.
int CMatrixPro2::replaceElementAt(int i, int j, int newInt){
   assert((i-1 >= 0) && (i-1 < dim) && (j-1 >= 0) && (j-1 < dim));

   int oldElement = getElementAt(i, j);
   arr2D[i-1][j-1] = newInt;
   return oldElement;
}

//this swaps the values of two desired positions.
void CMatrixPro2::swapElementsAt(int i1, int j1, int i2, int j2){
   assert((i1 - 1 >= 0) && (i1 - 1 <= dim) && (j1 - 1 >= 0) && (j1 - 1 <= dim) && (i2 - 1 >= 0) && (i2 - 1 <= dim) && (j2 - 1 >= 0) && (j2 <= dim));

   int temp = arr2D[i1-1][j1-1];
   arr2D[i1-1][j1-1] = arr2D[i2-1][j2-1];
   arr2D[i2-1][j2-1] = temp;
}

//this function allocates matrix memory (by default fills all the entries with 0s)
int** CMatrixPro2::allocateMatrixMemory(int n){
   assert(n >= 1);
   dim = n;
   arr2D = new int *[dim];

   for (int i = 0; i < dim; i++){
      arr2D[i] = new int[dim];

      for (int j = 0; j < dim; j++){
         arr2D[i][j] = 0;
      }
   }
   return arr2D;
}

//this is the destructor which calls the deallocate memory function
CMatrixPro2::~CMatrixPro2(){
   deallocateMatrixMemory(arr2D, dim);
}

//this funtion makes the matrix an identity (1s along the diagonal and 0s everywhere else)
void CMatrixPro2::makeIdentity(void){

   for (int i = 0; i < dim; i++){
      for(int j = 0; j < dim; j++){
         arr2D[i][j] = 0;
      }
   }

   for (int i = 0; i < dim; i++){
      arr2D[i][i] = 1;
   }
}

//this function determines if a matrix is diagonal (a number along the diagonal and 0s everywhere else)
bool CMatrixPro2::isDiagonal(void){
   for (int i = 0; i < dim; i++){
      for (int j = 0; j < dim; j++){
         if ((arr2D[i][j] && i != j) != 0){
	         return false;
	      }
      }
   }
   return true;
}

//this function determines if a matrix is an identity
bool CMatrixPro2::isIdentity(){
   for (int i = 0; i < dim; i++){
      if (arr2D[i][i] != 1){
	      return false;
      }

      for (int j = 0; j < dim; j++){
	      if (i != j){
	         if (arr2D[i][j] != 0){
	            return false;
	         }
	      }
      }
   }
   return true;
}

//this function determines if a matrix is larger than another by overloading the greater than operator >
bool CMatrixPro2::operator >(const CMatrixPro2 &M){
     assert(dim = M.dim);
     for (int i = 0; i < M.dim; i++){
        for (int j = 0; j < M.dim; j++){
           if (arr2D[i][j] > M.arr2D[i][j]){
              return true;
            }
	      }
     }
     return false;
}

//this function determines if a matrix is smaller than another by overloading the lesser than operator <
bool CMatrixPro2::operator <(const CMatrixPro2 &M){
   assert(dim = M.dim);
   for (int i = 0; i < M.dim; i++){
      for (int j = 0; j < M.dim; j++){
	      if (arr2D[i][j] < M.arr2D[i][j]){
	         return true;
	      }
      }
   }
   return false;
}

//this function determines if a matrix is equal to another by overloading the == operator
bool CMatrixPro2::operator ==(const CMatrixPro2 &M){
   assert(dim = M.dim);
   for (int i = 0; i < M.dim; i++){
      for (int j = 0; j < M.dim; j++){
	      if (M.arr2D[i][j] == arr2D[i][j]){
	         return true;
	      }
      }
   }
   return false;
}

//this functions adds two matrices together
CMatrixPro2 CMatrixPro2::operator +(const CMatrixPro2 &M){
   assert(dim = M.dim);
   CMatrixPro2 temp(dim);

   for (int i = 0; i < dim; i++){
      for (int j = 0; j < dim; j++){
        temp.arr2D[i][j] = arr2D[i][j] + M.arr2D[i][j];
      }
   }

   return temp;
}

//this functions adds an integer to a matrix(the integer is added to each of the matrix's values) by overloading the + operator
CMatrixPro2 CMatrixPro2::operator +(int x){
   CMatrixPro2 temp(dim);
   for (int i = 0; i < dim; i++){
      for (int j = 0; j < dim; j++){
	      temp.arr2D[i][j] = arr2D[i][j] + x;
      }
   }
   return temp;
}

//this functions subtracts a matrix from another
CMatrixPro2 CMatrixPro2::operator -(const CMatrixPro2 &M){
   assert(dim = M.dim);
   CMatrixPro2 temp(dim);
   for (int i = 0; i < dim; i++){
      for (int j = 0; j < dim; j++){
	      temp.arr2D[i][j] = arr2D[i][j] - M.arr2D[i][j];
      }
   }
   return temp;
}

//this function subtracts an integer from a matrix (the integer is subtracted from each of the matrix's values) by overloading the - operator
CMatrixPro2 CMatrixPro2::operator -(int x){
   CMatrixPro2 temp(dim);
   for (int i = 0; i < dim; i++){
      for (int j = 0; j < dim; j++){
	      temp.arr2D[i][j] = arr2D[i][j] - x;
      }
   }
   return temp;
}

//this function multiplies a matrix to another
CMatrixPro2 CMatrixPro2::operator *(const CMatrixPro2 &M){
   assert(dim = M.dim);
   CMatrixPro2 temp(dim);
   for (int i = 0; i < dim; i++){
      for (int j = 0; j < dim; j++){
	      for (int k = 0; k < dim; k++){
	         temp.arr2D[i][j] += (arr2D[i][k] * M.arr2D[k][j]);
	 }
      }
   }
   return temp;
}

//this function multiplies an integer to a matrix (the integer is multiplied to each of the matrix's values) by overloading the * operator
CMatrixPro2 CMatrixPro2::operator *(int x){
   CMatrixPro2 temp(dim);
   for (int i = 0; i < dim; i++){
      for (int j = 0; j < dim; j++){
	      temp.arr2D[i][j] = arr2D[i][j] * x;
      }
   }
   return temp;
}

//this function overloads the += operator and sets the left operand equal to its sum with the left operand(another matrix).
CMatrixPro2 &CMatrixPro2::operator +=(const CMatrixPro2 &M){
   assert(dim = M.dim);
   for (int i = 0; i < dim; i++){
      for (int j = 0; j < dim; j++){
        this -> arr2D[i][j] = arr2D[i][j] + M.arr2D[i][j];
      }
   }

   return *this;
}

//this function overloads the += operator and sets the left operand equal to its sum with the left operand(an integer).
CMatrixPro2 &CMatrixPro2::operator +=(int x){
   for (int i = 0; i < dim; i++){
      for (int j = 0; j < dim; j++){
	      this -> arr2D[i][j] = arr2D[i][j] + x;
      }
   }
   return *this;
}

//this function overloads the -= operator and sets the left operand equal to its difference  with the left operand(another matrix).
CMatrixPro2 &CMatrixPro2::operator -=(const CMatrixPro2 &M){
   assert(dim = M.dim);
   for (int i = 0; i < dim; i++){
      for (int j = 0; j < dim; j++){
	      this -> arr2D[i][j] = arr2D[i][j] - M.arr2D[i][j];
      }
   }
   return *this;
}

//this function overloads the -= operator and sets the left operand equal to its product with the left operand(an integer).
CMatrixPro2 &CMatrixPro2::operator -=(int x){
   for (int i = 0; i < dim; i++){
      for (int j = 0; j < dim; j++){
	      this -> arr2D[i][j] = arr2D[i][j] - x;
      }
   }
   return *this;
}

//this function overloads the *= operator and sets the left operand equal to its product with the left operand(another matrix).
CMatrixPro2 &CMatrixPro2::operator *=(const CMatrixPro2 &M){
   assert(dim = M.dim);
   CMatrixPro2 temp(dim);
   for (int i = 0; i < dim; i++){
      for (int j = 0; j < dim; j++){
	      for (int k = 0; k < dim; k++){
	         temp.arr2D[i][j] += (arr2D[i][k] * M.arr2D[k][j]);
	      }
      }
   }
   *this = temp;
   return *this;
}

//this function overloads the *= operator and sets the left operand equal to its product with the left operand(another integer).
CMatrixPro2 &CMatrixPro2::operator *=(int x){
   for (int i = 0; i < dim; i++){
      for (int j = 0; j < dim; j++){
	      this -> arr2D[i][j] = arr2D[i][j] * x;
      }
   }
   return *this;
}

//this is the copy matrix function which overloads the assignment operator =
CMatrixPro2& CMatrixPro2::operator =(const CMatrixPro2 &M){
   if (this != &M){
      if (M.dim != dim){
	      this -> resizeMatrix(M.dim);
      }

      deallocateMatrixMemory(arr2D, dim);
      arr2D = allocateMatrixMemory(M.dim);

      for (int i = 0; i < M.dim; i++){
         for (int j = 0; j < M.dim; j++){
            arr2D[i][j] = M.arr2D[i][j];
         }
      }
      dim = M.dim;
      }
   return *this;
}
