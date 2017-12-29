/**
 * Prepare Yourself to Competitions!
 */
#include <cmath>
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

/**
 * Main
 */
int main(void)
{
    // Containers
    int n, sum, t_used, p_used;
    vector<int> t, p, d;
    
    // Gather input data
    n = getIntFromStream(fin);
    t = exhaustIntsFromStream(t, fin);
    p = exhaustIntsFromStream(p, fin);
    
    // Calculate deltas
    int min_index = 0;
    int min_delta = MAX_VAL * 2;
    for (int i = 0; i < n; ++i)
    {
        int delta = t[i] - p[i];
        
        if (delta >= 0)
        {
            sum += t[i];
            t_used++;
        }
        else
        {
            sum += p[i];
            p_used++;
        }
        
        // Absolute value of set delta tracks optimization point
        d.push_back(delta);
        if (abs(delta) < min_delta)
        {
            min_delta = abs(delta);
            min_index = i;
        }
    }
    
    // Apply correction, if necessary
    if (t_used == 0)
    {
        // t_i < p_i for all i hence d_i < 0
        sum += d[min_index];
    }
    else if (p_used == 0)
    {
        // t_i >= p_i for all i hence d_i > 0
        sum -= d[min_index];
    }
    
    fout << sum << endl;
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
