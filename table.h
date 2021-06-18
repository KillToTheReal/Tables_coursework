#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef TABLE_H
    #define TABLE_H

using namespace std;

template<typename T>
class Table
{
private:

    vector<vector<T>> tr;

public:

    Table(int n = 5, int m = 5); //Constructor
    void Info(); //Output of table
    void AddRows(int n, T value = 0); //Default adding "n" rows from back filling them with "value"
    void AddRows(int n, T value, int from); //Adding "n" rows filled with "value" from position "from"
    void AddColumns(int n, T value = 0); //Default adding "n" cols from back filling them with "value"
    void AddColumns(int n, T value, int from);
    void RemoveRows(int n, int from = -2); //Default removing "n" rows from back
    void RemoveColumns(int n, int from = 0);
    void InsertInto(int m, int n, T value); //Insert value into cell [m][n]
    void FillArea(int a,int b, int m, int n, T value);
    void ClearTable(); //Fills table with 0
    vector<vector<T>> Find(T value); //Finds all the values that we ask in the table and prints them. If needed, can return map of found values in table
    void WriteToFile(string file = "example",string format = "csv",string delimeter = ",",bool numeration = false);//Copies table to file
    void ReadFromFile(string file = "example", string format = "csv", char delimeter = ',');
    float ArithmeticalMeanRow(int row);
    float ArithmeticalMeanCol(int col);
    T SumRow(int row);
    T SumCol(int col);
};

#include "table.cpp"
#endif
