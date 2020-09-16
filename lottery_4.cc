#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    const int size = 7;
    int winningDigits[size];
    int player[size];
    int count=0;
    ifstream datafile;  

    datafile.open("player.dat");

    for(int i=0; i<size; i++)
    {
        winningDigits[i]=rand()%10;
        datafile >> player[i];
        if (winningDigits[i]==player[i])
        count++;
    }
/*
for(int i=0; i<size; i++)
{
    winningDigits[i]=rand()%10;
    cout << "Enter number " << i+1 << " ";
    cin >> player[i];

    if (winningDigits[i]==player[i])
        count++;
}
*/
    cout << "WinningDigits: ";
    for(int i=0; i<size; i++)
    cout << winningDigits[i] << " ";

    cout << "\nPlayer:        ";
    for(int i=0; i<size; i++)
    cout << player[i] << " ";

    cout << " \nThere are " << count << " matching elements ";
    for(int i=0; i<size; i++)
    if(winningDigits[i]==player[i])
    cout << i+1 << " ";
    cout << "\n";
}