/**
 * A + B ^ 2
 */
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main(void)
{
    int a, b;
    fin >> a >> b;
    fout << a + (long long) (b) * b;
    return 0;
}

