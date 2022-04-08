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
    for (i=0;i<len; i++)
    {
        min_index = find_min_index(a,i,len);
    
        tmp = a[i];
        a[i] = a[min_index];
        a[min_index] = tmp;
    }
    return a;
}

vector<int> merge(vector<int> left,vector<int> right)
{
    vector<int> merged;

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
    while (l < left.size())
    {
        merged.push_back(left[l]);
        l++;
    }
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

vector<int> qsort(vector<int> list)
{
    int i,j;
  
    if(list.size() <= 1)
    {
        return list;
    }

    int pivot = list[0];
  
    vector<int> lower,higher;

    for(i=1; i < list.size(); i++)
    {
        if (list[i] < pivot)
        {
            lower.push_back(list[i]);
        }else{
            higher.push_back(list[i]);
        }
    }
  
    lower = qsort(lower);
    higher = qsort(higher);

    for(i=0 ; i < lower.size(); i++)
    {
        list[i]=lower[i];
    }

    list[i] = pivot;
    i++;

    for(j=0;j<higher.size();j++)
    {
        list[i] = higher[j];
        i++;
    }
  
    return list; 
}

void swap(vector<int>& list, int i, int j)
{
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

// grabbed code from pandaericbear
void qsort2(vector<int>& list, int low, int high)
{
    int p = list[low];
    int goodPivot;
    int first = list[low];
    int mid = list[low + (high-low) / 2];
    int last = list[high];
    if(first>mid)
    {
        if(first<last)
            goodPivot = first;
        else if(mid>last)
            goodPivot = mid;
        else
            goodPivot = last;
    }else{
        if(last > mid)
            goodPivot = mid;
        else if (first > last)
            goodPivot = first;
        else
            goodPivot = last;
    }
    int l = low;
    int h = high;

    while(l <= h)
    {
        while(list[l] < goodPivot)
        {
            l++;
        }
        while(list[h] > goodPivot)
        {
            h--;
        }
        if(l <= h)
        {
            swap(list, l, h);
            l++;
            h--;
        }
    }
    if(low < high)
    {
        qsort2(list, low, l-1);
        qsort2(list, l, high);
    }
}


void print_help(char *command_name)
{
    cout << "Usage: "<< command_name;
    cout << " [-h|-p|-m N|-s N|-a algorithm]\n\n";
    cout << " -m MAX_ELEMENT_SIZE\n";
    cout << " -s DATA_SET_SIZE\n";
    cout << " -a[s|m]: s - selection, m - merge\n";
}

extern char *optarg;

int main(int argc, char *argv[])
{
    int size = 25000;
    int max_val = 200; 

    char algorithm = 's' ; 
    bool print = false; 
    char c;

    while((c = getopt(argc, argv, "phs:m:a:")) != -1)
    {
        switch (c) 
        {
            case 'h':
	            print_help(argv[0]);
	            exit(0);
	            break;
            case 'p':
	            print = true;
	            break;
            case 's':
	            size = stoi(optarg);
	            break;
            case 'm':
	            max_val = stoi(optarg);
	            break;
            case 'a':
	            algorithm = optarg[0];
        }
    }

    srand(time(nullptr));
    vector<int> a(size);
    int i;
    for(i=0;i<size; i++)
    {
        a[i] = rand()%max_val;
    }

    if(print)
    {
        print_vector(a);
        cout << "\n";
    }

    cout << "Starting the sort!\n";
    struct timeval tp;

    gettimeofday(&tp,NULL);
    long start_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

    if (algorithm == 's')
    {
        a = ssort(a);
    }else if(algorithm == 'm')
    {
        a = msort(a);
    }else if(algorithm == 'q') 
    {
        a = qsort(a);
    }else if(algorithm == 'Q')
    {
        qsort2(a, 0, size);
    }

    gettimeofday(&tp,NULL);
    long current_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

    long elapsed = current_time - start_time;

    if(print) 
    {
        print_vector(a);
    }
    cout << "Algorithm: " << algorithm << "\n";
    cout << "Time: " << elapsed << "\n";

    return 0;
}
