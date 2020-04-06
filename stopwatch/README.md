# Stopwatch

### editting
+ create stopwatch instance before calling a specific function
```
{
    Stopwatch st("manager_.Run() #1");
    manager_.Run();
}
```

### result
+ execute binary
```
$ ./a.out
hello gprof
manager_.Run() #1: 0ms
hello gprof : 10000000
manager_.Run() #2: 21ms
```
