/**
 * Prepare Yourself to Competitions!
 */
#include <cmath>
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
int getLargestOfTwo(int x, int y);
int getIntFromStream(ifstream& ifs);
vector<int>& exhaustIntsFromStream(vector<int>& buf, ifstream& ifs);
int trackOptimalUse(int x, int y, int optimum, bool& xIsUsed, bool& yIsUsed);

/**
 * Main
 */
int main(void)
{
    // Containers
    vector<int> t, p;
    int n = 0, sum = 0;
    bool t_used = false;
    bool p_used = false;
    
    // Gather input data
    n = getIntFromStream(fin);
    t = exhaustIntsFromStream(t, fin);
    p = exhaustIntsFromStream(p, fin);
    
    // Minimum delta strategy
    int diff = MAX_VAL * 2;
    for (int i = 0; i < n; ++i)
    {
        sum += getLargestOfTwo(t[i], p[i]);
        diff = trackOptimalUse(t[i], p[i], diff, t_used, p_used);
    }
    
    // Apply correction, if necessary
    if (!t_used || !p_used)
        sum -= diff;
    
    fout << sum << endl;
    
    return EXIT_SUCCESS;
}

/**
 * Return the largest positive value
 */
int getLargestOfTwo(int x, int y)
{
    int delta = x - y;
    if (delta >= 0)
    {
        return x;
    }
    else
    {
        return y;
    }
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

/**
 * Maintains optimum delta and tracks parameter usage
 */
int trackOptimalUse(int x, int y, int optimum, bool& xIsUsed, bool& yIsUsed)
{
    int res, delta;
    
    delta = x - y;
    
    // Track usage
    if (delta >= 0)
        xIsUsed = true;
    else
        yIsUsed = true;
    
    // Track minimum
    if (abs(delta) < optimum)
        res = abs(delta);
    else
        res = optimum;
    
    return res;
}
