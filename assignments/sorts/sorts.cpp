#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>
using namespace std;

void print_vector(vector<int> a)
{
    for (auto i : a)
    {
        cout << i << ", ";
    }
    cout << "\n";
}

int find_min_index(vector<int> a, int start_index,int stop_index)
{
    int min_index = start_index;
    int i;
    for(i = start_index ; i < stop_index; i++)
    {
        if (a[i] < a[min_index])
        {
            min_index = i;
        }
    }
    return min_index;
}

vector<int> ssort(vector<int> a)
{
    int i,min_index,j,tmp;
    int len = a.size();
    // loop through the vector from 0 to end
    for (i=0;i<len; i++)
    {
        // find the smallest value from i to the end
        min_index = find_min_index(a,i,len);
    
        // swap it into position i
        tmp = a[i];
        a[i] = a[min_index];
        a[min_index] = tmp;
    }
    return a;
}

/*
  left and right are already sorted
  merged should be a new vector with all the
  elements in left and right, and result
  should be sorted
*/
vector<int> merge(vector<int> left,vector<int> right)
{
    vector<int> merged;

    // your code here
    int l = 0;
    int r = 0;

    while (l < left.size() && r < right.size())
    {
        if (left[l] < right[r])
        {
            merged.push_back(left[l]);
            l++;
        }else{
            merged.push_back(right[r]);
            r++;
        }
    }
    // add any extra elements in left
    while (l < left.size())
    {
        merged.push_back(left[l]);
        l++;
    }
    // add any extra elements in right
    while (r < right.size())
    {
        merged.push_back(right[r]);
        r++;
    } 
    return merged;
}

vector<int> msort(vector<int> v)
{
    if (v.size()<2)
        return v;
    vector<int> left;
    vector<int> right;
    for (int x=0; x<v.size(); x++)
    {
        if(x<v.size()/2)
        {
            left.push_back(v[x]);
        }else{
            right.push_back(v[x]);
        }
    }
    left = msort(left);
    right = msort(right);
    return merge(left,right);
}

int main()
{
    int size=20;
    int max_val=100;

    srand(time(nullptr));
    vector<int> a(size);
    int i;
    for (i=0;i<size; i++)
    {
        a[i] = rand()%max_val;
    }
    /*
    print_vector(a);
    std::cout << "\n";
    a = ssort(a);
    print_vector(a);
    */
    vector<int> left = {1,2,5,6,10,15};
    vector<int> right = {3,7,8,12,16,19,20};
    print_vector(left);
    print_vector(right);
    vector<int> m = merge(left,right);
    print_vector(m);
    vector<int> ms = {80,9,7,333,1,4,1800,10,11,9,22,33};
    print_vector(msort(ms));
    return 0;
}