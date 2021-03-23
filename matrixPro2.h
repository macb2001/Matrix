//Mackenzie Broughton
//Matrix Class
//March 6, 2020
//Purpose: create a Matrix class that can manipulate matrices with various functions, which are implemented through overloaded operators.

#ifndef MATRIXPRO2_H
#define MATRIXPRO2_H
#include <iostream>
using namespace std;

class CMatrixPro2{
  public:
   CMatrixPro2(int n = 2);
   CMatrixPro2(const CMatrixPro2 &M);
   ~CMatrixPro2();
   int getDimension();
   int getElementAt(int i, int j);
   int replaceElementAt(int i, int j, int newInt);
   void swapElementsAt(int i1, int j1, int i2, int i3);
   void resizeMatrix(int newSize);
   void makeIdentity();
   bool isDiagonal(void);
   bool isIdentity(void);
   bool operator >(const CMatrixPro2 &M);
   bool operator <(const CMatrixPro2 &M);
   bool operator ==(const CMatrixPro2 &M);
   CMatrixPro2 operator +(const CMatrixPro2 &M);
   CMatrixPro2 operator +(int x);
   CMatrixPro2 operator -(const CMatrixPro2 &M);
   CMatrixPro2 operator -(int x);
   CMatrixPro2 operator *(const CMatrixPro2 &M);
   CMatrixPro2 operator *(int x);
   CMatrixPro2 &operator =(const CMatrixPro2 &M);
   CMatrixPro2 &operator +=(const CMatrixPro2 &M);
   CMatrixPro2 &operator +=(int x);
   CMatrixPro2 &operator -=(const CMatrixPro2 &M);
   CMatrixPro2 &operator -=(int x);
   CMatrixPro2 &operator *=(const CMatrixPro2 &M);
   CMatrixPro2 &operator *=(int x);
   friend istream& operator>>(istream& is, CMatrixPro2 &M);
   friend ostream& operator<<(ostream& os, CMatrixPro2 &M);

  private:
   int **arr2D;
   int dim;
   void deallocateMatrixMemory(int** A, int n);
   int **allocateMatrixMemory(int n);
};

#endif
