#include "awaitor.h"

using namespace Concurrency;

Awaitor::Awaitor(std::function<void()> suspend_job)
{
    this->suspend_job = suspend_job;
    suspend_result = AwaitStatus::FAILURE;
}

bool Awaitor::await_ready() const noexcept
{
    // by default, the coroutine will not be suspended right away when co_await-ing
    return false;
}

void Awaitor::await_suspend(std::coroutine_handle<> handle) noexcept
{
    // presumably, do an operation that must be made asynchronous, like I/O. 
    // Note that in the future callbacks could signal this function by reference or return value when an event happens (operation complete, timeout, error, etc...)
    suspend_job();
    // set the result of the suspend job
    suspend_result = AwaitStatus::SUCCESS;
    handle.resume();
}

Awaitor::AwaitStatus Awaitor::await_resume() const noexcept
{
    // return the result of the suspend job
    return suspend_result;
}
