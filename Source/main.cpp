//demo for cpp11
#include <iostream>
#include "LLArray.hpp"
#include "BigIntergate.h"

using namespace std;

typedef pair<int, int> POINT;

template <int m, int n>
inline void down_walk(POINT& point);
template <int m, int n>
inline void down_walk(POINT& point);
template <int m, int n>
inline bool leftdown_walk(POINT& point, array<array<int, n>, m>&, int& count);
template <int m, int n>
inline bool rightup_walk(POINT& point, array<array<int, n>, m>&, int& count);

inline template <int m, int n>
inline void right_walk(POINT& point)
{
    if(n == point.second+1) down_walk<m, n>(point);
    else point.second++;
    
}
template <int m, int n>
inline void down_walk(POINT& point)
{
    if(m == point.first+1) right_walk<m, n>(point);
    else point.first++;
}
template <int m, int n>
inline bool leftdown_walk(POINT& point, array<array<int, n>, m>& arr, int& count)
{
    bool isContinue = false;
    if(0 == point.second)
    {
        down_walk<m, n>(point);
        
    }
    else if(m == point.first+1)
    {
        right_walk<m, n>(point);
    }
    else
    {
        point.first++; point.second--;
        isContinue = true;
    }
    arr[point.first][point.second] = count++;
    return isContinue;
}
template <int m, int n>
inline bool rightup_walk(POINT& point, array<array<int, n>, m>& arr, int& count)
{
    bool isContinue = false;
    if(0 == point.first)
    {
        right_walk<m, n>(point);
    }
    else if(n == point.second+1)
    {
        down_walk<m, n>(point);
    }
    else
    {
        point.first--; point.second++;
        isContinue = true;
    }
    arr[point.first][point.second] = count++;
    return isContinue;
}

template<int m, int n>
void getRect_()
{
    array<array<int, n>, m> result;
    memset(result.data(), 0, m*n*sizeof(int));
    
    pair<int, int> cur_pos = { 0, 0 };
    int count =1;
    result[0][0] = count++;
    while (count <= m*n)
    {
        while(rightup_walk<m, n>(cur_pos, result, count)){}
        while(leftdown_walk<m, n>(cur_pos, result, count)){}
    }
    for (auto& row : result)
    {
        for (auto& col : row)
        {
            printf("%d\t", col);
        }
        printf("\n");
    }
    
}

template<int m, int n>
void getRect()
{
    int result[m][n] = {0};

//    int test = 0;
//    for(auto &it : result)
//    {
//        for(auto &it_ : it)
//        {
//            it_ = test++;
//        }
//    }
//
//    memset(&result, 0, sizeof(result));
//
//    int line_count = m + n - 1;
//    int tri_line_count = min(m, n) / 2 + 1;
//    int count = 1;
//    int line_start = 1;
//    int direct = 0;
//    for(int sum = 0; sum <= tri_line_count; sum++)
//    {
//        for(int step = 0; step <= sum; step++)
//        {
//            int row = 0, col = 0;
//            if(direct%2==0)
//            {
//                row = sum-step;
//                col = step;
//            }
//            else
//            {
//                row = step;
//                col =sum-step;
//            }
//
//            result[row][col] = count;
//            result[m-1-row][n-1-col] = m*n+1 - result[row][col];
//            count += 1;
//        }
//        direct += 1;
//        line_start += 1;
//    }
//    int max_len = min(m, n);
    
    pair<int, int> cur_pos = { 0, 0 };
    right_walk<m, n>(cur_pos);
    int count =1;
    while (count <= m*n)
    {
        
    }
    result[cur_pos.first][cur_pos.second] = count++;
    
}

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
    BigIntergate num1("123456789987654321");
    BigIntergate num2("123456789987654321");
    
    
    cout << num1 * num2 << endl;
    
    vector<int> n1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> n2 = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    
    auto result = Mul2BigIntergate<int>(n1, n2);
    for (auto r : result)
    {
        cout << r;
    }
    cout << endl;
    getRect<6, 4>();

    int *p = new int(16);
    
	system("pause");
    return 0;
}
