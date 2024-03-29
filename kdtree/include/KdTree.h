#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <pybind11/complex.h>

namespace pybind = pybind11;

#define MAX 1000000
#define NIL -1

using namespace std;

class Node
{
public:
    int location;
    int p, l, r;
    Node() {}
};

class Point
{
public:
    int id;
    double x, y, z;
    Point() {}
    Point(int id, double x, double y, double z) : id(id), x(x), y(y), z(z) {}

    void print()
    {
        cout << (int)x << " " << (int)y << " " << (int)z << endl;
    }
};

class KdTree
{
public:
    Point P[MAX];
    Node T[MAX];
    int np = 0;
    int dim;
    int vcount;
    int vlist[50000][3];
    vector<Point> range_ans;
    int num_range_ans;

    KdTree()
    {
    }
    KdTree(int vcount, int dim) : vcount(vcount), dim(dim) {}

    void initialze();
    void print();
    int makeKDTree(int l, int r, int depth);
    void region_find(int v, int sx, int tx, int sy, int ty, int sz, int tz, int depth);
    void nearst_find(int v, double x1, double y1, double z1, double &r, int depth, Point &ans);
    vector<int> nearst_bruteforce(double x1, double y1, double z1, double r);
    void region_bruteforce(int x1, double x2, double y1, double y2, double z1, double z2);
    void read_input(string str);
    vector<Point> get_range_ans();
};

bool lessX(const Point &p1, const Point &p2);
bool lessY(const Point &p1, const Point &p2);
bool lessZ(const Point &p1, const Point &p2);
