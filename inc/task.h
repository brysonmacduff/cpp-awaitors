#ifndef TASK_H
#define TASK_H

#include <coroutine>
#include <stdlib.h>

namespace Concurrency
{ 
class Task
{
public:
    struct promise_type
    {
        friend Task;
        // call at the start of co_await
        std::suspend_always initial_suspend();
        // returns a handle to this task
        Task get_return_object();
        // called at the end of co_await
        std::suspend_never final_suspend() noexcept;
        // called on co_yield. Argument is passed via co_yield
        std::suspend_always yield_value(int code);
        // does nothing
        void return_void();
        // called if an exception occurs
        void unhandled_exception();

        int yield_code;
    };

private:
    std::coroutine_handle<promise_type> coroutine;

public:
    Task(std::coroutine_handle<promise_type> ch);
    void Resume();
    void Destroy();
    bool IsDone();
    int GetYieldCode();
};
}

#endif