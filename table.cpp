#include <iomanip>
#include <iostream>
#include <vector>
#include <cstring>
#include "table.h"
using namespace std;


template<typename T>
Table<T>::Table(int n , int m)
{
    tr.resize(n);
    for(int i = 0; i < n; i++)
    {
        tr[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            tr[i][j] = (T)0;
        }
    }
}

template<typename T>
float Table<T>::ArithmeticalMeanRow(int row)
{
    float sum = 0;
    float cnt = 0;
    int i = 0;
    for(i; i < tr[row].size(); i++)
    {
        sum+=tr[row][i];
        cnt++;
    }
    float res = sum / cnt;

    return res;
}

template<typename T>
float Table<T>::ArithmeticalMeanCol(int col)
{
    float sum = 0;
    float cnt = 0;
    
    for(int i = 0; i < tr[col].size()-1; i++)
    {
        sum+=tr[i][col];
        cnt++;
    }

    float res = sum / cnt;
    return res;
}

template<typename T>
void Table<T>::RemoveColumns(int n, int from)
{

    for(int i = 0; i < tr.size(); i++)
    {
        if(tr[i].begin()+from > tr[i].end() || tr[i].begin()+from+n > tr[i].end())
        {
            cout << "Too much columns to delete!\n";
            return;
        }
        tr[i].erase(tr[i].begin()+from,tr[i].begin()+from+n);
    }
}

template<typename T>
void Table<T>::RemoveRows(int n, int from)
{
    if(from < 0)
        from++;

    if(from+n+1 < tr.size())
    {
        if(from == -1)
        {
            for(int i = 0; i<n;i++)
            {
                tr.erase(tr.end());
            }
        }
        else
        {

            for(int i = from-1; i<from+n-1;i++)
            {
                tr.erase(tr.begin()+from);
            }
        }
    } else {
        cout << "You're above table bounds,cannot delete "<< from+n << " rows";
        return;
    }
}


template<typename T>
vector<vector<T>> Table<T>::Find(T value)
{
    vector<vector<T>> keys;
    keys.resize(tr.size());
    for(int i = 0; i<tr.size(); i++)
    {

        for(int j = 0; j<tr[0].size(); j++)
        {
            keys[i].push_back(0);
        }
    }

    for(int i1 = 0; i1<tr.size(); i1++)
    {

        for(int j1 = 0; j1<tr[0].size(); j1++)
        {
            if(tr[i1][j1] == value)
                keys[i1][j1] = 1;
        }
    }
    int cnt = 0;
    for(int i2 = 0; i2<tr.size(); i2++)
    {
        for(int j2 = 0; j2<tr[0].size(); j2++)
        {
            if(keys[i2][j2] == 1)
            {
                cnt++;
                cout <<cnt<< ". " << "Value '" <<value<<"' found in cell: " <<"[" << i2 << "]" << "[" << j2 << "]" << endl;
            }

        }

    }
    if(cnt == 0)
        cout << "Nothing found on "<< value << endl;

    return keys;
}


template<typename T>
void Table<T>::Info()
{
    cout << endl << "           Table info." << endl;
    for(int siz = 0; siz<tr[0].size()+1;siz++)
    {
        cout<<"******";
    }

    cout << endl;
    for(int j1 = 0; j1 < tr[0].size(); j1++)
    {
        string bruh = to_string(j1) + ".";
        cout << setw(6) << bruh;
    }
    cout<<endl;

    for(int i = 0; i< tr.size(); i++)
    {
        for(int siz = 0; siz<tr[0].size()+1; siz++)
        {
            cout<<"------";
        }
        cout << endl;    
        cout << i << ".";
        if(i<=9)
            cout << " "<< "|";
        for(int j = 0; j < tr[i].size(); j++)
        {
            cout << setw(5) << tr[i][j] <<  "|";
        }
        cout  << endl;
    }
    
     for(int siz = 0; siz<tr[0].size()+1; siz++)
        {
            cout<<"------";
        }
        cout<<endl;
    for(int siz = 0; siz<tr[0].size()+1;siz++)
        {
            cout<<"******";
        }
        cout<<endl;
}


template<typename T>
T Table<T>::SumRow(int row)
{
    int sum = 0;
    for(int i=0; i < tr[row].size(); i++)
    {
        sum+=tr[row][i];
    }
    return sum;
}


