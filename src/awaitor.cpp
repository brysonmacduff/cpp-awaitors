#include "awaitor.h"

using namespace Concurrency;

Awaitor::Awaitor(std::function<void()> suspend_job)
{
    this->suspend_job = suspend_job;
}

bool Awaitor::await_ready() const noexcept
{
    // by default, the coroutine will not be suspended right away when co_await-ing
    return false;
}

void Awaitor::await_suspend(std::coroutine_handle<> handle) const noexcept
{
    // presumably, do an operation that must be made asynchronous, like I/O
    suspend_job();
    handle.resume();
}

void Awaitor::await_resume() const noexcept
{
    // do nothing on resumption of the coroutine
}
