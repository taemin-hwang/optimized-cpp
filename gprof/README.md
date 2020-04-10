# gprof

### compile option (-pg)
```
g++ main.cpp -pg
```

### run
```
./a.out
```

### output
```
gmon.out
```

### gprof result
```
gprof --graph a.out gmon.out > result.log
```
