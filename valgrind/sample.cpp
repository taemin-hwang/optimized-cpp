#include <iostream>
#include <vector>
#include <cstring>
#include <memory>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono_literals;

class Func {
public:
    Func() = default;
    void SetFunc(void (*f_)()) { f = f_; };
    void Run() { f(); }

private:
    void (*f)();

};

class Manager {
public:
    Manager() { func = make_unique<Func>(); }
    void SetFunc(void (*f_)()) { func->SetFunc(f_); }
    void Run() { func->Run(); }

private:
    unique_ptr<Func> func;
};

int main() {
    Manager manager_;
    manager_.SetFunc([]() { cout << "hello gprof" << endl;});
    manager_.Run();
    manager_.SetFunc([]() {
        cout << "hello gprof" << endl;
        this_thread::sleep_for(1s);
        });
    manager_.Run();
}
