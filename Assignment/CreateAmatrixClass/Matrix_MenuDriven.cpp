/*
8. Create a Matrix class. Write a menu-driven program to perform following Matrix
operations (exceptions should be thrown by the functions if matrices passed to them are
incompatible and handled by the main() function):
a. Sum
b. Product
c. Transpose
*/

#include <iostream>
using namespace std;

class Matrix {
    int MatrixA[10][10],MatrixB[10][10],MatrixC[10][10];
    int n;
public:

   void CreateMatrix(){

                //for elements input /Internal creation
                cout << "Enter/Decide  your Matrix size:";
                cin >>n;

                //  Add exception check here
                if(n > 10)
                {
                    throw "Matrix size exceeds limit";
                }

                cout << "Enter elements of matrix:\n";
                for(int i=0;i<n;i++) {
                    for(int j=0;j<n;j++) {
                        cin >> MatrixA[i][j];
                    }
                }

                cout << "Matrix is:\n";
                for(int i=0;i<n;i++) {
                    for(int j=0;j<n;j++) {
                        cout << MatrixA[i][j] << " ";
                    }
                    cout << endl;
                }

            }

    //For  Additon .
    void MatrixSum(){

                //for elements input /Internal creation
                cout << "Enter  your  Matrix size:";
                cin >>n;

                //  Add exception check here
                if(n > 10)
                {
                    throw "Matrix size exceeds limit";
                }

                cout << "Enter elements of matrixA:\n";
                for(int i=0;i<n;i++) {
                    for(int j=0;j<n;j++) {
                        cin >> MatrixA[i][j];
                    }
                }
                //For second Matrix.
                

                cout << "Enter elements of matrixB:\n";
                for(int i=0;i<n;i++) {
                    for(int j=0;j<n;j++) {
                        cin >> MatrixB[i][j];
                    }
                }

                //Adding two matrices
                
                for(int i=0;i<n;i++) {
                    for(int j=0;j<n;j++) {
                        MatrixC[i][j] =  MatrixA[i][j]+MatrixB[i][j];
                    }
                }
                //Sum of Matrices /Output
                cout << "Sum Of two Matrices:\n";
                for(int i=0;i<n;i++) {
                    for(int j=0;j<n;j++) {
                        cout << MatrixC[i][j] << " ";
                    }
                    cout << endl;
                }

            }
    // for Multiplication
    void MatrixMultiply(){

                //for elements input /Internal creation
                cout << "Enter  your  Matrix size:";
                            cin >>n;
             //  Add exception check here
                if(n > 10)
                {
                    throw "Matrix size exceeds limit";
                }
                cout << "Enter elements of matrixA:\n";
                for(int i=0;i<n;i++) {
                    for(int j=0;j<n;j++) {
                        cin >> MatrixA[i][j];
                    }
                }
                //For second Matrix.
                

                cout << "Enter elements of matrixB:\n";
                for(int i=0;i<n;i++) {
                    for(int j=0;j<n;j++) {
                        cin >> MatrixB[i][j];
                    }
                }

                //Adding two matrices
                
               for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        MatrixC[i][j] = 0;
                        for(int k=0;k<n;k++)
                        {
                            MatrixC[i][j] += MatrixA[i][k] * MatrixB[k][j];
                        }
                    }
                }

                //Product  of Matrices /Output
                cout << "Product  Of two Matrices:\n";
                for(int i=0;i<n;i++) {
                    for(int j=0;j<n;j++) {
                        cout << MatrixC[i][j] << " ";
                    }
                    cout << endl;
                }

            }
    //Transpose of Matrix 
     void MatrixTranspose(){

                //for elements input /Internal creation
                cout << "Enter/Decide  your Matrix size:";
                cin >>n;
                 //  Add exception check here
                if(n > 10)
                {
                    throw "Matrix size exceeds limit";
                }
                cout << "Enter elements of matrix:\n";
                for(int i=0;i<n;i++) {
                    for(int j=0;j<n;j++) {
                        cin >> MatrixA[i][j];
                    }
                }

                cout << "Matrix is:\n";
                for(int i=0;i<n;i++) {
                    for(int j=0;j<n;j++) {
                        cout << MatrixA[j][i] << " ";
                    }
                    cout << endl;
                }

            }        
};

int main (){
    Matrix M1 ;
    int Choice ;

    cout << "1. Matrix Creation\n";
    cout << "2. Matrix Summation\n";
    cout << "3. Matrix Multiplication\n";
    cout << "4. Matrix Transpose\n";

    cout << "Enter your Choice:"<<endl;
    cin >> Choice;
try
    {
    switch (Choice)
    {
        case 1:
            M1.CreateMatrix();
            break;
        case 2:
            M1.MatrixSum();
            break;
        case 3:
            M1.MatrixMultiply();
            break;
        case 4:
            M1.MatrixTranspose();
            break;
        default:
            cout<<"Invalid choice";
    }
}
catch(const char* msg)
{
    cout << msg;
}

    
   
   
}