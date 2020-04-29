# Template-Scapegoat

## Using the header-file in your own project
Download the files in the `include/` directory, \
and use `g++` with the `-Idir` option \
Example: `g++ -I./include test.cpp -g`

## Running tests

Prereqiusites:
- c++11 or higher
- gnu-sed for makefile
   
### Compiling
```
make clean
make depend
make
```

### Execution
```
make run
```