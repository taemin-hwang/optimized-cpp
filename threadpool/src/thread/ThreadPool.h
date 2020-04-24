#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_

#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <mutex>
#include <queue>
#include <future>
#include <thread>
#include <vector>

class ThreadPool {
public:
    ThreadPool(size_t num_threads);
    ~ThreadPool();

    //void EnqueueJob(std::function<void()> job);
    template<class F, class... Args>
    std::future<typename std::result_of<F(Args...)>::type> EnqueueJob(F f, Args... args);

private:
    size_t num_threads_;
    std::vector<std::thread> worker_threads_;
    std::queue<std::function<void()>> jobs_;
    std::condition_variable cv_job_q_;
    std::mutex m_job_q_;

    bool stop_all;
    void WorkerThread();
};

template<class F, class... Args>
std::future<typename std::result_of<F(Args...)>::type> ThreadPool::EnqueueJob(F f, Args... args) {
    if(stop_all) {
        throw std::runtime_error("Threadpool exit");
    }

    using return_type = typename std::result_of<F(Args...)>::type;

    auto job = std::make_shared<std::packaged_task<return_type()>>(std::bind(f, args...));

    std::future<return_type> job_result_future = job->get_future();
    {
        //std::unique_lock<std::mutex> lock(m_job_q_);
        std::lock_guard<std::mutex> lock(m_job_q_);
        jobs_.push([job]() { (*job)(); });
    }
    cv_job_q_.notify_one();

    return job_result_future;
}

#endif
