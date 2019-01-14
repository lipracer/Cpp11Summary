//demo for cpp11
#include "include/LLArray.hpp"
#include <iostream>

using namespace std;

int main(int argc, char** argvs)
{
    int nArray[24];
    for(int i=0; i < 24; ++i)
    {
        nArray[i] = i;
    }
    
    LLArray<int, 3> array(nArray, {2, 3, 4});
    
    for (int i=0; i<array.size(); ++i)
    {
        for(int j=0; j<array[i].size(); ++j)
        {
            for (int k=0; k<array[i][j].size(); ++k)
            {
                cout << array[i][j][k] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
