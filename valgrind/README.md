# Valgrind
valgrind detects memory management and threading bugs, and profile programs in detail

## precondition
* kcachegrind provide visualization of profile datay
```
sudo apt-get install valgrind
sudo apt-get install kcachegrind
```

## compile option (-g)
+ add -g compile option to add debug symbol
```
g++ main.cpp -std=c++14 -g
```

## memory checker
### run
```
valgrind --leak-check=full --show-leak-kinds=all ./a.out
```

## cpu profiler
### run
```
valgrind --tool=callgrind ./a.out
```

### outout
```
callgrind.out.*
```

### callgrind result
```
kcachegrind callgrind.out.*
```
