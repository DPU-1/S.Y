#include <iostream>
#include <string>
using namespace std;

void getInput()
{

    int n;
    cout << "Enter no of cities : " << endl;
    cin >> n;
    string citynames[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\n Enter " << i + 1 << " city name :";
        cin >> citynames[i];
    }

    int arr[n][n];
    int l, m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 999;
        }
    }
    char ch;
    cout << "\n Enter D for Directed and U for undirected : ";
    cin >> ch;
    if (ch == 'U' || ch == 'u')
    {
        /////////////////////-FOR-----UNDIRECTED-////////////////////////////

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    arr[i][j] = -1;
                }
                else
                {
                    if (arr[i][j] == 999)
                    {
                        cout << "\n Enter time required(in Hours) to travel from " << citynames[i] << " to " << citynames[j] << " :";
                        cin >> arr[i][j];
                        arr[j][i] = arr[i][j];
                    }
                }
            }
        }
    }
    else if (ch == 'D' || ch == 'd')
    {
        /////////////////////-FOR-----DIRECTED-////////////////////////////
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    arr[i][j] = -1;
                }
                else
                {
                    {
                        cout << "\n Enter time required(in Hours) to travel from " << citynames[i] << " to " << citynames[j] << " :";
                        cin >> arr[i][j];
                    }
                }
            }
        }
    }

    // input for the matrix
    char chr;
    int s, d;
    do
    {
        cout << "\n Enter the boarding point no. and destination : \n";
        for (int k = 0; k < n; k++)
        {
            cout << k << "." << citynames[k] << endl;
        }
        cin >> s >> d;

        if (s != d)
        {
            cout << "\n Flight is available .Travelling time is " << arr[s][d] << "Hrs";
        }
        else
        {
            cout << "\n  Source and Destination cannot be same....Invalid Input !!";
        }
        cout << "\n Press r to check again :";
        cin >> chr;

    } while (chr != 'r' || chr != 'R');
}

int main()
{

    getInput();
}