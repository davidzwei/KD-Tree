#include <math.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include "KdTree.h"

using namespace std;

void KdTree::print()
{
    for (int i = 0; i < 100; i++)
    {
        this->P[i].print();
    }
}

int KdTree::makeKDTree(int l, int r, int depth)
{
    if (!(l < r))
        return NIL;

    int mid = (l + r) / 2;
    int t = this->np++;
    if (depth % 3 == 0)
    {
        sort(this->P + l, this->P + r, lessX);
    }
    else if (depth % 3 == 1)
    {
        sort(this->P + l, this->P + r, lessY);
    }
    else
    {
        sort(this->P + l, this->P + r, lessZ);
    }

    this->T[t].location = mid;
    this->T[t].l = this->makeKDTree(l, mid, depth + 1);
    this->T[t].r = this->makeKDTree(mid + 1, r, depth + 1);

    return t;
}

void KdTree::region_find(int v, int sx, int tx, int sy, int ty, int sz, int tz, int depth)
{
    int x = this->P[this->T[v].location].x;
    int y = this->P[this->T[v].location].y;
    int z = this->P[this->T[v].location].z;

    if (sx <= x && x <= tx && sy <= y && y <= ty && sz <= z && z <= tz)
    {
        this->range_ans.push_back(this->P[this->T[v].location]);
        this->num_range_ans++;
    }

    if (depth % 3 == 0)
    {
        if (this->T[v].l != NIL)
        {
            if (sx <= x)
            {
                this->region_find(this->T[v].l, sx, tx, sy, ty, sz, tz, depth + 1);
            }
        }
        if (this->T[v].r != NIL)
        {
            if (x <= tx)
            {
                this->region_find(this->T[v].r, sx, tx, sy, ty, sz, tz, depth + 1);
            }
        }
    }
    else if (depth % 3 == 1)
    {
        if (this->T[v].l != NIL)
        {
            if (sy <= y)
            {
                this->region_find(this->T[v].l, sx, tx, sy, ty, sz, tz, depth + 1);
            }
        }
        if (this->T[v].r != NIL)
        {
            if (y <= ty)
            {
                this->region_find(this->T[v].r, sx, tx, sy, ty, sz, tz, depth + 1);
            }
        }
    }
    else
    {
        if (this->T[v].l != NIL)
        {
            if (sz <= z)
            {
                this->region_find(this->T[v].l, sx, tx, sy, ty, sz, tz, depth + 1);
            }
        }
        if (this->T[v].r != NIL)
        {
            if (z <= tz)
            {
                this->region_find(this->T[v].r, sx, tx, sy, ty, sz, tz, depth + 1);
            }
        }
    }
}

void KdTree::nearst_find(int v, double x1, double y1, double z1, double &r, int depth, Point &ans)
{
    double sx = x1 - r;
    double tx = x1 + r;
    double sy = y1 - r;
    double ty = y1 + r;
    double sz = z1 - r;
    double tz = z1 + r;

    double x = this->P[this->T[v].location].x;
    double y = this->P[this->T[v].location].y;
    double z = this->P[this->T[v].location].z;

    if (sx <= x && x <= tx && sy <= y && y <= ty && sz <= z && z <= tz)
    {
        double r1 = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1) + (z - z1) * (z - z1));
        if (r1 < r)
        {
            ans = this->P[this->T[v].location];
        }
        r = r1;
    }

    if (depth % 3 == 0)
    {
        if (this->T[v].l != NIL)
        {
            if (sx <= x)
                this->nearst_find(this->T[v].l, x1, y1, z1, r, depth + 1, ans);
        }
        if (this->T[v].r != NIL)
        {
            if (x <= tx)
                this->nearst_find(this->T[v].r, x1, y1, z1, r, depth + 1, ans);
        }
    }
    else if (depth % 3 == 1)
    {
        if (this->T[v].l != NIL)
        {
            if (sy <= y)
                this->nearst_find(this->T[v].l, x1, y1, z1, r, depth + 1, ans);
        }
        if (this->T[v].r != NIL)
        {
            if (y <= ty)
                this->nearst_find(this->T[v].r, x1, y1, z1, r, depth + 1, ans);
        }
    }
    else
    {
        if (this->T[v].l != NIL)
        {
            if (sz <= z)
                this->nearst_find(this->T[v].l, x1, y1, z1, r, depth + 1, ans);
        }
        if (this->T[v].r != NIL)
        {
            if (z <= tz)
                this->nearst_find(this->T[v].r, x1, y1, z1, r, depth + 1, ans);
        }
    }
}

