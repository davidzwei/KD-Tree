CXX = g++
CFLAGS = -O3 -Wall -shared -std=c++11 -fPIC
INCLUDE = `python3 -m pybind11 --includes`
CONFIG = `python3-config --extension-suffix`
PY = -I /usr/include/python3.8

all:
	$(CXX) $(CFLAGS) $(INCLUDE) KdTree.cpp -o KdTree$(CONFIG) $(PY)

normal:
	g++ -o kdtree test.cpp KdTree.cpp

data:
	g++ -O3 -o make_data make_data.cpp

test:
	# $(CXX) $(CFLAGS) $(INCLUDE) KdTree.cpp -o KdTree$(CONFIG) $(PY)
	python3 -m pytest

clean:
	rm -rf __pycache__ .pytest_cache KdTree*.so test kdtree make_data