template<typename T>
T Table<T>::SumCol(int col)
{
    int sum = 0;
    int i = 0;
    for(i; i < tr[col].size() - 1; i++)
    {
        sum+=tr[i][col];
    }
    return sum;
}


template<typename T>
void Table<T>::AddRows(int n, T value) //Добавляет n строк с конца
{
    int lastsize = tr.size();
    for(int i = 0 ; i < n; i++)
    {
        tr.push_back(vector<T>());

        for(int j = 0; j < tr[0].size(); j++)
        {
            tr[lastsize].push_back(value);
        }
        lastsize++;
    }
}


template<typename T>
void Table<T>::AddRows(int n, T value, int from) //Добавляем n строк с позиции from
{

    int startsize = from;
    for(int i = startsize ; i < from+n; i++)
    {
        tr.insert(tr.begin()+startsize, vector<T>());
        for(int j = 0; j < tr[0].size(); j++)
        {
            tr[i].push_back(value);
        }
        startsize++;
    }

}


template<typename T>
void Table<T>::AddColumns(int n,T value)
{
    for(int f = 0; f < n; f++)
    {
        for(int i = 0; i < tr.size(); i++)
        {
            tr[i].insert(tr[i].end(),value);
        }
    }
}


template<typename T>
void Table<T>::AddColumns(int n,T value, int from)
{
    for(int f = from; f < n + from; f++)
    {
        for(int i = 0; i < tr.size(); i++)
        {
            tr[i].insert(tr[i].begin()+from,value);
        }
    }
}


template<typename T>
void Table<T>::InsertInto(int m,int n, T value)
{
    tr[m][n] = value;
}


void Table<T>::FillArea(int a,int b, int m, int n, T value)
{
    // a, b = Begin coordinates
    //m,n = Size of rectangle

    if(a+m > tr.size() || b+n > tr[a].size())
    {
        cout <<" Out of bounds";
        return;
    }
    for(int i = a; i < a+m; i++)
    {
        for(int j = b; j < b+n; j++)
        {
            tr[i][j] = value;
        }
    }
}


template<typename T>
void Table<T>::ClearTable()
{
    this->FillArea(0,0,tr.size()-1,tr[0].size(),0); 
}


template<typename T>
void Table<T>::WriteToFile(string file, string format, string delimeter,bool numeration)
{
    ofstream out;
    file=file+"."+format;
    out.open(file);
    if(out.is_open())
    {
        if(numeration == true)
        {
            out << "    ";
            for(int j1 = 0; j1 < tr[0].size(); j1++)
            {
                string bruh = to_string(j1) + ".";
                out << setw(5) << bruh;
            }
            out<<endl;
            for(int i = 0; i< tr.size(); i++)
            {
                out << i << ".";
                if(i<=9)
                    out << " ";
                for(int j = 0; j < tr[i].size(); j++)
                {
                    out << setw(4) << tr[i][j]<< ",";
                }
                out << endl;
            }
        } else if(numeration == false)
        {
            for(int i = 0; i< tr.size(); i++)
            {
                for(int j = 0; j < tr[i].size(); j++)
                {
                    out << tr[i][j]<< delimeter;
                }
                out << endl;
            }

        }
        out.close();
    }
    else {
        cout << "Can't create file" << endl;
        return;
    }

}


template<typename T>
void Table<T>::ReadFromFile(string file, string format, char delimeter)
{
    fstream myfile;
    file = file+"."+format;
    myfile.open(file, ios::in);
    if (myfile.is_open())
    {
        int j = 0;
        tr.resize(0);
        string line;
        char delim = delimeter;
        while(getline (myfile,line))
        {
            tr.push_back(vector<T>());
            const string s =  line;
            stringstream ss(s);
            string item;
            while(getline(ss, item, delim))
            {
                if(std::strcmp( typeid(T).name() ,"i") == 0)
                tr[j].push_back(stoi(item));

                if(std::strcmp( typeid(T).name() ,"f") == 0)
                    tr[j].push_back(stof(item));

                if(std::strcmp( typeid(T).name() ,"d") == 0)
                    tr[j].push_back(stod(item));
            }

            j++;
        }
        myfile.close();
    }
    else
    {
        cout << "Can't open file" << endl;
        return;
    }
}
