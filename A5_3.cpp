#include <iostream>
using namespace std;

int main()
{
    int graph[5][5] =
    {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    int selected[5] = {0};
    selected[0] = 1;

    int edges = 0;

    cout << "MST:\n";

    while (edges < 4)
    {
        int min = 999;
        int x = 0, y = 0;

        for (int i=0; i<5; i++)
        {
            if (selected[i])
            {
                for (int j=0; j<5; j++)
                {
                    if (!selected[j] && graph[i][j])
                    {
                        if (graph[i][j] < min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << graph[x][y] << endl;

        selected[y] = 1;
        edges++;
    }

    return 0;
}
