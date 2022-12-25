#include "KdTree.h"


int main() {
    // int vcount = 300;

    KdTree* tree = new KdTree();
    tree->read_input();
    tree->initialze();

    // for (int i = 1; i <= vcount; i++) {
    //     tree->P[i - 1] = Point(i - 1, vlist[i][0], vlist[i][1], vlist[i][2]);
    //     tree->T[i - 1].l = tree->T[i - 1].r = tree->T[i - 1].p = NIL;
    // }
    
    cout << endl << endl;

    int root = tree->makeKDTree(0, tree->vcount, 0);
    cout << "root = " << root <<endl;

    cout << "vlist = " <<tree->vlist[0][0] << endl;


    cout << endl << endl;
    cout << endl << endl;
    cout << "--- nn find demo --- "<< endl;

    double x1 = 50, y1 = 100, z1 = 200, r = 10000;
    Point ans;
    tree->nearst_find(root, 145, 146, 153, r, 0, ans);
    ans.print();
    
    Point ans2;
    tree->nearst_bruteforce(145, 146, 153, r, ans2);
    ans2.print();


    //-----------------------------------------
    cout << endl << endl;
    cout << endl << endl;
    cout << "--- region find demo --- "<< endl;

    vector<Point> ans1;
    // tree->region_find(root, -1, 1, -5, 5, -1, 3, 0, ans1);
    tree->region_find(root, 60, 100, 5, 950, -1, 100, 0, ans1);

    for (int i = 0; i < ans1.size(); i++) {
        ans1[i].print();
    }

    // return 0;
}

