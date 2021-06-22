#include "table.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

bool unit_test()
{
    Table<float> n(4,5);
    cout << endl << "UNIT_TEST" << endl;
    cout<<"Your table";
    n.Info();

    cout<< endl <<"Function of adding rows(1,3) and columns(1,2):";
    n.AddRows(1,3);
    n.AddColumns(1,2);
    cout<<endl<<"Table after editing: ";
    n.Info();
    cout << endl << "Function of deleting rows(1) and columns(0)" << endl;
    n.RemoveRows(1);
    n.RemoveColumns(1);
    cout<<endl<<"Table after editing: ";
    n.Info();
    cout << endl << "Function of insertion in cell ((1,0, 12), (2,2,7)):";
    n.InsertInto(1,0,12);
    n.InsertInto(2,2,7);
    cout<<endl<<"Table after editing: ";
    n.Info();
    cout << endl << "Function of filling an area (0,1,1,4,25)";
    n.FillArea(0,1,1,4,25);
    cout<<endl<<"Table after editing: ";
    n.Info();
    cout << endl << "Function of searching (25). Returns vector of results and prints it. Else returns false" << endl;
    n.Find(25);
    cout << endl << "Function of writing to file.";
    n.WriteToFile("unit_test");
    cout << endl << "Function of erasing a table";
    n.ClearTable();
    n.Info();
    cout << endl << "Function of reading from a file.";

    n.ReadFromFile("unit_test","csv",',');
    n.Info();
    cout<< endl << "Function of finding Arithmetical mean";
    float a = n.ArithmeticalMeanCol(1);
    float b = n.ArithmeticalMeanRow(1);
    cout<< endl << "On row 1: " << b;
    cout << endl << "On col 1: " << a;

     cout << endl << "Function of finding sum: ";
     cout << endl << "On row 1: " << n.SumRow(1);
     cout << endl << "On col 1: " << n.SumCol(1);
    return true;
}
