# find_square

This package provides a Python interface to a C++ implementation of a function `find_square(y, a, b)` using SWIG.  
It searches for an integer `n` such that `n * n == y`, assuming `f(n) = n * n` is strictly increasing.

---

##  Prerequisites

Before installing or running the package, make sure you have the following installed on your system:

- **C++ compiler** (e.g. `g++` or `clang++`)
- **CMake** (for building C++ code)
- **SWIG** (for generating Python bindings)
- **Python 3.8+** (with `pip`)

On macOS, you can install these with [Homebrew](https://brew.sh/):

```
    brew install cmake swig python
```

On Ubuntu/Debian
```
    sudo apt-get install build-essential cmake swig python3 python3-pip
```


## Running C++ Tests
cd increasing_function
mkdir -p build
cd build
cmake ..
make
./runFindTests


###  Running Python Tests

# Wrap the C++ library
cd increasing_function
swig -python -c++ -I. find_square.i
# Move find_square_wrap.cxx and find_square.py to python_wrapper folder
mv find_square_wrap.cxx  python_wrapper/find_square_wrap.cxx 
mv find_square.py  python_wrapper/find_square.py

# Compile the package for python
cd python_wrapper
mkdir -p build
cd build

# Adjust this according to your architecture (e.g. arm64 for Apple M1 Pro)
cmake .. \
  -DCMAKE_OSX_ARCHITECTURES=arm64 \
  -DPython3_EXECUTABLE=$(which python3)

make
cd ..

# Run the python tests
cd python_wrapper
./test_find_square.py  


##  Installation

### Option 1 (Recommended): Use a virtual environment

cd find_square_pkg
python3 -m venv venv
source venv/bin/activate
python3 -m pip install .

### Option 2 (Quick): Install to your user environment
## On macOS (Python 3.12+), --break-system-packages may be required due to PEP 668 protections.
cd increasing_function
mkdir -p find_square_pkg/find_square
cp python_wrapper/find_square.py find_square_pkg/find_square/find_square.py
cp python_wrapper/build/_find_square.so find_square_pkg/find_square/_find_square.so
cd find_square_pkg
python3 -m pip install . --break-system-packages
rm -rf build find_square.egg-info

## Use the package 
python3
>>> import find_square
>>> print(find_square.find_square(81.0, 0, 20))
9
>>>
