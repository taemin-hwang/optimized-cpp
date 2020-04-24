#include <iostream>
#include "thread/ThreadPool.h"

using namespace std;

int work(int t, int id) {
    cout << id << " : start" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(t));
    cout << id << " : end ," << t << endl;
    return t;
}

int main() {
    ThreadPool pool(3);
    std::vector<std::future<int>> futures;
    for(int i = 0; i < 10; ++i) {
        futures.emplace_back(pool.EnqueueJob(work, i % 3 + 1, i));
    }

    for(auto& f : futures) {
        cout << f.get() << endl;
    }
}
