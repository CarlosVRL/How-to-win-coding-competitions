/**
 * Create a Team!
 */
#include <fstream>
#include <iostream>

using namespace std;

/**
 * File Management
 */
ifstream fin("input.txt");
ofstream fout("output.txt");

/**
 * Constants
 */
const int COL_SIZE = 3;
const int ROW_SIZE = 3;

/**
 * Prototypes
 */
void populateRoles(int matrix[ROW_SIZE][COL_SIZE]);
void printRoles(int matrix[ROW_SIZE][COL_SIZE]);

#define fout cout

/**
 * Main
 */
int main(void)
{
    // Read the input file into matrix
    int roles[ROW_SIZE][COL_SIZE];
    populateRoles(roles);
    
    // Debug Print
    printRoles(roles);
    
    return EXIT_SUCCESS;
}

/**
 * Functions
 */
void populateRoles(int matrix[ROW_SIZE][COL_SIZE])
{   
    for (int i = 0; i < ROW_SIZE; ++i)
    {
        for (int j = 0; j < COL_SIZE; ++j)
        {
            fin >> matrix[i][j];
        }
    }
    return;
}

void printRoles(int matrix[ROW_SIZE][COL_SIZE])
{   
    for (int i = 0; i < ROW_SIZE; ++i)
    {
        for (int j = 0; j < COL_SIZE; ++j)
        {
            cout << "value: " << matrix[i][j] << endl;
        }
    }
    return;
}
