#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

int main()
{
    Job jobs[] =
    {
        {'A',2,100},
        {'B',1,19},
        {'C',2,27},
        {'D',1,25},
        {'E',3,15}
    };

    int n = 5;

    sort(jobs, jobs+n, compare);

    char slots[3] = {' ',' ',' '};

    for (int i=0; i<n; i++)
    {
        for (int j=jobs[i].deadline-1; j>=0; j--)
        {
            if (slots[j] == ' ')
            {
                slots[j] = jobs[i].id;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";

    for (int i=0; i<3; i++)
        cout << slots[i] << " ";

    return 0;
}
