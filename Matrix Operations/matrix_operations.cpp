/****************************************************
Program:	Matrix Operations
Author:		John Griner

Description:
					This program tests a student's understanding
						with matrices. Matrix information is read
						using standard I/O, and the program
						processes the information

Input:		Matrix dimensions and elements are read from the
						standard I/O.

Output:
			a. Matrix A is transposed and printed
			b. The result of Matrix A * Matrix B
			c. Whether or not Matrix B is symmetric
			d. The result of Matrix A + Matrix B
*****************************************************/
#include <iostream>

using namespace std;

// function prototypes
void printMatrix(int [][9], int, int);
void transposeMatrix(int [][9], int, int);
void multiply(int [][9], int [][9], int, int, int, int);
void symmetry(int [][9], int, int);
void add(int [][9], int [][9], int, int, int, int);

// begin main function
int main(){

	// used to store row dimensions of matricies
	int rowA = 0;
	int rowB = 0;
	// used to store column dimensions
	int columnA = 0;
	int columnB = 0;
	// stores individual matrix element
	int element = 0;
	// stores number of elements
	int number = 0;
	// increments for rows
	int matrix_row = 0;
	// increments for columns
	int matrix_column = 0;
	// maximum elements for given dimensions
	int limit = 0;
	// matrix A
	int matrixA[9][9];
	// matrix B
	int matrixB[9][9];

	//	Get input from the user. This can be achieved through input redirection.
	//		Ex: ./main < inputFile.txt
	cout << endl;
	cout << "Please enter the dimensions of Matrix A (rows, columns): " << endl;
	cin >> rowA >> columnA;
	// limit is calculated for matrix A
	limit = rowA*columnA;

	cout << "Please enter the elements of the matrix, in order from left ";
	cout << "to right, top to bottom:\n";

	// while still reading elements
	while(number < limit){
		cin >> element;
		// if row is not full
		if(matrix_column < columnA){
			// insert element and increment column
			matrixA[matrix_row][matrix_column] = element;
			matrix_column++;
		}
		// else row is full
		else{
			// increment row and update the column
			matrix_row++;
			matrix_column = 0;
			// insert element and increment column
			matrixA[matrix_row][matrix_column] = element;
			matrix_column++;
		}
		// increment number of elements
		number++;
	}	// finished reading in values for first matrix

	cout << endl;
	// reset variables for matrix B
	matrix_row = matrix_column = 0;
	// reset variable for matrix B
	number = 0;

	//	Get input from the user. If using input redirection, this will be
	// 		automatically handled.
	cout << "Please enter the dimensions of Matrix B (rows, columns): " << endl;
	cin >> rowB >> columnB;
	// limit is calculated for matrix B
	limit = rowB * columnB;

	cout << "Please enter the elements of the matrix, in order from left ";
	cout << "to right, top to bottom\n";


	// while still reading elements
	while(number < limit){
		cin >> element;
		// if row is not full
		if(matrix_column < columnB){
			// insert element and increment column
			matrixB[matrix_row][matrix_column] = element;
			matrix_column++;
		}
		// else row is full
		else{
			// increment row and update the column
			matrix_row++;
			matrix_column = 0;
			// insert element and increment column
			matrixB[matrix_row][matrix_column] = element;
			matrix_column++;
		}
		// increment number of elements
		number++;
	}	// finished reading in values for first matrix

	cout << endl << endl;

	// Function calls to perform on the two matrices just created.
	transposeMatrix(matrixA, rowA, columnA);
	cout << endl;
	multiply(matrixA, matrixB, rowA, columnA, rowB, columnB);
	cout << endl;
	symmetry(matrixB, rowB, columnB);
	cout << endl;
	add(matrixA, matrixB, rowA, columnA, rowB, columnB);

	// return from main function
	return 0;
}

