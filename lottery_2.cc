#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

vector<int> generate_lottery_numbers()
{
    vector<int> lottery_numbers;

    for(int i=0; i<10; ++i)
        lottery_numbers.push_back(i);

    shuffle(lottery_numbers.begin(), lottery_numbers.end(), default_random_engine(time(nullptr)));
    lottery_numbers.resize(5);
    return lottery_numbers;
}

int main()
{
    vector<int> v = generate_lottery_numbers();

    for(auto e : v)
        cout << e << '\n';
}