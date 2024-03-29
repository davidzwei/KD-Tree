import pytest
import timeit
import time
import KdTree
import random


def test_dim3_node10():
    assert 1 == 1
    tree = KdTree.KdTree(10, 3)
    assert tree.vcount == 10
    assert tree.dim == 3
    tree.read_input("../data/data_3_10.txt")
    tree.initialze()
    ans = KdTree.Point()
    root = tree.makeKDTree(0, 100, 0)
    print(root)
    tree.nearst_find(root, 5, 5, 5, 1000000, 0, ans)
    ans.print()
    assert int(ans.x) == 7
    assert int(ans.y) == 6
    assert int(ans.z) == 6

def test_dim3_node100():
    assert 1 == 1
    tree = KdTree.KdTree(100, 3)
    assert tree.vcount == 100
    assert tree.dim == 3
    tree.read_input("../data/data_3_100.txt")
    tree.initialze()
    ans = KdTree.Point()
    root = tree.makeKDTree(0, 100, 0)
    print(root)
    tree.nearst_find(root, 50, 50, 50, 1000000, 0, ans)
    ans.print()
    assert int(ans.x) == 43
    assert int(ans.y) == 45
    assert int(ans.z) == 56

def test_dim3_node1000():
    assert 1 == 1
    tree = KdTree.KdTree(1000, 3)
    assert tree.vcount == 1000
    assert tree.dim == 3
    tree.read_input("../data/data_3_1000.txt")
    tree.initialze()
    ans = KdTree.Point()
    root = tree.makeKDTree(0, 1000, 0)
    print(root)
    tree.nearst_find(root, 500, 500, 500, 1000000, 0, ans)
    ans.print()
    #486 541 487
    assert int(ans.x) == 486
    assert int(ans.y) == 541
    assert int(ans.z) == 487

def test_dim3_node1000():
    assert 1 == 1
    tree = KdTree.KdTree(1000, 3)
    assert tree.vcount == 1000
    assert tree.dim == 3
    tree.read_input("../data/data_3_1000.txt")
    tree.initialze()
    ans = KdTree.Point()
    root = tree.makeKDTree(0, 1000, 0)
    print(root)
    tree.nearst_find(root, 500, 500, 500, 1000000, 0, ans)
    ans.print()
    #486 541 487
    assert int(ans.x) == 486
    assert int(ans.y) == 541
    assert int(ans.z) == 487

def test_region_search1000():
    # init kd tree with 10000 nodes with 3 dimension
    tree = KdTree.KdTree(1000, 3)
    # read data 
    tree.read_input("../data/data_3_1000.txt")
    tree.initialze()
    # build kd tree
    root = tree.makeKDTree(0, 1000, 0)
    # search nodes in specific region 
    tree.region_find(root, 500, 600, 500, 600, 500, 600, 0)
    range_ans = tree.get_range_ans()
    assert(range_ans[0].x) == 538
    assert(range_ans[0].y) == 566
    assert(range_ans[0].z) == 551


    