/****************************************************
Program:	Graph Search
Author:		John Griner

Description:
					This program implements the depth first search and breadth first
						algorithms in C++.

	Input:	Through the standard input, the user inputs the adjacency
						matrix, number of nodes, and the start node.

Output:
			The program will compute the DFS and BFS traversals and display
						the sequence of each algorithm.
****************************************************/
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// const variable to keep size of input matrix
const int SIZE = 9;

// Function Prototypes
void depth(int[SIZE][SIZE], int, int, bool[SIZE]);
void breadth (int[SIZE][SIZE], int);

// begin main function
int main(){

	// number of nodes in the graph
	int numberOfNodes = 0;
	// adjacency matrix to strore the graph
	int matrix[SIZE][SIZE];
	// variable for node to start the search algorithms
	int startNode = 0;
	// variable for input limit
	int limit = 0;
	// variable for number of elements
	int number = 0;
	// stores input into matrix
	int element = 0;
	// variable for rows
	int matrix_row = 0;
	// variable for columns
	int matrix_column = 0;
	// column and row limits
	int column = 0;
	int row = 0;
	// array to check for visits
	bool visit[10] = {0};

	cout << endl;
	// code for user input. Can use input redirection. Ex. ./main < input.txt
	cout << "Please enter the number of nodes: ";
	cin >> numberOfNodes;
	limit = numberOfNodes*numberOfNodes;
	cout << "\nPlease enter the adjacency matrix: " << endl;
	cout << endl;
	column = row = numberOfNodes;				// length * width

	// code to move input to matrix

	// while still reading elements
	while(number < limit){
		// read in element
		cin >> element;
		// if row is not full
		if(matrix_column < column){
				// insert element
			matrix[matrix_row][matrix_column] = element;
			// increment column
			matrix_column++;
		}
		// else the row is full
		else{
			// increment row and reset column counter
			matrix_row++;
			matrix_column = 0;
			// insert element and increment column counter
			matrix[matrix_row][matrix_column] = element;
			matrix_column++;
		}
		// increment number of elements
		number++;
	}

	// Printing the matrix
	cout << "Printing matrix:\n";
	for(int i = 0; i < numberOfNodes; i++){
		for(int j = 0; j < numberOfNodes; j++){
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	// Ask user for start node, or use input redirection file
	cout << "What is the start node? " << endl;
	cin >> startNode;
	cout << endl;

	cout << "Depth First Search Traversal: ";
	// call for depth function
	depth(matrix, startNode, numberOfNodes, visit);

	cout << "\n\nBreadth First Search Traversal: ";
	// call for breadth function
	breadth(matrix, startNode-1);

	cout << endl << endl;

	// return from the main function
	return 0;
}


/************************************************************
Function Name: depth
Description:	This function recursively moves through a 2D Matrix
							performing a Depth First Search on it. It requires the
							matrix, start node, number of nodes, and a way to remember
							if a node has already been visited. Because arrays begin
							at 0 and humans like to start at 1, there are many instances
							of "variable-1" or "variable+1"
************************************************************/
void depth(int matrix[9][9], int startNode, int numberOfNodes, bool visit[9]){

	// visit the start node
	visit[startNode-1] = 1;
	// print the start node
	cout << startNode << ", ";

	// find out which nodes are adjacent
	for(int b = 0; b < numberOfNodes; b++){
		// if node is adjacent
		if(matrix[startNode-1][b] == 1)
			// .. and if node hasn't been visited
			if(visit[b] == 0)
				// perform depth function on that node
				depth(matrix, b+1, 9, visit);
	}
	// return from depth() function
	return;
}

/***********************************

FOR REFERENCE PURPOSES ONLY!

The depth function can also be implemented without recursion. This is performed by
	using a stack to hold the visited nodes. As you can see, this is not the optimal
	way to implement this function.
************************************

	bool visit[10] = {0};
	int alreadyBeenThere = 0;
	int skip = 0;

	stack<int> depthStack;

	depthStack.push(startNode);
	cout << startNode;
	visit[startNode-1] = 1;

	int b = 0;

	while(!depthStack.empty()){

	startNode = depthStack.top();

		if(matrix[startNode - 1][b] == 1){
			if(visit[b] == 0){
				depthStack.push(b+1);
				cout << ", " << b+1;
				visit[b] = 1;
				startNode = b+1;
				b = 0;
				alreadyBeenThere = 0;
				skip = 0;
			}
			else if(visit[b] == 1){
				alreadyBeenThere++;
				b++;
			}
		}
		else{
			skip++;
			b++;
		}

		if(skip + alreadyBeenThere == numberOfNodes){
			depthStack.pop();
			b = 0;
			alreadyBeenThere = 0;
			skip = 0;
		}
	}

	return;
}
************************/

/************************************************************
Function Name: breadth
Description:	This function uses a queue to perform a Breadth First Search
 							of a 2D array. Because arrays begin at 0 and humans
							like to start at 1, there are many instances of
							"variable-1" or "variable+1".
************************************************************/
void breadth (int matrix[SIZE][SIZE], int startNode){

	// initialize the visit array
	bool visit[SIZE] = {0};

	// create a queue
	queue<int> breadthQueue;

	// print the start node
	cout << startNode+1;
	// push the start node onto queue
	breadthQueue.push(startNode);
	// mark node as visited
	visit[startNode] = 1;

	// begin do-while loop
	do{
		for(int a = 0; a < SIZE; a++)
			// if the node is adjacent to start node
			if(matrix[startNode][a] == 1){
				// if node hasn't been visited
				if(visit[a] == 0){
					// move node onto the queue
					breadthQueue.push(a);
					// print node
					cout << ", " << a+1;
					// mark as visited
					visit[a] = 1;
				}
			}

			// remove front node of queue
			breadthQueue.pop();
			// start node is new start node
			startNode = breadthQueue.front();
	}
	// parameter to continue do-while loop
	while(!breadthQueue.empty());

	// return from breadth() function
	return;
}
