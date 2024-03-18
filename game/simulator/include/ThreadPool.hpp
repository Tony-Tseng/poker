#pragma once
#include <condition_variable> 
#include <functional> 
#include <iostream> 
#include <mutex> 
#include <queue> 
#include <thread> 

class ThreadPool
{
private:
    std::vector<std::thread> threads_;
    std::queue<std::function<void()> > tasks_;
    std::mutex queue_mutex_;
    std::condition_variable cv_;
    bool stop_ = false;

public:
    ThreadPool(size_t num_threads = std::thread::hardware_concurrency());
    ~ThreadPool()
    { 
        {
            // Lock the queue to update the stop flag safely 
            std::unique_lock<std::mutex> lock(queue_mutex_); 
            stop_ = true;
        }
        
        cv_.notify_all(); 

        // Joining all worker threads to ensure they have 
        // completed their tasks 
        for (auto& thread : threads_) { 
            thread.join(); 
        } 
    }

    void enqueue(std::function<void()> task);
};