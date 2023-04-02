// MagicSquare.cpp
#include "MagicSquare.h"
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

vector<vector<int>> magic(int n)
{
    assert(n % 2 == 1);
    vector<vector<int>> mag;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
            row.push_back(0);
        mag.push_back(row);
    }

    int r = n - 1;
    int c = n / 2;
    mag[r][c] = 1;
    pair<int, int> nextrc;

    for (int i = 2; i <= n*n; i++)
    {
        nextrc = next_rc(mag, r, c);
        mag[nextrc.first][nextrc.second] = i;
        r = nextrc.first;
        c = nextrc.second;
        print_magic(mag);
    }
    return mag;
}

pair<int, int> next_rc(vector<vector<int>> mag, int r, int c)
{
    int r1 = r;
    int c1 = c;
    pair<int, int> nextrc;
    int n = mag.size();
    if (r1 == n-1 && c1 == n-1)
    {
       nextrc.first = r1 - 1;
       nextrc.second = c1;
       return nextrc;
    }

    r1 = r1 + 1;
    c1 = c1 + 1;

    if (r1 < n && c1 < n)
    {
        if (mag[r1][c1] == 0)
        {
            nextrc.first = r1;
            nextrc.second = c1;
            return nextrc;
        }
        else
        {
            r1 = r1 - 2;
            c1 = c1 - 1;
            nextrc = wrap(r1, c1, n);
            return nextrc;
        }
    }
    else
    {
        nextrc = wrap(r1, c1, n);
        return nextrc;
    }
}

pair<int, int> wrap(int r, int c, int n)
{
    pair<int, int> rc;
    if (r >= n)
    {
        rc.first = 0;
        rc.second = c;
        return rc;
    }
    if (r < 0)
    {
        rc.first = n -1;
        rc.second = c;
        return rc;
    }
    if (c >= n)
    {
        rc.first = r;
        rc.second = 0;
        return rc;
    }
    if (c < 0)
    {
        rc.first = r;
        rc.second = n - 1;
        return rc;
    }

    rc.first = r;
    rc.second = c;
    return rc;
}

// read a_square.txt
void read_square(vector<vector<int>> & square)
{
    ifstream inp;
    vector<int> nums;
    inp.open("square11A.txt");
    int next;
    inp >> next;
    while (!inp.fail())
    {
        nums.push_back(next);
        inp >> next;
    }
    inp.close();

    assert(sqrt(nums.size()) == floor(sqrt(nums.size())));
    int n = static_cast<int>(sqrt(nums.size()));
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<int> row;
        for (int j = 1; j <= n; j++)
        {
            row.push_back(nums[k]);
            k++;
        }
        square.push_back(row);
    }
    return;
}

// print out the magic square
void print_magic(const vector<vector<int>> & mag)
{
    cout << endl;
    for (int i = 0; i < mag.size(); i++)
    {
        for (int j = 0; j < mag.size(); j++)
            if (mag[i][j] == 0)
                cout << left << setw(6) << "~" << " ";
            else
                cout << left << setw(6) << mag[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    return;
}

// true if vector of vector is magic square: row sums,
// col sums and diaganol sums are the same;
// output arguement int& msum takes on value of that sum;
bool test_magic(const vector<vector<int>> & mag, int& msum)
{
    int dim = mag[0].size();
    int rsum = row_sum(0, mag);

    for (int i = 1; i < dim; i++)
        if (row_sum(i, mag) != rsum)
            return false;
    for (int i = 0; i < dim; i++)
        if (col_sum(i, mag) != rsum)
            return false;
    if (diag1_sum(mag) != rsum || diag2_sum(mag) != rsum)
        return false;
    
    msum = rsum;
    return true;
}

// sum of ith row
int row_sum(int i, const vector<vector<int>> & mag)
{
    int dim = mag[0].size();
    int sum = 0;
    for (int j = 0; j < dim; j++)
        sum += mag[i][j];
    return sum;
}

// sum of jth column
int col_sum(int j, const vector<vector<int>> & mag)
{
    int dim = mag[0].size();
    int sum = 0;
    for (int i = 0; i < dim; i++)
        sum += mag[i][j];
    return sum;
}

// sum of main diagonal
int diag1_sum(const vector<vector<int>> & mag)
{
    int dim = mag[0].size();
    int sum = 0;
    for (int i = 0; i < dim; i++)
        sum += mag[i][i];
    return sum;
}

// sum of off diagonal
int diag2_sum(const vector<vector<int>> & mag)
{
    int dim = mag[0].size();
    int sum = 0;
    for (int i = dim - 1, j = 0; j < dim; i--, j++)
        sum += mag[i][j];
    return sum;
}