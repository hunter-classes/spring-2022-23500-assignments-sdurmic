#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> a)
{
    for (auto i : a)
    {
        cout << i << ", ";
    }
    cout << "\n";
}

int count(vector<int> v, int val)
{
    int i = 0;
    for(int x=0; x<v.size(); x++)
    {
        if(v[x] == val)
        {
            i++;
        }
    }
    return i;
}

int largest(vector<int> v)
{
    int max = 0;
    for(int x=0; x<v.size(); x++)
    {
        if(v[x] > max)
        {
            max = v[x];
        }
    }
    return max;
}

int mode(vector<int> v)
{
    int mode = 0;
    int f = 0;

    for(int x=0; x<v.size(); x++)
    {
        if((count(v, v[x]))>f)
        {
            f = count(v, v[x]);
            mode = v[x];
        }
    }
    return mode;
}

int mode2(vector<int> v)
{
    vector<int> freq(largest(v) + 1);
    for(int i: v)
    {
        freq[i]++;
    }

    int max = 0;
    for(int i=0; i<freq.size(); i++)
    {
        if (freq[max]<freq[i])
            max = i;
    }
    return max;
}

int main()
{
    int max = 10;
    srand(time(nullptr));
    vector<int> v(10);
    int x;
    for(x=0; x<10; x++)
    {
        v[x] = rand()%max;
    }
    cout << "Vector v: ";
    print_vector(v);
    cout << "The number of times 3 appears in Vector v: " << count(v, 3) << "\n";
    cout << "The largest number in Vector v: " << largest(v) << "\n";
    cout << "The mode of Vector v: " << mode(v) << "\n";
}
