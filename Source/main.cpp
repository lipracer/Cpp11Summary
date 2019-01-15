//demo for cpp11
#include <iostream>
#include "LLArray.hpp"
#include "BigIntergate.h"

using namespace std;

int main(int argc, char** argvs)
{
    int nArray[24];
    for(int i=0; i < 24; ++i)
    {
        nArray[i] = i;
    }
    
    LLArray<int, 3> array(nArray, 2, 3, 4);
    
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
    //BigIntergate num1("123456789987654321");
    //BigIntergate num2("123456789987654321");
    
    
//    cout << num1 * num2 << endl;
	system("pause");
    return 0;
}
