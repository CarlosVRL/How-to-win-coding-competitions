/**
 * Prepare Yourself to Competitions!
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
 * File Management
 */
ifstream fin("input.txt");
ofstream fout("output.txt");

/**
 * Constants
 */
static const int MAX_VAL = 1000;
static const int MAX_COUNT = 100;
static const int EOL = MAX_COUNT * (4 + 1); // Max integer size + white space

/**
 * Prototypes
 */
int getIntFromStream(ifstream& ifs);
vector<int>& exhaustIntsFromStream(vector<int>& buf, ifstream& ifs);

#define fout cout // Debug

/**
 * Main
 */
int main(void)
{
    // Containers
    int n;
    vector<int> t, p;
    
    // Gather input data
    n = getIntFromStream(fin);
    t = exhaustIntsFromStream(t, fin);
    p = exhaustIntsFromStream(p, fin);
    
    return EXIT_SUCCESS;
}

/**
 * Get (first) integer value from input file stream
 * 
 * @param ifs the input file stream
 * @return the integer
 */
int getIntFromStream(ifstream& ifs)
{
    int res;
    ifs >> res;
    ifs.ignore(EOL, '\n');
    return res;
}

/**
 * Exhaust integers from input file stream until end of line
 * 
 * @param buf an input buffer to populate
 * @return the populated input array
 */
vector<int>& exhaustIntsFromStream(vector<int>& buf, ifstream& ifs)
{
    int val;
    string line;
    getline(ifs, line);
    istringstream iss(line);
    while (iss >> val)
    {
        buf.push_back(val);
    }
    return buf;
}
