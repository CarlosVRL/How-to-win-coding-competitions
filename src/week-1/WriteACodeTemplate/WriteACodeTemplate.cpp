/**
 * WriteACodeTemplate!
 */
#include <fstream>

using namespace std;

/**
 * File Management
 */
ifstream fin("input.txt");
ofstream fout("output.txt");

/**
 * Constants
 */
struct Keyboard {
    int width;
    int height;
};

/**
 * Main
 */
int main(void)
{
    // Parse template
    Keyboard keyboard = initializeKeyboard(fin);
    
    // Match on Logic
    
    // Build Output
    fout << "out\n";
    return EXIT_SUCCESS;
}
