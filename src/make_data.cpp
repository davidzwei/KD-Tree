#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    return v1[0] < v2[0];
}


void generate(int dim, int number, int min, int max, string str)
{
    srand(time(NULL));
    int count = 0;
    vector<vector<int>> data(number, vector<int>(dim));

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            data[i][j] = rand() % (max - min + 1) + min;
            cout << data[i][j] << " ";
        }
        count++;
        cout << "count = " << count;
        cout << endl;
    }

    sort(data.begin(), data.end(), sortcol);

    // write to file
    FILE *fptr;
    fptr = fopen(str.c_str(), "w");

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            fprintf(fptr, "%d ", data[i][j]);
        }
        fprintf(fptr, "\n");
    }
    fclose(fptr);
}

int main()
{
    int dim = 3;
    int number = 30000;
    int min = 0;
    int max = 30000;

    string str = "data_" + to_string(dim) + "_" + to_string(number) + ".txt";
    cout << str << endl;
    generate(dim, number, min, max, str);

    FILE *fptr;
    fptr = fopen("data.txt", "r");
    if (fptr == NULL) {
        perror("Failed: ");
        return 1;
    }

    fclose(fptr);

    return 0;
}