void KdTree::initialze()
{
    for (int i = 1; i <= vcount; i++)
    {
        this->P[i - 1] = Point(i - 1, this->vlist[i][0], this->vlist[i][1], this->vlist[i][2]);
        this->T[i - 1].l = this->T[i - 1].r = this->T[i - 1].p = NIL;
    }
}

void KdTree::read_input(string str)
{
    FILE *fptr;
    fptr = fopen(str.c_str(), "r");
    if (fptr == NULL)
    {
        perror("Failed: ");
        exit(1);
    }

    for (int i = 0; i < this->vcount; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            fscanf(fptr, "%d", &vlist[i][j]);
        }
    }

    fclose(fptr);
}

vector<Point> KdTree::get_range_ans()
{
    return this->range_ans;
}

bool lessX(const Point &p1, const Point &p2) { return p1.x < p2.x; }
bool lessY(const Point &p1, const Point &p2) { return p1.y < p2.y; }
bool lessZ(const Point &p1, const Point &p2) { return p1.z < p2.z; }

vector<int> KdTree::nearst_bruteforce(double x1, double y1, double z1, double r)
{
    double distance = r;
    double ans_x, ans_y, ans_z;

    for (int i = 0; i < this->vcount; i++)
    {
        double x = this->vlist[i][0];
        double y = this->vlist[i][1];
        double z = this->vlist[i][2];
        double r1 = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1) + (z - z1) * (z - z1));

        if (r1 < distance)
        {
            ans_x = x;
            ans_y = y;
            ans_z = z;
            distance = r1;
        }
    }
    vector<int> ans;
    ans.push_back(int(double(ans_x)));
    ans.push_back(int(double(ans_y)));
    ans.push_back(int(double(ans_z)));
    return ans;
}

void KdTree::region_bruteforce(int x1, double x2, double y1, double y2, double z1, double z2)
{
    for (int i = 0; i < this->vcount; i++)
    {
        if (vlist[i][0] <= x2 && vlist[i][0] >= x1)
        {
            if (vlist[i][1] <= y2 && vlist[i][1] >= y1)
            {
                if (vlist[i][2] <= z2 && vlist[i][2] >= z1)
                {
                    ;
                }
            }
        }
    }
}

PYBIND11_MODULE(KdTree, m)
{
    pybind::class_<Point>(m, "Point")
        .def(pybind::init())
        .def(pybind::init<int, int, int, int>())
        .def("print", &Point::print)
        .def_readwrite("x", &Point::x)
        .def_readwrite("y", &Point::y)
        .def_readwrite("z", &Point::z);

    pybind::class_<KdTree>(m, "KdTree")
        .def(pybind::init())
        .def(pybind::init<int, int>())
        .def("print", &KdTree::print)
        .def("makeKDTree", &KdTree::makeKDTree)
        .def("region_find", &KdTree::region_find)
        .def("nearst_find", &KdTree::nearst_find)
        .def("read_input", &KdTree::read_input)
        .def("initialze", &KdTree::initialze)
        .def("get_range_ans", &KdTree::get_range_ans)
        .def("nearst_bruteforce", &KdTree::nearst_bruteforce)
        .def_readwrite("vcount", &KdTree::vcount)
        .def_readwrite("dim", &KdTree::dim)
        .def_readwrite("num_range_ans", &KdTree::num_range_ans)
        .def_readwrite("range_answer", &KdTree::range_ans);
}
