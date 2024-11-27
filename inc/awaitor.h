#ifndef AWAITOR_H
#define AWAITOR_H

#include <coroutine>
#include <functional>
#include <unistd.h>
#include <spdlog/spdlog.h>

namespace Concurrency
{
class Awaitor
{
public:
    Awaitor(std::function<void()> suspend_job);

    // Determines if the coroutine should be suspended immediately.
    bool await_ready() const noexcept;
    // Suspends the coroutine and decides when it should be resumed
    void await_suspend(std::coroutine_handle<> handle) const noexcept;
    // Defines what happens when the coroutine is resumed
    void await_resume() const noexcept;

private:
    std::function<void()> suspend_job;
};
}

#endif