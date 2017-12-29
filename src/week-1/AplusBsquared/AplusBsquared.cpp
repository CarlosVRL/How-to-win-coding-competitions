/**
 * A + B ^ 2
 */
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

static const int EXPONENT_POWER = 2;

int main(void)
{
    int a, b;
    fin >> a >> b;
    fout << a + pow(b, EXPONENT_POWER);
    return 0;
}