/************************************************************
Function Name: transposeMatrix
Description: This function takes a matrix and its dimensions
				and then prints out the transpose of that matrix
************************************************************/
void transposeMatrix(	int matrix[][9],
											int row,
											int column){

	cout << "The transpose of Matrix A is : " << endl;

	// iterate through columns
	for(int i = 0; i < column; i++){
		// iterate through rows
		for(int j = 0; j < row; j++){
			// print out element
			cout << matrix[j][i] << " ";
		}
		cout << endl;
	}
	return;
}//	end transposeMatrix() function


/************************************************************
Function Name: multiply
Description: This function performs the multiplication operation
				on two matrices. The function takes two matrices
				and their dimensions and creates an answer matrix.
				The answer matrix is printed.
************************************************************/
void multiply(	int matrixA[][9],
								int matrixB[][9],
								int rowA,
								int columnA,
								int rowB,
								int columnB){

	cout << "Matrix A * Matrix B: " << endl;

	// the following check to see if the number of columns in the first
	//	matrix is equal to the number of rows in the second matrix, which is
	// 	required for matrix multiplication

	if(columnA != rowB){
		cout << "Matrices can not be multiplied" << endl;
		return;
	}

	// store element in answer matrix
	int result;
	// used for answer matrix
	int matrixAnswer[9][9];

	// iterate through rows
	for (int i=0;i<rowA;i++){
		// sort through columns
		for(int j=0;j<columnB;j++){

			// initialized result
			result = 0;

			// add the multiplied value of row and column elements
    	for(int k=0; k < rowB; k++){
							// adds together the product of certain elements
            	result += matrixA[i][k]*matrixB[k][j];
      }
			// sets result to answerMatrix element
			matrixAnswer[i][j] = result;
		}
  }

	// print out the solution

	// iterate through rows
	for(int i = 0; i < rowB-1; i++){
		// iterate through columns
		for(int j = 0; j < columnB; j++){
			// print out element
			cout << matrixAnswer[i][j] << " ";
		}
		cout << endl;
	}
	return;
}// end multiply() definition


/************************************************************
Function Name: symmetry
Description: This function tests whether or not a matrix is
				symmetric.
************************************************************/
void symmetry(	int matrixB[][9],
								int rowB,
								int columnB){

		// iterate through rows
    for(int i = 0; i < rowB; i++){
			// iterate through columns
    	for(int j = 0; j < columnB; j++){
				// checks symmetry per element
    		if(matrixB[i][j] != matrixB[j][i]){
    			cout << "Matrix B is not symmetric." << endl;
    			return;
    		}
    	}
		}

		// if this point is reached, the matrix is symmetric
   	cout << "Matrix B is symmetric. ";		// if matrix is symmetric
   	cout << endl << endl;
	return;
}	// end symmetry() definition


/************************************************************
Function Name: add
Description: This function performs the addision operation
				on two matrices. The function takes two matrices
				and their dimensions and creates an answer matrix.
				The answer matrix is printed.
************************************************************/
void add(	int matrixA[][9],
					int matrixB[][9],
					int rowA,
					int columnA,
					int rowB,
					int columnB){

	// Only if we received good data, perform the appropriate operations
	if(rowA == rowB && columnA == columnB){
		cout << "Matrix A + Matrix B = : " << endl;

		// Stores answer in matrix
		int matrixAnswer[9][9];

		// iterate through rows
	  for(int i = 0; i < rowA; i++){
			// iterate through columns
    	for(int j = 0; j < columnA; j++){
				// add the elements from both matricies
    		matrixAnswer[i][j] = matrixA[i][j] + matrixB[i][j];
			}
		}

		// print out the solution

		// iterate through rows
    for(int i = 0; i < rowB; i++){
			// iterate through columns
    	for(int j = 0; j < columnB; j++){
				// print out element
				cout << matrixAnswer[i][j] << " ";
			}
			cout << endl;
		}
	}

	// else... good data was not received as parameters
	else{
		cout << "Matrix A and Matrix B addition is not possible. " << endl << endl;
	}
	return;

}	// end add() definition
