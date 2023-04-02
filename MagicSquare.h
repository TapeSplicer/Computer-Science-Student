// MagicSquare.h
#ifndef MAGICSQUARE_H_
#define MAGICSQUARE_H_

#include <iostream>
#include <vector>
using namespace std;

// Function Prototypes - Make a Magic Square
pair<int, int> next_rc(vector<vector<int>>, int, int);
pair<int, int> wrap(int, int, int);
vector<vector<int>> magic(int);

// Function Prototypes - Test the Magic Square
void read_square(vector<vector<int>> &);
void print_magic(const vector<vector<int>> &);
bool test_magic(const vector<vector<int>> &, int&);
int row_sum(int i, const vector<vector<int>> &);
int col_sum(int j, const vector<vector<int>> &);
int diag1_sum(const vector<vector<int>> &);
int diag2_sum(const vector<vector<int>> &);

#endif