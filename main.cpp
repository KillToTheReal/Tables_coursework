#include <iostream>
#include "table.h"
using namespace std;

int main()
{
    Table<float> bruh(4,5);

    bruh.InsertInto(0,1,15.21);

    bruh.Info();
    bruh.AddRows(3, 6.23);
    bruh.AddRows(2,7.6);
    bruh.AddColumns(2,8.5);
    bruh.RemoveColumns(1);
    bruh.Info();
    bruh.AddColumns(2,17,3);
    bruh.WriteToFile("example","csv");
    bruh.Info();
    bruh.Find(0);
    cout<<endl<<bruh.ArithmeticalMeanRow(2);
    cout<<endl<<bruh.ArithmeticalMeanCol(4);
    cout<<endl<<bruh.SumCol(4);
    return 0;
}
