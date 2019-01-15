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
    
    LLArray<int, 4> array(nArray, 2, 2, 2, 3);
    
    for (int i=0; i<array.size(); ++i)
    {
        for(int j=0; j<array[i].size(); ++j)
        {
            for (int k=0; k<array[i][j].size(); ++k)
            {
                for (int l=0; l<array[i][j][k].size(); ++l)
                {
                    cout << array[i][j][k][l] << " ";
                }
                cout << endl;
            }
            cout << endl << endl;
        }
        cout << endl << endl << endl;
    }
    //BigIntergate num1("123456789987654321");
    //BigIntergate num2("123456789987654321");
    
    
//    cout << num1 * num2 << endl;
	system("pause");
    return 0;
}
