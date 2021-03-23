//Test for Matrix Class
//Date: March 6, 2020
//Mackenzie Broughton

#include<iostream>
#include"./matrixPro2.h"
#include<fstream>
using namespace std;

int main()
{
   int d; // matrix dimension
   cout << "Making a 2 x 2 matrix A." << endl;
   CMatrixPro2 A; // Establish a 2 x 2 matrix
   d = A.getDimension();
   cout << "Enter elements of a " << d << " x " << d << " matrix A:" << endl;
   cin >> A;      // instead of m1.read(); (get some data from user
   cout << "Matrix A is: " << endl;
   cout << A;
   cout << endl;

   cout << "Making a 2 x 2 matrix B." << endl;
   CMatrixPro2 B;
   d = B.getDimension();
   cout << "Enter elements of a " << d << " x " << d << " matrix B:" << endl;
   cin >> B;      // instead of m1.read(); (get some data from user
   cout << "Matrix B is: " << endl;
   cout << B;
   cout << endl;

   cout << "Making a 2 x 2 matrix C." << endl;
   CMatrixPro2 C;
   d = C.getDimension();
   cout << "Enter elements of a " << d << " x " << d << " matrix C:" << endl;
   cin >> C;      // instead of m1.read(); (get some data from user
   cout << "Matrix C is: " << endl;
   cout << C;
   cout << endl;

   cout << "After CMatrixPro2 A += B, A is: " << endl;
   A += B;
   cout << A;
   cout << endl;

   cout << "After CMatrixPro2 B += 2, B is: " << endl;
   B += 2;
   cout << B;
   cout << endl;

   cout << "After CMatrixPro2 C -= B, C is: " << endl;
   C -= B;
   cout << C;
   cout << endl;

   cout << "After CMatrixPro2 A -= 3, A is: " << endl;
   A -= 3;
   cout << A;
   cout << endl;

   cout << "After CMatrixPro2 C *= B, C is: " << endl;
   C *= B;
   cout << C;
   cout << endl;

   cout << "After CMatrixPro2 A *= 5, A is: " << endl;
   A *= 5;
   cout << A;
   cout << endl;

   cout << "Now making matrices B and C equal to A." << endl;
   B = A;
   C = A;
   
   cout << "Matrix B is now:" << endl;
   cout << B;

   cout << "Matrix C is now:" << endl;
   cout << C;

   return 0;
}
