/**
 * Create a Team!
 */
#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>

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
double calculateOptimumDistribution(int matrix[ROW_SIZE][COL_SIZE]);
double calculateEfficiency(int a, int b, int c);

/**
 * Main
 */
int main(void)
{
    // Read the input file into matrix
    int roles[ROW_SIZE][COL_SIZE];
    populateRoles(roles);
    
    // Algorithm Strategy: Cycle All Possibilities
    double res = calculateOptimumDistribution(roles);
    
    fout << setprecision(15);
    fout << res << endl;
    
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
            fout << "value: " << matrix[i][j] << endl;
        }
    }
    return;
}

double calculateOptimumDistribution(int matrix[ROW_SIZE][COL_SIZE])
{
    // Containers
    int a, b, c;
    double tmp, opt;
    
    // Primary loop is over the First Row Values (Person A Power)
    for (int i = 0; i < COL_SIZE; ++i)
    {
        a = matrix[0][i];
        
        // Secondary loop is over the 2nd Row Values (Person B Power)
        for (int j = 0; j < COL_SIZE; ++j)
        {
            // skip value taken by A
            if (j == i) continue;
            b = matrix[1][j];
            
            // Final loop is over the 3rd Row Values (Person C Power)
            for (int k = 0; k < COL_SIZE; ++k)
            {
                // skip values taken by A and B
                if (k == i || k == j) continue;
                c = matrix[2][k];
                
                tmp = calculateEfficiency(a, b, c);
                if (tmp > opt) opt = tmp;
            }
        }
    }
    return opt;
}

double calculateEfficiency(int a, int b, int c)
{
    return sqrt(a*a + b*b + c*c);
}