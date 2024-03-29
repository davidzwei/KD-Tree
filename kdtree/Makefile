CXX = g++
CFLAGS = -O3 -Wall -shared -std=c++11 -fPIC
INCLUDE = -Iinclude `python3 -m pybind11 --includes`
CONFIG = `python3-config --extension-suffix`
PY = -I /usr/include/python3.8

SRCDIR = src
INCDIR = include

# Generate .so file
all: $(SRCDIR)/KdTree.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -I$(INCDIR) $^ -o KdTree$(CONFIG) $(PY)

# Compile data generation program
make_data: $(SRCDIR)/make_data.cpp
	g++ -O3 -o make_data $^

# Run tests
test:
	python3 -m pytest

# Clean intermediate and generated files
clean:
	rm -rf __pycache__ .pytest_cache KdTree*.so test kdtree make_data
