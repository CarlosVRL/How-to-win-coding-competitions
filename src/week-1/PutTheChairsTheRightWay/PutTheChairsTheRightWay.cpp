/**
 * Put the Chairs the Right Way!
 */
#include <fstream>
#include <iomanip>

using namespace std;

/**
 * File Management
 */
ifstream fin("input.txt");
ofstream fout("output.txt");

/**
 * Constants
 */
const int DIVISOR = 6;

/**
 * Main
 */
int main(void)
{
    // Solution by mid-point theorem
    double a, b, c, res;
    
    fin >> a >> b >> c;
    
    res = (a + b + c) / DIVISOR;
    
    fout << setprecision(15) << res << endl;
    
    return EXIT_SUCCESS;
}
